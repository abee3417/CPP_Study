#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && c == a){ // case1
        cout << 10000 + a * 1000 << endl;
    }
    else if (a != b && b != c && c != a){ // case3
        if (a > b && a > c){ // a가 젤 클 경우
            cout << a * 100 << endl;
        }
        else if (b > a && b > c){ // b가 젤 클 경우
            cout << b * 100 << endl;
        }
        else{ // 나머지 : c가 젤 클 경우
            cout << c * 100 << endl;
        }
    }
    else{ // case2
        if (a == b){ // a == b 
            cout << 1000 + a * 100 << endl;
        }
        else if (b == c){ // b == c
            cout << 1000 + b * 100 << endl;
        }
        else{ // 나머지 : a == c
            cout << 1000 + c * 100 << endl;
        }
    }
    return 0;
}