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
    int M = 200000;
    int Q; cin>>Q;
    V<Pii> Infants(N);//rate, school
    cin>>Infants;
    rep(i,N) Infants[i].se--;

    V<multiset<int>> Schools(M);
    for(const auto& [rate, school]:Infants){
        Schools[school].insert(rate);
    }

    multiset<int> Highests;

    V<int> MaxRate(M, -INF);
    rep(i,M){
        if(Schools[i].size()){
            int rate = *(Schools[i].rbegin());
            Highests.insert(rate);
            //MaxRate[i] = rate;
        }
    }
    //EL(*(Highests.rbegin())-*(Highests.begin()))
    rep(i,N){ES(Infants[i].fi) EL(Infants[i].se)}


    queue<int> que;
    rep(q,Q){
        EL(q)
        int InfId; cin>>InfId; InfId--;
        int newSchool; cin>>newSchool; newSchool--;

        auto& Inf = Infants[InfId];
        int rate = Inf.fi;
        int oldSchool = Inf.se;
        Inf.se = newSchool;

        EL(q)
        //Highests から oldSchool抜く
        int highest = *(Schools[oldSchool].rbegin());
        EL(highest)
        //for(const auto& e:Highests){
          //  ES(e)
        //}
        auto it = Highests.find(highest);
        ES(*it)
        Highests.erase(it);
        //Highests から newSchool抜く
        if(Schools[newSchool].size()){
            highest = *(Schools[newSchool].rbegin());
            auto it2 = Highests.find(highest);
            ES(*it2)
            Highests.erase(it2);
        }


        EL(q)
        //oldSchool から rate抜く
        auto it3 = Schools[oldSchool].find(rate);
        Schools[oldSchool].erase(it3);
        //MaxRate[oldSchool] = -INF;

        Schools[newSchool].insert(rate);

        que.push(newSchool);
        que.push(oldSchool);

        while(!que.empty()){
            int school = que.front(); que.pop();
            EL(school)
            if(Schools[school].size()==0) continue;
            highest = *(Schools[school].rbegin());
            Highests.insert(highest);
            //MaxRate[school] = highest;
            EL(school)
        }

        rep(i,N){ES(Infants[i].fi) EL(Infants[i].se)}

        //PL(*(Highests.rbegin())-*(Highests.begin()))
        PL(*(Highests.begin()))
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
