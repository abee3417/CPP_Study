#include <iostream>
#include <string>
using namespace std;
class Family;
class Child { // 아이들 이름을 링크드리스트에 저장하는 클래스
private:
	string m_name;
	Child * next; // 링크드리스트 연결을 위한 next
	Family * family;
public:
	Child(string name); // 이름설정 생성자
	string get_name(); // 이름 보내주는 함수
	Child *get_next(); // next에 있는 주소 보내주는 함수
	void set_next(Child *data); // next 연결 함수
	void get_family(Family *data);	// Family 포인터 받는 함수
	void Tellme(); // 가족 정보 출력 함수
	
};