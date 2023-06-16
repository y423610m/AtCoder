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

ll Len(const string& T, ll k){
   deque<char> que;
   ll cnt = 0;
   ll ans = 0;
   rep(r,T.size()){
      if(T[r]=='x') cnt++;
      que.push_back(T[r]);
      while(cnt>k){
         if(que.front()=='x') cnt--;
         que.pop_front();
      }
      chmax(ans, que.size());
   }
   return ans;
}

void solve() {

   ll N,M,K;
   cin>>N>>M>>K;
   string S; cin>>S;

   ll cntO = 0, cntX = 0;
   rep(i,N){
      if(S[i]=='o') cntO++;
      else cntX++;
   }
   ES(cntX) EL(cntO)

   if(cntX*M<=K) END(N*M)

   ll ans1 = 0;
   ll m = K/cntX;
   if(m) m--;
   ans1 += m * N;
   K -= m*cntX;


   EL(ans1)
   EL(M)
   EL(m)
   EL(K)


   ll ans = ans1;

   rep(_,2){

      //尺取り
      string T;
      if(M-m==1) T = S;
      else if(M-m==2) T = S+S;
      else if(M-m==3) T = S+S+S;
      else  T = S+S+S+S;

      chmax(ans, ans1 + Len(T, K));

      // EL(T)

      // ll l = N, r = N;
      
      // //ひとまず広げる
      // ll cand = 0;
      // while(l-1>=0&&T[l-1]=='o') l--, cand++;
      // while(r+1<T.size()&&T[r+1]=='o') r++, cand++;
      // ES(0) ES(l) ES(r) EL(cand)

      // //Kになるまで左，右の順で広げる
      // ll cnt = 0;
      // while(1){
      //    if(l-1>=0&&T[l-1]=='x'&&cnt<K) cnt++, l--;
      //    while(l-1>=0&&T[l-1]=='o') l--, cand++;
      //    if(l-1<0||cnt==K) break;
      // }
      // while(1){
      //    if(r+1<T.size()&&T[r+1]=='x'&&cnt<K) cnt++, r++;
      //    while(r+1<T.size()&&T[r+1]=='o') r++, cand++;
      //    if(r+1>=T.size()||cnt==K) break;
      // }
      // ES(1) ES(l) ES(r) ES(cand) EL(cand+ans1+K)


      // chmax(ans, cand+ans1+K);

      // while(r+1<T.size()){
      //    //右端一つ
      //    r++;
      //    while(r+1<T.size()&&T[r+1]=='o') r++, cand++;
         
         
      //    while(l<=r&&T[l]!='x'){
      //       if(T[l]=='o') cand--;
      //       l++;
      //    }
      //    l++;
      //    // if(l<T.size()&&S[l]=='-') l++;
      //    chmax(ans, cand+ans1+K);
      //    ES(2) ES(l) ES(r) ES(cand) EL(cand+ans1+K)
      // }

      reverse(ALL(S));
      EL("reverse")
   }

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

/*
ABC300 5完
A for
B H*W回rotate
C #のマスから四方に伸ばし続ける
D 高々10**6程度までの素数見ればよくて，枝刈り3重ループ
E dp[x]=Σ(dp[x*i])/5 : i=2~6
F 尺取り．両端部分だけやろうとしたけど，サンプル３で詰まり，時間切れ．
高々両端２セットずつくらいみればできそう．
*/