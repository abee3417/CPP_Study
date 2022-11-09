#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class CMytring {
private:
	char * m_data;
	int m_len;
public:
	CMytring()
	{
		m_data = 0;// 초기치가 없는 경우는 포인터를 0으로 초기화 한다.
	}
	~CMytring()
	{
		if (m_data != 0) {
			free(m_data);// 메모리가 할당되어 있으면 free시킨다.
		}
	}
	void Set(const char *p)
	{
		char *t;
		delete m_data;
		m_len = strlen(p);
		// 원래 메모리가 있으면 먼저 free를 시켜 줘야한다.
		m_data = strdup(p);
		// 메모리를 필요한 길이 만큼 할당하고 복사한다.
	}
	void Print()
	{
		if (m_data != 0) {
			cout << m_data << endl;// cout 으로 내용을 출력한다.
		}
		else {
			cout << "빈 스트링" << endl;
		}// 메모리가 없는 경우 "빈 스트링"이라고 출력한다.
	}
};
int main() {
	CMytring s;
	s.Print();
	s.Set("Hello");
	s.Print();
	s.Set("Hello world");
	s.Print();
}
