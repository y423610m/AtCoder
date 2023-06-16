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

#if __has_include(<atcoder/modint>)
#include <atcoder/modint>
using namespace atcoder;
// ostream &operator<<(ostream &os, const mint x) {os<<x.val();return os;}
// istream &operator>>(istream &is, mint& x){ll val; is >> val; x = val; return is;}
#endif

void solve() {

    ll N; cin>>N;
    string T; cin>>T;

    const ll p1 = 998'244'353;
    const ll p2 = 1000'000'007;

    using mint1 = atcoder::static_modint<p1>;
    using mint2 = atcoder::static_modint<p2>;


    mint1 A1 = 0;//正
    mint2 A2 = 0;//正
    mint1 B1 = 0;//反
    mint2 B2 = 0;//反

    rep(i,N){
        A1 = A1*7+T[i];
        A2 = A2*11+T[i];        
    }
    rep(i,N){
        B1 = B1*7+T[N*2-1-i];
        B2 = B2*11+T[N*2-1-i];
    }
    ES(A1.val()) EL(B1.val())

    rep(i,N){
        EL(i)
        if((A1==B1)&&(A2==B2)){
            string ans;
            rep(j,N) ans += T[N*2-1-i-j];
            PL(ans)
            END(N-(i))
        }
        if(i==N-1) continue;

        A1 += mint1(7).pow(i)*T[N*2-1-i];
        A1 -= mint1(7).pow(i)*T[N-1-i];
        A2 += mint2(11).pow(i)*T[N*2-1-i];
        A2 -= mint2(11).pow(i)*T[N-1-i];
        ES(T[N*2-1-i]) EL(T[N-1-i])

        B1 = B1*7;
        B1 -= mint1(7).pow(N)*T[N*2-1-i];
        B1 += T[N*2-1-i-N];
        B2 = B2*11;
        B2 -= mint2(11).pow(N)*T[N*2-1-i];
        B2 += T[N*2-1-i-N];
        ES(T[N*2-1-i]) EL(T[N*2-1-i-N])
    }


    END(-1)

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
