#include <iostream>

using namespace std;

int getGCD(int a, int b) {
	if (a < b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	if (b == 0) {
		return a;
	}
	return getGCD(b, a % b);
}

int main()
{
	int N, FirstRing, InputRing, GCD; // 
	cin >> N >> FirstRing;

	for (int i = 1; i < N; i++) {
		cin >> InputRing;
		GCD = getGCD(InputRing, FirstRing);
		cout << FirstRing / GCD << "/" << InputRing / GCD << "\n";
	}

}
