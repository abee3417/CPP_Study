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

class Bank{
    private:
        Account *arr[100];
    public:
        void make(int n);
        void deposit(int n);
        void withdraw(int n);
        void transfer_test(int n1, int n2, int type, int money);
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
    cout << "�ܾ�: " << this->money << endl << endl;
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
    arr[cnt[n]++] = new Account(ID, money, max, name, n);
}
void Bank::deposit(int n){
    int ID, money;
    cout << "[�Ա�]" <<  endl;
    cout << "����ID: ";
    cin >> ID;
    cout << "�Աݾ�: ";
    cin >> money;
    for (int i = 0; i < cnt[n]; i++){
        if (ID == arr[i]->get_ID()){
            if (money > arr[i]->get_max()){
                cout << "�Ա��ѵ��ʰ�" << endl;
            }
            else if (money < 0){
                cout << "�Աݾ׿���" << endl;
            }
            else{
                arr[i]->add_money(money);
                cout << "�ԱݿϷ�" << endl;
            }
            break;
        }
    }
    
}
void Bank::withdraw(int n){
    int ID, money;
    cout << "[���]" << endl;
    cout << "����ID: ";
    cin >> ID;
    cout << "��ݾ�: ";
    cin >> money;
    for (int i = 0; i < cnt[n]; i++){
        if (ID == arr[i]->get_ID()){
            if (money > arr[i]->get_money()){
                cout << "����ܾ׺���" << endl;
            }
            else if (money < 0){
                cout << "��ݾ׿���" << endl;
            }
            else{
                arr[i]->minus_money(money);
                cout << "��ݿϷ�" << endl;
            }
            break;
        }
    }
}
void Bank::transfer_test(int n1, int n2, int type, int money){
    if (money > arr[n1]->get_money()){
        cout << "����ܾ׺���" << endl;
    }
    else if (money < 0){
        cout << "��ݾ׿���" << endl;
    }
    else if (money > bank[type].arr[n2]->get_max()){
        cout << "�Ա��ѵ��ʰ�" << endl;
    }
    else{
        arr[n1]->minus_money(money);
        bank[type].arr[n2]->add_money(money);
        cout << "������ü�Ϸ�" << endl;
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
    if (n != type){ // ���������� �ƴϸ� ������ 5%
        money = money - (money * 5 / 100);
    }
    cout << "�Ա�ID: ";
    cin >> ID2;
    for (int i = 0; i < cnt[n]; i++){
        if (ID1 == arr[i]->get_ID()){ // ��ݰ��� ���� ã��
            for (int j = 0; j < cnt[type]; j++){
                if (ID2 == bank[type].arr[j]->get_ID()){ 
                    transfer_test(i, j, type, money);
                }
            }
            break;
        }            
    }
}
void Bank::show_all(int n){
    for (int i = 0; i < cnt[n]; i++){
        arr[i]->show();
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