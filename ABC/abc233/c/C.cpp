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
	ll n,x;
	cin>>n>>x;

	vector<vector<ll> > A(n);
	rep(i,n){
		int l; cin>>l;
		A[i] = vector<ll>(l);
		rep(j,l){
			cin>>A[i][j];
		}
	}

	vector<unordered_map<ll, ll> > vmp(n+1);
	vector<vector<ll> > vvi(n+1);
	vmp[0][x]=1;
	vvi[0] = vector<ll>();
	vvi[0].push_back(x);
	repi(i,1,n+1){
		rep(j,A[i-1].size()){
			ll a = A[i-1][j];
			rep(k,vvi[i-1].size()){
				//PS(i)PS(j)PL(k)
				ll b = vvi[i-1][k];
				if(b!=0&&b%a==0){
					vvi[i].push_back(b/a);
					vmp[i][b/a]+=vmp[i-1][b];
					//PS(i)PS(j)PS(b)PS(a)PL(vmp[i][b/a])
				}
			}
		} 
		sort(ALL(vvi[i]));
		auto it = unique(ALL(vvi[i]));
		vvi[i].erase(it,vvi[i].end());
	}
	//for(auto num:vmp[n])

	PL(vmp[n][1])


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
