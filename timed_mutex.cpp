//Ex: if one thread is doing some task and if another thread try to lock then it can't bcz task is already loked by another thread so t2 can do some other task without wasting time i.e is in t1.try_lock() case but in this timed lock t2 can wait for a perticukar amount of time to unlocked by t1 and after unlock immidietly do the task by locking same viceversa...

//Member function:
//1.lock..
//2.try_lock..
//3.try_lock_for()..
//4.try_lock_until..
//5.unlock..


#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

int myAmount=0;
std::timed_mutex m;

void increament(int i){
	if(m.try_lock_for(std::chrono::seconds(1))){
		++myAmount;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		cout<<"thread"<<i<<"Entered"<<endl;
		m.unlock();
	}else{
		cout<<"Tread"<<i<<"Couln't enter"<<endl;
	}
}
int main(){
	std::thread t1(increament,1);
	std::thread t2(increament,2);
	t1.join();
	t2.join();
	cout<<myAmount<<endl;
	return 0;
}
