#include<iostream>
#include<thread>//thread library

using namespace std;
void foo(){
	cout<<"Iside the routine foo()"<<endl;
}

int main()
{
	thread first(foo); //thread name is first

	thread second=move(first); //thread name is first
	cout<<"\n"<<"Inside main()...."<<endl;
	
	if(first.joinable()){
	//synchronice the thread using join
	first.join();
	}

	if(second.joinable()){
		second.join();
	}

	cout<<"\n"<<"both thread completed"<<endl;
	cout<<"main completed"<<endl;
	return 0;
}
