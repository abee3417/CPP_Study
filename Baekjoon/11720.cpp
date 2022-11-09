#include <iostream>
using namespace std;

int main(){
    int n;
    int sum = 0;
    char arr[100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        sum += arr[i] - 48;
    }
    cout << sum << endl;
    return 0;
}