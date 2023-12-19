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

void solve() {

   ll N; cin>>N;
   V<Ar<ll,6>> XYZ(N); cin>>XYZ;

   V<ll> ans(N);
   rep(i,N){
      auto [x1,y1,z1, x2, y2, z2] = XYZ[i];
      repi(j,i+1,N){
         auto [X1,Y1,Z1, X2, Y2, Z2] = XYZ[j];

         bool ok = false;

         // x
         if(x1==X1||x1==X2||x2==X1||x2==X2){
            if(max(y1, Y1) < min(y2, Y2) && max(z1, Z1) < min(z2, Z2)) ok = true;
         }
         // y
         if(y1==Y1||y1==Y2||y2==Y1||y2==Y2){
            if(max(x1, X1) < min(x2, X2) && max(z1, Z1) < min(z2, Z2)) ok = true;
         }
         // z
         if(z1==Z1||z1==Z2||z2==Z1||z2==Z2){
            if(max(y1, Y1) < min(y2, Y2) && max(x1, X1) < min(x2, X2)) ok = true;
         }

         if(ok) ans[i]++, ans[j]++;
      }
   }

   rep(i,N) PL(ans[i])

   return;
}

void solve2(){
   ll N; cin>>N;
   V<Ar<ll,6>> XYZ(N); cin>>XYZ;

   V<ll> ans(N);

   ll M = 101;
   V<V<V<ll>>> X(M, V<V<ll>>(M+1, V<ll>(M+1, -1)));
   V<V<V<ll>>> Y(M, V<V<ll>>(M+1, V<ll>(M+1, -1)));
   V<V<V<ll>>> Z(M, V<V<ll>>(M+1, V<ll>(M+1, -1)));

   rep(i,N){
      auto [x1,y1,z1, x2, y2, z2] = XYZ[i];
      set<int> st;
      repi(x,x1,x2) repi(y,y1,y2){
         if(Z[z1][x][y]!=-1) st.insert(Z[z1][x][y]); 
         if(Z[z2][x][y]!=-1) st.insert(Z[z2][x][y]); 
         Z[z1][x][y] = i;
         Z[z2][x][y] = i;
      }
      repi(z,z1,z2) repi(y,y1,y2){
         if(X[x1][z][y]!=-1) st.insert(X[x1][z][y]); 
         if(X[x2][z][y]!=-1) st.insert(X[x2][z][y]); 
         X[x1][z][y] = i;
         X[x2][z][y] = i;
      }
      repi(x,x1,x2) repi(z,z1,z2){
         if(Y[y1][x][z]!=-1) st.insert(Y[y1][x][z]); 
         if(Y[y2][x][z]!=-1) st.insert(Y[y2][x][z]); 
         Y[y1][x][z] = i;
         Y[y2][x][z] = i;
      }
      ans[i] += st.size();
      for(auto a:st) ans[a]++;
      EL(ans)
   }
   rep(i,N) PL(ans[i])
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
