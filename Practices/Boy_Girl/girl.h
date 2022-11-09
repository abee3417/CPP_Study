#include <iostream>
#include <string>    
using namespace std;
class Boy;
class Girl {
public:
	string m_name;
	Boy * m_boyfriend;
	Girl(string data);
	void hello();
	void setBF(Boy *data);
};
