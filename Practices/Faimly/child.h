#include <iostream>
#include <string>
using namespace std;
class Family;
class Child { // ���̵� �̸��� ��ũ�帮��Ʈ�� �����ϴ� Ŭ����
private:
	string m_name;
	Child * next; // ��ũ�帮��Ʈ ������ ���� next
	Family * family;
public:
	Child(string name); // �̸����� ������
	string get_name(); // �̸� �����ִ� �Լ�
	Child *get_next(); // next�� �ִ� �ּ� �����ִ� �Լ�
	void set_next(Child *data); // next ���� �Լ�
	void get_family(Family *data);	// Family ������ �޴� �Լ�
	void Tellme(); // ���� ���� ��� �Լ�
	
};