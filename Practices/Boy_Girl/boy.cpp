#include <iostream>
#include <string>
using namespace std;
#include "boy.h" 
#include "girl.h" 
Boy::Boy(string data) {  // �̸� ���� ������
	m_name = data;
}
void Boy::hello() { // ��� ���
	cout << "���� " << m_name << "�Դϴ�.";
	cout << "�� ����ģ���� " << m_girlfriend->m_name << "�Դϴ�." << endl;
}
void Boy::setGF(Girl *data) { // ����ģ�� �̸� ����
	m_girlfriend = data;
}