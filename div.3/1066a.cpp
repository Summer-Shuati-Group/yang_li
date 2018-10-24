#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int n, L, v, l, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> L >> v >> l >> r;
		cout << ((l - 1) / v) + (L / v - r / v) << endl;
	}
	return 0;
}