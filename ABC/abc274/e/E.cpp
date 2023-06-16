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
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

using Pdd = pair<double, double>;

double calcDist(const Pii& a, const Pii& b){
    return sqrt( 1.0*(a.fi-b.fi)*(a.fi-b.fi) + 1.0*(a.se-b.se)*(a.se-b.se) );
}
//1の数
//__builtin_popcount()
//__builtin_popcountll()
//下から初めて1が現れる場所(1-indexed)
//__builtin_ffs()
//__builtin_ffsll()
//先頭に何個0があるか
//__builtin_clz()
//__builtin_clzll()
//末尾に何個0があるか
//__builtin_ctz()
//__builtin_ctzll()
void solve() {

    int N,M; cin>>N>>M;

    V<Pii> Pos(N+M); cin>>Pos;
    Pos.push_back({0,0});

    using P = pair<double, vector<int>>;

    int mask = 0;
    rep(i,N) mask |= (1<<i);

    double ans = 1e18;
    queue<P> que;//time, velo, last, visited
    que.push({0.,{1, N+M, 0}});

    //unordered_map<int, V<double>> minTime;
    V<V<V<double>>> minTime(33);
    V<int> v = {1,2,4,8,16,32};
    rep(i,6){
        minTime[v[i]] = V<V<double>>(N+M+1, V<double>(1<<(N+M), 1e18));
    }


    while(!que.empty()){
        double t = que.front().fi;
        int vel = que.front().se[0];
        int p = que.front().se[1];
        int visited = que.front().se[2];
        // double vel = que.front().fi.se;
        // int p = que.front().se.fi;
        // int visited = que.front().se.se;
        que.pop();

        ES(t) ES(vel) ES(p) EL(visited)

        if(t>ans) continue;
        if(minTime[vel][p][visited]<t) continue;


        if(p>=N&&p!=N+M){
            vel *= 2;
        }

        // if(__builtin_popcount(visited)==N+M){
        if((visited&mask)==mask){
            chmin(ans, t+calcDist(Pos[N+M], Pos[p])/vel);
            continue;
        }

        rep(i,N+M) if((visited&(1<<i))==0){
            double dt = calcDist(Pos[p], Pos[i])/vel;
            if(t+dt<minTime[vel][p][visited|(1<<i)]){
                minTime[vel][p][i] = t+dt;
                que.push({t+dt, {vel, i, visited|(1<<i)}});
                rep(j,v.size()){
                    if(v[j]==vel) break;
                    chmin(minTime[v[j]][p][visited|(1<<i)], t+dt);
                }

            }
        }
    }

    PL(ans)

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

