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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<ll,ll>;
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


struct Edge{int from, to, cost, id, used;
};

bool operator<(Edge a, Edge b){
    return a.cost<b.cost;
}

void solve() {

    int n,m,k,s,t,x;
    cin>>n>>m>>k>>s>>t>>x;
    s--; t--; x--;

    vector<Edge> Edges;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--, v--;
        int w=1;
        //cin>>w;
        Edges.push_back({u,v,w,i,0});
        Edges.push_back({v,u,w,i,0});
    }

    V<V<V<mint>>> dp(k+1, V<V<mint>>(n, V<mint>(2,0)));
    dp[0][s][0]=1;
    rep(i,k){
        rep(j,Edges.size()){
            int u = Edges[j].from;
            int v = Edges[j].to;

            if(v!=x){
                dp[i+1][v][0] += dp[i][u][0];
                dp[i+1][v][1] += dp[i][u][1];
            }
            else{
                dp[i+1][v][1] += dp[i][u][0];
                dp[i+1][v][0] += dp[i][u][1];
            }
        }
    }

    // rep(i,k+1){
    //     rep(j,n) PS(dp[i][j][0]) PL("")
    // }

    PL(dp[k][t][0])


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
