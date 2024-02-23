//JOIN NOTE:
//* once a thread is started we wait for this thread to finish by calling join()  function on thread object..
//* double join will result into program termination.
//* If needed we should check thread is joinable before joing..
//if we give to join for same thread it will show any error.. but it will terminate the execution so it is not  allowed...  so that check with condiationa;l statement i.e if(t1. joinable()){}

//2 type: DETACH NOTES
//*)this is used to detach newly creted thread from the parent thread.
//*) Always check before detaching a thread that it is joinabl otherwise we may end up double detaching and double detach() will result into programm termination.
//*)If we have detached thread and main function is returning then the detached thread execution is suspended.

//NOTE:
//either join() or detach() should be called on thread object, otherwise; during thread object's destructor it will terminate the program. bcz inside destructor it checks if threads is still joinable? if ye sthen terminate the program. 
#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
void run(int x)
{
	while(x>0){

	cout<<"CCPnote"<<endl;
	x--;
	}
	this_thread::sleep_for(chrono::seconds(3));
}
void run1(int y){
	while(y>0){
		cout<<y<<" ";
	y--;
	}
	this_thread::sleep_for(chrono::seconds(3));
	cout<<"THread finish"<<endl;
}
int main(){
thread t1(run,10);
if(t1.joinable()){
t1.join();//to attach
}

thread t2(run1,10);
if(t2.joinable()){
t2.detach();
}
//here t2 will not wait to like sleep() will not work ...
cout<<"Main completed"<<endl;
	return 0;
}
