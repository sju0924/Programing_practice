#include <iostream>

using namespace std;


int getFactorial(int max, int min) {
	int res = 1;
	for (int i = min + 1; i <= max; i++) {
		res = res * i;
	}
	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << getFactorial(n, n - k) / getFactorial(k, 1);
}
