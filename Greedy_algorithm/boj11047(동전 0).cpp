// boj11047(동전 0)

#include <iostream>

using namespace std;
int coin[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K; //동전의 종류의 갯수, 만들어야되는 돈
	cin >> N >> K;

	int cur = K, res = 0;//실시간 돈과 결과

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	for (int i = N-1; i >-1; i--) {
		while (cur >= coin[i]) {
			res += cur/coin[i] ;
			cur -= coin[i] * (cur/coin[i]);
		}
	}
	cout << res;
}

