#include <iostream>
#include<cmath>

using namespace std;

int cnt = 1;
void print(char edge, float res) {
	cout << fixed;
	cout.precision(3);



	cout << "Triangle #" << cnt << "\n";

	if (edge == 'x') {
		cout << "Impossible.\n\n";
	}
	else cout << edge << " = " << res << "\n\n";

	cnt++;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a = 1, b = 1, c = 1;
	cin >> a >> b >> c;
	while (a || b || c) {
		if ((a >= c || b >= c) && c != -1) {
			print('x', 1);
		}
		else if (a == -1 || b == -1 || c == -1) {
			if (a == -1) {
				print('a', sqrt(c * c - b * b));
			}
			if (b == -1) {
				print('b', sqrt(c * c - a * a));
			}
			if (c == -1) {
				print('c', sqrt(a * a + b * b));
			}

		}
		cin >> a >> b >> c;

	}



}
