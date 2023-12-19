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



// #define endl "\n"

void solve() {

   ll N;cin>>N;
   string S;cin>>S;
   string T;cin>>T;

   // {
   //    bool ok = true;
   //    rep(i,N) if(S[i]!='C' && T[i]=='C') END(No) 
   // }

   
   auto ok2 = [&](string& s, string& t)->bool {
      if(s.size()==0) return true;
      V<set<ll>> mp(3);
      rep(i,t.size()) mp[t[i]-'A'].insert(i);

      {
      V<ll> cntS(3), cntT(3);
      rep(i,s.size()) cntS[s[i]-'A']++;
      rep(i,t.size()) cntT[t[i]-'A']++;
      if(cntT[0]>cntS[0]+cntS[2]) return false;
      if(cntT[1]>cntS[1]+cntS[2]) return false;
      }

      V<ll> id(s.size(), -1);
      rep(i,s.size()){
         if(s[i]=='A'){
            id[i] = *mp[0].begin();
            mp[0].erase(mp[0].begin());
         }
         if(s[i]=='B'){
            id[i] = *mp[1].begin();
            mp[1].erase(mp[1].begin());
         }
      }
      rep(i,s.size()){
         if(s[i]=='C'){
            if(!mp[0].empty()){
               id[i] = *mp[0].begin();
               mp[0].erase(mp[0].begin());
               s[i] = 'A';
            }
            else{
               id[i] = *mp[1].begin();
               mp[1].erase(mp[1].begin());
               s[i] = 'B';
            }
         }
      }
      EL(id)
      EL(s)

      sort(ALL(id), [&](int l, int r){
         if(s[l]==s[r]) return l < r;
         if(s[l]=='A'&&s[r]=='B'){
            return l < r;
         }
         return false;
      });
      EL(id)
      string tmp;
      rep(i,s.size()) tmp += t[id[i]];
      rep(i,tmp.size()-1) if(tmp.substr(i,2)=="AB"&&t.substr(i,2)=="BA") swap(tmp[i], tmp[i+1]);
      // EL((tmp))
      // rep(i,id.size()-1) if(id[i+1] != id[i]+1) return false;


      // string tmp;
      // rep(i,s.size()) tmp += s[id[i]];
      // ES(tmp) EL(t)
      // return tmp == t;
      // rep(i,s.size()) if(s[id[i]]!=t[i]) return false;
      // ES(s) EL(t)
      // V<ll> cntS(3), cntT(3);
      // rep(i,s.size()) cntS[s[i]-'A']++;
      // rep(i,t.size()) cntT[t[i]-'A']++;
      // if(cntT[0]>cntS[0]+cntS[2]) return false;
      // if(cntT[1]>cntS[1]+cntS[2]) return false;
      // if(t[0]=='A' && s[0]=='B') return false;
      return true;
   };

   auto ok = [&](string& s, string& t)->bool {
      map<char, ll> cntS;
      map<char, ll> cntT;
      rep(i,s.size()) cntS[s[i]]++;
      rep(i,t.size()) cntT[t[i]]++;
      if(cntS['A'] > cntT['A']) return false;
      if(cntS['B'] > cntT['B']) return false;
      rep(i,s.size()) if(s[i]=='C'){
         if(cntS['A'] < cntT['A']){
            s[i] = 'A';
            cntS['A']++;
         }
         else{
            s[i] = 'B';
         }
      }

      ll cs = 0;
      ll ct = 0;
      for(ll i=s.size()-1;i>=0;i--){
         cs += s[i] == 'A';
         ct += t[i] == 'A';
         if(cs > ct) return false;
      }
      return true;
   };

   string s;
   string t;
   rep(i,N){
      if(T[i]=='C'){
         if(S[i]!='C') END(No)
         if(!ok(s, t)) END(No)
         s.clear();
         t.clear();
      }
      else{
         s += S[i];
         t += T[i];
      }
   }
   if(!ok(s,t)) END(No)
   PL(Yes)

   return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);//小数点以下
   // std::cout << std::setbase(16);//8進数表示.8,10,16のみ
   // stoll(s,nullptr,base);
   int TT = 1;
   cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
