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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

constexpr int MAX = 1001;
int main(){
    int N; cin>>N;
    int D; cin>>D;
    V<int> p(N); cin>>p;
    V<int> q(N); cin>>q;

    atcoder::modint998244353 dp[MAX][MAX], nx[MAX][MAX];
    dp[0][0] = 1;
    rep(t, N) {
        rep(i, D + 1) rep(j, D + 1) nx[i][j] = 0;
        ll pt = p[t], qt = q[t];
        for (int rt = -MAX * 2; rt <= MAX * 2; rt++) {
            int di = abs(pt - rt);
            int dj = abs(qt - rt);
            if (min(di, dj) > D) continue;
            for (int i = 0, ie = D - di; i <= ie; i++) {
            for (int j = 0, je = D - dj; j <= je; j++) {
                nx[i + di][j + dj] += dp[i][j];
            }
            }
        }
        swap(dp, nx);
    }
    mint ans = 0;
    rep(i,MAX) rep(j,MAX) ans += dp[i][j];
    PL(ans)
    return 0;
}

