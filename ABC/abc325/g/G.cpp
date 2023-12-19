#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long int;
using ld = long double;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
constexpr ll MOD = 998'244'353;
// constexpr ll MOD = 1000'000'007;
// #define _GLIBCXX_DEQUE_BUF_SIZE 512
// #pragma comment(linker, "/stack:1000000000")


//mint


// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
constexpr ll INF = (1LL<<30)-1;
constexpr ll LINF = (1LL<<62)-1;
string Yes = "Yes";
string No = "No";

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
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
template<typename T> ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T> istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T> void operator--(vector<T>& A){for(auto& a:A) a--;}//pre
template<typename T> void operator--(vector<T>& A, int){for(auto& a:A) a--;}//post
template<typename T> void operator++(vector<T>& A){for(auto& a:A) a++;}//pre
template<typename T> void operator++(vector<T>& A, int){for(auto& a:A) a++;}//post
template<typename T, typename U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template<typename T, typename U> void chmax(T& t, const U& u) {if (t < u) t = u;}
template<typename T, typename U, typename S> void chmm(T& t, const U& u, const S& s) {if(t < u){t = u;} if(t > s){t = s;}}//clamp



#define endl "\n"

void solve(){
   try{
      string S; cin>>S;
      ll N = S.size();
      ll K; cin>>K;

      //dp[i][j]:=[i,j)を何文字にできるか
      V<V<ll>> dp(N+1, V<ll>(N+1, LINF));
      rep(l,N+1){
         rep(r,N+1){
            dp[l][r] = max(r-l, 0LL);
         }
      }

      repi(d,1,N+1){
         // rep(l,N){
         for(ll l=N-1;l>=0;l--){
            ll r = l+d;
            if(r>N) continue;
            for(ll m=l;m<=r;m++) chmin(dp[l][r], dp[l][m]+dp[m][r]);
            if(S[l]!='o') continue;
            if(S[r-1]!='f') continue;
            if(dp[l+1][r-1]==0){
               chmin(dp[l][r], 0);
               for(ll dr=1;r+dr<=N;dr++){
                  ll k = dr;
                  chmin(k, K);
                  chmin(dp[l][r+dr], max(0LL, dp[r][r+dr]-k));
               }
               // for(ll dr=1;dr<=K && r+dr<=N ;dr++) chmin(dp[l][r+dr], 0);
            }
         }
      }

      // for(ll l=N-1;l>=0;l--){
      //    for(ll r=l+2;r<=N;r++){
      //       for(ll m=l+1;m<r;m++) chmin(dp[l][r], dp[l][m]+dp[m][r]);
      //       for(ll m=l+1;m<r;m++){
      //          if(S[l]!='o') continue;
      //          if(S[m]!='f') continue;

      //       }
      //       if(S[l]!='o') continue;
      //       if(S[r-1]!='f') continue;
      //       if(dp[l+1][r-1]==0){
      //          chmin(dp[l][r], 0);
      //          for(ll dr=1;dr<=K && r+dr<=N;dr++) chmin(dp[l][r+dr], 0);
      //       }
      //    }
      // }

      rep(l,N+1){
         ES(l) EL(dp[l])
      }

      PL(dp[0][N])
   }
   catch(const exception& e){
      throw exception();
   }

}

void solve2() {

   string S; cin>>S;
   ll N  = S.size();
   ll K; cin>>K;K+=2;

   map<ll, Pll> mp;//isOf, len
   rep(i,S.size()){
      if(i+1<N && S.substr(i,2)=="of"){
         mp[i] = {true, 2};
         i++;
         continue;
      }
      else{
         if(mp.empty()) mp[0] = {false, 1};
         else {
            // back()  -> Pll -> len
            prev(mp.end())->se.se++;
         }
      }
   }
   // if(mp.)

   ll id = N;
   ll r = 0;
   while(!mp.empty()){
      auto it = prev(mp.end());
      chmin(id, it->fi);

      auto [isOf, len] = (it->se);
      if(!isOf){
         r += len;
         mp.erase(id);
      }
      else{
         if(K > len) r -=  max(r, K-len);
         else r += len-K;
         mp.erase(id);
      }
   }

   PL(r)

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
