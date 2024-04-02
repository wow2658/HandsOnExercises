#include<iostream>
#include <vector>
#include<map>
using namespace std;

int hash_string1(string str, int n)
{
	int sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum += str[i] - 'a';	// to 0-25 range
	return sum % n;
} // 이런 쉬운 연산은 충돌하는 경우가 많다

int hash_string2(string str, int n)
{
	int sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum = sum * 26 + str[i] - 'a';	// base 26 number
	cout << sum << "\n";
	return sum % n;
} // 좀더 복잡한 연산에 모듈러까지 소수로 나누면 충돌이 매우 적어질 것이다.


int main() {


	cout << hash_string2("abc", 7) << "\n";		// 0+1*26+2 = 28 % 7 = 0
	// 1 * 26 * 26 * 26 + 2 * 26 * 26 + 3 * 26 + 4 = 19010
	cout << hash_string2("abcde", 70) << "\n";	// 19010 % 70 = 40
	cout << hash_string2("abcde", 7) << "\n";   // 19010 % 7 = 5
	cout << hash_string2("bcdea", 7) << "\n";	// 494260 % 7 = 4
	cout << hash_string2("abcwz", 7) << "\n";	// 19525 % 7 = 2


	return 0;
}
