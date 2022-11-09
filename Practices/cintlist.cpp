#include <iostream>
using namespace std;
class CIntList {
private:
	int arr[100] = { 0 }; // 정수를 저장할 배열
	int i = 0, count = 0; // 출력할 배열의 갯수를 count 하기 위한 변수들
	int j, k, m, n; // 반복문을 위한 변수들
public:
	void insert(int n) { // 정수를 배열에 넣는 insert 함수
		arr[i] = n;
		i++;
		count++;
	}
	void printAll() { // 정수를 입력된 순서대로 출력하는 printAll 함수
		for (j = 0; j < count; j++) {
			cout << this->arr[j] << " " << endl;
		}
	}
	void remove(int n) { // n값이 있는지 찾아보고, 있으면 삭제하는 remove 함수
		for (k = 0; k < 100; k++) {
			if (this->arr[k] == n) {
				for (k; k < 100; k++) {
					this->arr[k] = this->arr[k + 1]; // 뒤에 있는 데이터들을 앞으로 쭉 민다
				}
				count--; // 데이터를 삭제했으므로 출력할 배열의 개수도 하나 줄인다
				break;
			}
		}
	}
	void sort() { // 들어있는 정수를 오름차순으로 정렬하는 sort 함수
		int temp;
		for (m = 1; m < count; m++) {
			temp = arr[m]; // 숫자를 임시로 저장
			for (n = m - 1; n >= 0; n--) {
				if (arr[n] < temp) { // 앞의 요소가 더 작으면 중지
					break;
				}
				arr[n + 1] = arr[n]; // 큰 숫자를 뒤로 이동
			}
			arr[n + 1] = temp; // 저장된 값을 넣는다
		}
	}
};

int main() {
	CIntList myList;
	int i, n;
	cout << "10개의 정수를 입력하세요" << endl;
	for (i = 0; i < 10; i++) {
		cin >> n;
		myList.insert(n);
	}

	cout << "출력 결과" << endl;
	myList.printAll();   // 열개의 정수를 입력된 순서대로 출력
	cout << "삭제할 정수를 입력하세요" << endl;
	cin >> n;
	myList.remove(n);   // n 값이 있는지 찾아보고, 있으면 삭제
	cout << "삭제한 후 출력 결과" << endl;
	myList.printAll();   // 출력.
	cout << "오름차순으로 재정렬" << endl;
	myList.sort();    // 들어있는 정수를 오름차순으로 정렬한다.
	myList.printAll();
}