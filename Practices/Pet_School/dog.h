#include <iostream>
#include <string>    
using namespace std;
class DogSchool;
class Dog {
public:
	string m_name;
	string school_name;
	Dog(string data);
	void dropSchool();
	void setName(string data);
	void speak();
};

