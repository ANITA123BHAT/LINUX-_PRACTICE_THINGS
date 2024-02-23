#include<iostream>
#include<thread>//thread library
using namespace std;

auto f=[](int x)
{
	cout<<"\n"<<"Inside the lambda expression.."<<x<<endl;
};
int main()
{
	thread thread_object(f,0);
	cout<<"\n"<<"Inside main()...."<<endl;
	thread_object.join();
        return 0;
}
