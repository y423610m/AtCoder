#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, n) for (int i = a; i < (int)(n); i++)
#define repll(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repill(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define PS(a) cout<<(a)<<" ";
#define PL(a) cout<<(a)<<endl;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;


void solve() {

	string s; cin>>s;
	vector<ll> vll(s.size(),0);
	//reverse(ALL(s))
	rep(i,s.size()){
		if(i==0) vll[i]=s[i]-'0';
		else vll[i]=vll[i-1]+s[i]-'0';
	}
	reverse(ALL(vll));
	rep(i,vll.size()-1){
		vll[i+1]+=vll[i]/10;
		vll[i]%=10;
	}

	while(vll.back()>=10){
		vll.push_back(0);
		vll.back() += vll[vll.size()-2]/10;
		vll[vll.size()-2]%=10;
	}

	reverse(ALL(vll));
	rep(i,vll.size()) cout<<vll[i];
	PL("")


	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}
