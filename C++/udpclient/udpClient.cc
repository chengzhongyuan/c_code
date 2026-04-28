#define _WIN32_WINNT 0x0600
#include <iostream>
#include <string>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h> // 用于修改控制台编码

// 强制告诉 Visual Studio / 编译器链接 Windows 网络底层库
#pragma comment(lib, "ws2_32.lib")

class UdpChatClientWin {
private:
    SOCKET _sockfd;// 这个是不同的地方，在windows中有特定的文件描述符格式
    sockaddr_in _serverAddr{};// 需要填入ip地址端口号还有网络协议域

public:
    UdpChatClientWin(const std::string& serverIp, int serverPort) {
        // 1. 初始化 Windows 网络底层环境
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "WSAStartup 失败！" << std::endl;
            exit(1);
        }

        // 2. 创建 UDP 套接字 (注意这里返回的是 SOCKET 类型)
        _sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (_sockfd == INVALID_SOCKET) {
            std::cerr << "创建 Socket 失败！" << std::endl;
            WSACleanup();
            exit(1);
        }

        // 3. 配置你要连接的 Linux 服务器地址
        _serverAddr.sin_family = AF_INET;
        _serverAddr.sin_port = htons(serverPort);
        // 将字符串格式的 IP 转换为网络字节序
        /*
            参数 1：AF_INET（你要翻译哪种语言？）
            告诉翻译官：“我接下来给你的字符串是 IPv4 地址，请按照 IPv4 的规则来翻译。”（如果是 IPv6，这里就填 AF_INET6）。

            参数 2：serverIp.c_str()（你要翻译的那句话是什么？）
            这就是你的公网 IP 字符串，比如 "49.232.244.54"。
            细节注意： 为什么要在后面加 .c_str()？因为底层网络函数都是 C 语言写的，它们不认识 C++ 的 std::string 对象，只认识 C 语言的字符指针 char*。.c_str() 就是把 C++ 字符串打回 C 语言原形的方法。

            参数 3：&_serverAddr.sin_addr（翻译好的结果存到哪里？）
            你把你刚刚准备好的快递面单（_serverAddr）里的 sin_addr 区域的内存地址交给了翻译官。翻译官翻译完之后，会直接把那串底层的二进制数字写进这个内存位置。
        */
        InetPton(AF_INET, serverIp.c_str(), &_serverAddr.sin_addr);
    }

    void run() {
        // 【子线程：耳朵】专门在后台死循环接收 Linux 服务器的群发消息
        std::thread recvThread([this]() {
            char buffer[1024];
            while (true) {
                // Windows 下 recvfrom 最后两个参数可以传 nullptr，因为我们不需要记录服务器的地址（我们已经知道了）
                int n = recvfrom(_sockfd, buffer, sizeof(buffer) - 1, 0, nullptr, nullptr);
                if (n > 0) {
                    buffer[n] = '\0';
                    // 简单的清行动画：先用空格覆盖当前行的 "(我) > "，打印消息后，再重新打出提示符
                    std::cout << "\r" << std::string(30, ' ') << "\r"; 
                    std::cout << buffer << "\n(我) > " << std::flush;
                }
            }
        });
        
        // 分离线程，让它在后台默默运行
        recvThread.detach(); 

        // 【主线程：嘴巴】专门负责读取键盘输入，并发送给 Linux 服务器
        std::string message;
        std::cout << "====================================\n";
        std::cout << "  成功启动 Windows UDP 客户端！\n";
        std::cout << "  请输入消息开始群聊 (按 Ctrl+C 退出)\n";
        std::cout << "====================================\n";
        std::cout << "(我) > ";
        
        while (true) {
            std::getline(std::cin, message);
            if (message.empty()) continue;

            // 发送数据到公网的 Linux 服务器
            int sendBytes = sendto(_sockfd, message.c_str(), (int)message.size(), 0, 
                                   (sockaddr*)&_serverAddr, sizeof(_serverAddr));
            
            if (sendBytes == SOCKET_ERROR) {
                std::cerr << "\n[错误] 发送失败，错误码: " << WSAGetLastError() << "\n";
            }
            
            std::cout << "(我) > ";
        }
    }

    ~UdpChatClientWin() {
        // 4. 关闭套接字，清理 Windows 网络环境
        closesocket(_sockfd);
        WSACleanup();
    }
};

int main() {
    // 🌟 解决跨平台中文乱码的终极绝招：强制把 Windows 控制台改为 UTF-8 编码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // ==============================================================
    // ⚠️ 极其重要：
    // 这里必须填写你 CentOS 机器的【公网 IP】！不能填 127.0.0.1！
    // 比如：UdpChatClientWin client("49.232.244.54", 8888);
    // ==============================================================
    std::string serverPublicIp = "49.232.244.54"; // 替换为你的真实公网 IP
    int serverPort = 8888;                        // 替换为你的真实端口

    UdpChatClientWin client(serverPublicIp, serverPort);
    client.run();

    return 0;
}