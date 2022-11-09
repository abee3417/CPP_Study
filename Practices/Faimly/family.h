#include <iostream>
#include <string>
using namespace std;
class Man;
class Wife;
class Child;
class Family {
private:
	Man * man; // 남편 포인터
	Wife * wife; // 아내 포인터
	Child * child; // 아이들 포인터
public:
	Family(Man *m, Wife *f);
	Man *get_man(); // 남편 포인터 넘겨줌
	Wife *get_wife(); // 아내 포인터 넘겨줌
	Child *get_child(); // 아이들 포인터 넘겨줌
	void AddChild(Child *data); // 아이들 링크드리스트 연결함수
	//void set_child(Child *data); // 아이들 포인터 넘겨줌
};

