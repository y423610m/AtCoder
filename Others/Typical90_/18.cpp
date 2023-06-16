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
const double M_PI = 3.1415;

void solve() {
	int T; cin>>T;
	int L,X,Y; cin>>L>>X>>Y;

	int q; cin>>q;
	rep(i,q){
		int e; cin>>e;
		double x = 0.;
		double y = -0.5*L*sin(2.0*M_PI*1.0*e/T);
		double z = 0.5*L-0.5*L*cos(2.0*M_PI*1.0*e/T);

		double d = sqrt( (X-x)*(X-x) + (Y-y)*(Y-y) );
		double D = sqrt( (X-x)*(X-x) + (Y-y)*(Y-y) + (0.-z)*(0.-z) );


		double COS = d/D;
		double rad = acos(COS);
		double ans = 180.0*rad/M_PI;

		PL(ans)
	}

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
