#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

using ll = long long;
//__uint128_t
const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;

//#define _GLIBCXX_DEQUE_BUF_SIZE 512

// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define endl "\n"
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
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template<typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template<typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template<typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template<typename T, unsigned long int sz > ostream &operator<<(ostream &os, const array< T , sz > &v) {for(int i = 0; i < sz; i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template<typename T, unsigned long int sz > istream &operator>>(istream &is, array< T , sz > &v) {for(T& in:v){cin>>in;} return is;}
template<class T, class U > void chmin(T& t, const U& u) {if (t > u) t = u;}
template<class T, class U > void chmax(T& t, const U& u) {if (t < u) t = u;}

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

// vector<int> A = {1,2,3,2,1};
// LIS lis(A, true);
// EL(lis.size())
// EL(lis.example)
// EL(lis.example_ids)

// string s = "12321";
// LIS lis2(s, true);
// EL(lis2.example)

void solve() {

    ll N; cin>>N;
    V<ll> A(N); cin>>A;

    // LIS lis(A,false);
    // PL(lis.size())
    // EL(lis.example)

    V<ll> B;

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
