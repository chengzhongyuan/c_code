#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/* 1、学习使用vector构造函数 */
void learn_constructor()
{
    cout<< "/* 1、学习使用vector构造函数 */"<<endl;
    vector<int> v1;       // 无参构造
    vector<int> v2(4,100);// 构造并初始化n个
    vector<int> v3(v2);   // 拷贝构造
    vector<int> v4(v2.begin(),v2.end());// 这个是使用v2的迭代器

    int myints[] = {1,2,3,4};
    vector<int> v5(myints, myints + sizeof(myints)/sizeof(myints[0])); //直接使用数组进行构造

    // 使用迭代器遍历v5，打印输出
    for(vector<int>::iterator it = v5.begin(); it != v5.end();it++)
    {
        cout<< *it <<" ";
    }
    cout<<endl;
    // 如果我要使用迭代器倒着打印
    for(vector<int>::reverse_iterator it = v5.rbegin(); it != v5.rend();it++)
    {
        cout<< *it <<" ";
    }
    cout<<endl;

    // 使用范围 for 循环输出v1
    cout<<"v1数据输出:";
    for (int num : v1) {
        cout << num << " ";
    }
    cout<<endl;

    // 使用范围 for 循环输出v2
    cout<<"v2数据输出:";
    for(int num : v2){
        cout<<num<<" ";
    }
    cout<<endl;

    // 使用范围 for 循环输出v3
    cout<<"v3数据输出:";
    for(int num : v3){
        cout<<num<<" ";
    }
    cout<<endl;

    // 使用范围 for 循环输出v4
    cout<<"v4数据输出:";
    for(int num : v4){
        cout<<num<<" ";
    }
    cout<<endl;
} 

/* 2、关于vector之中空间增长的问题 */
void learn_capacity()
{
    int myints[] = {1,3,5,6,7,7,8};
    // 已存在数组迭代器方式构建
    vector<int> v1(myints, myints+sizeof(myints)/sizeof(myints[0]));
    cout<<"size:"<<v1.size()<<endl;
    cout<<"capacity:"<<v1.capacity()<<endl;

    // 改变vector的size
    v1.resize(3); // 这样是保留1 3 5三位
    v1.resize(5,100);// 用100去填充空余位置1 3 5 100 100
    v1.resize(8);

    // 改变容量,在已经知道vector中元素个数的请款下，可以将空间预设足够，避免一边插入一边扩容的低下效率
    v1.reserve(100);

    // 使用范围for循环
    for(int num : v1)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<"size:"<<v1.size()<<endl;
    cout<<"capacity:"<<v1.capacity()<<endl;
}
/* 3、学习vector各种接口 */
void learn_modifiers()
{
    int myints[] = {1,3,5,6,7,7,8};
    // 已存在数组迭代器方式构建
    vector<int> v1(myints, myints+sizeof(myints)/sizeof(myints[0]));

    // 在这里find是一个算法,在头文件#include<algorithm>之中
    auto it = find(v1.begin(), v1.end(), 30);
    if (it != v1.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // 进行尾插
    v1.push_back(7);
    // 进行尾删
    v1.pop_back();
    // 在pos之前插入数据
    v1.insert(v1.begin()+1,9);
    // 插入另一个数组
    int myarray[] = {501, 502, 503};
    v1.insert(v1.begin(), myarray, myarray+3);
    // 插入另一个vector
    std::vector<int> anothervector(2, 400); // [400, 400]
    v1.insert(v1.begin()+2, anothervector.begin(), anothervector.end());

    // 删除当前位置的数据，这里的位置全部都是用迭代器去进行体现的
    v1.erase(v1.begin() + 1);
    // 这个位置也可以通过find来获取,遍历一遍找到7
    auto pos = find(v1.begin(), v1.end(), 7);
    v1.erase(pos);
    
    // 交换两个vector
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200
    foo.swap(bar);
    cout<<v1[3]<<endl;

    for(int num: v1)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    
}

/* 4、关于迭代器失效的问题 注意任何会引起其底层空间改变的操作，都有可能是迭代器失效*/
void learn_iterator()
{
    std::vector<int> v = {1, 2, 3};
    auto it = v.begin(); // 指向 1

    v.insert(v.begin(), 0); // 插入后，可能重新分配内存，那么这个时候it指向的就是一块已经被释放的空间，显然这是很严重的

    std::cout << *it; // ? it 已失效，可能崩溃或输出错误
    
    // 我们应该在插入之后再重新进行获取
    v.insert(v.begin(), 0);
    it = v.begin(); // ? 重新获取

    /* 
    erase删除pos位置元素后，pos位置之后的元素会往前搬移，没有导致底层空间的改变，理论上讲迭代
    器不应该会失效，但是：如果pos刚好是最后一个元素，删完之后pos刚好是end的位置，而end位置是
    没有元素的，那么pos就失效了。因此删除vector中任意位置上元素时，vs就认为该位置迭代器失效
    了。
    */

}

/* 5、删除vector之中的所有偶数 */
void learn_erase()
{
    vector<int> v1{ 1, 2, 3, 4 };
    auto it1 = v1.begin();
    while (it1 != v1.end())
    {
        if (*it1 % 2 == 0)
            v1.erase(it1);
 
        ++it1;
    }

    // 下面这个才是正确的吧，上面那个好像是越界了
    vector<int> v2{ 1, 2, 3, 4 };
    auto it2 = v2.begin();
    while (it2 != v2.end())
    {
        if (*it2 % 2 == 0)
        it2 = v2.erase(it2);  // 使用 erase 的返回值更新迭代器
        else
        ++it2;
    } 

    // 同样在之前提到的string之后如果进行这些操作也是会失效的
}

int main()
{
    /* 1、学习使用vector构造函数 */
    learn_constructor();

    /* 2、关于vector之中空间增长的问题 */
    learn_capacity();

    /* 3、学习vector各种接口 */
    learn_modifiers();

    /* 4、关于迭代器失效的问题 */
    learn_iterator();
    return 0;
}