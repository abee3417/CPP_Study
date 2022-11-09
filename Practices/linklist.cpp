/*#include <iostream>
#include <string>
using namespace std;

class Person {
	friend class PList;
private:
	string name;
	string id;
	Person * next;
public:

	Person(string name, string id) {
		this->name = name;
		this->id = id;
	}
	//Person * getnext() {
	//	return next;e
	//}
	//void setnext(Person *pnext) {
	//	next = pnext;
	//}
	Person() {
	}
	void show() {
		cout << "이름 : " << name << " 주민번호 : " << id << endl;
	}
};

class PList {
private:
	Person * head;
public:
	void add(Person *per) {
		Person *temp = new Person;
		if (head == 0) {
			temp->name = per->name;
			temp->id = per->id;
			temp->next = 0;
			head = temp;
		}
		else {
			Person *headtemp = head;
			temp->name = per->name;
			temp->id = per->id;
			temp->next = 0;
			while (headtemp->next != 0) {
				headtemp = headtemp->next;
			}
			headtemp->next = temp;
		}
	}

	PList() {
		head = 0;
	}
	void showAll() {
		Person *headtemp = head;

		while (headtemp != 0) {
			headtemp->show();
			headtemp = headtemp->next;
		}
	}
	Person *find(string id) {
		Person *headtemp = head;
		while (headtemp != 0) {
			if (id == headtemp->id) {
				return headtemp;
			}
			headtemp = headtemp->next;
		}
	}
	void remove(Person *p) {
		Person *htemp = head;
		if (p->id == head->id) {
			head = htemp->next;
			delete htemp;
			htemp = 0;
			return;
		}
		while (htemp->next != 0) {
			if (htemp->next == p) {
				Person*removal = htemp->next;
				if (removal->next != 0)
					htemp->next = removal->next;
				else htemp->next = 0;
			}
			htemp = htemp->next;
		}
	}
};


int main() {
	PList * theList = new PList;
	string id;
	theList->add(new Person("김길동", "950101-1111111"));
	theList->add(new Person("박길동", "950101-2222222"));
	theList->add(new Person("홍길동", "950101-3333333"));
	theList->showAll();
	cout << "주민번호로 찾기:";
	cin >> id;  // string id; 로 선언
	Person *p = theList->find(id);
	p->show();  cout << "삭제합니다." << endl;
	theList->remove(p);
	theList->showAll();
}*/
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;
class CBase
{
protected:
	friend class CFamily;
	string name;
	CFamily* family;
	void show_child();
public:
	CBase(char* _name) : name(_name), family(NULL) { }
	virtual void Tellme() { cout << "나는 " << name; }
	virtual string GetName() { return name; }
};
class CMan : public CBase
{
public:
	CMan(char* _name) : CBase(_name) { }
	void Tellme();
};
class CWoman : public CBase
{
public:
	CWoman(char* _name) : CBase(_name) { }
	void Tellme();
};
class CChild : public CBase
{
public:
	CChild(char* _name) : CBase(_name) { }
	void Tellme();
};
class CFamily
{
	CMan *father;
	CWoman *mother;
	vector<CChild*> child;
public:
	CFamily(CMan* _m, CWoman* _f) : father(_m), mother(_f)
	{
		if (father != NULL) father->family = this;
		if (mother != NULL) mother->family = this;
	}
	void AddChild(CChild* c)
	{
		if (c != NULL)
		{
			c->family = this;
			child.push_back(c);
		}
	}
	CMan* GetFather() { return father; }
	CWoman* GetMother() { return mother; }
	CChild* GetChild(int index) { return child[index]; }
	int GetChildCount() { return child.size(); }
};
void CBase::show_child()
{
	if (family != NULL)
	{
		bool first = true;
		for (int i = 0; i<family->GetChildCount(); i++)
		{
			if (name == family->GetChild(i)->GetName()) continue;
			if (!first) cout << ", ";
			cout << family->GetChild(i)->GetName();
			first = false;
		}
	}
}
void CMan::Tellme()
{
	CBase::Tellme();
	if (family != NULL)
	{
		if (family->GetMother() != NULL)
		{
			cout << ", 내 아내는 " << family->GetMother()->GetName();
		}
		if (family->GetChildCount() > 0)
		{
			cout << ", 아이들은 ";
			show_child();
		}
	}
	cout << endl;
}
void CWoman::Tellme()
{
	CBase::Tellme();
	if (family != NULL)
	{
		if (family->GetFather() != NULL)
		{
			cout << ", 내 남편은 " << family->GetFather()->GetName();
		}
		if (family->GetChildCount() > 0)
		{
			cout << ", 아이들은 ";
			show_child();
		}
	}
	cout << endl;
}
void CChild::Tellme()
{
	CBase::Tellme();
	if (family != NULL)
	{
		cout << ", 아버지는 " << family->GetFather()->GetName();
		cout << ", 어머니는 " << family->GetMother()->GetName();
		if (family->GetChildCount() > 1)
		{
			cout << ", 형제들은 ";
			show_child();
			cout << "이 있습니다.";
		}
	}
	cout << endl;
}
int main()
{
	CMan *m = new CMan("김부자");
	CWoman *f = new CWoman("강예쁜");
	CFamily *myFamily = new CFamily(m, f); // 생성자에서 서로 포인터를 연결해 준다. 
	CChild *c1 = new CChild("김장남");
	CChild *c2 = new CChild("김차남");
	CChild *c3 = new CChild("김삼남");
	myFamily->AddChild(c1);
	myFamily->AddChild(c2);
	myFamily->AddChild(c3);
	c1->Tellme();  // 나는 김장남, 아버지는 김부자, 어머니는 강예쁜, 형제들은 김차남, 김삼남이 있습니다. 
	m->Tellme(); // 나는 김부자, 내 아내는 강예쁜, 아이들은 김장남, 김차남, 김삼남 
	f->Tellme();
	return 0;
}
