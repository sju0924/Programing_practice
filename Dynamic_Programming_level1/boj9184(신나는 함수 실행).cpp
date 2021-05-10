// boj9184(신나는 함수 실행).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int arr[21][21][21];
void print(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
	else if(a>20||b>20||c>20) cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[20][20][20] << "\n";
	else  cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << "\n";

}

int main()
{

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for (int i = 0; i < 21;i++) {
		for (int j = 0; j < 21;j++) {
			for (int k = 0; k < 21;k++) {
				if (!i || !j || !k) arr[i][j][k] = 1;
				else if (i < j && j < k) arr[i][j][k] = arr[i][j][k-1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
				else arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
			}
		}
	}
	int input[3] ;
	cin >> input[0] >> input[1] >> input[2];
	while (input[0] != -1 || input[1] != -1|| input[2] != -1) {
		
		print(input[0], input[1], input[2]);
		cin >> input[0] >> input[1] >> input[2];
	}
	
}