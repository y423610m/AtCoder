#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define rrep(i, a, n) for (int i = (int)(a); i > (int)(n); i--)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define rrepll(i, a, n) for (ll i = (ll)(a); i > (ll)(n); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()
#define puts(a) cout<<(a)<<" ";
#define putl(a) cout<<(a)<<endl;

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

const int MAX_V = 100;

ll Power(ll a, ll b){
	ll ret = 1;
	repll(i,b) ret *= a;
	return ret;
}

int area(int a, int b){
	return 4*a*b+3*a+3*b;
}

void solve() {

	int n;cin>>n;
	vector<int> S(n);
	rep(i,n) cin>>S[i];

	vector<int> OK;
	repi(a,1,1001){
		repi(b,1,1001){
			OK.push_back(area(a,b));
		}
	}

	sort(ALL(OK));
	auto result = unique(ALL(OK));
	OK.erase(result,OK.end());

	int ans=0;
	rep(i,n) if(find(ALL(OK),S[i])==OK.end()) ans++;

	cout<<ans<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
