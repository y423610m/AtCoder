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

vector<ll> enumDivs(ll n, bool sorten=true){
    vector<ll> result;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            result.push_back(i);
            if(i*i!=n) result.push_back(n/i);
        }
    }
    if(sorten) sort(result.begin(), result.end());
    return result;
}

map<ll, ll> prime_factor(ll n){
    map<ll, ll> res;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) res[n]++;
    return res;
}

void solve() {

    ll N;cin>>N;

    auto divs = enumDivs(N);
    ll ans = 0;
    for(auto d:divs){
        if(d==1) continue;
        if(N%d==0){
            N/=d;
            ans++;
        }
    }
    PL(ans)

    return;
}

void solve2(){
    ll N;cin>>N;
    if(N<=1) END(0)

    auto divs = enumDivs(N);
    EL(divs)
    EL(divs.size())
    //dp[i][j]:=i番目まで使って，積がjとなる最小値
    V<V<ll>> dp(divs.size()+1, V<ll>(divs.size(),-LINF));
    dp[1][0] = 0;

    repi(i,1,divs.size()){
        dp[i+1] = dp[i];
        rep(j,divs.size()){
            if(divs[i]*divs[j]<=N){
                ll to = lower_bound(ALL(divs), divs[i]*divs[j])-divs.begin();
                chmax(dp[i+1][to], dp[i][j]+1);
            }
            else break;
            if(divs[i]*divs[j]==N) break;
        }
    }
    PL(dp[divs.size()][divs.size()-1])

    rep(i,divs.size()+1) EL(dp[i])
}

void solve3(){
    ll N; cin>>N;
    map<ll,ll> factors = prime_factor(N);

    ll ans = 0;
    for(auto [P,E]:factors){
        ll p = P;
        while(N%p==0){
            N /= p;
            p *= P;
            ans++;
        }
    }
    PL(ans)
}

//pair<Q, R> = pair< A/B, A%B > 0項目が最大次数
pair<vector<int>, vector<int>> polyDivide(vector<int> A, vector<int> B){
    //preprocessing
    if(A[0]==0){
        reverse(A.begin(), A.end());
        while(A.back()==0) A.pop_back();
        reverse(A.begin(), A.end());
    }
    if(B[0]==0){
        reverse(B.begin(), B.end());
        while(B.back()==0) B.pop_back();
        reverse(B.begin(), B.end());
    }
    
    //ans
    int lenA = A.size();
    int lenB = B.size();
    vector<int> Q;
    for(int i=0;i+lenB<=lenA;i++){
        int q = 0;
        if(A[i]!=0){
            q = A[i]/B[0];
            for(int j=0;j<lenB;j++){
                A[i+j] -= q*B[j];
            }
        }
        Q.push_back(q);
    }

    vector<int> R = A;
    if(!R.empty() && R[0]==0){
        reverse(R.begin(), R.end());
        while(!R.empty() && R.back()==0) R.pop_back();
        reverse(R.begin(), R.end());
    }

    return {Q, R};

}

//vector<int> A = {1,6,9};
//vector<int> B = {1,3};
//reverse(A.begin(),A.end());
//reverse(B.begin(),B.end());
//auto C = polyDivide(A,B);
//auto Q = C.first;
//auto R = C.second;
//reverse(Q.begin(), Q.end());
//reverse(R.begin(), R.end());
//PL(Q) // 1 3
//EL(R) // あまりないのでsize=0

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve3();
   return 0;
}
