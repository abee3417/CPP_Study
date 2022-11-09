#include <iostream>
using namespace std;

int main(){
    int arr1[100][100];
    int arr2[100][100];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr2[i][j];
            arr1[i][j] += arr2[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}