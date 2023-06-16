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

struct Mex {
private:
  std::set<std::pair<int, int>> s;
 
public:
  Mex() {
    s.emplace(-INF, -INF);
    s.emplace(INF, INF);
  }
 
  bool contains(int x) const {
    auto it = std::prev(s.lower_bound(std::make_pair(x+1, x+1)));
    auto [l, u] = *it;
    return l <= x && x <= u;
  }
 
  bool insert(int x) {
    auto nit = s.lower_bound(std::make_pair(x+1, x+1));
    auto it = std::prev(nit);
    auto [l, u] = *it;
    auto [nl, nu] = *nit;
    if (l <= x && x <= u) return false;
    if (u == x-1) {
      if (nl == x+1) {
        s.erase(it);
        s.erase(nit);
        s.emplace(l, nu);
      } else {
        s.erase(it);
        s.emplace(l, x);
      }
    } else {
      if (nl == x+1) {
        s.erase(nit);
        s.emplace(x, nu);
      } else {
        s.emplace(x, x);
      }
    }
    return true;
  }
 
  int mex(int x = 0) const {
    auto [l, u] = *std::prev(s.lower_bound(std::make_pair(x+1, x+1)));
    if (l <= x && x <= u) {
      return u+1;
    } else {
      return x;
    }
  }
};

template<typename T, typename F>
T binSearch(T ok, T ng, F check){
    while(abs(ok-ng)>1){
        T mid = (ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}



void solve() {

    int N; cin>>N;
    ll M; cin>>M;
    V<ll> A(N); cin>>A;

    V<Mex> Nekoset(M);

    rep(i,N){
        if(A[i]>N) continue;
        if(A[i]+M*(i+1)<0) continue;

        auto check = [&](auto x){
            ES(i) ES(x) ES(A[i]) EL(A[i]+x*(i+1))
            if(0>A[i]+x*(i+1)) return true;
            return false;
        };

        ll l = binSearch(1LL, M+1, check);
        //ES(i) ES(A[i]) ES(l) EL(A[i]+l*(i+1))

        for(ll j=l;j<=M;j++){
            if(N<A[i]+j*(i+1)) break;
            if(A[i]+j*(i+1)<0) continue;
            Nekoset[j-1].insert(A[i]+j*(i+1));
        }
    }

    rep(i,M){
        PL(Nekoset[i].mex())
    }

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


/*
ABC272 解いた．遅め？5完
A:全部足す
B:全探索
C:偶奇分けして最大2要素の和
D:距離の2乗がMになる移動を予め全列挙O(M),あとは普通のbfs.
E:mexは[0,N]の範囲になる．調和級数になるので，NlogN.初めて[0,N]に含まれる操作回数探すのにlogN.全体でNlogNlogN.
*/