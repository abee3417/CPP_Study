#include <iostream>
using namespace std;

// 링크드리스트 Link 구조체
struct Link {
	int value;
	Link *next;
};

struct Stack {
	Link *start;
	// 초기화
	void init() {
		this->start = 0;
	}
	// 입력받은 숫자를 링크드리스트 스택에 집어넣는 insert 멤버함수
	void insert(int num) {
		Link *stack = (Link *)malloc(sizeof(Link));
		stack->value = num;
		stack->next = this->start;
		this->start = stack;
	}
	// 스택이 비었는지 확인하는 isEmpty 멤버함수
	int isEmpty() {
		if (this->start == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	// 링크드리스트 스택의 데이터를 리턴하는 top 멤버함수
	int top() {
		return this->start->value;
	}
	// 링크드리스트 스택의 위에서부터 없애는 pop 멤버함수
	void pop() {
		Link *temp;
		temp = this->start;
		this->start = temp->next;
		free(temp);
	}
};

int main() {
	Stack s;  int num;
	s.init();  // 포인터 초기화
	while (cin >> num) {
		s.insert(num);
	}
	// 이제 하나씩 빼자.
	while (!s.isEmpty()) {
		cout << s.top() << endl;
		s.pop();
	}
}