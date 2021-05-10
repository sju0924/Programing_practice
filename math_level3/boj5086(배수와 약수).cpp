// boj5086(배수와 약수)

#include <iostream>

using namespace std;


void get_Relation(int a, int b) {
	if (!a || !b) cout<<"neither\n";

	if (b % a == 0) cout << "factor\n";
	else if (a % b == 0) cout << "multiple\n";
	else cout << "neither\n";
}

int main()
{
	int A, B;
	cin >> A >> B;

	while (A || B) {
		get_Relation(A, B);
		cin >> A >> B;
	}
}

