#include <iostream>
using namespace std;

// ��ũ�帮��Ʈ Link ����ü
struct Link {
	int value;
	Link *next;
};

struct Stack {
	Link *start;
	// �ʱ�ȭ
	void init() {
		this->start = 0;
	}
	// �Է¹��� ���ڸ� ��ũ�帮��Ʈ ���ÿ� ����ִ� insert ����Լ�
	void insert(int num) {
		Link *stack = (Link *)malloc(sizeof(Link));
		stack->value = num;
		stack->next = this->start;
		this->start = stack;
	}
	// ������ ������� Ȯ���ϴ� isEmpty ����Լ�
	int isEmpty() {
		if (this->start == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	// ��ũ�帮��Ʈ ������ �����͸� �����ϴ� top ����Լ�
	int top() {
		return this->start->value;
	}
	// ��ũ�帮��Ʈ ������ ���������� ���ִ� pop ����Լ�
	void pop() {
		Link *temp;
		temp = this->start;
		this->start = temp->next;
		free(temp);
	}
};

int main() {
	Stack s;  int num;
	s.init();  // ������ �ʱ�ȭ
	while (cin >> num) {
		s.insert(num);
	}
	// ���� �ϳ��� ����.
	while (!s.isEmpty()) {
		cout << s.top() << endl;
		s.pop();
	}
}