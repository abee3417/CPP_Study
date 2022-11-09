#include <iostream>
using namespace std;

int main(){
    int arr[10][10];
    int max_i = 1;
    int max_j = 1;
    int max = 0;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            if (arr[i][j] > max){
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    cout << max << endl << max_i << " " << max_j << endl;
    return 0;
}