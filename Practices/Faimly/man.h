#include <iostream>
#include <string>
using namespace std;
class Family;
class Man {
private:
	string m_name;
	Family * family;
public:
	Man(string name);
	string get_name(); // 이름 보내주는 함수
	void get_family(Family *data);	// Family 포인터 받는 함수
	void Tellme();
};