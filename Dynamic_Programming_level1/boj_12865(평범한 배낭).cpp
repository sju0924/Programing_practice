/* boj 12865

 냅색 문제로 유명한 문제이다.
 
 i번째 짐까지 넣었을 때 무게가 j일 경우 최대 가치 값을 구하는 알고리즘이다.
 i번째의 짐을 넣지 않는 경우는 i-1번째의 j무게일때의 값과 같고,
 넣는 경우는 i-1번째의 j-w[i]의 가치값과 v[i]의 값과 같다.
*/

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; //물건의 갯수, 최대 버틸 수 있는 무게
	int* w, * v; // 물건의 무게, 물건의 가치
	int** dp;

	cin >> n >> k;
	w = new int[n];
	v = new int[n];
	dp = new int* [n];

	for (int i = 0; i < n; i++) {
		dp[i] = new int[k + 1];
		cin >> w[i] >> v[i];
	}
	
	for (int i = 0; i <= k; i++) {
		if (i >= w[0]) {
			dp[0][i] = v[0];
		}
		else dp[0][i] = 0;

		//cout << dp[0][i] << " ";
	}

	//cout << endl;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j-w[i]>=0 && dp[i - 1][j - w[i]] + v[i] > dp[i - 1][j]) { // dp[i][j]가 바뀌는 조건
				dp[i][j] = dp[i - 1][j - w[i]] + v[i];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		//	cout << dp[i][j] << " ";
		}
	//	cout << endl;
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i][k]) max = dp[i][k];
	}
	cout << max;


}
