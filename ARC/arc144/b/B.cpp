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


void solve() {

    int N; cin>>N;
    ll a,b; cin>>a>>b;
    V<ll> A(N); cin>>A;
    sort(ALL(A));

    ll ans = -LINF;

    //すべての要素をx以上にする
    auto check = [&](auto x){
        //増やした回数
        ll cnt = 0;
        ll m = LINF;
        rep(i,N){
            ll Ai = A[i];
            if(Ai<x){
                //増やす
                cnt += (x-Ai+a-1)/a;
                Ai += (x-Ai+a-1)/a*a;
            }
            if(Ai>x){
                //減らす
                cnt -= (Ai-x)/b;
                Ai -= (Ai-x)/b*b;
            }
            //ES(Ai)

            chmin(m, Ai);
            ES(Ai)
        }

        ES(x) ES(m) EL(cnt)

        if(cnt<=0){
            chmax(ans, m);
            return true;
        }
        return false;
    };

    ll result = binSearch(A[0], A.back(), check);
    //if(a==b) END(-1)
    //PL(ans)
    PL(result)

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
