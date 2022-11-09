#include <iostream>
#include <string>
using namespace std;
class Person { // 링크드리스트 클래스
public:
	string m_name, m_day;
	Person * next;
	Person(string name, string day) {
		m_name = name;
		m_day = day;
	}
};

class PList {
private:
	Person * start;
	string name, day;
public:
	void add(Person *data) { // 삽입한 순서대로 링크드리스트를 만든다
		data->next = this->start;
		this->start = data;
	}
	int isEmpty() { // 비었는지 확인
		if (this->start == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	string top_name() { // 제일 윗값 리턴
		return this->start->m_name;
	}
	string top_day() {  // 제일 윗값 리턴
		return this->start->m_day;
	}
	void pop() { // pop 함수
		Person *temp;
		temp = this->start;
		this->start = temp->next;
		free(temp);
	}
	void showAll() { // 위에서부터 차례대로 출력
		while (!this->isEmpty()) {
			cout << this->top_name() << endl;
			cout << this->top_day() << endl;
			this->pop();
		}
	}
};

int main() {
	string id;
	PList * theList = new PList();
	theList->add(new Person("김길동", "950101-1111111"));
	theList->add(new Person("박길동", "950101-2222222"));
	theList->add(new Person("홍길동", "950101-3333333"));
	theList->showAll();
	cout << "주민번호로 찾기:";
	cin >> id;  // string id; 로 선언
	/*
	Person *p = theList->find(id);
	if (p) {
		p->show();  cout << "삭제합니다." << endl;
		theList->remove(p);
	}
	theList->showAll();
	*/
}