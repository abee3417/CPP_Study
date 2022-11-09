#include <iostream>
#include <string>
using namespace std;
#include "family.h"
#include "man.h"
#include "wife.h"
#include "child.h"
Family::Family(Man *m, Wife *f) {
	man = m;
	wife = f;
	child = 0;
	man->get_family(this); // family �����͸� ���� ���� �ֵ��� �Ѱ��ش�
	wife->get_family(this); // ���� ����
}

Man *Family::get_man() {
	return man;
}

Wife *Family::get_wife() {
	return wife;
}

Child *Family::get_child() {
	return child;
}

void Family::AddChild(Child *data) { // ��ũ�帮��Ʈ ����
	if (child == 0) {
		child = data;
		child->get_family(this); // family �����͸� ���� ���� �ֵ��� �Ѱ��ش�
	}
	else {
		Child *temp = child;
		while (temp->get_next() != 0) {
			temp = temp->get_next();
		}
		temp->set_next(data);
		child->get_family(this); // family �����͸� ���� ���� �ֵ��� �Ѱ��ش�
	}
}
