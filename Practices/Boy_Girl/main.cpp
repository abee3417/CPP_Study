#include <iostream>
#include <string>
using namespace std;
#include "boy.h" 
#include "girl.h" 
int main() {
	Boy *b = new Boy("��ö��");
	Girl *g = new Girl("�迵��");
	b->setGF(g);  g->setBF(b);  // ��ģ/��ģ�� �����ϴ� �Լ�
	b->hello();  g->hello();
}