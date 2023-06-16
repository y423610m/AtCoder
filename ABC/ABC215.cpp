#include <bits/stdc++.h>
using namespace std;

void solveABC215A() {
	string s;
	cin >> s;
	if (s == "Hello,World!") cout << "AC" << endl;
	else cout << "WA" << endl;
}

void solveABC215B() {

	ll n; cin >> n;
	ll k = 0;
	ll d = 1;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	while (d <= n) {
		d *= 2;
		k++;
	}
	cout << k - 1 << endl;
}

void solveABC215C() {

	string s;
	int k;
	cin >> s >> k;
	k--;

	sort(s.begin(), s.end());
	int cnt = 0;
	if (k == 0) {
		cout << s << endl;
		return 0;
	}
	while (next_permutation(s.begin(), s.end())) {
		cnt++;
		if (cnt == k) {
			cout << s << endl;
			return 0;
		}
	}
}

void solveABC215D() {
	//all TLE

	int n, m;
	cin >> n >> m;

	vector<int> vi(n);
	rep(i, n) cin >> vi[i];

	set<int> st;
	rep(i, n) {
		int a = vi[i];
		int d = 2;
		while (a != 1) {
			if (a % d == 0) {
				st.insert(d);
				while (a % d == 0) a /= d;
			}
			d++;
		}
	}
	vector<bool> ans(m + 1, true);
	ans[0] = false;
	//ans[1] = false;
	auto it = st.begin();
	while (it != st.end()) {//���鐔
		int d = *it;
		int e = 1;
		while (d * e <= m) {
			ans[d * e] = false;
			e++;
		}
		it++;
	}
	cout << count(ans.begin(), ans.end(), true) << endl;
	rep(i, m + 1) if (ans[i]) cout << i << endl;

	//cout << st.size() << endl;
	/*
	//�_���Ȑ���񋓂��āC����Ɋ܂܂�Ȃ���������
	set<int> ng;
	auto it = st.begin();
	while (it != st.end()) {//���鐔
		int d = *it;
		int e = 1;
		while (d * e <= m) {
			ng.insert(d* e);
			e++;
		}
		it++;
	}

	vector<int> ret;
	repi(i, 1, m + 1) {
		if (ng.find(i) == ng.end()) ret.push_back(i);
	}
	*/

	/*
	* //����鐔�̒萔�{�����������]��
	set<int> ret;
	rep(i, m) ret.insert(i + 1);
	auto it = st.begin();
	while (it != st.end()) {//���鐔
		int d = *it;
		int e = 1;
		while (d*e <= m) {
			ret.erase(d*e);
			e++;
		}
		it++;
	}
	*/


	/*
	//�V���v���ɑS�ʂ莎��
	vector<int> ret;
	repi(i,1, m+1) {//�������
		bool ok = true;
		auto it = st.begin();
		while (it != st.end()) {//���鐔
			int d = *it;
			if (i % d == 0) {
				ok = false;
				break;
			}
			it++;
		}
		if (ok) {
			ret.push_back(i);
		}
	}
	*/
	/*
	cout << ret.size() << endl;
	//rep(i, ret.size()) cout << ret[i] << endl;
	auto itr = ret.begin();
	while (itr != ret.end()) {
		cout << (*itr) << endl;
		itr++;
	}
	*/

}