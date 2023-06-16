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
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
ll RMQop(ll a, ll b){return max(a,b);}
ll RMQe(){return -LINF;}
using RMQ = segtree<ll, RMQop,RMQe>;//Range Max Query

ll RmQop(ll a, ll b){return min(a,b);}
ll RmQe(){return INF;}
using RmQ = segtree<ll, RmQop,RmQe>;// RmQ tree(vec); tree.prod(l,r)

template<typename T>
T RSQop(T a, T b){return a+b;}
template<typename T>
T RSQe(){return T(0);}
template<typename T>
using RSQ = segtree<T, RSQop<T>, RSQe<T>>;

ll seg_target;
bool f(ll v){return v<seg_target;}//seg.max_right<f>(x-1)
#endif

void solve() {

    int W; cin>>W;
    int N; cin>>N;

    V<int> L(N), R(N);
    V<ll> v(N);
    rep(i,N) cin>>L[i]>>R[i]>>v[i];

    //dp[i][j]:=i個目まで選んで，重さがjの時の最大価値
    V<RMQ> dp(N+1, RMQ(W+1));
    dp[0].set(0, 0);
    rep(i,N){
        EL(i)
        dp[i+1] = dp[i];
        rep(j,W+1){
            if(j-L[i]<0) continue;
            ll val = dp[i].prod(max(0,j-R[i]), max(0,j-L[i])+1);
            //if(val==-LINF) continue;
            ES(j) EL(val+v[i])
            dp[i+1].set(j,max(val+v[i], dp[i+1].get(j)));
        }
    }
    
    ll ans = dp[N].get(W);
    if(ans<0) END(-1)
    else END(ans)

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
