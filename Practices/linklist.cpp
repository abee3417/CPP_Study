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
		cout << "�̸� : " << name << " �ֹι�ȣ : " << id << endl;
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
	theList->add(new Person("��浿", "950101-1111111"));
	theList->add(new Person("�ڱ浿", "950101-2222222"));
	theList->add(new Person("ȫ�浿", "950101-3333333"));
	theList->showAll();
	cout << "�ֹι�ȣ�� ã��:";
	cin >> id;  // string id; �� ����
	Person *p = theList->find(id);
	p->show();  cout << "�����մϴ�." << endl;
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
	virtual void Tellme() { cout << "���� " << name; }
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
			cout << ", �� �Ƴ��� " << family->GetMother()->GetName();
		}
		if (family->GetChildCount() > 0)
		{
			cout << ", ���̵��� ";
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
			cout << ", �� ������ " << family->GetFather()->GetName();
		}
		if (family->GetChildCount() > 0)
		{
			cout << ", ���̵��� ";
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
		cout << ", �ƹ����� " << family->GetFather()->GetName();
		cout << ", ��Ӵϴ� " << family->GetMother()->GetName();
		if (family->GetChildCount() > 1)
		{
			cout << ", �������� ";
			show_child();
			cout << "�� �ֽ��ϴ�.";
		}
	}
	cout << endl;
}
int main()
{
	CMan *m = new CMan("�����");
	CWoman *f = new CWoman("������");
	CFamily *myFamily = new CFamily(m, f); // �����ڿ��� ���� �����͸� ������ �ش�. 
	CChild *c1 = new CChild("���峲");
	CChild *c2 = new CChild("������");
	CChild *c3 = new CChild("��ﳲ");
	myFamily->AddChild(c1);
	myFamily->AddChild(c2);
	myFamily->AddChild(c3);
	c1->Tellme();  // ���� ���峲, �ƹ����� �����, ��Ӵϴ� ������, �������� ������, ��ﳲ�� �ֽ��ϴ�. 
	m->Tellme(); // ���� �����, �� �Ƴ��� ������, ���̵��� ���峲, ������, ��ﳲ 
	f->Tellme();
	return 0;
}
