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

template <typename T> vector<T> CCompress(vector<T>& A){
   vector<T> B = A;
   sort(B.begin(), B.end());
   B.erase(unique(B.begin(), B.end()), B.end());
   for(int i=0;i<(int)A.size();i++){
      A[i] = (int)(lower_bound(B.begin(), B.end(), A[i]) - B.begin());
   }
   return B;
}
//vector<int> A = {1,100,5,5};
//auto B = CCompress(A);
//-> A={0,2,1,1}, B={1,5,100}

//重複を許さない座標圧縮．同じ数字は先出から割り振る
template<typename T>
void reorder(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(auto& a:A){
        auto it = lower_bound(B.begin(), B.end(), a);
        a = it - B.begin();
        (*it)--;
    }
}

//重複を許さない座標圧縮．同じ数字は後方から割り振る
template<typename T>
void reorder_rev(vector<T>& A){
    vector<T> B = A;
    sort(ALL(B));
    for(int i=A.size()-1;i>=0;i--){
        auto it = lower_bound(B.begin(), B.end(), A[i]);
        A[i] = it - B.begin();
        (*it)--;
    }
}

void solve() {

   ll N; cin>>N;
   
   V<ll> R(N), C(N), X(N);
   rep(i,N) cin>>R[i]>>C[i]>>X[i];

   auto dictR = CCompress(R);
   auto dictC = CCompress(C);

   V<Ar<ll,3>> RC(N);
   rep(i,N) RC[i] = {R[i], C[i], i};
   sort(ALL(RC));

   V<Pll> sumR(dictR.size()), sumC(dictC.size());
   rep(i,N){
      sumR[R[i]].fi += X[i];
      sumC[C[i]].fi += X[i];
   }
   rep(r,dictR.size()) sumR[r].se = r;
   rep(c,dictC.size()) sumC[c].se = c;


   ll ans = 0;
   rep(i,N){
      ll cand = sumR[R[i]].fi + sumC[C[i]].fi - X[i];
      chmax(ans, cand);
   }

   // r行目を選んだ時の最大値を知りたい
   // sort(RALL(sumR));
   sort(RALL(sumC));
   rep(i, sumR.size()){
      auto [sr, r] = sumR[i];
      //if(sr+sumC[0].fi<ans) break;
      rep(j, sumC.size()){
         auto [sc, c] = sumC[j];
         ll cand = sr + sc;
         if(cand<ans) break;
         
         auto it = lower_bound(ALL(RC), Ar<ll,3>{r, c, 0});
         if(it!=RC.end()&&(*it)[0]==r&&(*it)[1]==c){
            cand -= X[(*it)[2]];
         }
         chmax(ans, cand);
         if(it==RC.end()) break;

      }
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
