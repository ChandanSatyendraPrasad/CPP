//To use condition variable for signalling between 2 threads
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class MathOp
{
    int m_data;
    bool flag;
    std::mutex m_mutex;
    std::condition_variable m_condvar;
public:
    MathOp()
    {
        m_data = 0;
        flag = false;
    }
    bool isOperDone()
    {
        return flag;
    }
    void task_thr2()
    {
        cout<<"thread 2 started "<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        cout<<"thread 2 before locking"<<endl;
        std::lock_guard<std::mutex> lockguard(m_mutex);
        cout<<"thread 2 after locking"<<endl;
        m_data = m_data + 10;
        flag = true;
        m_condvar.notify_one();
        cout<<"thread 2 after notify"<<endl;
    }

    void task_thr1()
    {
        cout<<"thread1 started "<<endl;
        int a = 10,b = 40,sum;
        sum = a + b;
        cout<<"thread 1 sum is "<< sum << endl;

        //It std::unique_lock is the lock to apply to mutex by the thread
        //and pass it as 1st parameter of wait function
        //called on condition variable object for which it is waiting to be signaled
        std::unique_lock<std::mutex> lck(m_mutex);
        cout<<"thread 1 after locking"<<endl;

        //below wait function is thread on condition variable object i.e. thread1 will wait
        //for condition variable to get signal
        //While wait function will release lock, block the thread
        //and will wait for condition variable to get signal
        //once condition variable gets signal, then it will
        //unblock the thread1 and will again acquire lock
        //and will check if condition have really met and if no then
        //will again call wait and put thread1 in waiting queue
        //and if condition is met then it will  execute other instruction
        m_condvar.wait(lck, [this](){
                       return isOperDone();
                       });
        cout<<"thread 1 m_data is "<<m_data<<endl;
        cout<<"thread 1 got executed"<<endl;
    }
};

    int main()
    {
        MathOp obj;
        cout<<"main started "<<endl;
        std::thread threadObj1(&MathOp::task_thr1,&obj);
        std::thread threadObj2(&MathOp::task_thr2,&obj);
        threadObj1.join();
        threadObj2.join();
        cout<<"main before exiting "<<endl;
        return 0;
    }



/*#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Test
{
    bool dataLoad;
    std::mutex m_mutex;
    std::condition_variable m_condvar;
public:
    Test()
    {
        dataLoad = false;
    }
    void loadingData_thr2()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout<<"It is loading the data "<<endl;
        std::lock_guard<std::mutex> lockguard(m_mutex);
        dataLoad = true;
        m_condvar.notify_one();
        cout<<"It is loading the data **** "<<endl;
    }
    bool isDataLoaded()
    {
        return dataLoad;
    }
    void waiting_Thread()
    {
        cout<<"in thread1 handshaking with server "<<endl;

        std::unique_lock<std::mutex> lock(m_mutex);
        cout<<"It is thread1 after locking "<<endl;

        //below wait function is thread on condition variable object i.e. thread1 will wait
        //for condition variable to get signal
        //While wait function will release lock, block the thread
        //and will wait for condition variable to get signal
        //once condition variable gets signal, then it will
        //unblock the thread1 and will again acquire lock
        //and will check if condition have really met and if no then
        //will again call wait and put thread1 in waiting queue
        //and if condition is met then it will  execute other instruction
        m_condvar.wait(lock, std::bind(&Test::isDataLoaded, this));
        cout<<"It is thread1 after waiting "<<endl;

    }
};

int main()
{
    Test testobj;
    std::thread threadObj1(&Test::loadingData_thr2,&testobj);
    std::thread threadObj2(&Test::waiting_Thread,&testobj);
    threadObj1.join();
    threadObj2.join();
    return 0;
}

*/
