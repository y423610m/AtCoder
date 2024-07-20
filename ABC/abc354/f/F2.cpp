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
using Tiii = tuple<int, int, int>;
using Tiiii = tuple<int, int, int, int>;
using Pll = pair<ll,ll>;
using Tlll = tuple<ll,ll,ll>;
using Tllll = tuple<ll,ll,ll,ll>;
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

template <typename T>
struct LIS{
    size_t sz = 0;
    T example;
    vector<int> example_ids;
    vector<int> ids;
    vector<int> from;
    LIS(const T& A, bool strict)
    :from(A.size(), -1)
    {
        T B;
        auto it = B.end();
        for(int i=0;i<A.size();i++){
            if(strict) it = lower_bound(B.begin(), B.end(), A[i]);
            else       it = upper_bound(B.begin(), B.end(), A[i]);
            if(it==B.end()){
                B.push_back(A[i]);
                if(B.size()>1) from[i] = ids.back();
                ids.emplace_back(i);
            }
            else{
                
                int id = it-B.begin();
                if(B[id]==A[i]) continue;//ADD
                B[id] = A[i];
                ids[id] = i;
                if(id) from[i] = ids[id-1];
            }
            // EL(B)
            // EL(ids)
            // EL(from)
        }
        sz = B.size();

        if(B.size()==0) return;
        int id = ids.back();
        while(id!=-1){
            example.push_back(A[id]);
            example_ids.emplace_back(id);
            id = from[id];
        }
        reverse(example.begin(), example.end());
        reverse(example_ids.begin(), example_ids.end());
    }

    size_t size(){return sz;}

    // vector<int> A = {1,2,3,2,1};
    // LIS lis(A, true);
    // EL(lis.size())
    // EL(lis.example)
    // EL(lis.example_ids)

    // string s = "12321";
    // LIS lis2(s, true);
    // EL(lis2.example)
};



#define endl "\n"

void solve() {

   ll N; cin>>N;
   V<ll> A(N); cin>>A;

   LIS F(A, true);
   EL(F.example)
   EL(F.example_ids)

   auto invA = A;
   reverse(ALL(invA));
   rep(i,N) invA[i] = -A[i];
   LIS B(invA, true);
   rep(i,B.example.size()) B.example[i] = -B.example[i];
   rep(i,B.example_ids.size()) B.example_ids[i] = N-1-B.example_ids[i];
   reverse(ALL(B.example));
   reverse(ALL(B.example_ids));
   EL(B.example)
   EL(B.example_ids)

   if(B.exmaple.size()==1){
      PL(1)
      rep(i,N) PS(i+1);
      END("")
   }

   V<ll> ans(N, false);
   rep(i,F.example_ids.size()) ans[F.example_ids[i]] = true;
   rep(i,B.example_ids.size()) ans[B.example_ids[i]] = true;
   rep(i,N)if(!ans[i]){
      ll l = -LINF;
      ll r = LINF;
      //F
      {

      }


      // if(l<=i&&i<=r) ans[i] = true;
   }

   ll cnt= 0;
   rep(i,N) cnt += ans[i];
   PL(cnt)
   rep(i,N) if(ans[i]) PS(i+1)
   PL("")

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

/*

*/