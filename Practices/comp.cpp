#include <iostream>  
using namespace std;
class Complex {
public:
	double num, complex;
	void setValue(double ii, double cc) { // 값을 설정하는 setValue 함수
		this->num = ii;
		this->complex = cc;
	}

	Complex &addTo(Complex &k) { // 또다른 class의 num과 complex를 각각 더해주는 addTo 함수
		this->num += k.num;
		this->complex += k.complex;
		return *this;
	}

	void print() { // class를 출력하는 print 함수
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

Complex sub(Complex &x, Complex &y) { // 서로 다른 class의 num과 complex를 각각 빼주는 sub 함수 (global)
	Complex d;
	d.setValue(x.num - y.num, x.complex - y.complex); // 뺀 값을 setValue로 넘겨 값을 설정.
	return d;
}

Complex add(Complex &x, Complex &y) { // 서로 다른 class의 num과 complex를 각각 더해주는 add 함수 (global)
									  // 실수 부분과 복소수 부분을 전부 return하기 위해 Complex class를 임시로 선언한다.
	Complex c;
	c.setValue(x.num + y.num, x.complex + y.complex); // 더한 값을 setValue로 넘겨 값을 설정.
	return c;
}

int main() {
	Complex a, b, c, d;
	a.setValue(1.1, 2.2);   // 이것은 1.1 + 2.2i 라는 뜻.
	b.setValue(2.2, 3.3);

	c = add(a, b);  // add는 global 함수이다.

	a.addTo(b);  //  a에 b를 더한다.

	d = sub(a, b);  // 뺄셈을 나타내는 global 함수.

	cout << "a = ";
	a.print();   // 자기 자신의 값을 복소수 형태로 출력
	cout << "c = ";
	c.print();
	cout << "d = ";
	d.print();

	a.addTo(a).addTo(b).addTo(c);  // 개념적으로 말하자면 a += a; a+= b; a+= c;
	cout << "a = ";
	a.print();

}