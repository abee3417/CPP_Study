#include <iostream>
#include <string>
using namespace std;
class Family;
class Wife {
private:
	string m_name;
	Family * family;
public:
	Wife(string name);
	string get_name(); // �̸� �����ִ� �Լ�
	void get_family(Family *data);	// Family ������ �޴� �Լ�
};