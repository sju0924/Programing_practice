#include <iostream>
#include<string>
#include<vector>

using namespace std; 

vector<int>Plus(0); //벡터 저장
vector<int>Minus(0);

int is_sign(char code) {
	if (code >= '0' && code <= '9') return 0;
	else if (code == '+') return 1;
	else if (code == '-') return -1;
	else return -2;

}

int main()
{
	string input;
	int CurState = 1; // 1일때 - plus, -1일때 - minus로 들어감
	int cur = 0,tmp;
	cin >> input;
	
	for (int i = 0; i < input.length();i++) {
		if (tmp = is_sign(input.at(i))) {
			if (CurState == 1)Plus.push_back(cur); //마이너스 기호가 나오기 전에는 무조건 더한
			else if (CurState == -1) Minus.push_back(cur); //마이너스 기호가 나왔으면 무조건 뺌. 플러스일경우 - 괄호치고 마이너스일경우 - 그냥뺌

			if (tmp == -1) CurState = -1;// 마이너스 기호 검출
			cur = 0;
		}
		else {
			cur = cur * 10 + input.at(i) - 48;
		}
	}

	if (CurState == 1) Plus.push_back(cur);
	else if (CurState == -1) Minus.push_back(cur);

	int res = 0 ;
	for (int i = 0; i < Plus.size();i++) {
		res += Plus.at(i);
	}
	for (int i = 0; i < Minus.size();i++) {
		res -= Minus.at(i);
	}

	cout << res;

}
