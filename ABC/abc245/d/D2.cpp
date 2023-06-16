#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
//const int MOD = 1000'000'007;

const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
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
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

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

void solve2(){
    vector<int> A = {1,6,9};
    vector<int> B = {1,3};
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    auto C = polyDivide(A,B);
    auto Q = C.first;
    auto R = C.second;
    reverse(Q.begin(), Q.end());
    reverse(R.begin(), R.end());
    PL(Q)
    EL(R)
}

void solve() {

    int n,m; cin>>n>>m;
    V<int> A(n+1), C(n+m+1);
    cin>>A;
    cin>>C;
    reverse(ALL(A));
    reverse(ALL(C));

    auto B = polyDivide(C, A);
    auto Q = B.first;
    auto R = B.second;
    reverse(Q.begin(), Q.end());
    reverse(R.begin(), R.end());
    PL(Q)
    EL(R)

    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
