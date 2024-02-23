#include<iostream>
#include<thread>//thread library
using namespace std;

class thread_object{
	public:
		void operator() (int x){
			for(int i=0;i<x;i++){
				cout<<"thread using function objectas callable"<<endl;
			}
		}
};
int main()
{
	thread thread1(thread_object(),3);
	cout<<"\n"<<"Inside main()...."<<endl;
	thread1.join();
        return 0;
}
