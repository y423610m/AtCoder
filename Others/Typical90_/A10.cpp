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

	int n; cin>>n;
	int sum1 = 0, sum2=0;
	vector<int> vi1,vi2;
	vi1.push_back(0);
	vi2.push_back(0);
	rep(i,n){
		int c,p;
		cin>>c>>p;
		if(c==1) sum1+=p;
		else sum2+=p;
		vi1.push_back(sum1);
		vi2.push_back(sum2);
	}

	int q; cin>>q;
	rep(i,q){
		int l,r;
		cin>>l>>r;
		l--;//r--;
		PS(vi1[r]-vi1[l])PL(vi2[r]-vi2[l])
	}

	return;
}

int main() {
	solve();
	return 0;
}
