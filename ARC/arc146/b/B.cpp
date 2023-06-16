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
#define fi first
#define se second
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

template<typename T, typename F>
T binSearch(T ok, T ng, F check){
    while(abs(ok-ng)>1){
        T mid = (ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}

int NN, MM, KK;
V<int> AA;
ll ANS = 0;

void input(){
    cin>>NN>>MM>>KK;
    AA.resize(NN);
    cin>>AA;
}

//二分探索->単調性なし？
void solve() {

    int N,M,K;
    N = NN;
    M = MM;
    K = KK;
    V<int> A = AA;

    //mにするために必要な操作回数計算，M以下ならtrue
    auto check = [&](auto m){
        // EL(m)
        V<int> ms(N);
        rep(i,A.size()){
            if(m>A[i]) ms[i] = m-A[i];
            else{
                int mA = m&A[i];
                ms[i] = m - mA;
            }
        }
        // EL(ms)
        sort(ALL(ms));
        ll op = 0;
        rep(i,K) op += ms[i];

        if(op<=M){
            ES(m) EL(op)
            return true;
        }
        return false;
    };

    int ans = binSearch(0, INF, check);
    chmax(ANS,ans);


    return;
}

//最大のK個使用->当然ダメ
void solve2(){
    int N,M,K;
    N = NN;
    M = MM;
    K = KK;
    V<int> A = AA;

    sort(RALL(A));

    //最大いくつまでできるか検証
    V<int> B(K);
    rep(i,K) B[i] = A[i];
    sort(ALL(B));
    //mにするために必要な操作回数計算，M以下ならtrue
    auto check = [&](auto m){
        ll op = 0;
        rep(i,B.size()){
            if(m>B[i]) op += m-B[i];
        }
        if(op<=M){
            ES(m) EL(op)
            return true;
        }
        return false;
    };

    int ans = binSearch(B[0], INF, check);

    chmax(ANS,ans);


}

//全探索
void solve3() {

    int N,M,K;
    N = NN;
    M = MM;
    K = KK;
    V<int> A = AA;

    V<Pii> ms(A.size());//必要変化量,id
    //mにするために必要な操作回数計算，M以下ならtrue
    auto check = [&](auto m){
        // EL(m)
        rep(i,A.size()){
            if(m>A[i]) ms[i] = {m-A[i], i};
            else{
                int mA = m&A[i];
                ms[i] = {m-mA, i};
            }
        }
        // EL(ms)
        sort(ALL(ms));
        ll op = 0;
        rep(i,K) op += ms[i].fi;

        if(op<=M){
            M -= op;
            rep(i,K) A[ms[i].se] += ms[i].fi;
            if(A.size()>K){
                vector<int> B;
                rep(i,K) B.push_back(A[ms[i].se]);
                swap(A,B);
                while(ms.size()>K) ms.pop_back();
            }
            return true;
        }
        return false;
    };

    //EL(check(42))

    int ans = 0;
    for(int i=31;i>=0;i--){
        if(check(ans|(1<<i))){
            ans |= (1<<i); 
        }
        EL(A)
    }
    chmax(ANS,ans);



    return;
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   input();
   solve();
   solve2();
   solve3();
   PL(ANS)
   return 0;
}
