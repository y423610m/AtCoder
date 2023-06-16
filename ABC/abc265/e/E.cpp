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

void solve() {

    int N,M; cin>>N>>M;
    V<ll> dx(3), dy(3);
    rep(i,3) cin>>dx[i]>>dy[i];

    V<Pll> XY(M); 
    rep(i,M) cin>>XY[i].fi>>XY[i].se;
    set<Pll> NG(ALL(XY));

    V<V<mint>> dp(N+1, V<mint>(N+1));//dp[j][k]:=1*j, 2*k回実行
    V<V<mint>> nxt(N+1, V<mint>(N+1));
    dp[0][0] = 1;

    rep(i,N){
        rep(j,N+1) rep(k,N+1) nxt[j][k] = 0;

        rep(j,N){
            if(j>i) continue;
            rep(k,N){
                if(j+k>i) continue;
                if(dp[j][k]==0) continue;

                Pll pos({0, 0});
                pos.fi = dx[0]*j+dx[1]*k+dx[2]*(i-j-k);
                pos.se = dy[0]*j+dy[1]*k+dy[2]*(i-j-k);

                if(NG.find(pos)!=NG.end()) continue;
                nxt[j+1][k] += dp[j][k];
                nxt[j][k+1] += dp[j][k];
                nxt[j][k] += dp[j][k];
            }
        }
        swap(dp, nxt);
        // EL(i)
        // rep(j,N+1) EL(dp[j])
    }

    mint ans = 0;
    rep(j,N+1) rep(k,N+1){
        Pll pos({0,0});
        pos.fi = dx[0]*j+dx[1]*k+dx[2]*(N-j-k);
        pos.se = dy[0]*j+dy[1]*k+dy[2]*(N-j-k);
        if(NG.find(pos)!=NG.end()) continue;
        ans += dp[j][k];
    }
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
