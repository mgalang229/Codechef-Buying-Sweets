#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		// create a 'sum' variable to get the total number of banknotes
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		// calculate the number of sweets that can be bought using
		// the sum of banknotes in the 'total' variable
		int total = sum / x;
		bool checker = false;
		// run two loops to calculate the sum of all the elements
		// while skipping the current element to check if there is
		// an extra banknote(s) that were provided
		for (int i = 0; i < n; i++) {
			// create a 'temp' variable to store the total sum of elements
			// without the current element being iterated upon by index 'i'
			int temp = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					// if index 'i' is equal to index 'j', then continue the loop
					continue;
				}
				// otherwise, add the current element in the 'temp' variable
				temp += a[j];
			}
			// check if the 'temp' variable divided by 'x' is still
			// equal to the 'total' variable
			if (temp / x == total) {
				// if it's equal, then set the 'checker' to true and break the loop
				checker = true;
				break;
			}
		}
		cout << (checker ? -1 : total) << '\n';
	}
	return 0;
}
