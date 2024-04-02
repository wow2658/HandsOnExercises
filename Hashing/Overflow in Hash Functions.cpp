#include<iostream>
#include <vector>
#include<cassert>
using namespace std;

// 해시값의 결과가 음수가 나오는 경우를 예방해보자.

// 첫 번째 경우는 value값으로 음수가 들어와버려서 모듈러연산 결과로 음수를 반환할 때이다.
int hash_num(int value, int n_ = 65407)
{
	long long n = n_;
	return (value % n + n) % n;
} // value % n는 반드시 n보다는 작을 것이다. 그러므로 n을 더해놓으면 일단 양수는 확보되는것이고 그 상태에서 또 n을 나누는 기법이다.

unsigned int hash_num2(int value, unsigned int n = 65407)
{
	return (unsigned int)value % n;
} // 아니면 아예 value를 unsigned int으로 명시적 형변환을 해버려서 음수를 방지하는 방법도 있다.



// 두 번째 경우는 뭔가를 제곱해서 곱하는 특성상 수가 매우 커져서 오버플로우가 발생했을 때가 있다.
// 이때는 unsigned long long 이라던지 더 큰 데이터 형식을 사용해서 방지할 수 있다.
int hash_string(string str, int n)
{
	long long nn = n;
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum = (sum * 26 + str[i] - 'a') % nn;
	return sum % nn;
}


int main()
{

	return 0;
}
