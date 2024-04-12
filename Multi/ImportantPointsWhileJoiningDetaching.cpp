#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

class childThread
{
public:
    void operator()()
    {
        cout<<"Inside Child Thread with thread id is "<<std::this_thread::get_id()<<" started"<<endl;
    }
};
void func()
{
    cout<<"In callback func "<<endl;
    for(int i=0; i< 25;i++){};
}
int main()
{
    cout<<"In main thread, thread join in C++11"<<endl;
    std::thread threadObj(func);
    //threadObj.join();
    //threadObj.join();


    if(threadObj.joinable())
    {
        threadObj.join();
    }
    if(threadObj.joinable())
    {
        threadObj.join();
    }

    cout<<"Waiting for child thread to finish its execution "<<endl;
    cout<<"In Main thread and Exit only after child thread completes its execution "<<std::endl;
    return 0;
}
