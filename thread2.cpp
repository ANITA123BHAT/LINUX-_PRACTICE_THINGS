#include<iostream>
#include<thread>
using namespace std;
//type3. functor (function ovbject).....
class Base{
	public:
		void operator() (int x){
			while(x-->0){
				cout<<x<<endl;
			}
		}
		//this is treated as callable function...
};
int main(){
	cout<<"Inside the main function()"<<endl;
	thread t1((Base()),10);
	t1.join();
}
