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


void solve(){
    ll N; cin>>N;
    V<ll> P(N); cin>>P;

    V<ll> dist(N);
    rep(i,N) dist[i] = (P[i]-i+N)%N;
    sort(RALL(dist));
    EL(dist)

    queue<ll> right;
    queue<ll> left;

    ll ans = LINF;
    ll right_sum = 0;
    ll left_sum = 0;

    rep(i,N){
        if(dist[i]<=N-dist[i]){
            right.push(dist[i]);
            right_sum += dist[i];
        }
        else{
            left.push(dist[i]);
            left_sum += dist[i];  
        }
    }

    repll(i,N){
        while(!right.empty()){
            ll r = right.front();
            r = (r+i+2*N)%N;
            if(r<=N-r) break;
            r = right.front();
            right_sum -= r;
            left_sum += r;
            left.push(r);
            right.pop();
        }
        while(!left.empty()){
            ll l = left.front();
            l = (l+i+2*N)%N;
            if(l>N-l) break;
            l = left.front();
            left_sum -= l;
            right_sum += l-N;
            right.push(l-N);
            left.pop();
        }
        ES(i)
        ll cand = right_sum+i*right.size();
        ES(cand) ES(right.size())
        cand += N*left.size()-(left_sum+i*left.size());
        ES(cand) EL(left.size())
        chmin(ans, cand);
    }
    PL(ans)

}


int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1; //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve();
   return 0;
}
