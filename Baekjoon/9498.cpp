#include <iostream>
using namespace std;

int main(){
    int A;
    cin >> A;
    if (90 <= A && A <= 100){
        cout << "A" << endl;
    }
    else if (80 <= A && A <= 89){
        cout << "B" << endl;
    }
    else if (70 <= A && A <= 79){
        cout << "C" << endl;
    }
    else if (60 <= A && A <= 69){
        cout << "D" << endl;
    }
    else{
        cout << "F" << endl;
    }
    return 0;
}