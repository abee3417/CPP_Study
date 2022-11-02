#include <iostream>
#include <string.h>
using namespace std;

class Account{
    private:
        int ID;
        int money;
        int max;
        int bank_n;
        int account_n;
        int count;
        char level;
        char* name;
    public:
        Account(int ID, int money, int max, char *name, int bank_n, int account_n);
        Account(int ID, int money, int max, char *name, int bank_n, int account_n, int count, char level);
        int get_ID();
        int get_money();
        int get_max();
        char* get_name();
        int get_type();
        int get_bank_n();
        void set_account_n(int n);
        int get_account_n();
        void set_count();
        int get_count();
        void set_level();
        char get_level();
        virtual void add_money(int money);
        void minus_money(int money);
        
};
class Normal_Account : public Account{
    private:
	    int rate; //기본이율
    public:
        Normal_Account(int ID, int money, int max, char *name, int bank_n, int account_n, int rate, int count, char level);
        ~Normal_Account();
        virtual void add_money(int money);
};
class Credit_Account : public Account{
    private:
        int rate;
        int level;
    public:
        Credit_Account(int ID, int money, int max, char *name, int bank_n, int account_n, int rate, int count, char level);
        ~Credit_Account();
        virtual void add_money(int money);
};
class Saving_Account : public Account{
    private:
        int date;
        int balance;
        int save_count;
        int level;
    public:
        Saving_Account(int ID, int money, int max, char *name, int bank_n, int account_n, int count, char level, int date, int balance);
        ~Saving_Account();
        virtual void add_money(int money);
};
class Node_acc{
    public:
        Account* member;
        Node_acc* next;
        Node_acc(){
            this->member = NULL;   
            this->next = NULL;
        }
        Node_acc(int ID, int money, int max, char *name, int bank_n){
            this->member = new Account(ID, money, max, name, bank_n, 0);      
            this->next = NULL;
        }
};
class Bank{
    private:
        Node_acc *head;
        char* bank_name;
    public:
        Bank(const char *name);
        void make(int ID, int money, int max, char *name, int bank_n);
        int change_type(int ID, int account_n, int date, int balance);
        int deposit(int ID, int money, int max, int bank_n, int countYN);
        int withdraw(int ID, int money, int charge, int max, int bank_n, int countYN);
        void check_level(Node_acc *user);
        char* get_bank_name();
        Node_acc* get_acc_head();
};
class Node_bank{
    private:
        int bank_n;
    public:     
        Bank* member;
        Node_bank* next;
        Node_bank(){
            this->member = NULL;
            this->bank_n = 0;
            this->next = NULL;
        }
        Node_bank(const char *name, int code){
            this->member = new Bank(name);
            this->bank_n = code;
            this->next = NULL;
        }
        int get_code(){
            return this->bank_n;
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
        int transfer(int ID1, int ID2, int money, int max, int bank_n, int target_n);
        Node_bank* get_bank_head();
};

Account::Account(int ID, int money, int max, char *name, int bank_n, int account_n){ //신규 생성자
    this->ID = ID;
    this->money = money;
    this->max = max;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->bank_n = bank_n;       
    this->account_n = account_n;
    this->count = 0;
    this->level = 'D';
}
Account::Account(int ID, int money, int max, char *name, int bank_n, int account_n, int count, char level){ //변경 생성자
    this->ID = ID;
    this->money = money;
    this->max = max;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->bank_n = bank_n;       
    this->account_n = account_n;
    this->count = count;
    this->level = level;
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
    return this->bank_n;
}
int Account::get_bank_n(){
    return this->bank_n;
}
void Account::set_account_n(int n){
    this->account_n = n;
}
int Account::get_account_n(){
    return this->account_n;
}
void Account::set_count(){
    this->count++;
}
int Account::get_count(){
    return this->count;
}
void Account::set_level(){
    this->level--;
}
char Account::get_level(){
    return this->level;
}
void Account::add_money(int money){
    this->money += money;
}
void Account::minus_money(int money){
    this->money -= money;
}

Normal_Account::Normal_Account(int ID, int money, int max, char *name, int bank_n, int account_n, int rate, int count, char level)
	: Account(ID, money, max, name, bank_n, account_n, count, level){
        this->rate = rate;
    }
Normal_Account::~Normal_Account(){}
void Normal_Account::add_money(int money){
	Account::add_money(money); //원금추가
	Account::add_money(money*(this->rate/100.0)); //이자추가
}

Credit_Account::Credit_Account(int ID, int money, int max, char *name, int bank_n, int account_n, int rate, int count, char level)
	: Account(ID, money, max, name, bank_n, account_n, count, level){
        this->rate = rate;
    }
Credit_Account::~Credit_Account(){}
void Credit_Account::add_money(int money){
    int bonus = 0;
    Account::add_money(money); //원금추가
	Account::add_money(money*(this->rate/100.0)); //이자추가
    switch(this->get_level()){
        case 'A':
            bonus = money*(3.5/100.0);
            break;
        case 'B':
            bonus = money*(2.0/100.0);
            break;
        case 'C':
            bonus = money*(1.0/100.0);
            break;
    }
	Account::add_money(bonus); //특별이자
}

Saving_Account::Saving_Account(int ID, int money, int max, char *name, int bank_n, int account_n, int count, char level, int date, int balance)
	: Account(ID, money, max, name, bank_n, account_n, count, level){
        this->date = date;
        this->balance = balance;
        this->save_count = 0;
    }
Saving_Account::~Saving_Account(){}
void Saving_Account::add_money(int money){
	Account::add_money(this->balance); //금액과 상관없이 원래 금액을 입금.
    this->save_count++;
    if (this->save_count == date){ // 같아지면 이자지급 후 해지를 위해 계좌타입을 임시로 -1로 설정
        Account::add_money(this->balance * (1.03 * this->date) - this->balance * this->date);
        this->set_account_n(-1);
    }
}

Bank::Bank(const char *name) {
    this->bank_name = new char[strlen(name) + 1];
    strcpy(this->bank_name, name);
    head = NULL;
}
void Bank::make(int ID, int money, int max, char *name, int bank_n){
    if(head == NULL) {
        head = new Node_acc(ID, money, max, name, bank_n);
    }
    else if (head->next == NULL){
        head->next = new Node_acc(ID, money, max, name, bank_n);
    }
    else{
        Node_acc* new_node = new Node_acc(ID, money, max, name, bank_n);
        Node_acc* temp = new Node_acc();
        temp->next = head;
        while(temp->next->next != NULL){
            temp->next = temp->next->next;
        }
        temp->next->next = new_node;
    }
}
int Bank::change_type(int ID, int account_n, int date, int balance){
    Node_acc* temp = new Node_acc();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            int money = temp->next->member->get_money();
            int max = temp->next->member->get_max();
            char *name = temp->next->member->get_name();
            int bank_n = temp->next->member->get_bank_n();
            int count = temp->next->member->get_count();
            char level = temp->next->member->get_level();
            switch(account_n){
                case 1:
                    temp->next->member = new Normal_Account(ID, money, max, name, bank_n, account_n, 2, count, level);
                    return 1;
                case 2:
                    if (level <= 'C'){ // 신용등급이 A, B, C일때만 개설
                        temp->next->member = new Credit_Account(ID, money, max, name, bank_n, account_n, 5, count, level);
                        return 1;
                    }
                    else{
                        return 0;
                    }
                case 3:
                    if (level <= 'C'){ // 신용등급이 A, B, C일때만 개설
                        temp->next->member = new Saving_Account(ID, money, max, name, bank_n, account_n, count, level, date, balance);
                        return 1;
                    }
                    else{
                        return 0;
                    }
            }
            break;
        }
        temp->next = temp->next->next;
    }
    return 0;
}
int Bank::deposit(int ID, int money, int max, int bank_n, int countYN){
    Node_acc* temp = new Node_acc();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (money > temp->next->member->get_max() || money < 0){
                return 0;
            }
            else{
                temp->next->member->add_money(money);
                if (countYN == 1){ // 순수 입출금일때만 count증가
                    temp->next->member->set_count();
                    this->check_level(temp);
                }
                if (temp->next->member->get_account_n() == -1){ // 적금계좌 만기해지 확인 시 일반예금으로 전환
                    this->change_type(ID, 1, 0, 0);
                    return 2;
                }
                return 1;
            }
        }
        temp->next = temp->next->next;
    }
    return 0;
}
int Bank::withdraw(int ID, int money, int charge, int max, int bank_, int countYN){
    Node_acc* temp = new Node_acc();
    temp->next = head;
    while(temp->next != NULL){
        if (ID == temp->next->member->get_ID()){
            if (temp->next->member->get_account_n() == 3 || money > temp->next->member->get_money() || money < 0){ //적금계좌는 출금불가
                return 0;
            }
            else{
                if (temp->next->member->get_account_n() == 2){ //신용신뢰계좌면 수수료 절반
                    charge /= 2;
                }
                temp->next->member->minus_money(money + charge);
                if (countYN == 1){ // 순수 입출금일때만 count증가
                    temp->next->member->set_count();
                    this->check_level(temp);
                }   
                return 1;
            }
        }
        temp->next = temp->next->next;
    }
    return 0;
}
void Bank::check_level(Node_acc *user){
    int count = user->next->member->get_count();
    int type = user->next->member->get_account_n();
    if (type != 2 && (count == 3 || count == 6 || count == 9)){ // 계좌타입이 신용신뢰면 신용등급고정이므로 X
        user->next->member->set_level();
    }
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
    this->add_bank("농협", 1);
    this->add_bank("신한", 2);
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
int Master::transfer(int ID1, int ID2, int money, int max, int bank_n, int target_n){
    int charge = 0;
    Node_bank* trav = new Node_bank();
    Node_bank* target1 = new Node_bank();
    Node_bank* target2 = new Node_bank();
    trav->next = this->get_bank_head();
    if (bank_n != target_n){
        charge = money * 5 / 100;
    }
    while (trav->next != NULL) {
        if (bank_n == trav->next->get_code()){
            if((trav->next->member->withdraw(ID1, money, charge, max, bank_n, 0)) == 0){ // 출금오류발생시
                return 0;
            }
        }
        if(target_n == trav->next->get_code()){
            if((trav->next->member->deposit(ID2, money, max, bank_n, 0)) == 0){ // 입금오류발생시
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
    int opt, bank_n, ID, ID2, money, max, test, account_n, target_n;
    int balance, date; //적금계좌 전용 변수
    int code = 3;
    char* name;
    Master* GM = new Master(); // 총관리자
    Node_acc* trav_acc = new Node_acc();
    Node_bank* trav_bank = new Node_bank();
    GM->setting();
    while (1){
        cout << endl << "-----Bank List-----" << endl;
        cout << "0. 은행추가" << endl;
        trav_bank->next = GM->get_bank_head();
        while (trav_bank->next != NULL) {
            cout << trav_bank->next->get_code() << ". " << trav_bank->next->member->get_bank_name() << endl;
            trav_bank->next = trav_bank->next->next;
        }
        cout << "선택 : ";
        cin >> bank_n;
        if (bank_n == 0){
            char* bank_name = scan("은행이름입력 : ", 20);
            if (GM->dup_test(bank_name) == 0){ // 중복일 경우
                cout << "은행 중복";
            }
            else{
                GM->add_bank(bank_name, code);
                code++;
            }
            continue;
        }
        else{
            trav_bank->next = GM->get_bank_head();
            while (trav_bank->next != NULL && bank_n != trav_bank->next->get_code()) {
                trav_bank->next = trav_bank->next->next;
            }
        }
        cout << endl << "-----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 계좌변경" << endl;
        cout << "3. 입금" << endl;
        cout << "4. 출금" << endl;
        cout << "5. 계좌이체" << endl;
        cout << "6. 계좌번호 전체 출력" << endl;
        cout << "7. 프로그램 종료" << endl;
        cout << "선택 : ";
        cin >> opt;
        cout << endl;
        switch(opt){
            case 1:
                cout << "[계좌개설]" << endl;
                ID = scan("계좌ID: ");
                name = scan("이름 : ", 20);
                money = scan("입금액: ");
                max = scan("최대입금한도: ");
                trav_bank->next->member->make(ID, money, max, name, bank_n);
                break;
            case 2:
                cout << "[계좌변경]" << endl;
                ID = scan("계좌ID: ");
                cout << "-----Account List-----" << endl;
                cout << "1. 일반예금계좌" << endl;
                cout << "2. 신용신뢰계좌" << endl;
                cout << "3. 일반적금계좌" << endl;
                cout << "4. 취소" << endl;
                cout << "선택 : ";
                cin >> account_n;
                if (account_n == 3){
                    date = scan("납입개월: ");
                    balance = scan("월입금액: ");
                    test = trav_bank->next->member->change_type(ID, account_n, date, balance);
                }
                else if (account_n == 4){
                    break;  
                }
                else{
                    test = trav_bank->next->member->change_type(ID, account_n, 0, 0);
                }
                if(test == 0){
                    cout << "오류발생" << endl;
                }
                else{
                    cout << "업무완료" << endl; 
                }
                break;
            case 3:
                cout << "[입금]" <<  endl;
                ID = scan("입금ID: ");
                trav_acc->next = trav_bank->next->member->get_acc_head();
                while(trav_acc->next != NULL){
                    if (trav_acc->next->member->get_ID() == ID){
                        break;
                    }
                    trav_acc->next = trav_acc->next->next;
                }
                // 적금계좌인지 판별
                if (trav_acc->next != NULL){
                    if (trav_acc->next->member->get_account_n() == 3){
                        test = trav_bank->next->member->deposit(ID, 0, max, bank_n, 1);
                    cout << "적금계좌 자동입금 처리완료" << endl;
                    }
                    else{
                    money = scan("입금액: ");
                    test = trav_bank->next->member->deposit(ID, money, max, bank_n, 1);
                    }
                }
                else{
                    test = 0;
                }
                // 오류처리
                if(test == 0){
                    cout << "오류발생" << endl;
                }
                else if (test == 2){
                    cout << "만기해지로 일반예금으로 전환되었습니다." << endl;
                }
                else{
                    cout << "업무완료" << endl; 
                }
                break;
            case 4:
                cout << "[출금]" << endl;
                ID = scan("출금ID: ");
                money = scan("출금액: ");
                test = trav_bank->next->member->withdraw(ID, money, 0, max, bank_n, 1);
                if(test == 0){
                    cout << "오류발생" << endl;
                }
                else{
                    cout << "업무완료" << endl; 
                }
                break;
            case 5:
                cout << "[계좌이체]" << endl;
                ID = scan("출금ID: ");
                money = scan("입금액: ");
                trav_bank->next = GM->get_bank_head();
                while (trav_bank->next != NULL) {
                    cout << trav_bank->next->get_code() << ". " << trav_bank->next->member->get_bank_name() << endl;
                    trav_bank->next = trav_bank->next->next;
                }
                cout << "송금할 계좌의 은행 선택: ";
                cin >> target_n;
                ID2 = scan("보낼ID: ");
                test = GM->transfer(ID, ID2, money, max, bank_n, target_n);
                if(test == 0){
                    cout << "오류발생" << endl;
                }
                else{
                    cout << "업무완료" << endl; 
                }
                break;
            case 6:
                trav_acc->next = trav_bank->next->member->get_acc_head();
                while(trav_acc->next != NULL){
                    cout << "계좌ID: " << trav_acc->next->member->get_ID()<< endl;
                    cout << "이름: " << trav_acc->next->member->get_name() << endl;
                    cout << "잔액: " << trav_acc->next->member->get_money() << endl;
                    cout << "계좌타입: " << trav_acc->next->member->get_account_n() << endl;
                    cout << "(0:일반 / 1:예금 / 2:신용 / 3:적금)" << endl;
                    cout << "입출금횟수: " << trav_acc->next->member->get_count() << endl;
                    cout << "신용등급: " << trav_acc->next->member->get_level() << endl << endl;
                    trav_acc->next = trav_acc->next->next;
                }
                break;
            case 7:
                return 0;
        }
    }
}