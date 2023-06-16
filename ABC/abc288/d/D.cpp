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
// #define endl "\n"
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
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqr = priority_queue<T, vector<T>, greater<T>>;
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, typename U> void operator--(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator--(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, typename U> void operator++(pair<T, U>& p){p.first--, p.second--;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first--, p.second--;}//post
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

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

#if __has_include(<atcoder/segtree>)
#include <atcoder/segtree>
using namespace atcoder;
template<typename T> T opMax(T a, T b){return max(a,b);}
template<typename T> T opMin(T a, T b){return min(a,b);}
template<typename T> T opSum(T a, T b){return a+b;}
template<typename T> T e0(){return T(0);}
template<typename T> T e_LINF(){return -LINF;}
template<typename T> T eLINF(){return LINF;}

template<typename T=ll> using RMQ = segtree<T, opMax<T>, e_LINF<T>>;//Range Max Query
template<typename T=ll> using RmQ = segtree<T, opMin<T>, eLINF<T>>;// RmQ tree(vec); tree.prod(l,r)
template<typename T=ll> using RSQ = segtree<T, opSum<T>, e0<T>>;

ll seg_target;
bool f(ll vi){return vi<seg_target;}//seg.max_right<f>(x-1)
bool f2(ll vi){return vi>=seg_target;}//seg.max_right<f>(x-1)
//max_right<f>(l):=>[l:N)でfを満たす右端．
//min_left<f>(r):=>[0:r)でfを満たす左端．
//f(e)=trueでなければならない
//RMQ<ll> tree(N);
//tree.set(i,0);
//tree.get(i);
//tree.prod(l,r);//半開区間
#endif

void solve() {

    ll N,K;cin>>N>>K;
    V<ll> A(N); cin>>A;

    Lazy::LazyRSQ<ll> L(N), R(N);
    rep(i,N) L.set(i, {A[i],1});
    rep(i,N) R.set(i, {A[i],1});

    V<bool> Lzero(N), Rzero(N);

    //L更新
    rep(i,N){
        if(i+K>=N) break;
        ll l = L.prod(i,i+1).x;
        if(l==0) Lzero[i+K] = true;
        L.apply(i, i+K, {1, -l});
        rep(i,N){PS(L.prod(i,i+1).x)}PL("")
    }

    //L更新
    for(ll i=N-1;i>=0;i--){
        if(i-K+1<0) break;
        ll r = R.prod(i,i+1).x;
        if(r==0) Rzero[i-K+1] = true;
        R.apply(i-K+1, i+1, {1, -r});
        rep(i,N){PS(R.prod(i,i+1).x)}PL("")
    }

    EL(Lzero)
    EL(Rzero)

    ll Q; cin>>Q;
    rep(_,Q){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        bool okL = true;
        bool okR = true;
        for(int i=l+K;i<=r;i++){
            if(!Lzero[i]) okL = false;
            if(!Rzero[i]) okR = false;
        }
        if(okL||okR) PL("Yes")
        else PL("No")
    }

    return;
}

void solve2(){
    ll N,K;cin>>N>>K;
    V<ll> A(N); cin>>A;

    //diff[i,i+1]:=A[i], A[i+1]の差
    RSQ<ll> tree(N-1);
    rep(i,N-1){
        tree.set(i, A[i+1]-A[i]);
    }

    ll Q; cin>>Q;
    rep(_,Q){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        bool ok = true;
        for(int i=r-(K+1); i<=r;i++){
            if(i-K<l) continue;
            if(tree.prod(i-K,i-K+1)!=tree.prod(i,i+1)) ok = false;
        }
        if(ok) PL("Yes")
        else PL("No")
    }    

}



void solve3(){
    ll N,K;cin>>N>>K;
    V<ll> A(N); cin>>A;
    ll Q; cin>>Q;
    
    if(K==1){
        rep(_,Q) PL("Yes")
        return;
    }

    V<RSQ<ll>> tree(K, RSQ<ll>(N));
    rep(i,N){
        ll diff = A[i];
        if(i!=0) diff -= A[i-1];
        tree[i%K].set(i, diff);
    }

    rep(_,Q){
        ll l,r;
        cin>>l>>r;
        l--;
        //r--;
        bool ok = true;

        //ぴったりの時
        if(r-l+1==K){
            repi(i,l,r) if(A[i]!=A[l]) ok = false;
        }

        rep(I,K-1){
            ll i = r-I;
            // ES(l) ES(i+1) ES(i) EL(tree[i%K].prod(l,i+1))
            if(tree[(i+K-1)%K].prod(l,i+1)!=0) ok = false;
        }
        if(ok) PL("Yes")
        else PL("No")
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);//小数点以下
    // std::cout << std::setprecision(3);//全体有効数字
    // std::cout << std::defaultfloat;//設定戻す(6桁)
    // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
    // stoll(s,nullptr,base);
    int TT = 1;
    //cin>>TT;
    for(int tt = 0; tt<TT; tt++) solve3();
    return 0;
}


