#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

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
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    ll H,W,N; cin>>H>>W>>N;

    V<Pll> RC(N);
    V<ll> A(N);

    //h, <a, id>
    //w, <a, id>
    //map<ll,set<Pll>> Row,Col;
    V<V<Pll>> Row(H), Col(W);
    rep(i,N){
        ll r,c,a;
        cin>>r>>c>>a;
        r--, c--;
        RC[i] = {r,c};
        //Row[r].insert({a, i});
        //Col[c].insert({a, i});
        Row[r].push_back({a,i});
        Col[c].push_back({a,i});
        A[i] = a;
    }

    rep(h,H) sort(ALL(Row[h]));
    rep(w,W) sort(ALL(Col[w]));

    V<bool> visited(N, false);
    V<ll> dp(N,0);

    auto dfs = [&](auto dfs, int p) -> void {
        ll h = RC[p].fi;
        ll w = RC[p].se;
        {
            // move in row
            //auto it = Row[h].lower_bound({A[p]+1,0});
            auto it = lower_bound(ALL(Row[h]),Pll(A[p]+1,0));
            if(it!=Row[h].end()){
                ll a = it->fi;
                while(it!=Row[h].end()&&it->fi==a){
                    int to = it->se;
                    if(!visited[to]){
                        dfs(dfs, to);
                        visited[to] = true;
                    }
                    chmax(dp[p], dp[to]+1);
                    it++;
                }
            }
        }
        {
            // move in column
            // auto it = Col[w].lower_bound({A[p]+1,0});
            auto it = lower_bound(ALL(Col[w]),Pll(A[p]+1,0));
            if(it!=Col[w].end()){
                ll a = it->fi;
                while(it!=Col[w].end()&&it->fi==a){
                    int to = it->se;
                    if(!visited[to]){
                        dfs(dfs, to);
                        visited[to] = true;
                    }
                    chmax(dp[p], dp[to]+1);
                    it++;
                }
            }
        }
    };

    rep(i,N) if(!visited[i]){
        dfs(dfs, i);
        visited[i] = true;
    }

    rep(i,N) PL(dp[i])

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
