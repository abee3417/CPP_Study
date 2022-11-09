#include <iostream>
#include <string>
using namespace std;
class Person { // ��ũ�帮��Ʈ Ŭ����
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
	void add(Person *data) { // ������ ������� ��ũ�帮��Ʈ�� �����
		data->next = this->start;
		this->start = data;
	}
	int isEmpty() { // ������� Ȯ��
		if (this->start == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	string top_name() { // ���� ���� ����
		return this->start->m_name;
	}
	string top_day() {  // ���� ���� ����
		return this->start->m_day;
	}
	void pop() { // pop �Լ�
		Person *temp;
		temp = this->start;
		this->start = temp->next;
		free(temp);
	}
	void showAll() { // ���������� ���ʴ�� ���
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
	theList->add(new Person("��浿", "950101-1111111"));
	theList->add(new Person("�ڱ浿", "950101-2222222"));
	theList->add(new Person("ȫ�浿", "950101-3333333"));
	theList->showAll();
	cout << "�ֹι�ȣ�� ã��:";
	cin >> id;  // string id; �� ����
	/*
	Person *p = theList->find(id);
	if (p) {
		p->show();  cout << "�����մϴ�." << endl;
		theList->remove(p);
	}
	theList->showAll();
	*/
}