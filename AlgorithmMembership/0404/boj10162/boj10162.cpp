// boj10162.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{

	int A, B, C, D, E, res = 0;
	cin >> A >> B >> C >> D >> E;

	if (A <= 0) {
		res = -C * A + D + B*E;
	}
	else {
		res = (B - A) * E;
	}
	cout << res;


}