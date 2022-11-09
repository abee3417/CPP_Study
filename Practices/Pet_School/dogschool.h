#include <iostream>
#include <string>    
using namespace std;
class Dog;
class DogSchool {
public:
	int i = 0, count = 0;
	string m_name;
	Dog * dog[100];
	DogSchool(string data);
	void registerDog(Dog *data);
	void showDogs();
	void setName(string data);
};

