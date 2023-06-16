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

	int n,m; cin>>n>>m;
	vector<pair<int, int> > AB(m), CD(m);
	rep(i,m) cin>>AB[i].first>>AB[i].second;
	rep(i,m) cin>>CD[i].first>>CD[i].second;
	rep(i,m) AB[i].first--,AB[i].second--;
	rep(i,m) CD[i].first--,CD[i].second--;

	vector<int> change(n);
	rep(i,n) change[i]=i;

	sort(ALL(CD));

	if(AB==CD){
		PL("Yes")
		return;
	}

	while(next_permutation(ALL(change))){
		vector<pair<int, int> > ab = AB;
		rep(i,m){
			ab[i].first = change[ab[i].first];
			ab[i].second = change[ab[i].second];
			if(ab[i].first>ab[i].second) swap(ab[i].first,ab[i].second);
		}
		sort(ALL(ab));
		if(ab==CD){
			PL("Yes")
			return;
		}
		//rep(i,n) PS(change[i])
		//PL("")
	}

	PL("No")

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
