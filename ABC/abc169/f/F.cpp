#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
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

//N*N*S=1e10 TLE&MLE
void solve() {

    ll N,S; cin>>N>>S;
    V<ll> A(N); cin>>A;

    //i番目まで見て，j個の和がkである通り数．
    V<V<V<mint>>> dp(N+1, V<V<mint>>(N+1, V<mint>(S+1)));
    dp[0][0][0] = 1;
    rep(i,N){
        dp[i+1] = dp[i];
        ll a = A[i];
        rep(j,i+1){
            rep(k,S+1){
                if(k+a>S) break;
                dp[i+1][j+1][k+a] += dp[i][j][k];
            }
        }
    }

    mint ans = 0;
    rep(j,N+1){
        ans += dp[N][j][S]*mint(2).pow(N-j);
        EL(dp[N][j][S])
    }

    PL(ans)

    return;
}

void solve2() {

    ll N,S; cin>>N>>S;
    V<ll> A(N); cin>>A;

    //i番目まで見て，和がkである通り数．
    V<V<mint>> dp(N+1, V<mint>(S+1));
    dp[0][0] = 1;
    rep(i,N){
        dp[i+1] = dp[i];
        ll a = A[i];
        //rep(j,i+1){
        rep(k,S+1){
            if(k+a>S) break;
            dp[i+1][k+a] += dp[i][k]/2;
        }
        //}
    }

    mint ans = 0;
    //rep(j,N+1){
        ans += dp[N][S]*mint(2).pow(N);
        //EL(dp[N][j][S])
    //}

    PL(ans)

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
