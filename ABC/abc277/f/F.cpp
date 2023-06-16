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



void solve() {

    ll H,W; cin>>H>>W;
    V<V<ll>> A(H,V<ll>(W)); cin>>A;

    bool ng = false;

    V<ll> rowMax(H, 0);
    V<ll> rowMin(H, LINF);
    rep(h,H) rep(w,W) chmax(rowMax[h], A[h][w]);
    rep(h,H) rep(w,W) if(A[h][w]!=0) chmin(rowMin[h], A[h][w]);
    rep(h,H) A[h].push_back(rowMax[h]);
    rep(h,H) A[h].push_back(rowMin[h]);

    sort(ALL(A), [&](const V<ll>& a, const V<ll>& b){
        if(a[H]!=b[H]) return a[H]<b[H];
        return a[H+1]<b[H+1];
    });
    rep(h,H) A[h].pop_back();
    rep(h,H) A[h].pop_back();

    V<V<ll>> B(W,V<ll>(H));
    rep(h,H) rep(w,W) B[w][h] = A[h][w];
    swap(H,W);
    swap(A,B);

    rowMax = V<ll>(H, 0);
    rowMin = V<ll>(H, LINF);
    rep(h,H) rep(w,W) chmax(rowMax[h], A[h][w]);
    rep(h,H) rep(w,W) if(A[h][w]!=0) chmin(rowMin[h], A[h][w]);
    rep(h,H) A[h].push_back(rowMax[h]);
    rep(h,H) A[h].push_back(rowMin[h]);
    sort(ALL(A), [&](const V<ll>& a, const V<ll>& b){
        if(a[H]!=b[H]) return a[H]<b[H];
        return a[H+1]<b[H+1];
    });

    ll m = 0;
    rep(h,H) rep(w,W) if(A[h][w]!=0){
        if(A[h][w]<m) END("No")
        chmax(m, A[h][w]);
    }

    PL("Yes")

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

/*
ABC277 5完
A:for
B:map<char,bool>作った
C:すべてのA,Bと1,1e9を含めた配列を座標圧縮後，UnionFind.
D:条件読み間違えて1ペナ.map[X]=idを先に準備．UnionFindで統合しながらカードの和も足し合わせた．
E:スイッチ押した回数が奇数回，偶数回で距離配列作ってdijkstra.
*/