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
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll,ll>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int N; cin>>N;
    V<Pll> P(N); cin>>P;

    int M; cin>>M;
    V<Pii> OP(M);
    rep(i,M){
        int op; cin>>op;
        int p = 0;
        if(op>=3) cin>>p;
        OP[i] = {op,p};
    }

    int Q; cin>>Q;
    V<V<Pii>> query(M+1);
    rep(i,Q){
        int a,b;
        cin>>a>>b;
        a, b--;
        query[a].push_back({b,i});
        //ES(a) EL(b)
    }

    V<Pll> ANS(Q);

    using T = array<array<ll, 3>,2>;

    auto rot90 = [&](const T& A)->T {
        auto ret = A;
        ret[0][0] = A[1][0];
        ret[0][1] = A[1][1];
        ret[1][0] =-A[0][0];
        ret[1][1] =-A[0][1];
        ret[0][2] = A[1][2];
        ret[1][2] =-A[0][2];
        return ret;
    };
    auto rot270 = [&](const T& A)->T {
        auto ret = A;
        ret[0][0] =-A[1][0];
        ret[0][1] =-A[1][1];
        ret[1][0] = A[0][0];
        ret[1][1] = A[0][1];
        ret[0][2] =-A[1][2];
        ret[1][2] = A[0][2];
        return ret;
    };
    auto moveXP = [&](const T& A, ll p)->T {
        auto ret = A;
        rep(i,3) ret[0][i] = - A[0][i];
        ret[0][2] += p*2;
        return ret;
    };
    auto moveYP = [&](const T& A, ll p)->T {
        auto ret = A;
        rep(i,3) ret[1][i] = - A[1][i];
        ret[1][2] += p*2;
        return ret;
    };

    auto calcPos = [&](const T& A, const Pll& X)->Pll {
        auto [x,y] = X;
        ll nx = A[0][0]*x+A[0][1]*y+A[0][2];
        ll ny = A[1][0]*x+A[1][1]*y+A[1][2];
        return Pll(nx, ny);
    };

    T A;
    A[0] = {1,0,0};
    A[1] = {0,1,0};

    for(auto[pid, qid]:query[0]){
        auto [nx, ny] = calcPos(A, P[pid]);
        ANS[qid] = {nx, ny};
        ES(nx) EL(ny)
    }
    rep(i,M){
        EL(i)

        //op[i]実行
        if(OP[i].fi==1) A = rot90(A);
        else if(OP[i].fi==2) A = rot270(A);
        else if(OP[i].fi==3) A = moveXP(A, OP[i].se);
        else if(OP[i].fi==4) A = moveYP(A, OP[i].se);


        //query実行
        for(auto[pid, qid]:query[i+1]){
            auto [nx, ny] = calcPos(A, P[pid]);
            ANS[qid] = {nx, ny};
            ES(nx) EL(ny)
        }
    }

    rep(q,Q){
        PL(ANS[q])
    }

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
