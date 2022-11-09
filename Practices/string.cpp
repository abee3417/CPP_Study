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
		m_data = 0;// �ʱ�ġ�� ���� ���� �����͸� 0���� �ʱ�ȭ �Ѵ�.
	}
	~CMytring()
	{
		if (m_data != 0) {
			free(m_data);// �޸𸮰� �Ҵ�Ǿ� ������ free��Ų��.
		}
	}
	void Set(const char *p)
	{
		char *t;
		delete m_data;
		m_len = strlen(p);
		// ���� �޸𸮰� ������ ���� free�� ���� ����Ѵ�.
		m_data = strdup(p);
		// �޸𸮸� �ʿ��� ���� ��ŭ �Ҵ��ϰ� �����Ѵ�.
	}
	void Print()
	{
		if (m_data != 0) {
			cout << m_data << endl;// cout ���� ������ ����Ѵ�.
		}
		else {
			cout << "�� ��Ʈ��" << endl;
		}// �޸𸮰� ���� ��� "�� ��Ʈ��"�̶�� ����Ѵ�.
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
