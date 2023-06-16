#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

const int MOD = 998244353;
//const int MOD = 1000000007;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second

using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using P = pair<int, int>;
using mint = atcoder::static_modint<MOD>;

const int INF = (1<<30)-1;
const ll LINF = (1LL<<62)-1;

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    	os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

ostream &operator<<(ostream &os, const mint x) {
    os<<x.val();
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}


template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};


void solve() {
	
    int n,K; cin>>n>>K;
	if(K==1) END("Infinity")

	V<ll> X(n), Y(n);
	rep(i,n) cin>>X[i]>>Y[i];

	V<tuple<ll,ll,int>> ans; // vx,vy, id

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ll vx1 = X[j]-X[i];
			ll vy1 = Y[j]-Y[i];
			ll cnt = 2;

			int lastID = j;
			
			for(int k=j+1;k<n;k++){
				ll vx2 = X[k]-X[i];
				ll vy2 = Y[k]-Y[i];
				if(vx1*vy2-vy1*vx2==0LL){
					cnt++;
					lastID = k;
				}
			}
			//EL(cnt)
			if(cnt>=K){
				if(vx1==0) vy1 = 1LL;
				else if(vy1==0) vx1 = 1LL;
				else{
					ll GCD = gcd(abs(vx1),abs(vy1));
					vx1 /= GCD;
					vy1 /= GCD;
				}
				if(vx1<0){
					vx1 = -(vx1);
					vy1 = -(vy1);
				}
				ans.push_back({vx1, vy1, lastID});
			}
		}
	}
	//ES("b unique") EL(ans.size())
	sort(ALL(ans));
	auto it = unique(ALL(ans));
	ans.erase(it,ans.end());
	PL(ans.size())

	//rep(i,ans.size()){ ES(get<0>(ans[i]))  ES(get<1>(ans[i]))  EL(get<2>(ans[i])) }

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
