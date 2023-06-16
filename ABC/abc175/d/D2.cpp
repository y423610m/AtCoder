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

#if __has_include(<atcoder/scc>)
#include <atcoder/scc>
using namespace atcoder;
/*
scc_graph sg(N);
sg.add_edge(u,v);
vector<vector<int>> scc = sg.scc();
//トポロジカルソート済み
//辺のない頂点は長さ1のリストとなる．
*/
#endif

void solve() {

    int N; cin>>N;
    int K; cin>>K;
    V<int> P(N); cin>>P;
    rep(i,N) P[i]--;
    V<ll> C(N); cin>>C;

    scc_graph sg(N);
    rep(i,N) sg.add_edge(i,P[i]);
    vector<vector<int>> scc = sg.scc();

    V<bool> inLoop(N, false);
    V<int> CycleLens(N, 0);
    V<ll> CycleCosts(N, 0);

    for(const auto& group:scc){
        if(group.size()>1){
            ll CycleCost = 0;
            for(auto p:group){
                inLoop[p] = true;
                CycleLens[p] = group.size();
                CycleCost += C[p];
            }
            for(auto p:group){
                CycleCosts[p] = CycleCost;
            }
        }
    }

    ll ans = -LINF;
    rep(s,N){
        V<bool> visited(N,false);
        int p = s;
        int k = K;
        ll cost = 0;
        while(k){
            if(visited[p]) break;
            visited[p] = true;

            p = P[p];
            cost += C[p];
            k--;

            chmax(ans, cost);
            if(inLoop[p]) chmax(ans, cost+CycleCosts[p]*(k/CycleLens[p]));
        }
    }

    PL(ans)

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
