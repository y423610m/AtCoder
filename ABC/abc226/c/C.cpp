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

	int n; cin>>n;
	vector<ll> T(n);
	vector<vector<ll> > A(n);
	rep(i,n){
		cin>>T[i];
		int k; cin>>k;
		A[i] = vector<ll>(k);
		rep(j,k) {cin>>A[i][j]; A[i][j]--;}
	}

	ll ans = 0;
	vector<bool> done(n+1, false);
	queue<int> que;
	que.push(n-1);
	while(!que.empty()){
		int i = que.front();
		que.pop();
		rep(j,A[i].size()) if(done[A[i][j]]==false){
			que.push(A[i][j]);
			done[A[i][j]] = true;
			//putl(A[i][j])
		}
		ans += T[i];
	}

	//rep(i,n) puts(done[i])

	putl(ans)

	return;
}

int main() {
	solve();
	return 0;
}
