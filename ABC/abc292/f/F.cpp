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
template<class T,class U> struct std::hash<std::pair<T,U>>{size_t operator()(const std::pair<T,U> &p) const noexcept {return (std::hash<T>()(p.first)+1) ^ (std::hash<U>()(p.second)>>2);}};
template<typename T, unsigned long int sz> ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz> istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A){for(auto& a:A){a--;}}//pre
template<typename T, unsigned long int sz> void operator--(array< T , sz > &A, int){for(auto& a:A){a--;}}//post
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A){for(auto& a:A){a++;}}//pre
template<typename T, unsigned long int sz> void operator++(array< T , sz > &A, int){for(auto& a:A){a++;}}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp

using ld = long double;
ld eps = 1e-10;

template<typename T, typename F>
T binSearch(T ok, T ng, F check){
    while(abs(ok-ng)>eps){
        T mid = (ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}



void solve() {

    ld A,B; cin>>A>>B;
    if(A<B) swap(A,B);

    //A>=B


    //1辺xの正三角形が正方形に入るかどうか
    auto check = [&](auto x){
        EL(x)

        auto checkA = [&](auto angle){
            if(x*cosl(angle)<=A) return true;
            else return false;
        };
        auto checkB = [&](auto angle){
            if(x*sinl(angle)<=B) return true;
            else return false;
        };
        auto a = binSearch(ld(M_PI/2), ld(0.0), checkA);
        auto b = binSearch(ld(0.0), ld(M_PI/2), checkB);
        if(b-a<M_PI/3) return false;

        if(x*cosl(a)>A||x*sinl(a)>B) return false;
        if(x*cosl(b)>A||x*sinl(b)>B) return false;
        return true;
    };

    auto ans = binSearch(ld(0.0), hypot(A,B), check);
    PL(ans)

    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);//小数点以下
    // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
    // stoll(s,nullptr,base);
    int TT = 1;
    //cin>>TT;
    for(int tt = 0; tt<TT; tt++) solve();
    return 0;
}
