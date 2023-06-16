#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
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
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    ll H,W,N; cin>>H>>W>>N;
    ll sx,sy; cin>>sx>>sy; sx--,sy--;
    ll gx,gy; cin>>gx>>gy; gx--,gy--;
    V<Pll> XY(N); cin>>XY;
    rep(i,N) XY[i].fi--, XY[i].se--;

    map<ll,V<ll>> X,Y;//X[i][j]:=
    rep(i,N){
        auto [x,y] = XY[i];
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    for(auto& x:X) sort(ALL(x.se));
    for(auto& y:Y) sort(ALL(y.se));

    map<Pll,ll> dist;
    dist[{sx,sy}] = 0;
    queue<Pll> que;
    que.push({sx,sy});
    while(!que.empty()){
        auto [x,y] = que.front(); que.pop();
        ES(x) EL(y)
        if(x==gx&&y==gy) END(dist[Pll(x,y)]);
        if(Y.find(y)!=Y.end()){
            //x+
            ll ny = y;
            auto it = upper_bound(ALL(Y[y]),x);
            if(it!=Y[y].end()){
                ll nx = (*it)-1;
                if(nx!=x&&dist.find({nx,ny})==dist.end()){
                    que.push({nx,ny});
                    dist[{nx,ny}] = dist[{x,y}]+1;
                }
            }
            //x-
            it = lower_bound(ALL(Y[y]),x);
            if(it!=Y[y].begin()){
                it = prev(it);
                ll nx = (*it)+1;
                if(nx!=x&&dist.find({nx,ny})==dist.end()){
                    que.push({nx,ny});
                    dist[{nx,ny}] = dist[{x,y}]+1;
                }
            }
        }
        if(X.find(x)!=X.end()){
            //y+
            ll nx = x;
            auto it = upper_bound(ALL(X[x]),y);
            if(it!=X[x].end()){
                ll ny = (*it)-1;
                if(ny!=y&&dist.find({nx,ny})==dist.end()){
                    que.push({nx,ny});
                    dist[{nx,ny}] = dist[{x,y}]+1;
                }
            }
            //y-
            it = lower_bound(ALL(X[x]),y);
            if(it!=X[x].begin()){
                it = prev(it);
                ll ny = (*it)+1;
                if(ny!=y&&dist.find({nx,ny})==dist.end()){
                    que.push({nx,ny});
                    dist[{nx,ny}] = dist[{x,y}]+1;
                }
            }
        }
    }
    PL(-1)

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
