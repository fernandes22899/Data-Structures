CXX=g++

all: charlist.o set.o jumble setTest

charlist.o: charlist.cpp charlist.h
	$(CXX) -c charlist.cpp

jumble: jumble.cpp charlist.o
	$(CXX) -g jumble.cpp  charlist.o -o jumble

set.o: set.cpp set.h
	$(CXX) -c set.cpp

setTest: setTest.cpp set.o set.h
	$(CXX) setTest.cpp set.o -lgtest -lpthread -o setTest

clean:
	rm -f *.o setTest jumble charlist.o set.o
