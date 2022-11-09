#include <iostream>
#include <string>
using namespace std;
#include "family.h"
#include "man.h"
#include "wife.h"
#include "child.h"
Man::Man(string name) {
	m_name = name;
}

string Man::get_name() {
	return m_name;
}

void Man::get_family(Family *data) {
	family = data;
}

void Man::Tellme() {
	Child *temp = family->get_child(); // �ӽ� ������ ����
	cout << "���� " << m_name << ", ";
	cout << "�� �Ƴ��� " << family->get_wife()->get_name() << ", ";
	cout << "���̵��� ";
	while (temp != 0) { // ��ũ�� 0�ɶ� ����
		cout << temp->get_name(); // ���� �̸� ���
		temp = temp->get_next(); // �������� �Ѿ
		if (temp != 0) { // ��ũ�� 0 �ƴҶ���
			cout << ", "; // , �� ���δ�
		}
	}
	cout << " �� �ֽ��ϴ�." << endl;
}