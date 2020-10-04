# Drop The Byte!(boj 17949)
## 문제 개요
16진수로 입력을 하면 long_long(16비트, 8바이트) int char로 나누어 10진수로 변환하는 문제.

## 접근법
그냥 문자열 잘 나눠 가면서 계산하면 된다.<br/>
그런데 딱히 틀린 부분이 없음에도 계속 오답이 떠서 VS 말고 GCC 컴파일러에서 돌려 보았다. 그랬더니 18446744073709547520 + 3840이 0이 나오는게 아닌가.<br/>

	for (int j = 15;j >= 0;j--) {
	res += char_to_int(input[cur + 16 - j]) * pow(16, j); 
       	 }


이 부분이 문제였다. 

			for (int j = 15;j >= 0;j--) {
				temp = char_to_int(input[cur + 16 - j]) * pow(16, j);
				res += temp;
			}
  res에다 바로 더하지 말고 중간에 temp를 넣어줬더니 잘 돌아간다. 띠용?<br/>
  왜 이러는지 찾아봐도 안 나온다. 누가 알려주었으면 좋겠다. 


## CODE
~~~
#include <iostream>
#include<string>
#include<cmath>


using namespace std;



int char_to_int(char _c) {
	int res = (int)_c;
	if (_c >= '0' && _c <= '9') return res - 48;
	else if (_c >= 'a' && _c <= 'f') return res - 87;

	return 0;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, cur = -1;
	unsigned long long temp;
	char* input = new char[1000002];
	cin >> input;
	cin >> num;

	string cmd;

	unsigned long long res = 0;

	for (int i = 0; i < num; i++) {
		cin >> cmd;
		if (cmd == "char") {
			for (int j = 1;j >= 0;j--) {
				res += char_to_int(input[cur + 2 - j]) * pow(16, j);
			}
			cur += 2;
		}
		else if (cmd == "int") {
			for (int j = 7;j >= 0;j--) {
				res += char_to_int(input[cur + 8 - j]) * pow(16, j);
			}
			cur += 8;
		}
		else if (cmd == "long_long") {
			for (int j = 15;j >= 0;j--) {
				temp = char_to_int(input[cur + 16 - j]) * pow(16, j);
				res += temp;
			}

			cur += 16;

		}


		cout << res << "\n";
		res = 0;
	}

	delete[] input;
}
~~~
