#include <iostream>
#include <string>
using namespace std;
#include "girl.h" 
#include "boy.h" 
Girl::Girl(string data) { // �̸� ���� ������
	m_name = data;
}
void Girl::hello() { // ��� ���
	cout << "���� " << m_name << "�Դϴ�.";
	cout << "�� ����ģ���� " << m_boyfriend->m_name << "�Դϴ�." << endl;
}
void Girl::setBF(Boy *data) { // ����ģ�� �̸� ����
	m_boyfriend = data;
}