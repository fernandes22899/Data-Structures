CXX=g++

all: queue.o queueTest

queue.o: queue.cpp queue.h
	$(CXX) -g -c queue.cpp

queueTest: queueTest.cpp queue.cpp queue.h
	$(CXX) -g queueTest.cpp queue.cpp -lgtest -lpthread -o queueTest

clean:
	rm -f queueTest queue.o
