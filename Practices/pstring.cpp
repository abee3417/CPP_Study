#include <iostream>
using namespace std;
class Pstring {
private:
	char *m_str;
public:
	Pstring(char *str = 0) { // ��Ʈ���� ����� ��� ������
		
	}
	Pstring(const char *str) { // ��Ʈ���� ������ ���� ��� ������
		int count = 0;
		while (str[count] != '\0') {
			count++;
		}
		m_str = (char *)malloc(sizeof(char) * (count + 1));
		m_str[0] = count; // ��Ʈ���� ���̸� �ٸ� �������� �� �� �ֵ��� �迭�� ù��° ������ �����Ѵ�
		for (int i = 0; i < count; i++) { // ������ ��������� m_str�� �����Ѵ�
			m_str[i + 1] = str[i];
		}
	}

	void copy(Pstring data) {
		this->m_str = (char *)malloc(sizeof(char) * (data.m_str[0] + 1)); // �����ϱ� ���� ���� �Ҵ�
		for (int j = 0; j < data.m_str[0] + 1; j++) { // ��Ʈ���� ���̸�ŭ �����Ѵ�
			m_str[j] = data.m_str[j];
		}
	}

	void add(Pstring data) {
		// ������ ���� ���� �ڿ� �߰��ϱ� ���� ���� ���̿� �߰��� ������ ���̸�ŭ �߰��ؼ� ���Ҵ��Ѵ�
		this->m_str = (char *)realloc(this->m_str, sizeof(char) * (this->m_str[0] + data.m_str[0] + 1));
		for (int x = 0; x < data.m_str[0]; x++) {
			this->m_str[this->m_str[0] + x + 1] = data.m_str[x + 1]; // �߰��� ������ �ִ´�
		}
		this->m_str[0] += data.m_str[0]; // ���̸� �ٽ� �����ϱ� ���� ���� ���̿� �߰��� ������ ���̸� ���Ѵ�
	}

	int length() { // ������ ���� ���
		return this->m_str[0];
	}

	void print() {
		for (int y = 1; y < this->m_str[0] + 1; y++) { // [0]���� ���̰� ����������Ƿ� [1]���� ����Ѵ�.
			cout << this->m_str[y];
		}
		cout << endl;
	}

	void erase() { // �޸𸮸� free ���ش�
		free(this->m_str);
	}
};

int main() {
	Pstring s, t("Hello"), u("world");
	s.copy(t);
	s.add(u);
	cout << s.length() << endl;  // ��Ʈ���� ���̸� ��ȯ�ϴ� �Լ�
	s.print();
	s.erase();  // erase �Լ��� �޸𸮸� ���� free�ϴ� �Լ�.
	t.erase();
	u.erase();
}