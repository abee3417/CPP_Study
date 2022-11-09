#include <iostream>
using namespace std;
// Stack 클래스
class Stack {
public:
	class node {
	public:
		int data;
		node * next;
		node(int x, node *nxt) :data(x), next(nxt) {}
	};
	Stack(); void insert(int); int pop();
	void show();
protected:
	node * first;
};
// Stack 클래스 멤버함수
Stack::Stack() { first = 0; }
void Stack::insert(int x) {
	node * temp;
	temp = new node(x, first);
	temp->next = first;
	first = temp;
}
int Stack::pop() {
	int retval;
	node * temp;
	if (first == 0) return -1;
	retval = first->data;
	temp = first;
	first = first->next;
	delete temp;
	return retval;
}
void Stack::show() {
	node *temp;
	for (temp = first; temp; temp = temp->next)
		cout << temp->data << " --> ";
	cout << "END\n";
}
// Stack을 상속한 PositiveStack 클래스
class PositiveStack : public Stack {
public:
	PositiveStack();
	void insert(int n);
	void show();
};
// PositiveStack 클래스 멤버함수
PositiveStack::PositiveStack() {
	//
}
void PositiveStack::insert(int n) {
	if (n >= 0) { // 0이상일때만 링크드리스트에 저장
		Stack::insert(n);
	}
}
void PositiveStack::show() {
	Stack::show();
}
// main함수
int main() {
	Stack s;
	PositiveStack ps;

	s.insert(1);
	s.insert(2);
	s.insert(-3);
	s.insert(4);
	s.show();

	ps.insert(1);
	ps.insert(2);
	ps.insert(-3);
	ps.insert(4);
	ps.show();
}
