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

	ll h,w,k;
	cin>>h>>w>>k;

	ll x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;

	vector<vector<ll> > ans(2, vector<ll>(2,0));
	if(x1==x2&&y1==y2) ans[0][0]=1;
	else if(x1==x2) ans[0][1]=1;
	else if(y1==y2) ans[1][0]=1;
	else ans[1][1]=1;

	if(true){
		repll(i,k){
			//PS(ans[0][0])	PL(ans[0][1]) PS(ans[1][0])	PL(ans[1][1])
			vector<vector<ll> > ANS(2, vector<ll>(2));
			ANS[0][0] = ans[0][1]+ans[1][0];
			ANS[0][1] = (w-1)*ans[0][0]+ans[1][1]+(w-2)*ans[0][1];
			ANS[1][0] = (h-1)*ans[0][0]+ans[1][1]+(h-2)*ans[1][0];
			ANS[1][1] = (h-1)*ans[0][1]+(w-1)*ans[1][0]+(h-2+w-2)*ans[1][1];
			ANS[0][0] %= MOD;
			ANS[0][1] %= MOD;
			ANS[1][0] %= MOD;
			ANS[1][1] %= MOD;
			ans = ANS;
		}
	}
	PS(ans[0][0])//	PL(ans[0][1])	PS(ans[1][0])	PL(ans[1][1])
	//PL("end")

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
