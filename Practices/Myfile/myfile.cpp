#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class MyFile {
private:
	FILE * fp;
public:
	void openR(const char *str) { // �б�� ������ ����
		fp = fopen(str, "r");
		if (!fp) {
			throw(1); // ���� �� �����޼��� ����ϵ��� 1�� throw
		}
	}
	void openW(const char *str) { // ����� ������ ����
		fp = fopen(str, "w");
		if (!fp) {
			throw(2); // ���� �� �����޼��� ����ϵ��� 2�� throw
		}
	}
	int getchar(int &c) { // c�� EOF�� �Ǹ� 0�� ��ȯ�ϰ� �ƴϸ� 1�� ��ȯ
		if ((c = fgetc(fp)) == EOF) {
			return 0;
		}
		else {
			return 1;
		}
	}
	void putchar(int c) {
		fputc(c, fp);
	}
	void close() {
		fclose(fp);
	}
};

int main() {
	MyFile ifile, ofile;
	try {
		int c;
		ifile.openR("hello.in");   // �б�� ������ ����.
		ofile.openW("hello.out");  // ����� ������ ����.
		while (ifile.getchar(c) == 1) { // reference�� ����.
			ofile.putchar(c); // ���� �� 1�� ���� ������ putchar�� ȣ��
		}
		ifile.close();
		ofile.close();
	}
	catch (int c) {
		// ���� �޽��� ���
		switch (c) {
		case 1: cout << "������ �б� ���� ���� ���߽��ϴ�.\n";
			break;
		case 2: cout << "������ ���� ���� ���� ���߽��ϴ�.\n";
		}
	}
}