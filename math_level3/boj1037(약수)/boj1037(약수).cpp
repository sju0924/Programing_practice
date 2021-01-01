// boj1037(약수)

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, input;
	unsigned long long int min, max;
	cin >> N;
	min = 2 << 30;
	max = 0;

	//cout << min << endl;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (min > input) min = input;
		if (max < input) max = input;
	}

	cout << min * max;

}
