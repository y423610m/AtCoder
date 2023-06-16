#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    ll n;
    cin >> n;
    vector<ll> pow10(16);
    pow10[0] = 1;
    rep(i, 15) pow10[i + 1] = pow10[i] * 10ll;

    ll ans = 0;
    rep(l, 17) rep(r, 17) if (l > 0 && l + r <= 16) {
        string s = string(l, '1');
        ll ok = -1, ng = pow10[r], mid;
        while (ng - ok > 1) {
            mid = (ok + ng) / 2;
            string t = to_string(mid);
            while (sz(t) < r) t = '0' + t;
            if (r == 0) t = "";
            ll tmp = stol(s + t);
            (tmp <= n ? ok : ng) = mid;
        }
        // if (ok + 1 > 0) cout << l << ' ' << r << ' ' << ok << '\n';
        ans += ok + 1;
    }
    cout << ans << '\n';
}