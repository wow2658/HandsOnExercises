#include<iostream>
#include <vector>
#include<cassert>
using namespace std;

int hash_num(int value, int n_ = 65407) {
	long long n = n_;
	return (value % n + n) % n;
}

int hash_string(string str, int n = 65407) {
	long long nn = n;
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum = (sum * 26 + str[i] - 'a') % nn;
	return sum % nn;
}

int hash_string_lower_upper_digits(string str, int n_ = 65407)
{
	int base = 2 * 26 + 10;	// lower, upper and 10 digits
	// 이 부분에서 실수가 일어나면 hash table의 index범위 오류를 일으킬 수도 있다.
	long long n = n_;
	long long sum = 0;

	for (int i = 0; i < (int)str.size(); ++i)
	{
		// lowers from [0-25], upper [26-51] and digits [52-61]
		int value = 0;
		if (islower(str[i]))
			value = str[i] - 'a';
		else if (isupper(str[i]))
			value = 26 + str[i] - 'A';
		else if (isdigit(str[i]))
			value = 26 + 26 + str[i] - '0';
		else
			assert(false);
		sum = sum * base + value;	// base 26 number
		sum %= n;	// reduce to minimize overflows
	}
	return sum;
}

// aabcdefgAxT334gfg
// aabc defg AxT3 34gf g
int hash_string_folding(string str, int n_ = 65407) {
	long long n = n_;
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); i += 4) {
		string block = str.substr(i, 4);
		sum += hash_string_lower_upper_digits(block);
		sum %= n;
	}
	return sum;
}

// 숫자를 숫자로, 문자를 숫자로 바꾸는 hash를 구현해봤다.
// 데이터타입이 다른 숫자와 문자를 모두 반영해서 숫자로 바꾸는 hash는 어떻게 구현해야하나?
struct SomeObject
{
	const static int INTERNAL_LIMIT = 2147483647;
	string str1, str2;
	int number;

	// Convert all 3 elements as a hash value
	int hash()
	{
		long long res = hash_string_lower_upper_digits(str1 + str2, INTERNAL_LIMIT);
		res += hash_num(number, INTERNAL_LIMIT);
		return res % INTERNAL_LIMIT;
	}
};


int main() {
	cout << hash_string_folding("aabcdefgAxT334gfg");

	return 0;
}
