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

void solve() {

	int n,k;
	cin>>n>>k;
	k--;

	vector<vector<int> > P(n,vector<int>(3));
	rep(i,n)rep(j,3) cin>>P[i][j];

	vector<int> score(n);
	rep(i,n) score[i] = P[i][0]+P[i][1]+P[i][2];
	sort(ALL(score));
	reverse(ALL(score));

	int ans = 0;
	rep(i,n){
		 if(score[k]<=P[i][0]+P[i][1]+P[i][2]+300) cout<<"Yes"<<endl;
		 else cout<<"No"<<endl;
	}

	//cout<<ans<<endl;


	return;
}

int main() {
	solve();
	return 0;
}
