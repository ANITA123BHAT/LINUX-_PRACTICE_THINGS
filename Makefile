#this target will compile all file
#all:hello

#hello:main.o function1.o function2.o
#	g++ main.o  function1.o function2.o -o hello
#main.o:main.cpp
#	g++ -c main.cpp

#function1.o:function1.cpp
#	g++ -c function1.cpp

#function2.o:function2.cpp
#	g++ -c function2.cpp
#clean:
#	rm -rf *o hello
#here 3 object
#main.o function1.o all are target
# dependancy: whatever you write after ' :' i.e is depedancy
# g++ -c main.cpp are cmd
# clean cmd to clean all object file / executable file
# hello: is executing all object file
# it has dependancy of all file
# and then execute all file
# and then hello in all target


#declare the varibale..
CC=g++  #cc contains type of compiler

CFLAGS= -c Wall#set variable which type of compiler option 
all:hello

hello:main.o function1.o function2.o
	$(CC) main.o function1.o function2.o -o hello

main.o:main.cpp
	$(CC) $(CFLAGS) main.cpp

function1.o:function1.cpp
	$(CC) $(CL=FLAGS) function1.cpp

function2.o: function2.cpp
	$(CC) $(CFLAGS) function2.cpp

clean:
	rm -rf *o hello




