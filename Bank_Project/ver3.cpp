#include <iostream>
#include <string.h>
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
        char* get_name();
        int get_type();
        void add_money(int money);
        void minus_money(int money);
        void show();
};

class Node_acc{
    public:
        Account* member;
        Node_acc* next;
        Node_acc(){
            this->member = NULL;   
            this->next = NULL;
        }
        Node_acc(int ID, int money, int max, char *name, int type){
            this->member = new Account(ID, money, max, name, type);      
            this->next = NULL;
        }
};

class Bank{
    private:
        Node_acc *head;
        char* bank_name;
    public:
        Bank(const char *name);
        void make(int ID, int money, int max, char *name, int n);
        int deposit(int ID, int money, int max, int n);
        int withdraw(int ID, int money, int max, int n);
        char* get_bank_name();
        Node_acc* get_acc_head();
};

class Node_bank{
    private:
        int bank_code;
    public:     
        Bank* member;
        Node_bank* next;
        Node_bank(){
            this->member = NULL;
            this->bank_code = 0;
            this->next = NULL;
        }
        Node_bank(const char *name, int code){
            this->member = new Bank(name);
            this->bank_code = code;
            this->next = NULL;
        }
        int get_code(){
            return this->bank_code;
        }
};

class Master{
    private:
        Node_bank *head;
    public:
        Master() {
            head = NULL;
        }
        void add_bank(const char *name, int code);
        void setting();
        int dup_test(const char *name);
        int transfer(int ID1, int ID2, int money, int max, int n, int type);
        Node_bank* get_bank_head();
};

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
char* Account::get_name(){
    return this->name;
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

Bank::Bank(const char *name) {
    this->bank_name = new char[strlen(name) + 1];
    strcpy(this->bank_name, name);
    head = NULL;
}
void Bank::make(int ID, int money, int max, char *name, int n){
    if(head == NULL) {
        head = new Node_acc(ID, money, max, name, n);
    }
    else if (head->next == NULL){
        head->next = new Node_acc(ID, money, max, name, n);
    }
    else{
        Node_acc* new_node = new Node_acc(ID, money, max, name, n);
        Node_acc* temp = new Node_acc();
        temp->next = head;
        while(temp->next->next != NULL){
            temp->next = temp->next->next;
        }
        temp->next->next = new_node;
    }
}
int Bank::deposit(int ID, int money, int max, int n){
    Node_acc* temp = new Node_acc();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_max() || money < 0){
                return 0;
            }
            else{
                temp->next->member->add_money(money);
                return 1;
            }
        }
        temp->next = temp->next->next;
    }
    return 0;
}
int Bank::withdraw(int ID, int money, int max, int n){
    Node_acc* temp = new Node_acc();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_money() || money < 0){
                return 0;
            }
            else{
                temp->next->member->minus_money(money);
                return 1;
            }
        }
        temp->next = temp->next->next;
    }
    return 0;
}
char* Bank::get_bank_name(){
    return this->bank_name;
}
Node_acc* Bank::get_acc_head(){
    return this->head;
}

void Master::add_bank(const char *name, int code){
    if(head == NULL) {
        head = new Node_bank(name, code);
    }
    else if (head->next == NULL){
        head->next = new Node_bank(name, code);
    }
    else{
        Node_bank* new_node = new Node_bank(name, code);
        Node_bank* temp = new Node_bank();
        temp->next = head;
        while(temp->next->next != NULL){
            temp->next = temp->next->next;
        }
        temp->next->next = new_node;
    }
}
void Master::setting(){
    this->add_bank("����", 1);
    this->add_bank("����", 2);
}
int Master::dup_test(const char *name){
    Node_bank* trav_bank = new Node_bank();
    trav_bank->next = this->get_bank_head();
    while (trav_bank->next != NULL) {
        if (strcmp(name, trav_bank->next->member->get_bank_name()) == 0){
            return 0;
        }
        trav_bank->next = trav_bank->next->next;
    }
    return 1;
}
int Master::transfer(int ID1, int ID2, int money, int max, int n, int type){ // n1 ���������� �ڵ�, n2 �޴����� �ڵ�
    int charge = 0;
    Node_bank* trav = new Node_bank();
    Node_bank* target1 = new Node_bank();
    Node_bank* target2 = new Node_bank();
    trav->next = this->get_bank_head();
    if (n != type){
        charge = money * 5 / 100;
    }
    while (trav->next != NULL) {
        if (n == trav->next->get_code()){
            if((trav->next->member->withdraw(ID1, money + charge, max, n)) == 0){ // ��ݿ����߻���
                return 0;
            }
        }
        if(type == trav->next->get_code()){
            if((trav->next->member->deposit(ID2, money, max, n)) == 0){ // �Աݿ����߻���
                return 0;
            }
        }
        trav->next = trav->next->next;
    }
    return 1;
}
Node_bank* Master::get_bank_head(){
    return this->head;
}

int scan(const char* msg){
    cout << msg;
    int tmp;
    cin >> tmp;
    return tmp;
}

char* scan(const char* msg, int size){
    cout << msg;
    char* tmp = (char*)malloc(sizeof(char) * size);
    cin >> tmp;
    return tmp;
}



int main(){
    int opt, n, ID, ID2, money, max, test, type;
    int code = 3;
    char* name;
    Master* GM = new Master(); // �Ѱ�����
    Node_acc* trav_acc = new Node_acc();
    Node_bank* trav_bank = new Node_bank();
    GM->setting();
    while (1){
        cout << endl << "-----Bank List-----" << endl;
        cout << "0. �����߰�" << endl;
        trav_bank->next = GM->get_bank_head();
        while (trav_bank->next != NULL) {
            cout << trav_bank->next->get_code() << ". " << trav_bank->next->member->get_bank_name() << endl;
            trav_bank->next = trav_bank->next->next;
        }
        cout << endl << "���� : ";
        cin >> n;
        if (n == 0){
            char* bank_name = scan("�����̸��Է� : ", 20);
            if (GM->dup_test(bank_name) == 0){ // �ߺ��� ���
                cout << "���� �ߺ�";
            }
            else{
                GM->add_bank(bank_name, code);
                code++;
            }
            continue;
        }
        else{
            trav_bank->next = GM->get_bank_head();
            while (trav_bank->next != NULL && n != trav_bank->next->get_code()) {
                trav_bank->next = trav_bank->next->next;
            }
        }
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
                cout << "[���°���]" << endl;
                ID = scan("����ID: ");
                name = scan("�̸� : ", 20);
                money = scan("�Աݾ�: ");
                max = scan("�ִ��Ա��ѵ�: ");
                trav_bank->next->member->make(ID, money, max, name, n);
                break;
            case 2:
                cout << "[�Ա�]" <<  endl;
                ID = scan("�Ա�ID: ");
                money = scan("�Աݾ�: ");
                test = trav_bank->next->member->deposit(ID, money, max, n);
                if(test == 0){
                    cout << "�����߻�" << endl;
                }
                else{
                    cout << "�����Ϸ�" << endl; 
                }
                break;
            case 3:
                cout << "[���]" << endl;
                ID = scan("���ID: ");
                money = scan("��ݾ�: ");
                test = trav_bank->next->member->withdraw(ID, money, max, n);
                if(test == 0){
                    cout << "�����߻�" << endl;
                }
                else{
                    cout << "�����Ϸ�" << endl; 
                }
                break;
            case 4:
                cout << "[������ü]" << endl;
                ID = scan("���ID: ");
                money = scan("�Աݾ�: ");
                trav_bank->next = GM->get_bank_head();
                while (trav_bank->next != NULL) {
                    cout << trav_bank->next->get_code() << ". " << trav_bank->next->member->get_bank_name() << endl;
                    trav_bank->next = trav_bank->next->next;
                }
                cout << "�۱��� ������ ���� ����: ";
                cin >> type;
                ID2 = scan("����ID: ");
                test = GM->transfer(ID, ID2, money, max, n, type);
                if(test == 0){
                    cout << "�����߻�" << endl;
                }
                else{
                    cout << "�����Ϸ�" << endl; 
                }
                break;
            case 5:
                trav_acc->next = trav_bank->next->member->get_acc_head();
                while(trav_acc->next != NULL){
                    cout << "����ID: " << trav_acc->next->member->get_ID()<< endl;
                    cout << "�̸�: " << trav_acc->next->member->get_name() << endl;
                    cout << "�ܾ�: " << trav_acc->next->member->get_money() << endl << endl;
                    trav_acc->next = trav_acc->next->next;
                }
                break;
            case 6:
                return 0;
        }
    }
}