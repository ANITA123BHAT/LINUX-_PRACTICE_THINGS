#include<iostream>
#include<thread>//thread library

using namespace std;
void foo(){
	cout<<"Iside the routine foo()"<<endl;
}

int main()
{
	std::thread first(foo); //thread name is first
	cout<<"\n"<<"Inside main()...."<<endl;
	first.detach();
	if(first.joinable()){
	//synchronice the thread using join
	first.join();
	}
	cout<<"\n"<<"foo() completed"<<endl;
	cout<<"main completed"<<endl;
	return 0;
}
