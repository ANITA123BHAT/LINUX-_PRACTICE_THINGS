#include<iostream>
#include<thread>//thread library

using namespace std;
int main()
{
	cout<<"NUmber of threads ="<<thread::hardware_concurrency()<<endl;
	//this is for hardware level concurrency..
	
	return 0;
}
