#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define rrep(i, a, n) for (int i = (int)(a); i > (int)(n); i--)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define rrepll(i, a, n) for (ll i = (ll)(a); i > (ll)(n); i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define ALL(a)  (a).begin(),(a).end()

const int MAX_N = 100;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

ll ruijo(ll a, ll b){
	ll ret = 1;
	for(ll i = 0; i<b; i++){
		ret *= a;
	}
	return ret;
}

void solve() {

	ll n; cin>>n;
	ll ret = 0;
	ll k = 2;
	ll keta = 1;

	while(n>=k){
		for(int i=0; i<keta; i++){
			ret += ruijo(10,i);
			//cout<<"line 31  i "<<i<<"  "<<ret<<endl;
		}
		k *= 10;
		keta++;
	}
	keta--;

	ll n_ = n;
	while(n>0){
		int left = (n_/ll(ruijo(10,keta)))%10;
		if(left==0){
			
		}
		else if(left==1){
			ret += n-ll(ruijo(10, keta))+1;
			//cout<<ret<<endl;
		}
		else{//left>=2
			ret +=ll(ruijo(10,keta));
			for(int i=0; i<keta; i++){
				ret += ll(ruijo(10,i));
				//cout<<"line 70 "<<ret<<endl;
			}
			cout<<ret<<endl;
			return;
		}
		n -= ll(ruijo(10,keta));
		//cout<<"n "<<n<< "  "<<ll(ruijo(10,keta))<<endl;
		keta--;
	}

	cout<<ret<<endl;

	return;
}

int main() {
	solve();
	return 0;
}
