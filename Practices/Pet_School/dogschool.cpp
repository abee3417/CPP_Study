#include <iostream>
#include <string>
using namespace std;
#include "dogschool.h" 
#include "dog.h"
DogSchool::DogSchool(string data) {  // �̸� ���� ������
	m_name = data;
}
void DogSchool::registerDog(Dog *data) { // ������ �迭�� ����
	dog[i] = data;
	i++, count++;
}
void DogSchool::showDogs() { // ���
	cout << "����� " << m_name << "�Դϴ�." << endl;
	cout << "�л����� �Ұ��մϴ�." << endl;
	for (i = 0; i < count; i++) {
		if (dog[i]->m_name == "") { // ���� ó���� ������ �̸��� ���� ���
			for (int j = i; j < count; j++) {
				dog[j] = dog[j + 1]; // �迭�� �ϳ��� ����.
			}
			count--;
		}
		dog[i]->school_name = m_name;
		dog[i]->speak();
	}
	cout << endl;
}
void DogSchool::setName(string data) { // �б� �̸� �ٲٱ�
	m_name = data;
}
