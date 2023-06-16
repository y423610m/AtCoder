#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define pb(a) push_back(a)
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;
#define ES(a) cerr<<(a)<<" ";
#define EL(a) cerr<<(a)<<endl;
#define END(a) {PL(a) return;}
#define FI first
#define SE second

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    	os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

// std::ostream&
// operator<<( std::ostream& dest, __int128_t value )
// {
//     std::ostream::sentry s( dest );
//     if ( s ) {
//         __uint128_t tmp = value < 0 ? -value : value;
//         char buffer[ 128 ];
//         char* d = std::end( buffer );
//         do
//         {
//             -- d;
//             *d = "0123456789"[ tmp % 10 ];
//             tmp /= 10;
//         } while ( tmp != 0 );
//         if ( value < 0 ) {
//             -- d;
//             *d = '-';
//         }
//         int len = std::end( buffer ) - d;
//         if ( dest.rdbuf()->sputn( d, len ) != len ) {
//             dest.setstate( std::ios_base::badbit );
//         }
//     }
//     return dest;
// }

template <class T, class U> void chmin(T& t, const U& u) {if (t > u) t = u;}
template <class T, class U> void chmax(T& t, const U& u) {if (t < u) t = u;}

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using P = pair<int, int>;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;
//const ll MOD = 1000000007;
int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

void solve() {
	
	ll x; cin>>x;
    priority_queue<ll> que;
    que.push(x);

    while(1){
        ll top = que.top();
        que.pop();
        ll half = top/2;
        ll odd = top%2;

        if(top>10){
            if(odd){
                que.push(half);
                que.push(1+half);
            }
            else{
                que.push(half);
                que.push(half);
            }
        }
        else if(odd&&(top<half*(half+1))){
            que.push(half);
            que.push(1+half);
        }
        else if((!odd)&&(top<half*(half))){
            que.push(half);
            que.push(half);
        }
        else{
            que.push(top);
            break;
        }
        EL(top)
    }

    ll ans = 1;
    EL(que.size())
    while(!que.empty()){
        ll tmp = que.top();
        que.pop();
        tmp %= MOD;
        ans *= tmp;
        ans %= MOD;
       // ES(tmp)
    } 
    //EL("");

    PL(ans)

	return;
}

void solve2(){
    ll x; cin>>x;
    map<ll,ll> mp;
    mp[x]++;

    while(mp.rbegin()->first>=5){
        ll tmp = mp.rbegin()->first;
        ll n = mp.rbegin()->second;
        mp.erase(tmp);
        mp[tmp/2] += n;
        
        if(tmp%2==0) {mp[tmp/2] += n;}
        else {mp[1+tmp/2] += n;}
    }

    ll ans = 1;
    for(int i=2;i<=4;i++){
        ll tmp = 1;
        ll n = 0;
        while(tmp<MOD){
            tmp *= i;
            n++;
        }
        for(int j=0;j<mp[i]/n;j++){
            ans *= tmp % MOD;
            ans %= MOD;
        }
        for(int j=0;j<mp[i]%n;j++){
            ans *= i;
            ans %= MOD;
        }
    }

    PL(ans)

}



void solve3(){
    ll x; cin>>x;
    V<ll> pow2;
    pow2.push_back(1);
    rep(i,18) pow2.push_back(pow2.back());
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve2();

	return 0;
}
