#include <bits/stdc++.h>
using namespace std;

// const int MOD = 998'244'353;
const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
istream &operator>>(istream &is, mint& x){ll val; is >> val; x = val; return is;}
#endif

void solve() {

    string K; cin>>K;
    int D; cin>>D;

    //dp[i][j][k]:=上i桁目まで見て，余りがjで，Kあるのがいくつあるか
    V<V<V<mint>>> dp(K.size()+1, V<V<mint>>(D, V<mint>(2)));
    dp[0][0][1] = 1;
    rep(i,K.size()){
        rep(j,10){
            rep(d,D){
                dp[i+1][(d+j)%D][0] += dp[i][d][0];
                if(j<K[i]-'0') dp[i+1][(d+j)%D][0] += dp[i][d][1];
                //dp[i+1][(10*d+j)%D][1] += dp[i][d][0];
                if(j==K[i]-'0')dp[i+1][(d+j)%D][1] += dp[i][d][1];
            }
        }
    }
    // rep(k,2){
    //     rep(i,K.size()+1){
    //         rep(j,D){
    //             PS(dp[i][j][k])
    //         }
    //         PL("")
    //     }
    //     PL("")
    // }
    EL("a")
    mint ans = 0;
    ans = dp[K.size()][0][0]+dp[K.size()][0][1];
    PL(ans-1)

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
