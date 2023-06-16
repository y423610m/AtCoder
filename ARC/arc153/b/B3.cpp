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

#include "structure/tree/implicit_treap.hpp"
/*
MinUpdateQuery<ll,ll> tree;//->update(l,r,ll);
SumUpdateQuery<ll,ll> tree;//->update(l,r,ll);
MinAddQuery<ll,ll> tree;//->update(l,r,ll);
SumAddQuery<ll,ll> tree;//->update(l,r,ll);
MinmaxAffineQuery<ll> tree;//->update(l,r,{x,x});
SumAffineQuery<ll> tree;//->update(l,r,{a,b});

tree.set_by_vector(A);
tree.insert(pos, {x,x}));//
tree.update(l,r,{a,b});//ax+b
int sz = tree.size();
tree.erase(pos);
tree.reverse(l,r);
tree.rotate(l,m,r);//[l, r)の先頭がmになるようにシフトさせる。std::rotateと同じ仕様
auto x = tree.query(l,r);
auto x = tree[0];
tree.binary_search(l,r,x);
//tree.dump();//全出力
// 二分探索。[l, r)内のkでf0(tr[k], x) != xとなる最左/最右のもの。存在しない場合は-1
// // たとえばMinMonoidの場合、x未満の最左/最右の要素の位置を返す
*/

void solve() {

    ll H,W; cin>>H>>W;
    V<string> A(H); cin>>A;

    MinUpdateQuery<ll,ll> X,Y;
    rep(h,H) X.insert(h,h);
    rep(w,W) Y.insert(w,w);

    ll Q; cin>>Q;
    rep(_,Q){
        ll a,b; cin>>a>>b;
        X.reverse(0,a);
        X.reverse(a,H);
        Y.reverse(0,b);
        Y.reverse(b,W);
        // X.dump();
        // Y.dump();
    }

    V<string> B(H,string(W,'0'));
    rep(h,H) rep(w,W){
        B[h][w] = A[X[h]][Y[w]];
    }

    rep(h,H) PL(B[h])

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
