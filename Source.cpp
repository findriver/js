#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class IntegerNumber {
private:
	string integer;
public:
	IntegerNumber();
	IntegerNumber(unsigned int integer);
	IntegerNumber(string integer);
	void setInteger(unsigned int integer);
	void setInteger(string integer);
	unsigned int getIntValue() const;
	string toString() const;
	IntegerNumber addInteger(const IntegerNumber& integer_to_add) const;
	IntegerNumber addInteger(const string& integer_to_add) const;

	IntegerNumber subtractInteger(const IntegerNumber& integer_to_sub) const; //a-b
	IntegerNumber subtractInteger(const string& integer_to_sub) const;

	static size_t getTrimIndex(const string& integer);
	bool operator==(const IntegerNumber& integer) const;
	bool operator<(const IntegerNumber& integer) const;
	bool operator>=(const IntegerNumber& integer) const;
	bool operator>(const IntegerNumber& integer) const;
	bool operator!=(const IntegerNumber& integer) const;
	IntegerNumber operator+(const IntegerNumber& integer) const;
	IntegerNumber operator-(const IntegerNumber& integer) const;
	friend ostream& operator<<(ostream& in, IntegerNumber& integer);
};

int main() {

	// INSERT YOUR CODE HERE

	// This is a sample code that demonstrates how to use the
	//Big Integer arithmetic library.
	
	IntegerNumber A;
	IntegerNumber B("12");
	IntegerNumber C = "5";
	IntegerNumber D(B);
	IntegerNumber E(B);

	A = B;
	cout << A << " = " << B << endl;

	C = B + C;
	cout << C << endl;

	D = B - C;
	cout << D << endl;

	if (A < B) {
		E = E + B;
		cout << E << endl;
	}

	if (A >= B) {
		E = E - B;
		cout << E << endl;
	}

	if (A == B || C != D) {
		cout << A << " " << E << " "<< D << endl;
	}

	system("Pause");
	return 0;
	
}

IntegerNumber::IntegerNumber() {
	integer = "0";
}


IntegerNumber::IntegerNumber(unsigned int integer) {
	setInteger(integer);
}

IntegerNumber::IntegerNumber(string integer) {

	for (int i = 0; i < (int)integer.size() && integer[i] >= '0' && integer[i] <= '9'; i++) {
		
		this->integer += integer[i];
		}

	if (this->integer.size() == 0) {
		this->integer = "0";
	}
	else {
		this->integer = integer.substr(getTrimIndex(integer));
	}
}

void IntegerNumber::setInteger(unsigned int integer) {
	if (integer == 0) this->integer = "0";

	while (integer) {
		this->integer = (char)((integer % 10) + '0') + this->integer;
		integer /= 10;
	}
}

void IntegerNumber::setInteger(string integer) {
	this->integer = integer;
}

unsigned int IntegerNumber::getIntValue() const {
	unsigned int ret = 0;
	unsigned int biggest = 0xFFFFFFFF;
	for (int i = 0; i < (int)integer.size(); i++) {
		int unit = integer[i] - '0';
		if (ret >(biggest - unit) / 10.0) return 0;
		ret = ret * 10 + unit;
	}
	return ret;
}

string IntegerNumber::toString() const {
	return integer;
}

IntegerNumber IntegerNumber::addInteger(const IntegerNumber& integer_to_add) const {

	int a_n = max((int)(integer_to_add.toString().size() - toString().size()), 0);
	int b_n = max((int)(toString().size() - integer_to_add.toString().size()), 0);
	string a = string(a_n, '0') + toString();
	string b = string(b_n, '0') + integer_to_add.toString();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string result; int carry = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		result += ((char)(sum % 10 + '0'));
		carry = sum / 10;
	}


	if (carry != 0) result += ((char)(carry + '0'));

	reverse(result.begin(), result.end());

	return IntegerNumber(result.substr(getTrimIndex(result)));
}

IntegerNumber IntegerNumber::addInteger(const string& integer_to_add) const {
	
		return addInteger(IntegerNumber(integer_to_add));
}


IntegerNumber IntegerNumber::subtractInteger(const IntegerNumber& integer_to_sub) const {
	int a_n = max((int)(integer_to_sub.toString().size() - toString().size()), 0);
	int b_n = max((int)(toString().size() - integer_to_sub.toString().size()), 0);
	string a = string(a_n, '0') + toString();
	string b = string(b_n, '0') + integer_to_sub.toString();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string result; int carry = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		int sum = (b[i] - '0') - (a[i] - '0')  + carry;
		result += ((char)(sum % 10 + '0'));
		carry = sum / 10;
	}

	if (carry != 0) result += ((char)(carry + '0'));

	reverse(result.begin(), result.end());

	return IntegerNumber(result.substr(getTrimIndex(result)));
}


size_t IntegerNumber::getTrimIndex(const string& integer) {
	size_t index = 0;
	while (integer[index] == '0' && index < integer.size() - 1) index++;
	return index;
}

bool IntegerNumber::operator==(const IntegerNumber& integer) const {
	return this->integer == integer.toString();
}

bool IntegerNumber::operator<(const IntegerNumber& integer) const {
	return this->integer < integer.toString();
}

bool IntegerNumber::operator>=(const IntegerNumber& integer) const {
	return this->integer >= integer.toString();
}

bool IntegerNumber::operator>(const IntegerNumber& integer) const {
	return this->integer > integer.toString();
}

bool IntegerNumber::operator!=(const IntegerNumber& integer) const {
	return this->integer != integer.toString();
}

IntegerNumber IntegerNumber::operator+(const IntegerNumber& integer) const {
	return addInteger(integer);
}

IntegerNumber IntegerNumber::operator-(const IntegerNumber& integer) const {
	return subtractInteger(integer);
}

ostream& operator<<(ostream& in, IntegerNumber& integer) {
	in << integer.toString();

	return in;
}
