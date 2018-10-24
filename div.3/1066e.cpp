#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int solve(char arrn[], char arrm[], int n, int m) {
	int result = 0;
	int idx = 0;
	for (int i = max(n, m) - 1; i >= max(n, m) - min(n, m); i--) {
		// cout << "anythin" << endl;
		if (arrn[i] == arrm[i] && arrn[i] == '1') {
			// it should come out of 1 
			result += pow(2, idx);
		}
		idx++;
	}
	return result;
}

int main(int argc, char* argv[])
{
	int n, m, ans = 0;	
	cin >> n >> m;
	char* arrn = new char [n];
	char* arrm = new char [m];
	char* answer = new char [min(n, m)];
	for (int i = 0; i < n; i++) {
		cin >> arrn[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arrm[i];
	}
	int b = solve(arrn, arrm, n, m);
	ans += b;
	while(b > 0) {
		b = solve(arrn, arrm, n, m);
		char buffer[100000];
		b /= 2;
		arrm = itoa(b, buffer, 2);
		ans += b;
	}
	cout << b << endl;
	delete [] arrn;
	delete [] arrm;
	return 0;
}