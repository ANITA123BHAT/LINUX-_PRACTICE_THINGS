//try_lock() Tries to lock the mutex.Return immedietly.On succesful lock cquisition return true otherwie returns flase.
//1) If try_lock() is not able to lock mutex,then it doen't get that's why it is clled non-blocking.
//2) If try_lock() is called again by the same thread which owns the mutex, the behaviour is undefined.
//It is a dead lock situation with undefined behaviour.(If you want to be able to lock the same mutex by the same thred more than one tim the go for recursive_mutex)

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
int counter=0;
mutex mtx;

void increaseTheCounterFor100000Time(){
	for(int i=0;i<100000;++i){
		if(mtx.try_lock()){
			++counter;
			mtx.unlock();
		}
	}
}
int main(){
	thread t1(increaseTheCounterFor100000Time);
	thread t2(increaseTheCounterFor100000Time);
	t1.join();
	t2.join();
	cout<<"Counter could increse upto :"<<counter<<endl;
}
