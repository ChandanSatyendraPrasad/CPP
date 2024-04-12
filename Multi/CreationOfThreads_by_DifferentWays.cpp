//To create threads by three different ways:
//By passing function pointer
//By passing function object
//By using lambda function

#include <iostream>
#include <thread>
using namespace std;

void func(int x)
{
    for (int i = 0; i < x; i++) {
        cout << "Thread using function pointer as callable  "<<x<<endl;
    }
}

class Test {
public:
    void operator()(int t)
    {
        for (int i = 0; i < t; i++)
            cout << "Thread using function object as callable"<<endl;;
    }
};

int main()
{
    cout<<"To create threads by 3 different ways "<<endl;
    cout << "1st way by passing function pointer to the thread object as below: " << endl;

    //To create thread object by passing function pointer to constructor of thread object
    //once thread created then callback passed inside thread object will be executed
    thread threadObj1(func, 5);

    //Here below main thread is calling join function on threadObj1,
    //so it will wait for threadObj1 to complete its execution
    threadObj1.join();

    cout << "2nd way by passing function object to the thread object as below: " << endl;

    //Here once thread object is created as shown below
    //then function object passed in thread object will be called and executed
    thread threadObj2(Test(), 5);
    threadObj2.join();

    cout << "3rd way by using lambda function"<<endl;
    //Here we are creating thread object by using lambda function inside thread object
    thread threadObj3([](int x){
                      for (int i = 0; i < x; i++)
            cout << "Thread using lambda function"<<endl;
                      }, 5);
    threadObj3.join();

    return 0;
}
