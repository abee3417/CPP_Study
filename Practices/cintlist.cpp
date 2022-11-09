#include <iostream>
using namespace std;
class CIntList {
private:
	int arr[100] = { 0 }; // ������ ������ �迭
	int i = 0, count = 0; // ����� �迭�� ������ count �ϱ� ���� ������
	int j, k, m, n; // �ݺ����� ���� ������
public:
	void insert(int n) { // ������ �迭�� �ִ� insert �Լ�
		arr[i] = n;
		i++;
		count++;
	}
	void printAll() { // ������ �Էµ� ������� ����ϴ� printAll �Լ�
		for (j = 0; j < count; j++) {
			cout << this->arr[j] << " " << endl;
		}
	}
	void remove(int n) { // n���� �ִ��� ã�ƺ���, ������ �����ϴ� remove �Լ�
		for (k = 0; k < 100; k++) {
			if (this->arr[k] == n) {
				for (k; k < 100; k++) {
					this->arr[k] = this->arr[k + 1]; // �ڿ� �ִ� �����͵��� ������ �� �δ�
				}
				count--; // �����͸� ���������Ƿ� ����� �迭�� ������ �ϳ� ���δ�
				break;
			}
		}
	}
	void sort() { // ����ִ� ������ ������������ �����ϴ� sort �Լ�
		int temp;
		for (m = 1; m < count; m++) {
			temp = arr[m]; // ���ڸ� �ӽ÷� ����
			for (n = m - 1; n >= 0; n--) {
				if (arr[n] < temp) { // ���� ��Ұ� �� ������ ����
					break;
				}
				arr[n + 1] = arr[n]; // ū ���ڸ� �ڷ� �̵�
			}
			arr[n + 1] = temp; // ����� ���� �ִ´�
		}
	}
};

int main() {
	CIntList myList;
	int i, n;
	cout << "10���� ������ �Է��ϼ���" << endl;
	for (i = 0; i < 10; i++) {
		cin >> n;
		myList.insert(n);
	}

	cout << "��� ���" << endl;
	myList.printAll();   // ������ ������ �Էµ� ������� ���
	cout << "������ ������ �Է��ϼ���" << endl;
	cin >> n;
	myList.remove(n);   // n ���� �ִ��� ã�ƺ���, ������ ����
	cout << "������ �� ��� ���" << endl;
	myList.printAll();   // ���.
	cout << "������������ ������" << endl;
	myList.sort();    // ����ִ� ������ ������������ �����Ѵ�.
	myList.printAll();
}