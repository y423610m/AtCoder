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

	int h,w; cin>>h>>w;
	vector<string> vs(h);
	rep(i,h) cin>>vs[i];

	int dx[2] = {0,1};
	int dy[2] = {1,0};

	int ans = 1;

	queue<pair<int,int> > que;
	que.push({0,0});
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		rep(i,2){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&vs[nx][ny]=='.'){
				vs[nx][ny]='-';
				que.push({nx,ny});
				ans = max(ans, nx+ny+1);
			}
		}
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
