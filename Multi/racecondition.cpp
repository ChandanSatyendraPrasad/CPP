#include <iostream>
#include <thread>
#include <vector>

/*using namespace std;

class pocketMoney
{
    int m_rupees;
    public:
    pocketMoney()
    {
        m_rupees = 0;
    }
    void addPocketMoney(int rupees)
    {
        for(int i=0; i<rupees; i++)
        {
            m_rupees++;
            cout<<"callback memberfunc m_rupees is "<<m_rupees<<" and thread id is "<< std::this_thread::get_id() <<endl;
        }
    }
    int getPocketMoney()
    {
        return m_rupees;
    }
};

int main()
{
	pocketMoney pMoneyObj;
	std::vector<std::thread> threadVec;
	for(int i=0; i< 2; i++)
    {
        threadVec.push_back(std::thread(&pocketMoney::addPocketMoney, &pMoneyObj, 5));
    }
	for(int i = 0; i<threadVec.size(); i++)
	{
		threadVec.at(i).join();
	}
	return 0;
}
*/
class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
          std::cout<<"and thread id is "<< std::this_thread::get_id() <<std::endl;
       }
    }
};
int testMultithreadedWallet()
{
   Wallet walletObject;
   std::vector<std::thread> threads;
   for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
   }
   for(int i = 0; i < threads.size() ; i++)
   {
       threads.at(i).join();
   }
   return walletObject.getMoney();
}
int main()
{
  int val = 0;
  for(int k = 0; k < 1000; k++)
  {
     if((val = testMultithreadedWallet()) != 5000)
     {
       std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
     }
     else
     {
         std::cout<<"val is "<< val << std::endl;
     }
     std::cout<<"outside if else val is "<< val << std::endl;
  }
  return 0;
}
