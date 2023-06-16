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



void solve() {

    int N; cin>>N;
    ll W; cin>>W;

    ll sum = 0;
    multiset<Pii> st;
    rep(i,N){
        int s,t,p;
        cin>>s>>t>>p;
        st.insert({s,p});
        st.insert({t,-p});
    }

    for(auto& p:st){
        sum += p.se;
        ES(p.fi) ES(p.se) EL(sum)
        if(sum>W) END("No")
    }

    PL("Yes")

    return;
}

void solve2() {

    int N; cin>>N;
    ll W; cin>>W;

    ll sum = 0;
    map<int, ll> mp;
    rep(i,N){
        int s,t,p;
        cin>>s>>t>>p;
        mp[s] += p;
        mp[t] -= p;
    }

    for(auto& p:mp){
        sum += p.se;
        ES(p.fi) ES(p.se) EL(sum)
        if(sum>W) END("No")
    }

    PL("Yes")

    return;
}

void solve3(){
    int N; cin>>N;
    ll W; cin>>W;

    ll sum = 0;
    unordered_map<int,ll> mp;
    V<int> Time(2*N);
    //map<int, ll> mp;
    rep(i,N){
        int s,t,p;
        cin>>s>>t>>p;
        mp[s] += p;
        mp[t] -= p;
        Time[i*2] = s;
        Time[i*2+1] = t;
    }

    sort(ALL(Time));
    ERASE(Time);

    for(auto& t:Time){
        sum += mp[t];
        ES(t) ES(mp[t]) EL(sum)
        if(sum>W) END("No")
    }

    PL("Yes")
}


void solve4(){
    int N; cin>>N;
    ll W; cin>>W;

    const int MAXN = 200005;
    ll P[MAXN];
    // P.fill(0LL);

    rep(i,N){
        int s,t,p;
        cin>>s>>t>>p;
        P[s] += p;
        P[t] -= p;
    }

    ll sum = 0;
    for(const auto& p:P){
        sum += p;
        if(sum>W) END("No")
    }
    END("Yes")
}

int main() {
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   int TT = 1;
   //cin>>TT;
   for(int tt = 0; tt<TT; tt++) solve4();
   return 0;
}
