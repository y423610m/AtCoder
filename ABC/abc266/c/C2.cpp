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





//pair同士
template<typename T, typename U> pair<T,U> operator+(const pair<T,U>& a, const pair<T,U>& b){return pair<T,U>(a.first+b.first, a.second+b.second);}
template<typename T, typename U> pair<T,U> operator-(const pair<T,U>& a, const pair<T,U>& b){return pair<T,U>(a.first-b.first, a.second-b.second);}
template<typename T, typename U> T inner_prod(const pair<T,U>& a, const pair<T,U>& b){return a.first*b.first + a.second*b.second;}
template<typename T, typename U> T outer_prod(const pair<T,U>& a, const pair<T,U>& b){return a.first*b.second - a.second*b.first;}
//スカラー
template<typename S, typename T, typename U> pair<T,U> operator+(const S s, const pair<T,U>& p){return pair<T,U>(s+p.first, s+p.second);}
template<typename S, typename T, typename U> pair<T,U> operator+(const pair<T,U>& p, const S s){return pair<T,U>(p.first+s, s+p.second+s);}
template<typename S, typename T, typename U> pair<T,U> operator-(const S s, const pair<T,U>& p){return pair<T,U>(s-p.first, s-p.second);}
template<typename S, typename T, typename U> pair<T,U> operator-(const pair<T,U>& p, const S s){return pair<T,U>(p.first-s, p.second-s);}
template<typename S, typename T, typename U> pair<T,U> operator*(const S s, const pair<T,U>& p){return pair<T,U>(s*p.first, s*p.second);}
template<typename S, typename T, typename U> pair<T,U> operator*(const pair<T,U>& p, const S s){return pair<T,U>(p.first*s, p.second*s);}
template<typename S, typename T, typename U> pair<T,U> operator/(const pair<T,U>& p, const S s){return pair<T,U>(p.first/s, p.second/s);}
//互いに素にする.int, llのみ
template<typename T> pair<T, T> coprime(pair<T, T> p, bool distinct_opposite = false){
    if(p.fi==0&&p.se==0) return p;
    else if(p.fi==0){p.se = (distinct_opposite?p.se/abs(p.se):1);}
    else if(p.se==0){p.fi = (distinct_opposite?p.fi/abs(p.fi):1);}
    else{//firstを正になるように
        T g = (distinct_opposite?gcd(p.fi, p.se):gcd(p.fi, p.se)*(p.fi/abs(p.fi)));
        p.fi/=g; p.se/=g;
    }
    return p;
}
//ノルム
template<typename T> T norm(const pair<T,T>& p){return sqrt(p.fi*p.fi+p.se*p.se);}
template<typename T> T norm2(const pair<T,T>& p){return p.fi*p.fi+p.se*p.se;}
//回転rad
template<typename T> pair<T,T> rotate(pair<T,T> p, double angle){return {p.fi*cos(angle)-p.se*sin(angle), p.fi*sin(angle)+p.se*cos(angle)};}



void solve() {

    int N = 4;
    V<Pii> C(N); cin>>C;
    rep(i,N){
        Pii v1 = C[(i+1)%N]-C[i];
        Pii v2 = C[(i+3)%N]-C[i];
        ES(i) EL(outer_prod(v1, v2))
        if(outer_prod(v1, v2)<0) END("No")
    }
    PL("Yes")

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
