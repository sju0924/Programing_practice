// boj1012.cpp 

#include <iostream>

using namespace std;
int arr[51][51];
int is_searched[51][51];
int dX[4] = { -1,0,0,1 };
int dY[4] = { 0,-1,1,0 };
int res = 0;

//change: is_searched,arr 의 요소들이 0이 됨
void resetArr() {
	for (int i = 0; i < 51;i++) {
		for (int j = 0; j < 51;j++) {
			arr[i][j] = 0;
			is_searched[i][j] = 0;
		}
	}
	res = 0;
}

//input: 배추 위치 갯수 K
//change: arr 배열
void MakeArr(int K) {
	int M, N;
	
	resetArr();

	for (int i = 0; i < K; i++) { //위치 입력
		cin >> M >> N;
		arr[M][N] = 1;
	}


}

void dfs(int cX,int cY) {

	is_searched[cX][cY] = 1;

	for (int i =0; i < 4; i++) {
		if (arr[cX + dX[i]][cY + dY[i]] && !is_searched[cX + dX[i]][cY + dY[i]]) {
			dfs(cX + dX[i], cY + dY[i]);
		}
	}
}


int main()
{
	int T, M,N,K;

	cin >> T;

	for (int i = 0; i < T; i++) { //테스트 케이스 반복
		cin >> M >> N >> K;
		MakeArr(K);

		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if(!is_searched[x][y] && arr[x][y]){
					res++;
					dfs(x, y);
				}
			}
		}

		cout << res << "\n";

	}
}