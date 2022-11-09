#include <iostream>
#include <string>
using namespace std;
#include "family.h"
#include "man.h"
#include "wife.h"
#include "child.h"
Wife::Wife(string name) {
	m_name = name;
}

string Wife::get_name() {
	return m_name;
}

void Wife::get_family(Family *data) {
	family = data;
}