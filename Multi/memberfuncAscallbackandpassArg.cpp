#include <iostream>
#include <thread>

using namespace std;

class Test
{
    int m_var;
    public:
    Test()
    {
    }
    void m_func(int x)
    {
        m_var = x;
        cout<<"m_var is "<<m_var<<endl;
    }
};
int main()
{
    Test classObj;
    std::thread threadObj(&Test::m_func, &classObj,10);
    threadObj.join();
    return 0;
}
