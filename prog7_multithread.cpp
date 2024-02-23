#include<iostream>
#include<thread>//thread library

using namespace std;
void foo(int i){
	cout<<"Iside thread number:"<<i<<endl;
	//thread number is returned by this..
}

int main()
{
	thread myThread[20];
	for(int i=0;i<20;i++){
		myThread[i]=thread(foo,i);
	}
	cout<<"\n Inside the main().."<<endl;

	for(int i=0;i<20;i++){
		if(myThread[i].joinable()){
		myThread[i].join();
		}
	}
	cout<<"main completed"<<endl;
	return 0;
}
