#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
// __uint128_t
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;

constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";

// #define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
// #define ONLINE_JUDGE 1
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
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template<typename T> using V = vector<T>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, unsigned long int sz> using Ar = array< T , sz >;
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
template<typename T, typename U> void operator++(pair<T, U>& p){p.first++, p.second++;}//pre
template<typename T, typename U> void operator++(pair<T, U>& p, int){p.first++, p.second++;}//post
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

// #include "sort/merge_sort.hpp"

void solve() {

   ll N; cin>>N;
   V<ll> A(N); cin>>A;
   A--;

   auto B = A;
   sort(ALL(B));
   EL(B)

   V<set<ll>> pos(4);
   rep(i,N) pos[A[i]].insert(i);

   V<Pll> ranges(4);
   rep(i,4){
      ranges[i].fi = lower_bound(ALL(B), i) - B.begin();
      ranges[i].se = lower_bound(ALL(B), i+1) - B.begin();
   }

   ll ans = 0;


   auto check = [&](int i)->void {
      if(A[i]==B[i]) return;
      EL("")
      EL(A)

      /*
      B[i]がある場所のうち，A[i]がいるべき場所に答えがあれば，それ採用
      */
      // 判別する
      auto it = pos[B[i]].lower_bound(ranges[A[i]].fi);
      if(it!=pos[B[i]].end()){
         ll p = *(it);
         EL(p)
         if(p<ranges[A[i]].se){
            //swap!!
            pos[A[i]].erase(i);
            pos[B[i]].erase(p);
            pos[A[i]].insert(p);
            pos[B[i]].insert(i);
            swap(A[i], A[p]);
            ans++;
            EL("good")
            ES(i) EL(p)
            EL(A) 
         }
      }
   };


   rep(i,N){
      check(i);
   }

   rep(i,N){
      if(A[i]==B[i]) continue;
      EL("")
      EL(A)
      //適当に交換
      auto it = pos[B[i]].lower_bound(i);
      // if(it==pos[B[i]].end()) END("?????")
      assert(it!=pos[B[i]].end());
      ll p = *it;
      pos[A[i]].erase(i);
      pos[B[i]].erase(p);
      pos[A[i]].insert(p);
      pos[B[i]].insert(i);
      swap(A[i], A[p]);
      ans++;
      EL("normal")

      check(p);
   }
   EL(A)
   PL(ans)

   return;
}

void solve2(){
   ll N; cin>>N;
   V<ll> A(N); cin>>A;
   A--;
   auto B = A;
   sort(ALL(B));

   V<V<ll>> cnt(4, V<ll>(4));
   rep(i,N){
      cnt[A[i]][B[i]]++;
   }
   rep(i,4) EL(cnt[i])


   ll ans = 0;
   rep(i,4) rep(j,4) if(i!=j){
      ll tmp = min(cnt[i][j], cnt[j][i]);
      cnt[i][j] -= tmp;
      cnt[j][i] -= tmp;
      ans += tmp;
   }
   EL(ans)

   rep(i,4){
      rep(j,4) if(i!=j){
         rep(k,4) if(i!=k&&j!=k){
            ll tmp = min(min(cnt[i][j], cnt[j][k]), cnt[k][i]);
            cnt[i][j] -= tmp;
            cnt[j][k] -= tmp;
            cnt[k][i] -= tmp;
            ans += tmp*2;
         }
      }
   }
   EL(ans)

   rep(i,4){
      rep(j,4) if(i!=j){
         rep(k,4) if(i!=k&&j!=k){
            rep(l,4)if(i!=l&&j!=l&&k!=l){
               ll tmp = min(min(cnt[i][j], cnt[j][k]), min(cnt[k][l], cnt[l][i]));
               cnt[i][j] -= tmp;
               cnt[j][k] -= tmp;
               cnt[k][l] -= tmp;
               cnt[l][i] -= tmp;
               ans += tmp*3;
            }
         }
      }
   }
   EL(ans)

   PL(ans)
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve2();
   return 0;
}

/*
ABC302 6完
A (A+B-1)/B
B ４重for
C dfs
D sortしてlower, upper bound
E setで辺を管理して愚直にやる
F 1を含む集合からの，複数始点bfs
G 前から交換していけば行けそうと思ったけどそうでもなかった．
*/