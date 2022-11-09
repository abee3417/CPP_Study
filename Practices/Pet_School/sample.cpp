#include <iostream>
#include <string>
using namespace std;
#include "dog.h" 
#include "dogschool.h" 
int main() {
	Dog *d1, *d2;
	d1 = new Dog("철수");
	d2 = new Dog("영이");

	DogSchool * ds = new DogSchool("명랑 애견학교");

	ds->registerDog(d1);  // d1을 애견학교에 등록시킨다.
	ds->registerDog(d2);  // d2을 애견학교에 등록시킨다.
	ds->registerDog(new Dog("똘이"));
	ds->showDogs(); // 학교에 있는 개들을 전부 짖게 한다.
	d1->dropSchool();   // 철수를 자퇴시킨다.
	ds->showDogs();   //    
	d2->setName("Snoopy");   // 영이의 이름을 Snoopy로 바꾼다.
	ds->setName("MJ Canine School");  // 학교 이름을 바꾼다.
	ds->showDogs();   // 바뀐 이름이 반영되어야 한다.
}