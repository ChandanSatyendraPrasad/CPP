//using std::packaged_task and passing function as callback function
/*#include <iostream>
#include <thread>
#include <future>

using namespace std;

int addition(int a, int b)
{
    int res = a + b;
    return res;
}

int main()
{
    cout << "main thread " << endl;
    std::packaged_task<int(int,int)> pk_task(addition);
    std::future<int> futureObj = pk_task.get_future();

    std::thread threadObj(std::move(pk_task), 10, 5);
    threadObj.join();
    int val = futureObj.get();
    cout<<"val is "<<val<<endl;
    return 0;
}
*/

//std::packaged_task<> using function object
/*#include <iostream>
#include <thread>
#include <future>

using namespace std;

class Test
{
public:
    int operator()(int a, int b)
    {
        int res = a+b;
        return res;
    }
};

int main()
{
    std::packaged_task<int(int, int)> pk_task(std::move(Test()));
    std::future<int> futureObj = pk_task.get_future();
    std::thread threadObj(std::move(pk_task),10,5);
    threadObj.join();
    int val = futureObj.get();
    cout<<"val is "<<val<<endl;
    return 0;
}
*/


//to create packaged_task<> object using lambda function
#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main()
{
    std::packaged_task<int(int,int)> pk_task([](int a, int b){
                                    return a+b;
});
    std::future<int> futureObj = pk_task.get_future();
    std::thread threadObj(std::move(pk_task),10,5);
    threadObj.join();
    int val = futureObj.get();
    cout<<"val using lambda function is "<<val<<endl;
    return 0;
}

