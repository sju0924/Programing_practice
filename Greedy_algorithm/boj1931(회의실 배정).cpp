// boj1931(회의실 배정).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<unsigned int,unsigned int> >time; //[n][0]: 시작시간 [n][1]: 끝나는 시간
int N;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair<unsigned int, unsigned int> tmp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp.first >> tmp.second;
		time.push_back(tmp);
	}

	sort(time.begin(), time.end());

	int res = 0;
	unsigned int Next_Start = time[0].second;
	if (time[0].first != time[0].second) res++;
	for (int i = 0; i < N; i++) {
		if (time[i].first >= Next_Start) {
			res++;
		//	cout << i+1 << "번째에 res = " << res << "\n";
			Next_Start = time[i].second;
		}
		else if (time[i].second < Next_Start) Next_Start = time[i].second;
	}

	cout << res;
}
