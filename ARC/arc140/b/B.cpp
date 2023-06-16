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
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define SORT(a) sort(a.begin(), a.end());
#define REVERSE(a) reverse(a.begin(), a.end());
#define ERASE(a) a.erase(unique(a.begin(), a.end()), a.end());
using ll = long long;
using P = pair<int, int>;
template <class T> using V = vector<T>;
template< typename T >ostream &operator<<(ostream &os, const vector< T > &v) {for(int i = 0; i < (int) v.size(); i++) {os << v[i] << (i + 1 != (int) v.size() ? " " : "");}return os;}
template< typename T >istream &operator>>(istream &is, vector< T > &v) {for(T &in : v) is >> in;return is;}
template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}



void solve() {

    int n;cin>>n;
    string s; cin>>s;

    int ans = 0;
    int ans1 = 0;

    //AARCC search
    V<int> vp;// pos, r-i
    //while(1){
        //bool found = false;
        rep(i,s.size()){
            if(s[i]=='R'){
                int l = i, r = i;
                while(0<=l-1 && s[l-1]=='A' && r+1<(int)s.size() && s[r+1]=='C'){
                    l--; r++;
                    //s[l]=' '; s[r]=' ';
                    //found = true;
                }
                // if(r!=i && (r-i)%2==0){
                //     s[l]='A', s[r]='C';
                //     s[i]=' ';
                // }
                if(r!=i){
                    if(r-i==1) ans1++;
                    else if(r-i==2) ans+=2;
                    else{
                        vp.push_back(r-i-2);
                        ans += 2;
                    }
                }

            }
        }
       // if(!found) break;

    //     string t;
    //     rep(i,s.size()) if(s[i]!=' ') t += s[i];
    //     s = t;
    // }

    ans += ans1;
    int sum = 0;
    rep(i,vp.size()){
        sum += vp[i];
    }

    int tmp = min(sum,ans1);
    ans += tmp;
    sum -= tmp;
    //if(sum>0) ans++;
    
   // ES("ans1") EL(ans1)
    PL(ans)

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
