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

	int L,n,k;
	cin>>n>>L>>k;

	vector<int> A(n);
	rep(i,n) cin>>A[i];

	int l=-1,r=L+1;
	while(r-l>1){
		PS(l)PL(r)
		int mid = (l+r)/2;
		int cnt = 0;
		int tmp=0;
		repi(i,0,n){
			if( A[i]-tmp>=mid && L-A[i]>=mid ){
				cnt++;
				tmp=A[i];
			}
		}
		if(cnt>=k) l=mid;
		else r=mid;
	}

	PL(l);

	return;
}

int main() {
	solve();
	return 0;
}
