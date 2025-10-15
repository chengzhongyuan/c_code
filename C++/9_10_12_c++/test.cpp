#include<iostream>
#include<assert.h>

using namespace std;
// 内存管理收尾
template<class T>
    class vector // 动态增长的数组
    {
    private:
        T* _a;
        int _size;
        int _capaity;
    public:
        vector(int num):_a(nullptr),_size(0),_capaity(0)
        {
            /* 当然了这一段也可以不写 */ 
            _a = new T[num];
            _size = 0;
            _capaity = num;
        }
        ~vector()
        {
            delete[] _a;
            _a = nullptr;
            _size = _capaity = 0;
        }

        void pushback(const T& x);
        void push_pop();
        size_t size()
        {
            return _size;
        }
        // 引用传递返回值，修改返回对象
        T& operator[](size_t i)
        {
            assert(i < _size);
            return _a[i]; 
            // 这是一个传值的方式返回，会拷贝一个临时变量，但是临时变量具有常性质
        }
    };

    template<class T>
    void vector<T>::pushback(const T& x)
    {
        if (_size >= _capaity)
        {
            // 扩容逻辑
            int newCapacity = _capaity == 0 ? 1 : _capaity * 2;
            T* tmp = new T[newCapacity];
            for (int i = 0; i < _size; ++i)
                tmp[i] = _a[i];
            delete[] _a;
            _a = tmp;
            _capaity = newCapacity;
        }

        _a[_size++] = x;
    }
    
    template<class T>
    void vector<T>::push_pop()
    {
        assert(_size > 0);
        _size--;
    }
 
int main() {
    // // 为什么c++之中要有new和delete?
    // // new和delete是成对出现的
    // // 对于内置类型，new和delete的作用类似于malloc和free也可以说是一样的
    // int* p = new int(5);
    // cout << *p << endl;
    // delete p;
    // // 对于自定义类型new是会自动调用构造函数，delete会自动调用析构函数
    // 模板 使用模板，编写和类型无关的代码
    // 模板的原理就是把原本我的工作交给编译器，让他根据函数模板和类模板的类型去实例化出对应的函数和类
    
    vector<int> v(10);
    v.pushback(1);
    v.pushback(2);
    v[1]/*所以此时这个数是不允许你去修改的，怎么办呢？*/ = v[1]*2; 
    for(size_t i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    
    return 0;
}