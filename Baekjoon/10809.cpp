#include <iostream>
using namespace std;

int main(){
    int index, i = 0;
    char s[101];
    int location[26]; // 위치를 담을 배열
    for (int i = 0; i < 26; i++){ // 위치배열 -1로 초기화
        location[i] = -1;
    }
    cin >> s;

    while(s[i] != '\0'){
        index = s[i] - 'a'; // 인덱스 값 = 현재 알파벳 - 'a'(아스키 95)
        if (location[index] == -1){ // 첫 등장 위치표시이므로 -1일때만 위치등록을 해준다.
            location[index] = i;
        }
        i++;
    }
    for (int i = 0; i < 26; i++){
        cout << location[i] << " ";
    }
    cout << endl;
    return 0;
}