#include <iostream>
#include <string>
using namespace std;
class Man;
class Wife;
class Child;
class Family {
private:
	Man * man; // ���� ������
	Wife * wife; // �Ƴ� ������
	Child * child; // ���̵� ������
public:
	Family(Man *m, Wife *f);
	Man *get_man(); // ���� ������ �Ѱ���
	Wife *get_wife(); // �Ƴ� ������ �Ѱ���
	Child *get_child(); // ���̵� ������ �Ѱ���
	void AddChild(Child *data); // ���̵� ��ũ�帮��Ʈ �����Լ�
	//void set_child(Child *data); // ���̵� ������ �Ѱ���
};

