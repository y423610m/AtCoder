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

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;
const int MAX_V = 100;

void solve() {

	int t; cin>>t;

	rep(i,t){
		ll n2,n3,n4;
		cin>>n2>>n3>>n4;

		ll ret = 0;

		if(n3>=2){
			//3 3 4
			ll tmp = min(n3/2, n4);
			n3 -= 2*tmp;
			n4 -= tmp;
			ret += tmp;
		}
		if(n3>0){	
			// 3 3 2 2
			ll tmp = min(n3/2, n2/2);
			n3 -= 2*tmp;
			n2 -= 2*tmp;
			ret += tmp;
		} 

		if(n4>=2){
			// 4 4 2
			ll tmp = min(n4/2, n2);
			n4 -= 2*tmp;
			n2 -= tmp;
			ret += tmp;
		}
		if(n4>0){
			// 4 2 2 2
			ll tmp = min(n4, n2/3);
			n4 -= tmp;
			n2 -= 3*tmp;
			ret += tmp;
		}
		if(n2>=5){
			ret += n2 / 5;
		}

		cout<<ret<<endl;
	}

	return;
}

int main() {
	solve();
	return 0;
}
