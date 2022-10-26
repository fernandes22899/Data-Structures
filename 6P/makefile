CXX=g++

tests: setTest settest1 settest2 settest3 settest4 settest5

all: set.o

set.o: set.cpp
	$(CXX) -g -c set.cpp


setTest: setTest.cpp  set.o set.h
	$(CXX) -g setTest.cpp set.o -lgtest -lpthread -o setTest


settest1: settest1.cpp  set.o
	$(CXX) -g settest1.cpp set.o -lgtest -lpthread -o settest1

settest2: settest2.cpp  set.o
	$(CXX) -g settest2.cpp set.o -lgtest -lpthread -o settest2

settest3: settest3.cpp  set.o
	$(CXX) -g settest3.cpp set.o -lgtest -lpthread -o settest3

settest4: settest4.cpp  set.o
	$(CXX) -g settest4.cpp set.o -lgtest -lpthread -o settest4

settest5: settest5.cpp  set.o
	$(CXX) -g settest5.cpp set.o -lgtest -lpthread -o settest5

clean:
	rm -f *.o settest1 settest2 settest3 settest4 settest5
