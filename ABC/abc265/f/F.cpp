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

    int N,D; cin>>N>>D;
    V<int> P(N); cin>>P;
    V<int> Q(N); cin>>Q;

    V<V<Pii>> dist(N);//dP, dQ
    ///// N*D
    rep(i,N){
        dist[i].reserve(2*D);
        rep(dP,D+1){
            int pos = P[i]+dP;
            int dQ = abs(Q[i]-pos);
            if(dQ<=D) dist[i].push_back({dP, dQ});

            if(dP==0)continue;

            pos = P[i]-dP;
            dQ = abs(Q[i]-pos);
            if(dQ<=D) dist[i].push_back({dP, dQ});
        }
    }

    V<V<mint>> dp(D+1, V<mint>(D+1));// dp[k][l]  := dP=k, dQ=lの点の数
    dp[0][0] = 1;
    V<V<mint>> nxt(D+1, V<mint>(D+1));
    /////////  N*D*D*D
    rep(i,N){//100
        rep(k,D+1) rep(l,D+1) nxt[k][l] = 0;
        bool updated = false;

        rep(k,D+1){//1000
            rep(l,D+1){//1000
                if(dp[k][l]==0) continue;
                rep(j,dist[i].size()){//2000
                    int dP = dist[i][j].fi;
                    int dQ = dist[i][j].se;
                    if(k+dP>D) continue;
                    if(l+dQ>D) continue;
                    nxt[k+dP][l+dQ] += dp[k][l];
                    updated = true;
                }
            }
        }
        swap(nxt, dp);
        if(!updated) break;
    }

    mint ans = 0;
    rep(i,D+1) rep(j,D+1) ans += dp[i][j];
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
