// test driver for set ADT with built-in iterator
#include "set.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;


int main(){
    Set s1;
    Set::Iterator it, it2;
    // simple test
    assert(s1.size()==0);
    s1.erase("a");
    assert(s1.size()==0);

    s1.insert("a");
    assert(s1.size()==1);

    s1.insert("c");
    assert(s1.size()==2);
    s1.insert("c");
    assert(s1.size()==2);
    //cout << "passed simple test" << endl;

    // insert more
    for (int i = 0; i < 1000; i++){
       s1.insert(to_string(i));
       assert(s1.size() == 3+i);
    }
    assert(s1.size() == 1002);
    //cout << "passed insert more" << endl;

    // test find
    assert(s1.find("e")==s1.end());
    it = s1.find("c");
    assert(it!=s1.end());
    assert(*it=="c");
    //cout << "passed find";

    // boundary test
    assert(s1.find("1001")==s1.end());
    it = s1.find("0");
    assert(it!=s1.end());
    assert(*it=="0");

    it = s1.find("999");
    assert(it!=s1.end());
    assert(*it=="999");
    //cout << "passed boundary test" << endl;

    // test copy constructor and find()
    Set s2 = s1;
    assert(s1.size() == 1002);
    assert(s2.size() == 1002);

    s1.insert("xxx");
    assert(s1.size()==1003);
    assert(s2.size() == 1002);

    s2.insert("zzz");
    assert(s1.size()==1003);
    assert(s2.size() == 1003);

    it = s1.find("999");
    assert(it!=s1.end());
    it2 = s2.find("999");
    assert(it2!=s2.end());
    assert(it2!=it);
    //cout << "passed test copy constructor and find()" << endl;

    // test assignment operator
    Set s3;
    assert(s3.size()==0);

    s3 = s1;
    assert(s3.size()==1003);
    it = s3.find("xxx");
    assert(it!=s3.end());

    s2.insert("aaa");
    s3 = s2;
    assert(s3.size()==1004);
    it = s3.find("xxx");
    assert(it==s3.end());
    it = s3.find("aaa");
    assert(it!=s3.end());
    //cout << "passed test assignment operator" << endl;
}
