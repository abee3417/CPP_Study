#include <iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x;
    cin >> y;
    if (0 < x && x <= 1000 && 0 < y && y <= 1000){
        cout << "1" << endl;
    }
    else if (0 > x && x >= -1000 && 0 < y && y <= 1000){
        cout << "2" << endl;
    }
    else if (0 > x && x >= -1000 && 0 > y && y >= -1000){
        cout << "3" << endl;
    }
    else if (0 < x && x <= 1000 && 0 > y && y >= -1000){
        cout << "4" << endl;
    }
    return 0;
}