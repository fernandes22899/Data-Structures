CXX=g++

all: map.o mapTest mapTest0 mapTest1 mapTest2 mapTest3 mapTest4 mapTest4 mapTest5 mapTest6 mapTest7 mapTest8
map.o: map.cpp map.h
	$(CXX) -c map.cpp

mapTest: mapTest.cpp map.o map.h
	$(CXX) -g mapTest.cpp map.o -lgtest -lpthread -o mapTest
	#./mapTest

mapTest0: maptest0.cpp map.o map.h
	$(CXX) -g maptest0.cpp map.o -lgtest -lpthread -o mapTest0
	#./mapTest

mapTest1: maptest1.cpp map.o map.h
	$(CXX) -g maptest1.cpp map.o -lgtest -lpthread -o mapTest1

mapTest2: maptest2.cpp map.o map.h
	$(CXX) -g maptest2.cpp map.o -lgtest -lpthread -o mapTest2

mapTest3: maptest3.cpp map.o map.h
	$(CXX) -g maptest3.cpp map.o -lgtest -lpthread -o mapTest3

mapTest4: maptest4.cpp map.o map.h
	$(CXX) -g maptest4.cpp map.o -lgtest -lpthread -o mapTest4

mapTest5: maptest5.cpp map.o map.h
	$(CXX) -g maptest5.cpp map.o -lgtest -lpthread -o mapTest5

mapTest6: maptest6.cpp map.o map.h
	$(CXX) -g maptest6.cpp map.o -lgtest -lpthread -o mapTest6

mapTest7: maptest7.cpp map.o map.h
	$(CXX) -g maptest7.cpp map.o -lgtest -lpthread -o mapTest7

mapTest8: maptest8.cpp map.o map.h
	$(CXX) -g maptest8.cpp map.o -lgtest -lpthread -o mapTest8

clean:
	rm -f *.o  mapTest mapTest0 mapTest1 mapTest2 mapTest3 mapTest4 mapTest5 mapTest6 mapTest7 mapTest8
