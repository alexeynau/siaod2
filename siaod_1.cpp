#include <iostream>
#include <bitset>
#include <cmath>
#include <Windows.h>

using namespace std;

int Ex1(int number, int mask);
int Ex2(int number, int mask);
int Ex3(int number, int multiplier);
int Ex4(int number, int devider);
int Ex5(int number, int mask, int n);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Науменко А.А.\tИНБО-05-21\tВариант 1\nПрактическая работа №1. Побитовые операции:\n\n";

	cout << "Задание 1. Установить 5-ый и 7-ой (справа) биты константы в 1:\n";
	int X = 0xABCD;
	cout << "Константа X(hex) = " << hex << X << endl;
	cout << "X(bin)    = " << bitset<32>(X) << "\n";
	int mask = 0b10100000;
	cout << "M(bin)    = " << bitset<32>(mask) << "\n";
	cout << "X|M (bin) = " << bitset<32>(Ex1(X,mask)) << "\n\n";

	cout << "Задание 2. Установить биты числа (с 9-ого 4 слева) в 0:\n";
	cout << "Введите число X:";
	cin >> X;
	mask = 0b0001111000000000;
	cout << "X(bin)    = " << bitset<32>(X) << "\n";
	cout << "M(bin)    = " << bitset<32>(mask) << "\n";
	cout << "X|M (bin) = " << bitset<32>(Ex2(X, mask)) << "\n\n";

	cout << "Задание 3. Умножить число на 8 с помощью поразрядного сдвига:\n";
	cout << "Введите число X:";
	cin >> X;
	cout << "X(bin)       = " << bitset<32>(X) << "\n";
	int result = Ex3(X, 8);
	cout << "X << 3 (bin) = " << bitset<32>(result) << "\n";
	cout << "X * 8 (dec)  = " << dec << result << "\n\n";

	cout << "Задание 4. Разделить число на 8 с помощью поразрядного сдвига:\n";
	cout << "Введите число X:";
	cin >> X;
	cout << "X(bin)       = " << bitset<32>(X) << "\n";
	result = Ex4(X, 8);
	cout << "X << 3 (bin) = " << bitset<32>(result) << "\n";
	cout << "X / 8 (dec)  = " << dec << result << "\n\n";

	cout << "Задание 5. Установить n-ый бит числа в 1:\n";
	cout << "Введите число X:";
	cin >> X;
	cout << "Введите число n:";
	int n;
	cin >> n;
	mask = 1;
	cout << "X(bin)           = " << bitset<32>(X) << "\n";
	cout << "M(bin)           = " << bitset<32>(mask) << "\n";
	cout << "M << n     (bin) = " << bitset<32>(mask << n) << "\n";
	cout << "X | (M<<n) (bin) = " << bitset<32>(Ex5(X, mask, n)) << "\n";


}

int Ex1(int number, int mask) {
	return number | mask;
}

int Ex2(int number, int mask) {
	return number & mask;
}

int Ex3(int number, int multiplier) {
	return number << (int)log2(multiplier);
}

int Ex4(int number, int devider) {
	return number >> (int)log2(devider);
}

int Ex5(int number, int mask, int n) {
	mask = mask << n;
	return number | mask;
}