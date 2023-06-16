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
#define EL(a) cerr<<(a)<<endl;

const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const ll MOD = 998244353;

ll Power(ll a, ll b){
	ll ret = 1;
	rep(i,b) ret*=a;
	return ret;
}

void solve() {
	string n8;
	int k;
	cin>>n8>>k;

	reverse(ALL(n8));

	rep(_,k){
		ll N = 0;
		rep(i,n8.size()) N += (n8[i]-'0')*Power(8,i);

		string n9;
		while(N>0){
			n9 += N%9 + '0';
			N /= 9;
		}
		
		if(n8=="0") n9 = "0";

		//PS(_) 
		//EL(n9)

		rep(i,n9.size()) if(n9[i]=='8') n9[i]='5';


		n8 = n9;

		/*
		N = 0;
		rep(i,n9.size()) N += (n9[i]-'0')*Power(9,i);

		n8 = "";
		while(N>0){
			n8 += N%8 + '0';
			N /= 8;
		}
		*/
	}

	reverse(ALL(n8));
	//if(n8[0]=='0') n8.erase(n8.begin());
	PL(n8)

	return;
}

int main() {
	//string s; cin>>s;
	//EL(s)
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	rep(_, t) solve();

	return 0;
}
