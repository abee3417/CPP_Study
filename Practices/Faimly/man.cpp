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
	Child *temp = family->get_child(); // 임시 포인터 연결
	cout << "나는 " << m_name << ", ";
	cout << "내 아내는 " << family->get_wife()->get_name() << ", ";
	cout << "아이들은 ";
	while (temp != 0) { // 링크가 0될때 까지
		cout << temp->get_name(); // 아이 이름 출력
		temp = temp->get_next(); // 다음으로 넘어감
		if (temp != 0) { // 링크가 0 아닐때만
			cout << ", "; // , 를 붙인다
		}
	}
	cout << " 이 있습니다." << endl;
}