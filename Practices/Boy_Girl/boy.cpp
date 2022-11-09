#include <iostream>
#include <string>
using namespace std;
#include "boy.h" 
#include "girl.h" 
Boy::Boy(string data) {  // 이름 저장 생성자
	m_name = data;
}
void Boy::hello() { // 결과 출력
	cout << "나는 " << m_name << "입니다.";
	cout << "내 여자친구는 " << m_girlfriend->m_name << "입니다." << endl;
}
void Boy::setGF(Girl *data) { // 여자친구 이름 저장
	m_girlfriend = data;
}