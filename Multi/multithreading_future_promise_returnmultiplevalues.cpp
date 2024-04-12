//using std::future and std::promise to return value from thread
/*#include <iostream>
#include <thread>
#include <future>

using namespace std;

void func(std::promise<int> *promiseObj)
{
    cout<<"In func 1 "<<endl;
    promiseObj->set_value(10);
    cout<<"In func 2 "<<endl;
}

int main()
{
    cout << "main thread using future and promise object " << endl;
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    thread threadObj(func, &promiseObj);

    int val = futureObj.get();

    cout<<"val in main thread is "<<val<<endl;
    threadObj.join();
    return 0;
}

*/
#include <iostream>
#include <thread>
#include <future>

using namespace std;

void func(std::promise<int> *promiseObj,std::promise<char> *promiseObj2, std::promise<float> *promiseObj3)
{
    cout<<"In func 1 "<<endl;
    promiseObj->set_value(10);
    promiseObj2->set_value('s');
    promiseObj3->set_value(2.5);
    cout<<"In func 2 "<<endl;
}

int main()
{
    cout << "main thread using future and promise object " << endl;
    std::promise<int> promiseObj;
    std::promise<char> promiseObj2;
    std::promise<float> promiseObj3;
    std::future<int> futureObj = promiseObj.get_future();
    std::future<char> futureObj2 = promiseObj2.get_future();
    std::future<float> futureObj3 = promiseObj3.get_future();
    //std::thread threadObj(func, &promiseObj);
    std::thread threadObj(func, &promiseObj, &promiseObj2, &promiseObj3);
    int val = futureObj.get();
    char val2 = futureObj2.get();
    float val3 = futureObj3.get();
    cout<<"val in main thread is "<<val<<" and val2 is "<<val2<<" val3 is "<< val3<<endl;
    threadObj.join();
    return 0;
}

