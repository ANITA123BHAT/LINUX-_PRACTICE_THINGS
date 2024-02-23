#include<iostream>
#include<thread>
using namespace std;
//type4.Non static member fuction...
class Base{
	public:
		void run(int x){
			while(x>0){
				cout<<x<<endl;
				x--;
			}	
		}
};
//static member function we don't need an object ...
class Base1{
	public:
		static void fun1(int x){
			while(x>0){
				cout<<x<<endl;
				x--;
			}
		}
};
int main(){
	Base b;
	thread t(&Base::run,&b,10);
	thread t1(&Base1::fun1,10);//NO need of an object..
	t.join();
	t1.join();
	return 0;
}
