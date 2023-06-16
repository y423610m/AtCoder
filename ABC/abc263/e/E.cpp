#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
//const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
//#define ONLINE_JUDGE 1
#ifdef ONLINE_JUDGE
    #define ES(a) while(0){}
    #define EL(a) while(0){}
#else
    #define NAME(a) #a
    #define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
    #define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#endif
#define END(a) {PL(a) return;}
#define RES(a) cerr<<"\r"<<NAME(a)<<": "<<(a)<<"   ";
#define fi first
#define se second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
#endif

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
// ll RMQop(ll a, ll b){return max(a,b);}
// ll RMQe(){return -INF;}
// using RMQ = segtree<ll, RMQop,RMQe>;//Range Max Query
// ll RmQop(ll a, ll b){return min(a,b);}
// ll RmQe(){return INF;}
// using RmQ = segtree<ll, RmQop,RmQe>;// RmQ tree(vec); tree.prod(l,r)
// ll RSQop(ll a, ll b){return a+b;}
// ll RSQe(){return 0LL;}
// using RSQ = segtree<ll, RSQop, RSQe>;//Range Sum Query
// ll seg_target;
// bool f(ll v){return v<seg_target;}//seg.max_right<f>(x-1)
// //#else
#endif

mint RSQop(mint a, mint b){return a+b;}
mint RSQe(){return 0;}
using RSQ = segtree<mint, RSQop, RSQe>;//Range Sum Query

void solve() {

    int n; cin>>n;
    V<int> A(n-1); cin>>A;

    //i->nへの試行回数期待値
    V<mint> dp(n);
    dp[n-1] = 0;
    RSQ tree(n+1);
    for(int i=n-1-1;i>=0;i--){
        dp[i] = (tree.prod(i+1,i+1+A[i])+1+A[i]) / mint(A[i]);
        tree.set(i,dp[i]);
    }

    EL(dp)

    PL(dp[0])

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
