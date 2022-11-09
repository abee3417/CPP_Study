#include <iostream>  
using namespace std;
class Complex {
public:
	double num, complex;
	void setValue(double ii, double cc) { // ���� �����ϴ� setValue �Լ�
		this->num = ii;
		this->complex = cc;
	}

	Complex &addTo(Complex &k) { // �Ǵٸ� class�� num�� complex�� ���� �����ִ� addTo �Լ�
		this->num += k.num;
		this->complex += k.complex;
		return *this;
	}

	void print() { // class�� ����ϴ� print �Լ�
		cout << this->num;
		if (this->complex > 0) {
			cout << "+";
		}
		else {
			cout << "-";
		}
		cout << this->complex << "i" << endl;
	}
};

Complex sub(Complex &x, Complex &y) { // ���� �ٸ� class�� num�� complex�� ���� ���ִ� sub �Լ� (global)
	Complex d;
	d.setValue(x.num - y.num, x.complex - y.complex); // �� ���� setValue�� �Ѱ� ���� ����.
	return d;
}

Complex add(Complex &x, Complex &y) { // ���� �ٸ� class�� num�� complex�� ���� �����ִ� add �Լ� (global)
									  // �Ǽ� �κа� ���Ҽ� �κ��� ���� return�ϱ� ���� Complex class�� �ӽ÷� �����Ѵ�.
	Complex c;
	c.setValue(x.num + y.num, x.complex + y.complex); // ���� ���� setValue�� �Ѱ� ���� ����.
	return c;
}

int main() {
	Complex a, b, c, d;
	a.setValue(1.1, 2.2);   // �̰��� 1.1 + 2.2i ��� ��.
	b.setValue(2.2, 3.3);

	c = add(a, b);  // add�� global �Լ��̴�.

	a.addTo(b);  //  a�� b�� ���Ѵ�.

	d = sub(a, b);  // ������ ��Ÿ���� global �Լ�.

	cout << "a = ";
	a.print();   // �ڱ� �ڽ��� ���� ���Ҽ� ���·� ���
	cout << "c = ";
	c.print();
	cout << "d = ";
	d.print();

	a.addTo(a).addTo(b).addTo(c);  // ���������� �����ڸ� a += a; a+= b; a+= c;
	cout << "a = ";
	a.print();

}