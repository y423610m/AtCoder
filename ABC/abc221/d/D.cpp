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

const int MAX_V = 100;

void solve() {

	int n; cin>>n;
	vector<int> a(n), b(n), c(n);
	rep(i,n){
		 cin>>a[i]>>b[i];
		 c[i] = a[i]+b[i];
	}
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));

	vector<ll> d(n+1);

	int ia = 0;
	int ic = 0;
	int num = count(ALL(a),a[0]);
	bool keep = true;
	bool finishA = false;
	ll last = a[0];
	ll search = a[0];

	while(keep){

		while( a[ia]==search && ia!=n-1) ia++;
		while( c[ic]==search && ic!=n-1) ic++;

		if(finishA) search = c[ic];
		else{
			search = min(a[ia], c[ic]);
			if(ia==n-1&&a[ia]==search) finishA=true;
		}
		
		d[num] += search - last;

		cout<<num<<" "<<ia<<" "<<ic<<" "<<search-last<<endl;

		last = search;

		num += count(ALL(a), search);
		num -= count(ALL(c), search);


		if(ia==n-1&&ic==n-1){
			keep = false;
			break;
		}

	}

	repi(i,1,n+1) cout<<i<<"people  "<<d[i]<<endl;


	return;
}

int main() {
	solve();
	return 0;
}
