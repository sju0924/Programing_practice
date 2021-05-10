// boj2981(검문).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>

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

int sub(int a, int b) {
	if (a > b) return a - b;
	else return b - a;
}

int main()
{
	int N, input;
	int CurGCD;
	vector<int> num;
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> input;

		if (num.empty()) CurGCD = input;
		for (auto elem : num) { //num 요소들과 input의 차의 최대공약수 구함
			if (num.size() == 1) CurGCD = sub(CurGCD, input);
			else CurGCD = getGCD(sub(input,elem), CurGCD);

		}

		
		num.push_back(input);
	}

	for (int i = 2; i * 2 <= CurGCD; i++) {
		if (CurGCD % i == 0) cout << i << " ";
	}
	cout << CurGCD;
}
