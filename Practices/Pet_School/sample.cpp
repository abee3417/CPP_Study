#include <iostream>
#include <string>
using namespace std;
#include "dog.h" 
#include "dogschool.h" 
int main() {
	Dog *d1, *d2;
	d1 = new Dog("ö��");
	d2 = new Dog("����");

	DogSchool * ds = new DogSchool("��� �ְ��б�");

	ds->registerDog(d1);  // d1�� �ְ��б��� ��Ͻ�Ų��.
	ds->registerDog(d2);  // d2�� �ְ��б��� ��Ͻ�Ų��.
	ds->registerDog(new Dog("����"));
	ds->showDogs(); // �б��� �ִ� ������ ���� ¢�� �Ѵ�.
	d1->dropSchool();   // ö���� �����Ų��.
	ds->showDogs();   //    
	d2->setName("Snoopy");   // ������ �̸��� Snoopy�� �ٲ۴�.
	ds->setName("MJ Canine School");  // �б� �̸��� �ٲ۴�.
	ds->showDogs();   // �ٲ� �̸��� �ݿ��Ǿ�� �Ѵ�.
}