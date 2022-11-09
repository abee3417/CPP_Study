#include <iostream>
#include <string>
using namespace std;
#include "dog.h" 
#include "dogschool.h" 
Dog::Dog(string data) {  // 이름 저장 생성자
	m_name = data;
}
void Dog::dropSchool() { // 자퇴 처리 시킬 강아지 이름 비우기
	m_name = "";
}
void Dog::setName(string data) { // 강아지 이름 바꾸기
	m_name = data;
}
void Dog::speak() {
	cout << "멍멍, 나는 " << this->m_name << "입니다.";
	cout << "나는 " << this->school_name << "에 다닙니다." << endl;
}