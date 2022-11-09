#include <iostream>
#include <string>
using namespace std;
#include "dogschool.h" 
#include "dog.h"
DogSchool::DogSchool(string data) {  // 이름 저장 생성자
	m_name = data;
}
void DogSchool::registerDog(Dog *data) { // 강아지 배열에 저장
	dog[i] = data;
	i++, count++;
}
void DogSchool::showDogs() { // 출력
	cout << "여기는 " << m_name << "입니다." << endl;
	cout << "학생들을 소개합니다." << endl;
	for (i = 0; i < count; i++) {
		if (dog[i]->m_name == "") { // 자퇴 처리된 강아지 이름이 있을 경우
			for (int j = i; j < count; j++) {
				dog[j] = dog[j + 1]; // 배열을 하나씩 당긴다.
			}
			count--;
		}
		dog[i]->school_name = m_name;
		dog[i]->speak();
	}
	cout << endl;
}
void DogSchool::setName(string data) { // 학교 이름 바꾸기
	m_name = data;
}
