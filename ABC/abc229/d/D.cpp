#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).begin(),(a).end()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

void solve() {

	string s;
	int k;
	cin>>s>>k;

	if(k>=s.size()){
		PL(s.size())
		return;
	}

	int l = 0;
	//int r = 0;

	int cnt = 0;
	int ans = min(int(s.size()),k);
	//if(s[0]=='.') cnt++;

	rep(r,s.size()){
		if(s[r]=='.') cnt++;
		while(cnt>k&&l<=r){
			if(s[l]=='.')cnt--;
			l++;
		}
		ans = max(ans, r-l+1);
	}

	//PS(l) PS(r)
	PL(ans)
/*
	while(r-l+1<k){
		if(s[r]=='.') cnt++;
		r++;
	}
	int ans = r-l+1-cnt;
	while(r<s.size()){
		if(s[r]==)
	}
*/

	return;
}

int main() {
	solve();
	return 0;
}
