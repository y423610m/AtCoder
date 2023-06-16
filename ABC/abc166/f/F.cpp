// C++
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <iostream>
// #include <list>
// #include <map>
// #include <numeric>
// #include <queue>
// #include <set>
// #include <stack>
// #include <string>
// #include <utility>
// #include <vector>
// #include <array>
// #include <tuple>
// #include <unordered_map>
// #include <unordered_set>
// #include <iomanip>


#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll = long long;

const ll MOD = 998'244'353;
//const ll MOD = 1000'000'007;

const ll INF = (1LL<<30)-1;
const ll LINF = (1LL<<62)-1;
// int:[-2'147'483'648 : 2'147'483'647]
// ll:[-9'223'372'036'854'775'808 : 9'223'372'036'854'775'807]
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
// #define endl "\n"
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
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template< typename T, typename U > ostream &operator<<(ostream &os, const pair<T,U> &p) {os << p.first << ' ' << p.second; return os;}
template< typename T, typename U > istream &operator>>(istream &is, pair<T,U> &p) { is >> p.first >> p.second; return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    V<ll> F(3);
    PL(F[4])
    PL("a")

    ll N;
    V<ll> cnt(3);
    cin>>N>>cnt;
    V<string> S(N); cin>>S;
    S.push_back("AB");
    V<char> ans;

    rep(i,N){
        EL(i)
        int l = S[i][0]-'A';
        int r = S[i][1]-'A';
        if(cnt[l]==0&&cnt[r]==0) END("No")
        if(cnt[l]==0){
            cnt[l]++; cnt[r]--; ans.push_back('A'+l);
        }
        else if(cnt[r]==0){
            cnt[l]--; cnt[r]++; ans.push_back('A'+r);
        }
        else if(cnt[l]==1&&cnt[r]==1){
            int nl = S[i+1][0]-'A';
            int nr = S[i+1][1]-'A';
            if(nl==l||nr==l){
                cnt[l]++; cnt[r]--; ans.push_back('A'+l);
            }
            else{
                cnt[l]--; cnt[r]++; ans.push_back('A'+r);
            }
        }
        else{
            if(cnt[l]<cnt[r]){
                cnt[l]++; cnt[r]--; ans.push_back('A'+l);
            }
            else{
                cnt[l]--; cnt[r]++; ans.push_back('A'+r);
            }
        }
    }
    PL("Yes")
    rep(i,N) PL(ans[i])

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
