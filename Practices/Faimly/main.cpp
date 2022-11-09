#include <iostream>
#include <string>
using namespace std;
#include "family.h"
#include "man.h"
#include "wife.h"
#include "child.h"
int main() {
	Man *m = new Man("김부자");
	Wife *f = new Wife("강예쁜");
	Family *myFamily = new Family(m, f); // 생성자에서 서로 포인터를 연결해 준다.
	Child *c1 = new Child("김장남");
	Child *c2 = new Child("김차남");
	Child *c3 = new Child("김삼남");
	myFamily->AddChild(c1);
	myFamily->AddChild(c2);
	myFamily->AddChild(c3);
	c1->Tellme();  // 나는 김장남, 아버지는 김부자, 어머니는 강예쁜, 형제들은 김차남, 김삼남이 있습니다.
	m->Tellme(); // 나는 김부자, 내 아내는 강예쁜, 아이들은 김장남, 김차남, 김삼남
}