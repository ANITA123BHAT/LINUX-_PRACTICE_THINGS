#include<iostream>
#include<thread>
using namespace std;
void fun(int x){
	while(x>0){
		cout<<x<<endl;
		x--;
	}
}
int main(){
	//thread type2:lamda at thread creation...
	auto fun1=[](int x){
		while(x>0){
			cout<<x<<endl;
			x--;
		}
	};
thread t1(fun,11);//type2: function pointer for thread creation..
t1.join();
thread t(fun1,4);
t.join();

thread t2([](int y){//we can directly inject lamda at thread creation time.
while(y>0){
	cout<<y<<" ";
	y--;
}
cout<<endl;
},7);
t2.join();
return 0;
}
