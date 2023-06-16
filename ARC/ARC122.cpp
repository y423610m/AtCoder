#include <bits/stdc++.h>
using namespace std;

void solveARC122A() {
	/////////////////////////////////////
//２進数表記から1:+0 : -に変換
//なぜか例題３答え合わず．．．
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}

	//2^d<n
	int d = 1;
	while (d < n) {
		d *= 2;
	}
}

void solveARC122B() {

	long long int ret = 0;
	long long int ng = 0;

	for (int i = 0; i < (int)pow(2, n - 1); i++) {
		long long int sum = 0;
		vector<int> ope;
		bool last = true;
		bool b = true;
		int j = i;
		for (int k = 0; k < n - 1; k++) {

			if (j % 2 == 1) {
				last = true;
				ope.push_back(1);
			}
			else {
				if (last == false) b = false;
				last = false;
				ope.push_back(-1);
			}
			j /= 2;
		}

		ope.push_back(1);
		reverse(ope.begin(), ope.end());
		//cout << ope.size() << endl;
		//cout << b << " ope " << inner_product(v.begin(), v.end(), ope.begin(), 0) << endl;
		sum = (long long int)inner_product(v.begin(), v.end(), ope.begin(), 0);

		if (b) {
			//cout << count(ope.begin(), ope.end(), -1) << endl;
			cout << accumulate(ope.begin(), ope.end() - 1, 0) << endl;
			//cout << sum << "    ";
			ret += sum;
			//ret = 3;
			while (ret < 0) ret += 1000000007;
			if (ret > 0)	ret %= 1000000007;
			//cout << ret << endl;
		}
		//else ng += sum;
	}

	//ret %= 1000000007;
	cout << "ans" << ret << "   " << ng;

}