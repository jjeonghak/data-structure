#include <iostream>

using namespace std;

/*
비재귀 함수가 효울적이다.
재귀 함수를 사용한 경우 중복된 계산이 많으며 호출 스택으로 인한 메모리 부족이 발생할 우려가 있다.
중복된 계산은 다이나믹 프로그래밍과 메모이제이션을 통해 해결가능하지만 이 경우도 값저장을 위해 메모리를 사용한다.
*/

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main() {

	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;
	return 0;
}

int Fibonacci_recursive(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}

int Fibonacci_non_recursive(int n) {
	int cnt = 0, prev1 = 0, prev2 = 1;

	while (cnt < n) {
		if (cnt % 2 == 0)
			prev1 += prev2;
		else
			prev2 += prev1;
		cnt++;
	}
	if (n <= 0)
		return 0;
	else if (n % 2 == 0)
		return prev1;
	else
		return prev2;
}
