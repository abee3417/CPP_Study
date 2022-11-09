#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class MyFile {
private:
	FILE * fp;
public:
	void openR(const char *str) { // 읽기용 파일을 연다
		fp = fopen(str, "r");
		if (!fp) {
			throw(1); // 실패 시 오류메세지 출력하도록 1를 throw
		}
	}
	void openW(const char *str) { // 쓰기용 파일을 연다
		fp = fopen(str, "w");
		if (!fp) {
			throw(2); // 실패 시 오류메세지 출력하도록 2를 throw
		}
	}
	int getchar(int &c) { // c가 EOF가 되면 0을 반환하고 아니면 1을 반환
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
		ifile.openR("hello.in");   // 읽기용 파일을 연다.
		ofile.openW("hello.out");  // 쓰기용 파일을 연다.
		while (ifile.getchar(c) == 1) { // reference로 전달.
			ofile.putchar(c); // 리턴 값 1을 받을 때까지 putchar을 호출
		}
		ifile.close();
		ofile.close();
	}
	catch (int c) {
		// 오류 메시지 출력
		switch (c) {
		case 1: cout << "파일을 읽기 위해 열지 못했습니다.\n";
			break;
		case 2: cout << "파일을 쓰기 위해 열지 못했습니다.\n";
		}
	}
}