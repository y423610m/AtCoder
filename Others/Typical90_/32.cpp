#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

int n;
VV<int> A;
V<set<int> > XY;

int ans = INF;
set<int> st;
V<int> memo;


void dfs(int time, int pos, int prv){

	if(pos==n){
		chmin(ans, time);
		ES(time)
		rep(j,memo.size()) ES(memo[j]) 
		EL("")
	}
	else{
		rep(i,n) if(st.find(i)==st.end()){
			if(XY[i].find(prv)!=XY[i].end()) continue;
			st.insert(i);
			//memo.push_back(i);
			dfs(time+A[i][pos], pos+1, i);
			st.erase(i);
			//memo.pop_back();
		}
	}

	return;
}

void solve() {
	cin>>n;
	A.resize(n);
	rep(i,n) A[i].resize(n);
	rep(i,n) rep(j,n) cin>>A[i][j];

	int m; cin>>m;
	XY.resize(n+1);
	rep(i,m){
		int x,y; cin>>x>>y;
		x--; y--;
		XY[x].insert(y);
		XY[y].insert(x);
	}

	dfs(0, 0, -1);

	if(ans==INF) PL(-1)
	else PL(ans)

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
