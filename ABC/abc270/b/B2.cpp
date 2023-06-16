#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
#ifdef ONLINE_JUDGE
    #define ES(a) while(0){}
    #define EL(a) while(0){}
#else
    #define NAME(a) #a
    #define ES(a) cerr<<NAME(a)<<": "<<(a)<<" ";
    #define EL(a) cerr<<NAME(a)<<": "<<(a)<<endl;
#endif
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  bool xsign,ysign,zsign = 0;
  if(x > 0) xsign = 1;
  if(y > 0) ysign = 1;
  if(z > 0) zsign = 1;
  
  if(xsign != ysign){//壁問題なし
    EL("a")
    cout << abs(x) << endl;
    return 0;
  }
  else if(abs(x) < abs(y)){//壁問題なし
    EL("b")
    cout << abs(x) << endl;
    return 0;
  }
  else if(ysign != zsign){//壁あり，逆方向ハンマーとれる
    EL("c")
    cout << abs(x)+abs(z)+abs(z) << endl;
    return 0;
  }
  else if(abs(z) < abs(y)){//壁あり，同じ方向ハンマーとれる
    EL("d")
    cout << abs(x) << endl;
    return 0;
  }
  cout << -1 << endl;
}