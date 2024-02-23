#include<iostream>
#include<thread>//thread library

using namespace std;
void foo(){
	cout<<"Iside the routine foo()"<<endl;
}

void bar(int x){
  cout<<"Inside the routine  bar(int x)"<<endl;
  cout<<"X value"<<x<<endl;
}
int main()
{
	std::thread first(foo); //thread name is first
	std::thread second(bar,0);
	cout<<"\n"<<"Inside main()...."<<endl;
	//synchronice the thread using join
	first.join();
	second.join();
	cout<<"\n"<<"foo() and bar() completed"<<endl;
	cout<<"main completed"<<endl;
	return 0;
}
