#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b;
    cin >> c;
    if (b + c >= 60){ // c에서 시간을 덜어내 a에 더해준다
        a = a + (c / 60);
        c = c % 60; 
    }

    if (a >= 24){ // a가 24를 초과하면 24를 빼준다
        a = a - 24;
    }
    
    if (b + c < 60){
        cout << a << " " << b + c << endl;
    }
    else if (b + c == 60){
        if (a == 23){ // a가 23이면 23+1 = 0이므로 0 출력
            cout << 0 << " " << 0 << endl;
        }
        else{
            cout << a + 1 << " " << 0 << endl;
        }
    }
    else{
        if (a == 23){ // a가 23이면 23+1 = 0이므로 0 출력
            cout << 0 << " " << b + c - 60 << endl;
        }
        else{
            cout << a + 1 << " " << b + c - 60 << endl;
        }
    }

    return 0;
}