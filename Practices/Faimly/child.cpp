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
	Child *temp = family->get_child(); // 임시 포인터 연결
	cout << "나는 " << m_name << ", ";
	cout << "아버지는 " << family->get_man()->get_name() << ", ";
	cout << "어머니는 " << family->get_wife()->get_name() << ", ";
	cout << "형제들은 ";
	while (temp != 0) { // 링크가 0될때 까지
		if (m_name == temp->m_name) {
			temp = temp->next; // 현재 아이와 이름이 같으면 패스
		}
		else {
			cout << temp->m_name; // 아이 이름 출력
			temp = temp->next; // 다음으로 넘어감
			if (temp != 0) { // 링크가 0 아닐때만
				cout << ", "; // , 를 붙인다
			}
		}
	}
	cout << " 이 있습니다." << endl;
}