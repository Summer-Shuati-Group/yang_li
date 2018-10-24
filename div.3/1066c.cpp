#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int arr[2 * 100000 + 5];
	int n;
	cin >> n;
	int l = 1;
	// the first line of input will always be "L xxx"
	// therefore, after inserting the first number,
	// we have equal distance to the left and right
	// so that we need to increment the left by 1 
	int r = 0;
	for (int i = 0; i < n; i++) {
		char c;
		int idx;
		cin >> c >> idx;
		if (c == 'L') {
			arr[idx] = --l;
		}
		else if (c == 'R') {
			arr[idx] = ++r;
		}
		else if (c == '?') {
			cout << min(abs(l - arr[idx]), abs(r - arr[idx])) << endl;
		}
	}
	return 0;
}