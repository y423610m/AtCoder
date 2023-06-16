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
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

#if __has_include(<atcoder/dsu>)
#include <atcoder/dsu>
using namespace atcoder;
//dsu DSU(n);
//DSU.merge(a,b);
//if(DSU.same(a,b)){}
#endif

//DRUL  SENW
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T> vector<T> CCompress(vector<T>& A){
   vector<T> B = A;
   sort(B.begin(), B.end());
   B.erase(unique(B.begin(), B.end()), B.end());
   for(int i=0;i<(int)A.size();i++){
      A[i] = (int)(lower_bound(B.begin(), B.end(), A[i]) - B.begin());
   }
   return B;
}
//vector<int> A = {1,100,5,5};
//auto B = CCompress(A);
//-> A={0,2,1,1}, B={1,5,100}

//重複を許さない座標圧縮．同じ数字は先出から割り振る
template<typename T>
void reorder(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(auto& a:A){
        auto it = lower_bound(B.begin(), B.end(), a);
        a = it - B.begin();
        (*it)--;
    }
}

//重複を許さない座標圧縮．同じ数字は後方から割り振る
template<typename T>
void reorder_rev(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(int i=A.size()-1;i>=0;i--){
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        A[i] = it - B.begin();
        (*it)--;
    }
}

void solve() {

    ll H,W; cin>>H>>W;
    auto inGrid = [&](int nx, int ny){
        if(0<=nx&&nx<H&&0<=ny&&ny<W) return true;
        return false;
    };

    V<V<ll>> A(H,V<ll>(W)); cin>>A;

    //座標圧縮
    {
        V<ll> B;
        rep(h,H) rep(w,W) B.push_back(A[h][w]);
        auto dict = CCompress(B);
        rep(h,H) rep(w,W) A[h][w] = lower_bound(ALL(dict), A[h][w])-dict.begin();
    }
    EL(1)

    //同色同士結合
    dsu uf(H*W);
    rep(h,H) rep(w,W) rep(d,4){
        int nx = h+dx[d];
        int ny = w+dy[d];
        if(inGrid(nx,ny)&&A[h][w]==A[nx][ny]) uf.merge(h*W+w, nx*W+ny);
    }
    EL(2)

    //隣接リスト
    V<V<ll>> G(H*W);
    rep(h,H) rep(w,W) rep(d,4){
        int nx = h+dx[d];
        int ny = w+dy[d];
        if(inGrid(nx,ny)&&A[h][w]!=A[nx][ny]){
            ll u = uf.leader(h*W+w);
            ll v = uf.leader(nx*W+ny);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    EL(3)

    //重複削除
    rep(i,H*W){
        sort(ALL(G[i]));
        ERASE(G[i]);
    }
    EL(4)

    ll ans = 0;
    rep(h,H) rep(w,W) chmax(ans, uf.size(h*W+w));
    EL(5)

    V<ll> cnt(H*W+10);
    //根についてのみ確認
    rep(h,H) rep(w,W) if(G[h*W+w].size()>0){
        for(auto to:G[h*W+w]){
            ll nx = to/W;
            ll ny = to%W;
            cnt[A[nx][ny]] += uf.size(to);
            chmax(ans, uf.size(h*W+w)+cnt[A[nx][ny]]);
        }
        for(auto to:G[h*W+w]){
            ll nx = to/W;
            ll ny = to%W;
            cnt[A[nx][ny]] = 0;
        }
    }
    EL(6)
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
