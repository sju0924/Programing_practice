// boj11653(소인수분해).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int input,n;
	cin >> input;
	n = input;

	while (n % 2 == 0) {
		cout << 2 << "\n";
		n = n / 2;
	}

	for (int i = 3; i <= input; i += 2) {
		while (n % i == 0) {
			cout << i << "\n";
			n = n / i;
		}
		if (n == 1) break;
	}
}
