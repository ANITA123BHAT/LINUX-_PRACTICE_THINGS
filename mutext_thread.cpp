//Mutex:Mutual Exclusion
//Race condition:
//1) Race condition is a situation where 2 or more process/thread is tring to change the value of the data at a time.
//If there is   race condition than we have to protect taht data /section is called critical section/region.
//++x process 1.LOAD 2.INCR 3.STORE
//there is some accumalator register so their value get load by both thread and increment and store these process happends for both t1 and t2 so value store in Accumulator(AC) is 1.not a 2..


//MUTEX:
//1) Mutext that is use d to avoid the race condition.
//2) We use  lock() and unlock() on mutext to avoid race condition.. 
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int myAmount=0;
std::mutex m;//variable
void myThread(){
	m.lock();//here if it is locked by t1 and inc by 1 at that time t2 can not be execute bcz t1 is locked so after unlocking by t1 then only t2 can use .. so same process for t2 aslo like viceversa..:):)
	++myAmount;
	m.unlock();
}
int main(){
	thread t1(myThread);
	thread t2(myThread);
	t1.join();
	t2.join();
cout<<myAmount<<endl;
	return 0;
}
