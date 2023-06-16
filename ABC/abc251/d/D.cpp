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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<int, int>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}


int pop_count(long long a, int b=2){
    int ret = 0;
    while(a){
        if(a%b)ret++;
        a/=b;
    }
    return ret;
}
// vector<ll> dgt10 = digit(100,10) -> {1,0,0}
// vector<ll> dgt10 = digit(100,10,false) -> {0,0,1}
// vector<ll> dgt2 = digit(100,2) -> {1,1,0,0,1,0,0}


long long POW(long long a, long long b, long long mod = 0){
   long long ret = 1;
   long long tmp = a;
   if(mod) tmp%=mod;
   while(b){
      if(b&1){
         ret *= tmp;
         if(mod) ret%=mod;
      }
      b /= 2;
      tmp *= tmp;
      if(mod) tmp%=mod;
   }
   return ret;
}

void solve3(){
    int w; cin>>w;
    V<int> ans;
    rep(i,3){
        rep(j,100){
            int a = POW(100,i) * (1+j);
            if(a<=w) ans.push_back(a);
        }
    }
    SORT(ans)
    ERASE(ans)
    PL(ans.size());
    PL(ans)

}
//leading
template <typename T> int clz(T a, int b=2){
    int ret = 0;
    while(a){
        ret++;
        a/=b;
    }
    return sizeof(a)*8-ret;
}
//trailing
int ctz(long long a, int b=2){
    int ret = 0;
    a ^= a;
    while(a){
        if(a%b==1) ret++;
        else break;
        a /= b;
    }
    return ret;
}

void solve4(){
    int n;cin>>n;
   // PL(-~n)
    PL(clz(n))
    PL("")
    PL(clz((ll)n))
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve4();
   return 0;
}


