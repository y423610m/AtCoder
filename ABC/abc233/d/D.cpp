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

	int n; ll k;
	cin>>n>>k;

	vector<ll> A(n);
	rep(i,n) cin>>A[i];

	vector<ll> sum(n+1);
	unordered_map<ll,ll> mp;
	sum[0]=0;
	mp[0]=1;
	ll ans = 0;
	rep(i,n){
		sum[i+1]=sum[i]+A[i];
		if(mp[sum[i+1]-k]>0){
			ans += mp[sum[i+1]-k];
			//PL(i)
		}
		mp[sum[i+1]]++;
	}

	PL(ans)


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
