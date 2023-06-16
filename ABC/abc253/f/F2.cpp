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
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
using mint = atcoder::static_modint<MOD>;
// using mint = atcoder::modint;
// mint::set_mod(MOD);
//制約: a/b -> gcd(b,mod)==1
template<int m> ostream &operator<<(ostream &os, const atcoder::static_modint<m> x) {os<<x.val();return os;}
template<int m> istream &operator>>(istream &is, atcoder::static_modint<m>& x){ll val; is >> val; x = val; return is;}
ostream &operator<<(ostream &os, const atcoder::modint x) {os<<x.val();return os;}
istream &operator>>(istream &is, atcoder::modint& x){ll val; is >> val; x = val; return is;}
#endif

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

    ll N,M,Q; cin>>N>>M>>Q;

    //各クエリ２について，このあと最初に呼ばれるクエリ３を記録
    V<V<ll>> Points(Q);
    //i行目が最後に更新されたクエリ
    V<ll> lastUpdates(N, -1);

    V<array<ll,4>> Query(Q);
    rep(q,Q){
        ll t; cin>>t;
        if(t==1){
            ll l,r,x; cin>>l>>r>>x;
            l--, r--;
            Query[q] = {t,l,r,x};
        }
        else if(t==2){
            ll r,x; cin>>r>>x;
            r--;
            Query[q] = {t,r,x,0};
            lastUpdates[r] = q;
        }
        else{
            ll r,c; cin>>r>>c;
            r--,c--;
            Query[q] = {t,r,c,0};
            if(lastUpdates[r]!=-1){
                Points[lastUpdates[r]].push_back(q);
            }
        }
    }

    V<ll> R(N);
    V<ll> diff(Q);
    Lazy::LazyRSQ<ll> tree(M);
    rep(i,M) tree.set(i, {0, 1});
    rep(q,Q){
        ll t = Query[q][0];
        if(t==1){
            auto [t,l,r,x] = Query[q];
            tree.apply(l,r+1,{1,x});
        }
        else if(t==2){
            auto [t,r,x,_] = Query[q];
            R[r] = x;
            for(auto p:Points[q]){
                auto c = Query[p][2];
                diff[p] = tree.prod(c,c+1).x;
            }
        }
        else{
            auto [t,r,c,_] = Query[q];
            ll ans = tree.prod(c,c+1).x - diff[q];
            ans += R[r];
            PL(ans)
        }
    }
    EL(R)
    EL(diff)

    rep(c,M) ES(tree.prod(c,c+1).x)
    EL("")

    return;
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
    for(int tt = 0; tt<TT; tt++) solve();
    return 0;
}
