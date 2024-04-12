/*//Pass argument by Value while creating thread object
#include <iostream>
#include <thread>

using namespace std;

void func(int x)
{
    cout <<"In callback func and x is "<<x<<endl;
    x = 19;
    cout <<"after modifying in func x is "<<x<<endl;
}

int main()
{
    cout <<"In main thread pass argument by value"<<endl;
    int i = 10;
    thread t(func, i);
    cout<<"after thread creation in main thread"<<endl;
    t.detach();

    chrono::milliseconds dura( 3000 );
    this_thread::sleep_for( dura );

    cout<<"In main thread before exit i = "<<i<<endl;
    return 0;
}
*/

//Pass argument by Reference while creating thread object
#include <iostream>
#include <thread>

using namespace std;

void func(int &x)
{
    cout <<"In callback func and x is "<<x<<endl;
    x = 19;
    cout <<"after modifying in func x is "<<x<<endl;
}

int main()
{
    cout <<"In main thread pass argument by Reference"<<endl;
    int i = 10;
    thread t(func, ref(i));
    cout<<"after thread creation in main thread"<<endl;
    t.detach();

    chrono::milliseconds dura( 3000 );
    this_thread::sleep_for( dura );

    cout<<"In main thread before exit i = "<<i<<endl;
    return 0;
}


/*//Passing dynamically allocated variable while creating thread object
#include <iostream>
#include <thread>

using namespace std;

void func(int &x)
{
    cout <<"In callback func and x is "<<x<<endl;
    x = 19;
    cout <<"after modifying in func x is "<<x<<endl;
}

int main()
{
    cout <<"In main thread passing dynamic allocated variable by Reference"<<endl;
    int *p = new int(10);
    thread t(func, ref(*p));
    cout<<"after thread creation in main thread"<<endl;
    t.detach();

    chrono::milliseconds dura( 3000 );
    this_thread::sleep_for( dura );

    cout<<"In main thread before exit *p = "<<*p<<endl;
    return 0;
}

*/
