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

int n,m;
vector<int> par, Rank;

// 
void init() {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		Rank[i] = 0;
	}
}
//
int find(int x) {
if (par[x] == x) {
return x;
} else {
return par[x] = find(par[x]);
}
}
// 
void unite(int x, int y) {
x = find(x);
y = find(y);
if (x == y) return;
if (Rank[x] < Rank[y]) {
par[x] = y;
} else {
par[y] = x;
if (Rank[x] == Rank[y]) Rank[x]++;
}
}
// 
bool same(int x, int y) {
return find(x) == find(y);
}

void solve() {

	cin>>n>>m;

	par = vector<int>(n);
	Rank = vector<int>(n);

	init();

	vector<int> vi(n,0);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--; b--;
		vi[a]++;
		vi[b]++;
		if(same(a,b)){
			PL("No")
			return;
		}
		unite(a,b);
	}

	sort(ALL(vi));

	if(vi[n-1]>2){
		PL("No")
		return;
	}

	if(vi[1]>=2){
		PL("No")
		return;		
	}



	//rep(i,n) PS(vi[i])

	PL("Yes")

	return;
}

int main() {
	solve();
	return 0;
}
