#include <iostream>
#include <string>    
using namespace std;
class Girl;
class Boy {
public:
	string m_name;
	Girl * m_girlfriend;
	Boy(string data);
	void hello();
	void setGF(Girl *data);
};