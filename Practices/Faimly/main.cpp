#include <iostream>
#include <string>
using namespace std;
#include "family.h"
#include "man.h"
#include "wife.h"
#include "child.h"
int main() {
	Man *m = new Man("�����");
	Wife *f = new Wife("������");
	Family *myFamily = new Family(m, f); // �����ڿ��� ���� �����͸� ������ �ش�.
	Child *c1 = new Child("���峲");
	Child *c2 = new Child("������");
	Child *c3 = new Child("��ﳲ");
	myFamily->AddChild(c1);
	myFamily->AddChild(c2);
	myFamily->AddChild(c3);
	c1->Tellme();  // ���� ���峲, �ƹ����� �����, ��Ӵϴ� ������, �������� ������, ��ﳲ�� �ֽ��ϴ�.
	m->Tellme(); // ���� �����, �� �Ƴ��� ������, ���̵��� ���峲, ������, ��ﳲ
}