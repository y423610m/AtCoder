#include <bits/stdc++.h>
using namespace std;

//const int MOD = 998'244'353;
const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());

using ll = long long;
using P = pair<int, int>;
template <class T> using V = vector<T>;

template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}

template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



#if __has_include(<atcoder/modint>)
#include <atcoder/segtree>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace atcoder;
//modint
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
//segtree
ll RMQop(ll a, ll b){return max(a,b);}
ll RMQe(){return -INF;}
using RMQ = segtree<ll, RMQop,RMQe>;//Range Max Query
ll RmQop(ll a, ll b){return min(a,b);}
ll RmQe(){return INF;}
using RmQ = segtree<ll, RmQop,RmQe>;// RmQ tree(vec); tree.prod(l,r)
ll RSQop(ll a, ll b){return a+b;}
ll RSQe(){return 0LL;}
using RSQ = segtree<ll, RSQop,RSQe>;//Range Sum Query
ll seg_target;
bool f(ll v){return v<seg_target;}//seg.max_right<f>(x-1)
//#else
#endif

int keta(ll a, int b=10){int ret = 0; while(a){a /= b; ret++;} return ret; }
ll POW(ll a, ll b, ll mod = 0){	ll ret = 1;	ll tmp = a; if(mod){tmp%=mod;}	while(b){if(b&1){ret *= tmp; if(mod){ret%=mod;}} b /= 2; tmp *= tmp; if(mod){tmp%=mod;}}return ret;}
ll mod_inv(ll x, ll mod=0){ll m = mod-2;ll result = 1;ll tmp = x%mod;while(m){if(m&1){result *= tmp;}result %= mod;tmp = tmp*tmp;tmp %= mod;m /= 2;}return result;}
vector<ll> DIGIT(ll a, int b=2, bool reverse_ = true){vector<ll> ret;while(a){ret.push_back(a%b); a/=b; }if(reverse_){reverse(ret.begin(), ret.end());}return ret;}
template <typename T> int compress(vector<T>& A){ vector<T> B = A; sort(B.begin(), B.end()); B.erase(unique(B.begin(), B.end()), B.end()); for(int i=0;i<(int)A.size();i++){A[i] = (int)(lower_bound(B.begin(), B.end(), A[i]) - B.begin()); } return(int)B.size();}
template <typename T> ll inversion_number(vector<T>& A, ll mod = MOD){ int sz = compress(A); ll ret = 0; RSQ tree(sz); for(int i=0;i<(int)A.size();i++){ ret += i-tree.prod(0, A[i]+1); if(mod){ret%=mod;} tree.set(A[i], tree.get(A[i])+1); } return ret; }
vector<string> rotate_90n(const vector<string>& in, int n=1){vector<string> ret;if(n<0){n+=400000000;} n%=4;int h,w;if(n%2==0) {h = in.size(), w = in[0].size(); }else {h = in[0].size(), w = in.size();}ret = vector<string>(h,string(w,' '));for(int i=0;i<h;i++){for(int j=0;j<w;j++){if(n==0) {ret[i][j] = in[i][j];}if(n==1) {ret[i][j] = in[w-1-j][i];}if(n==2) {ret[i][j] = in[h-1-i][w-1-j];}if(n==3) {ret[i][j] = in[j][h-1-i];}}}return ret;}


void solve() {

	int n; cin>>n;
	V<int> L(n); cin>>L;

	SORT(L);

	ll ans = 0;

	repi(i,0,n){
		repi(j,i+1,n){
			repi(k,j+1,n){
				//if(L[k]>=L[i]+L[j]) break;
				//else ans++;
				if(L[k]<L[i]+L[j]) ans++;
			}
		}
	}



	// repi(i,0,n){
	// 	repi(j,i+1,n){
	// 		auto it = lower_bound(L.begin()+j+1, L.end(), L[i]+L[j]);
	// 		ans += max(0, (int)(it-j-L.begin())-1);
	// 		//ES(i) ES(j) EL(ans)
	// 	}
	// }
	PL(ans)

	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int TT = 1; //cin>>TT;
	for(int tt = 0; tt<TT; tt++) solve();

	return 0;
}
