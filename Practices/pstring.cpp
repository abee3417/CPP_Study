#include <iostream>
using namespace std;
class Pstring {
private:
	char *m_str;
public:
	Pstring(char *str = 0) { // 스트링이 비었을 경우 생성자
		
	}
	Pstring(const char *str) { // 스트링에 문장이 있을 경우 생성자
		int count = 0;
		while (str[count] != '\0') {
			count++;
		}
		m_str = (char *)malloc(sizeof(char) * (count + 1));
		m_str[0] = count; // 스트링의 길이를 다른 곳에서도 쓸 수 있도록 배열의 첫번째 공간에 저장한다
		for (int i = 0; i < count; i++) { // 문장을 멤버데이터 m_str에 복사한다
			m_str[i + 1] = str[i];
		}
	}

	void copy(Pstring data) {
		this->m_str = (char *)malloc(sizeof(char) * (data.m_str[0] + 1)); // 복사하기 위한 동적 할당
		for (int j = 0; j < data.m_str[0] + 1; j++) { // 스트링을 길이만큼 복사한다
			m_str[j] = data.m_str[j];
		}
	}

	void add(Pstring data) {
		// 문장을 기존 문장 뒤에 추가하기 위해 원래 길이에 추가할 문장의 길이만큼 추가해서 재할당한다
		this->m_str = (char *)realloc(this->m_str, sizeof(char) * (this->m_str[0] + data.m_str[0] + 1));
		for (int x = 0; x < data.m_str[0]; x++) {
			this->m_str[this->m_str[0] + x + 1] = data.m_str[x + 1]; // 추가할 문장을 넣는다
		}
		this->m_str[0] += data.m_str[0]; // 길이를 다시 저장하기 위해 원래 길이에 추가된 문장의 길이를 더한다
	}

	int length() { // 문장의 길이 출력
		return this->m_str[0];
	}

	void print() {
		for (int y = 1; y < this->m_str[0] + 1; y++) { // [0]에는 길이가 저장되있으므로 [1]부터 출력한다.
			cout << this->m_str[y];
		}
		cout << endl;
	}

	void erase() { // 메모리를 free 해준다
		free(this->m_str);
	}
};

int main() {
	Pstring s, t("Hello"), u("world");
	s.copy(t);
	s.add(u);
	cout << s.length() << endl;  // 스트링의 길이를 반환하는 함수
	s.print();
	s.erase();  // erase 함수는 메모리를 전부 free하는 함수.
	t.erase();
	u.erase();
}