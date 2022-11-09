#include <iostream>
#include <string>
using namespace std;
#include "family.h"
#include "man.h"
#include "wife.h"
#include "child.h"
Child::Child(string name) {
	m_name = name;
	next = 0;
}

string Child::get_name() {
	return m_name;
}

Child *Child::get_next() {
	return next;
}

void Child::set_next(Child *data) {
	next = data;
}

void Child::get_family(Family *data) {
	family = data;
}

void Child::Tellme() {
	Child *temp = family->get_child(); // �ӽ� ������ ����
	cout << "���� " << m_name << ", ";
	cout << "�ƹ����� " << family->get_man()->get_name() << ", ";
	cout << "��Ӵϴ� " << family->get_wife()->get_name() << ", ";
	cout << "�������� ";
	while (temp != 0) { // ��ũ�� 0�ɶ� ����
		if (m_name == temp->m_name) {
			temp = temp->next; // ���� ���̿� �̸��� ������ �н�
		}
		else {
			cout << temp->m_name; // ���� �̸� ���
			temp = temp->next; // �������� �Ѿ
			if (temp != 0) { // ��ũ�� 0 �ƴҶ���
				cout << ", "; // , �� ���δ�
			}
		}
	}
	cout << " �� �ֽ��ϴ�." << endl;
}