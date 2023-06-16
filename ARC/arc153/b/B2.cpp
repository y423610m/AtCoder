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

#if __has_include(<atcoder/lazysegtree>)
#include <atcoder/lazysegtree>
using namespace atcoder;
#endif

namespace Lazy{
    template<typename T>
    struct S{
        T x;
        ll size=1;
    };

    template<typename T>
    struct F{
        T a,b;
    };

    template<typename T> S<T> opSum(S<T> l, S<T> r){return S<T>{l.x+r.x, l.size+r.size};}
    template<typename T> S<T> opMax(S<T> l, S<T> r){return (l.x>=r.x?l:r);}
    template<typename T> S<T> opMin(S<T> l, S<T> r){return (l.x<=r.x?l:r);}

    template<typename T> S<T> e0(){return S<T>{0, 0};}
    template<typename T> S<T> eLINF(){return S<T>{LINF, 0};}
    template<typename T> S<T> e_LINF(){return S<T>{-LINF, 0};}

    template<typename T>
    S<T> FS(F<T> f, S<T> s){
        return S<T>{f.a*s.x+f.b*s.size, s.size};//ax+b
    }

    template<typename U=ll>
    F<U> FF(F<U> l, F<U> r){
        return F<U>{l.a*r.a, l.a*r.b+l.b};
    }

    template<typename U=ll>
    F<U> f0(){
        return F<U>{1,0};
    }
    template<typename T=ll> using LazyRSQ = lazy_segtree<S<T>, opSum<T>, e0<T>,     F<T>, FS<T>, FF<T>, f0<T>>;
    template<typename T=ll> using LazyRMQ = lazy_segtree<S<T>, opMax<T>, e_LINF<T>, F<T>, FS<T>, FF<T>, f0<T>>;
    template<typename T=ll> using LazyRmQ = lazy_segtree<S<T>, opMin<T>, eLINF<T>,  F<T>, FS<T>, FF<T>, f0<T>>;
    /*
    ll N,Q; cin>>N>>Q;
    V<ll> A(N); cin>>A;
    Lazy::LazyRSQ<mint> tree(N);
    rep(i,N) tree.set(i, {A[i],1});// {x, size}

    tree.apply(l,r,LS::F<mint>{a,b});//ax+b
    cout<<tree.prod(l,r).x<<endl;
    */
}

void solve() {

    ll H,W; cin>>H>>W;
    V<string> A(H); cin>>A;

    Lazy::LazyRSQ<ll> X(H), Y(W);//A[h][w]がどこにいるか
    rep(h,H) X.set(h,{h,1});
    rep(w,W) Y.set(w,{w,1});

    ll Q; cin>>Q;
    rep(_,Q){
        ll a,b; cin>>a>>b;
        X.apply(0,a,Lazy::F<ll>{-1,a});
        X.apply(a,H,Lazy::F<ll>{-1,a+H});
        Y.apply(0,b,Lazy::F<ll>{-1,b});
        Y.apply(b,W,Lazy::F<ll>{-1,b+W});
    }

    V<string> B(H,string(W,'0'));
    rep(h,H) rep(w,W){
        ll x = X.prod(h,h+1).x-1;
        ll y = Y.prod(w,w+1).x-1;
        ES(h) ES(w) ES(x) EL(y)
        B[h][w] = A[x][y];
    }
    rep(h,H) PL(B[h])

    return;
}

int X[500002], Y[500002];

void solve2(){
    ll H,W; cin>>H>>W;
    V<string> A(H); cin>>A;

    rep(h,H) X[h] = h;
    rep(w,W) Y[w] = w;

    ll Q; cin>>Q;
    rep(_,Q){
        ll a,b;
        cin>>a>>b;
        ll l = 0, r = a-1;
        while(l<r){
            swap(X[l],X[r]);
            l++,r--;
        }
        l = a, r = H-1;
        while(l<r){
            swap(X[l],X[r]);
            l++,r--;
        }
        l = 0, r = b-1;
        while(l<r){
            swap(Y[l],Y[r]);
            l++,r--;
        }
        l = b, r = W-1;
        while(l<r){
            swap(Y[l],Y[r]);
            l++,r--;
        }
    }

    V<string> B(H,string(W,'0'));
    rep(h,H) rep(w,W){
        B[h][w] = A[X[h]][Y[w]];
    }
    rep(h,H) PL(B[h])
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}
