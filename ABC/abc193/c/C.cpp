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

vector<ll> enumPrimes(int n){
    vector<ll> ret;
    if(n<2) return ret;
    vector<bool> prime(n+1, true);
    prime[0]=false;
    prime[1]=false;
    for(ll i=0;i<prime.size();i++){
        if(prime[i]){
            ret.push_back(i);
            for(ll j=2*i;j<prime.size();j+=i){
                prime[j]=false;
            }
        }
    }
    return ret;
}

vector<ll> enumPrimes(ll l, ll r){
    vector<ll> ret;
    if(l<2) l=2;
    if(l>r) return ret;
    vector<bool> prime_small((int)sqrt(r)+2, true);
    vector<bool> prime_big(r-l+1, true);
    prime_small[0]=false;
    prime_small[1]=false;
    for(ll i=0;i<prime_small.size();i++){
        if(prime_small[i]){
            for(ll j=2*i;j<prime_small.size();j+=i){
                prime_small[j]=false;
            }
            for(ll j=max(2*i,(l/i)*i);j<=r;j+=i){
                if(l<=j) prime_big[j-l] = false;
                //cout<<"loop"<<j<<endl;
            }
        }
    }
    for(ll i=l;i<=r;i++) if(prime_big[i-l]){
        cout<<i<<endl;
        ret.push_back(i);
    }
    return ret;
}


void solve() {

    ll N; cin>>N;

    auto P = enumPrimes(N);

    ll ans = N;
    for(auto p:P){
        ll q = p*p;
        while(q<=N){
            ans --;
            q *= p;
            ES(p) ES(q) EL(ans)
        }
    }
    rep(i,P.size()){
        ans -= P.end()-lower_bound(P.begin()+i+1, P.end(), N/P[i]);
    }
    PL(ans)

    return;
}

void solve2(){
    
    ll N; cin>>N;
    V<bool> done(sqrt(N)+1);

    ll ans = N;
    for(ll i=2;i*i<=N;i++){
        if(!done[i]){
            for(ll j=i;j<=done.size();j+=i){
                done[j] = true;
            }
            ans -= max(0LL, N/i-1);
            ES(i) EL(ans)
        }
    }
    PL(ans)

}

void solve3(){
    ll N; cin>>N;
    set<ll> st;
    for(ll i=2;i*i<=N;i++){
        ll x = i*i;
        while(x<=N){
            st.insert(x);
            x *= i;
        }
    }
    PL(N-st.size())
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
