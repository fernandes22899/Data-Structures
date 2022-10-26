// more tests cases for map::erase() method

#include "map.h"
#include <cassert>
#include <iostream>
using namespace std;

int main(){
	Map m1;
	m1.insert("45", "a");
	m1.insert("21", "a");
	m1.insert("4","a");
	m1.insert("61","a");
	m1.insert("2","a");
	m1.insert("35","a");
	m1.insert("3","a");
	m1.insert("8","a");
	m1.insert("31","a");
	m1.insert("12","a");
	m1.insert("33","a");
	m1.insert("49","a");
	m1.insert("17","a");
	m1.insert("9","a");
	m1.insert("27","a");

	assert(m1.size()==15);

	// test output
	cout << m1;
	// --- OWEN'S CHANGES --- //

	cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	// ---------------------- //


	Map::Iterator it;

	// erase elements not in the set

	m1.erase("62");
	assert(m1.size()==15);

	m1.erase("13");
	assert(m1.size()==15);

	m1.erase("100");
	assert(m1.size()==15);

	m1.erase("1");
	assert(m1.size()==15);

	// erase elements in the set
	m1.erase("9");
	assert(m1.size()==14);
	cout << m1 << endl;
	cout << "++++++++++++++ 9 erased ^^ +++++++++++++++"<< endl;

	m1.erase("27");
	assert(m1.size()==13);
	cout << m1 << endl;
	cout << "++++++++++++++ 27 erased ^^ +++++++++++++++"<< endl;

	m1.erase("21");
	assert(m1.size()==12);
	cout << m1 << endl;
	cout << "+++++++++++++ 21 erased ^^ ++++++++++++++++"<< endl;


	m1.erase("4");
	assert(m1.size()==11);
	cout << m1 << endl;
	cout << "++++++++++++++ 4 erased +++++++++++++++"<< endl;

	m1.erase("61");
	assert(m1.size()==10);
	cout << m1 << endl;
	cout << "+++++++++++++++ 61 erased ^^ ++++++++++++++"<< endl;

	m1.erase("33");
	assert(m1.size()==9);
	cout << m1 << endl;
	cout << "++++++++++++++ 33 erased ^^ +++++++++++++++"<< endl;

	m1.erase("12");
	assert(m1.size()==8);
	cout << m1 << endl;
	cout << "++++++++++++ 12 erased ^^ +++++++++++++++++"<< endl;

	m1.erase("3");
	assert(m1.size()==7);
	cout << m1 << endl;
	cout << "+++++++++++++ 3 erased ^^ ++++++++++++++++"<< endl;

	m1.erase("2");
	assert(m1.size()==6);
	cout << m1 << endl;
	cout << "+++++++++++++ 6 erased ^^ ++++++++++++++++"<< endl;

	m1.erase("17");
	assert(m1.size()==5);
	cout << m1 << endl;
	cout << "++++++++++++++ 17 erased ^^ +++++++++++++++"<< endl;

	m1.erase("45");
	assert(m1.size()==4);
	cout << m1 << endl;
	cout << "+++++++++++++++ 45 erased ^^ ++++++++++++++"<< endl;

	m1.erase("31");
	assert(m1.size()==3);
	cout << m1 << endl;
	cout << "+++++++++++++ 31 erased ^^ ++++++++++++++++"<< endl;

	m1.erase("49");
	assert(m1.size() == 2);
	cout << m1 << endl;
	cout << "+++++++++++++ 49 erased ^^ ++++++++++++++++"<< endl;

	m1.erase("35");
	assert(m1.size() == 1);
	cout << m1 << endl;
	cout << "++++++++++++++ 35 erased ^^ +++++++++++++++"<< endl;

	m1.erase("8");
	assert(m1.size() == 0 );
	cout << m1 << endl;
}
