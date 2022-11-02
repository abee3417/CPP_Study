#include <iostream>
#include <string.h>
#define bank_cnt 2 // ���� ������ �� : 2
using namespace std;

class Account{
    private:
        int ID;
        int money;
        int max;
        int type;
        char* name;
    public:
        Account(int ID, int money, int max, char *name, int type);
        int get_ID();
        int get_money();
        int get_max();
        int get_type();
        void add_money(int money);
        void minus_money(int money);
        void show();
};

class Node{
    public:
        Account* member;
        Node* next;
        Node(){
            this->member = NULL;   
            this->next = NULL;
        }
        Node(int ID, int money, int max, char *name, int type){
            this->member = new Account(ID, money, max, name, type);      
            this->next = NULL;
        }
        /*
        void set_next(Node* next){
            this->next = next;
        }
        Node* next{
            if (this->next == NULL){
                return NULL;
            }
            else{
                return this->next;
            }   
        }
        Account* member{
            return this->member;
        }
        */
};

class Bank{
    private:
        Node *head;
    public:
        Bank() {
            head=NULL;
        }
        void make(int n);
        void deposit(int n);
        void withdraw(int n);
        void transfer(int n);
        void show_all(int n);
};

Bank bank[2]; // [0] : ����, [1] : ����
int cnt[2] = {0}; // �� ���� �� ���� ���� ��� �迭

Account::Account(int ID, int money, int max, char *name, int type){
    this->ID = ID;
    this->money = money;
    this->max = max;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->type = type;           
}
int Account::get_ID(){
    return this->ID;
}
int Account::get_money(){
    return this->money;
}
int Account::get_max(){
    return this->max;
}
int Account::get_type(){
    return this->type;
}
void Account::add_money(int money){
    this->money += money;
}
void Account::minus_money(int money){
    this->money -= money;
}
void Account::show(){
    cout << "����ID: " << this->ID << endl;
    cout << "�̸�: " << this->name << endl;
    cout << "�ܾ�: " << this->money << endl;
}
void Bank::make(int n){
    int ID, money, max;
    char name[20];
    cout << "[���°���]" << endl;
    cout << "����ID: ";
    cin >> ID;
    cout << "�̸�: ";
    cin >> name;
    cout << "�Աݾ�: ";
    cin >> money;
    cout << "�ִ��Ա��ѵ�: ";
    cin >> max;
    if(head == NULL) {
        head = new Node(ID, money, max, name, n);
    }
    else if (head->next == NULL){
        head->next = new Node(ID, money, max, name, n);
    }
    else{
        Node* new_node = new Node(ID, money, max, name, n);
        Node* temp = new Node();
        temp->next = head;
        while(temp->next->next != NULL){
            temp->next = temp->next->next;
        }
        temp->next->next = new_node;
    }
}
void Bank::deposit(int n){
    int ID, money;
    cout << "[�Ա�]" <<  endl;
    cout << "����ID: ";
    cin >> ID;
    cout << "�Աݾ�: ";
    cin >> money;
    Node* temp = new Node();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_max()){
                cout << "�Ա��ѵ��ʰ�" << endl;
            }
            else if (money < 0){
                cout << "�Աݾ׿���" << endl;
            }
            else{
                temp->next->member->add_money(money);
                cout << "�ԱݿϷ�" << endl;
            }
            break;
        }
        temp->next = temp->next->next;
    }
}
void Bank::withdraw(int n){
    int ID, money;
    cout << "[���]" << endl;
    cout << "����ID: ";
    cin >> ID;
    cout << "��ݾ�: ";
    cin >> money;
    Node* temp = new Node();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_money()){
                cout << "����ܾ׺���" << endl;
            }
            else if (money < 0){
                cout << "��ݾ׿���" << endl;
            }
            else{
                temp->next->member->minus_money(money);
                cout << "��ݿϷ�" << endl;
            }
            break;
        }
        temp->next = temp->next->next;
    }
}
void Bank::transfer(int n){
    int ID1, type, ID2, money;
    cout << "[������ü]" << endl;
    cout << "���ID: ";
    cin >> ID1;
    cout << "��ݾ�: ";
    cin >> money;
    cout << "�Ա����� (1 ���� 2 ����):";
    cin >> type;
    type--;
    Node* temp1 = new Node();
    Node* temp2 = new Node();
    temp1->next = head;
    if (n != type){ // ���������� �ƴϸ� ������ 5%
        money = money - (money * 5 / 100);
        temp2->next = bank[type].head;
    }
    else{
        temp2->next = head;
    }
    cout << "�Ա�ID: ";
    cin >> ID2;
    while(temp1->next != NULL){
        if (ID1 == temp1->next->member->get_ID()){ // ��ݰ��� ���� ã��
            while(temp2->next != NULL){
                if (ID2 == temp2->next->member->get_ID()){ 
                    if (money > temp1->next->member->get_money()){
                        cout << "����ܾ׺���" << endl;
                    }
                    else if (money < 0){
                        cout << "��ݾ׿���" << endl;
                    }
                    else if (money > temp2->next->member->get_max()){
                        cout << "�Ա��ѵ��ʰ�" << endl;
                    }
                    else{
                        temp1->next->member->minus_money(money);
                        temp2->next->member->add_money(money);
                        cout << "������ü�Ϸ�" << endl;
                    }
                    break;
                }
                temp2->next = temp2->next->next;
            }
        }
        temp1->next = temp1->next->next;   
    }
}
void Bank::show_all(int n){
    Node* temp = new Node();
    temp->next = head;
    while(temp->next != NULL){
        temp->next->member->show();
        temp->next = temp->next->next;
    }
}

int main(){
    int opt, n;
    while (1){
        cout << endl << "-----Bank-----" << endl;
        cout << "1. ����" << endl;
        cout << "2. ����" << endl;
        cout << "���� : ";
        cin >> n;
        n--;
        cout << endl << "-----Menu-----" << endl;
        cout << "1. ���°���" << endl;
        cout << "2. �Ա�" << endl;
        cout << "3. ���" << endl;
        cout << "4. ������ü" << endl;
        cout << "5. ���¹�ȣ ��ü ���" << endl;
        cout << "6. ���α׷� ����" << endl;
        cout << "���� : ";
        cin >> opt;
        cout << endl;
        switch(opt){
            case 1:
                bank[n].make(n);
                break;
            case 2:
                bank[n].deposit(n);
                break;
            case 3:
                bank[n].withdraw(n);
                break;
            case 4:
                bank[n].transfer(n);
                break;
            case 5:
                bank[n].show_all(n);
                break;
            case 6:
                return 0;
        }
    }
}