// boj11399(ATM).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N, input;
	int min, max, mid;
	cin >> N;
	int* time = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> time[i];
	}
	sort(time, time + N);

	long long int res = 0;
	for (int i = 0; i < N; i++) {
		//cout << time[i] << " ";
		res += time[i] * (N - i);
	}

	cout <<res;
}

