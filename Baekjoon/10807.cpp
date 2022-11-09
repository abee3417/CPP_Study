#include <iostream>
using namespace std;

int main(){
    int n, t;
    int cnt = 0;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> t;
    for (int i = 0; i < n; i++){
        if (t == arr[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}