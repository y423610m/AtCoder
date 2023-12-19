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
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream&, const std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream& os, const std::tuple<T...>& tup){if (n != 0){os << " ";} os << std::get<n>(tup); print_tuple<n+1>(os, tup);}
template <typename... T> std::ostream& operator<<(std::ostream& os, const std::tuple<T...>& tup) {print_tuple<0>(os, tup); return os;}
template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>&){}
template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type input_tuple(std::istream& is, std::tuple<T...>& tup){is>> std::get<n>(tup); input_tuple<n+1>(is, tup);}
template <typename... T> std::istream& operator>>(std::istream& is, std::tuple<T...>& tup) {input_tuple<0>(is, tup); return is;}
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

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/find.hpp>
//boost::to_upper(S);
//boost::algorithm::replace_all(S, "Hello", "Goodbye");
//boost::algorithm::replace_first(S, "Hello", "Goodbye");
//boost::algorithm::replace_last(S, "Hello", "Goodbye");
//auto it = boost::algorithm::find_first(S, "a"); it.begin(), it.end();
//boost::algorithm::erase(S, "Hello");
//boost::algorithm::erase_head(S, 6);
//https://www.boost.org/doc/libs/1_81_0/doc/html/string_algo/usage.html#id-1.3.3.5.6

#define endl "\n"

#include "utils/timer.hpp"
//Timer timer;
//if(timer.pass()) PL(timer.time())
//TIMER_LOG(timer, "comment")
//timer.print();

void solve1(){
   ll N,M; cin>>N>>M;
   string S,T; cin>>S>>T;

   string mask = string(M, '#');

   auto check = [&](int bgn){
      if(bgn+M>N) return false;
      if(bgn<0) return false;

      {//avoid all #
         bool ok = false;
         rep(i,M) if(S[bgn+i]!='#'){
            ok = true;
            break;
         }
         if(!ok) return false;
      }

      {//check
         rep(i,M) if(S[bgn+i]!='#' && S[bgn+i]!=T[i]) return false;
      }

      {//check sand
         ll l = bgn;
         ll r = bgn+M-1;
         while(S[l]=='#') l++;
         while(S[r]=='#') r--;
         for(;l<=r;l++) if(S[l]=='#') return false;
      }

      return true;
   };

   queue<ll> que;
   rep(i,N) que.push(i);

   set<ll> Bgn;

   while(!que.empty()){
      auto id = que.front();
      que.pop();

      if(check(id)){
         Bgn.insert(id);
         rep(i,M) S[id+i] = '#';
         rep(i,M){
            if(!Bgn.contains(id-1-i)) que.push(id-1-i);
            if(!Bgn.contains(id+1+i)) que.push(id+1+i);
         }
         ES(id) EL(S)
      }
      else{
         EL(id)
      }
   }
   EL(S)

   if(S==string(N, '#')) PL(Yes)
   else PL(No)
}

void solve() {

   Timer timer;

   ll N,M; cin>>N>>M;
   string S,T; cin>>S>>T;

   string after = string(M, '#');

   while(1){
      rep(i,M){
         rep(j,M) if(i+j<M) {
            string tmp = T;
            rep(k, i) tmp[k] = '#';
            rep(k, j) tmp[M-1-k] = '#';
            boost::algorithm::replace_all(S, tmp, after);
            // ES(i) ES(j) ES(tmp) EL(S)
         }
         if(timer.pass(500)) break;
      }
      if(timer.pass(500)) break;
   }

   while(1){
      rep(_,2){
         string tmp = T;
         if(_) rep(k,M-1) tmp[k] = '#';
         else rep(k,M-1) tmp[M-1-k] = '#';

         boost::algorithm::replace_first(S, tmp, after);
         boost::algorithm::replace_last(S, tmp, after);
         // ES(i) ES(j) ES(tmp) EL(S)
         
         if(timer.pass(1800)) break;
      }
      if(timer.pass(1800)) break;
   }

   if(S==string(N, '#')) PL(Yes)
   else PL(No)

}

void solve2() {

   ll N,M; cin>>N>>M;
   string S,T; cin>>S>>T;

   //SからABCを抜き続ける

   set<pair<ll, char>> st;
   set<ll> ids;
   rep(i,N){
      st.insert({i, S[i]});
      ids.insert(i);
   }

   queue<ll> que;
   rep(i,N) que.push(i);

   while(!que.empty()){
      ll id = que.front();
      que.pop();

      if(!ids.contains(id)) continue;

      auto it = st.lower_bound({id, 0});
      bool ok = true;
      rep(i,M){
         if(it==st.end()){
            ok = false;
            break;
         }

         if(it->se!=T[i]){
            ok = false;
            break;
         }

         it++;
      }

      if(ok){
         it = st.lower_bound({id, 0});
         ids.erase(it->se);
         st.erase(it);
      }
   }


   if(ids.size()==0) PL(Yes)
   else PL(No)

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
