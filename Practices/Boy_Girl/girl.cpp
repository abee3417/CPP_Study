#include <iostream>
#include <string>
using namespace std;
#include "girl.h" 
#include "boy.h" 
Girl::Girl(string data) { // 이름 저장 생성자
	m_name = data;
}
void Girl::hello() { // 결과 출력
	cout << "나는 " << m_name << "입니다.";
	cout << "내 남자친구는 " << m_boyfriend->m_name << "입니다." << endl;
}
void Girl::setBF(Boy *data) { // 남자친구 이름 저장
	m_boyfriend = data;
}