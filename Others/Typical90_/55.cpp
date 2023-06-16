#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;


void solve() {
	int n,p,q;
	cin>>n>>p>>q;

	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int ans = 0;
	int cnt = 0;
	repi(i,0,n-4) repi(j,i+1,n-3) repi(k,j+1,n-2) repi(l,k+1,n-1) repi(m,l+1,n){
		ll pro = 1;
		pro *= a[i];
		pro %= p;
		pro *= a[j];
		pro %= p;
		pro *= a[k];
		pro %= p;
		pro *= a[l];
		pro %= p;
		pro *= a[m];
		pro %= p;
		if(pro==q) ans++;
	}
	PL(ans)
//	PL(cnt)

	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}
