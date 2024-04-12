//Main thread will wait for all threads to complete its execution by calling attach
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
using namespace std;

class childThread
{
public:
    void operator()()
    {
        for(int i =0; i< 20000;i++)
        {};
        cout<<"Inside Child Thread with thread id is "<<std::this_thread::get_id()<<" started"<<endl;
    }
};
int main()
{
    cout<<"In main thread, thread detach in C++11"<<endl;
    vector <thread> threadVec;
    for(int i = 0; i < 15; i++)
    {
        threadVec.push_back( thread( childThread() ) );
    }

    //When thread join is called for each threads in vector list,
    //then main thread will wait for all those threads for which it called join
    for_each(threadVec.begin(),threadVec.end(),[](thread &threadObj){
                  threadObj.join();
                  });

    cout<<"Waiting for all child threads to finish its execution "<<endl;
   // cout<<"In Main thread and Exit only after all the child threads completes its execution "<<std::endl;
    return 0;
}
