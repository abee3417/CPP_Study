#include <iostream>
#include <string.h>
#define bank_cnt 2 // 현재 은행의 수 : 2
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

Bank bank[2]; // [0] : 농협, [1] : 신한
int cnt[2] = {0}; // 각 은행 별 계좌 수를 담는 배열

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
    cout << "계좌ID: " << this->ID << endl;
    cout << "이름: " << this->name << endl;
    cout << "잔액: " << this->money << endl;
}
void Bank::make(int n){
    int ID, money, max;
    char name[20];
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << "이름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> money;
    cout << "최대입금한도: ";
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
    cout << "[입금]" <<  endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << "입금액: ";
    cin >> money;
    Node* temp = new Node();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_max()){
                cout << "입금한도초과" << endl;
            }
            else if (money < 0){
                cout << "입금액오류" << endl;
            }
            else{
                temp->next->member->add_money(money);
                cout << "입금완료" << endl;
            }
            break;
        }
        temp->next = temp->next->next;
    }
}
void Bank::withdraw(int n){
    int ID, money;
    cout << "[출금]" << endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << "출금액: ";
    cin >> money;
    Node* temp = new Node();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_money()){
                cout << "출금잔액부족" << endl;
            }
            else if (money < 0){
                cout << "출금액오류" << endl;
            }
            else{
                temp->next->member->minus_money(money);
                cout << "출금완료" << endl;
            }
            break;
        }
        temp->next = temp->next->next;
    }
}
void Bank::transfer(int n){
    int ID1, type, ID2, money;
    cout << "[계좌이체]" << endl;
    cout << "출금ID: ";
    cin >> ID1;
    cout << "출금액: ";
    cin >> money;
    cout << "입금은행 (1 농협 2 신한):";
    cin >> type;
    type--;
    Node* temp1 = new Node();
    Node* temp2 = new Node();
    temp1->next = head;
    if (n != type){ // 동일은행이 아니면 수수료 5%
        money = money - (money * 5 / 100);
        temp2->next = bank[type].head;
    }
    else{
        temp2->next = head;
    }
    cout << "입금ID: ";
    cin >> ID2;
    while(temp1->next != NULL){
        if (ID1 == temp1->next->member->get_ID()){ // 출금계좌 먼저 찾기
            while(temp2->next != NULL){
                if (ID2 == temp2->next->member->get_ID()){ 
                    if (money > temp1->next->member->get_money()){
                        cout << "출금잔액부족" << endl;
                    }
                    else if (money < 0){
                        cout << "출금액오류" << endl;
                    }
                    else if (money > temp2->next->member->get_max()){
                        cout << "입금한도초과" << endl;
                    }
                    else{
                        temp1->next->member->minus_money(money);
                        temp2->next->member->add_money(money);
                        cout << "계좌이체완료" << endl;
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
        cout << "1. 농협" << endl;
        cout << "2. 신한" << endl;
        cout << "선택 : ";
        cin >> n;
        n--;
        cout << endl << "-----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌이체" << endl;
        cout << "5. 계좌번호 전체 출력" << endl;
        cout << "6. 프로그램 종료" << endl;
        cout << "선택 : ";
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