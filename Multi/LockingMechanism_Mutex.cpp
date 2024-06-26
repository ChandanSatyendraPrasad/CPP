//Locking mechanism to avoid race condition
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class fridge
{
    int m_tomato;
    std::mutex mutex;
    public:
    fridge()
    {
        m_tomato = 0;
    }
    void addTomatoinFridge(int tomato)
    {
        mutex.lock();
        for(int i=0; i<tomato; i++)
        {
            m_tomato++;
            cout<<"callback memberfunc m_tomato is "<<m_tomato<<" and thread id is "<< std::this_thread::get_id() <<endl;
        }
        mutex.unlock();
    }
    int getTomatofromFridge()
    {
        return m_tomato;
    }
};

int multiThreadTomatoCount()
{
    fridge friObj;
	std::vector<std::thread> threadVec;
	for(int i=0; i< 5; i++)
    {
        threadVec.push_back(std::thread(&fridge::addTomatoinFridge, &friObj, 50));
    }
	for(int i = 0; i<threadVec.size(); i++)
	{
		threadVec.at(i).join();
	}
    return friObj.getTomatofromFridge();
}

int main()
{
    cout<<"In main func multithreaded "<<endl;
	/*fridge friObj;
	std::vector<std::thread> threadVec;
	for(int i=0; i< 2; i++)
    {
        threadVec.push_back(std::thread(&fridge::addTomatoinFridge, &friObj, 250));
    }
	for(int i = 0; i<threadVec.size(); i++)
	{
		threadVec.at(i).join();
	}
*/
    int cnt;
	//for(int i=0; i<1000; i++)
    //{
        //int tomatoCnt = multiThreadTomatoCount();

        if((cnt = multiThreadTomatoCount()) != 250)
        {
            cout<<"error occurred and tomatoCnt is "<<cnt<<endl;
        }
        else
        {
            cout<<"tomatoCnt is "<<cnt<<endl;
        }
    //}

    return 0;
}
