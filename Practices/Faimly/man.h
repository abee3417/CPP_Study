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
	string get_name(); // �̸� �����ִ� �Լ�
	void get_family(Family *data);	// Family ������ �޴� �Լ�
	void Tellme();
};