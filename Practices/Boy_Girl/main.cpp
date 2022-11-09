#include <iostream>
#include <string>
using namespace std;
#include "boy.h" 
#include "girl.h" 
int main() {
	Boy *b = new Boy("박철수");
	Girl *g = new Girl("김영은");
	b->setGF(g);  g->setBF(b);  // 남친/여친을 설정하는 함수
	b->hello();  g->hello();
}