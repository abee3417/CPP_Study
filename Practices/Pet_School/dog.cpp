#include <iostream>
#include <string>
using namespace std;
#include "dog.h" 
#include "dogschool.h" 
Dog::Dog(string data) {  // �̸� ���� ������
	m_name = data;
}
void Dog::dropSchool() { // ���� ó�� ��ų ������ �̸� ����
	m_name = "";
}
void Dog::setName(string data) { // ������ �̸� �ٲٱ�
	m_name = data;
}
void Dog::speak() {
	cout << "�۸�, ���� " << this->m_name << "�Դϴ�.";
	cout << "���� " << this->school_name << "�� �ٴմϴ�." << endl;
}