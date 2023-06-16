#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define all(obj) (obj).begin(), (obj).end()
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// 全て 1-index
vector<vector<int>> pls;
vector<int> mns(27);
// i日目に sce[i] のコンテストが行われた
vector<int> sce(366);
// コンテスト毎の開催日
//map<int, set<int>> mp;
vector<set<int>> mp(27);

int ans = 0;

//入力
void in_data(int d) {
    pls.resize(d + 1, vector<int>(27));
    rep(i, 1, 27) cin >> mns[i];
    rep(i, 1, d + 1) {
        rep(j, 1, 27) {
            cin >> pls[i][j];
        }
    }
}
//コンテスト k の開催日が、前回がl、今回がrの場合のマイナス
int getm(int l, int r, int k) {
    int g = r - l;
    return g * (g - 1) / 2 * mns[k];
}
//d日目のコンテストを oldk から newk に変更したときのプラス
int plsf(int day, int oldk, int newk) {
    int point = 0;
    point -= pls[day][oldk];
    point += pls[day][newk];
    return point;
}
//d日目のコンテストを oldk から newk に変更したときのマイナス
int mnsf(int day, int oldk, int newk) {

    //新たに付加されるマイナスの値
    int point = 0;

    //pre 前回の開催日   day 今回   nxt 次回
    
    //コンテストの開催日リスト(set)から、変更前の開催日を取り除く
    //auto itr = find(all(mp[oldk]), day);
    auto itr = mp[oldk].find(day);
    auto preitr = itr;
    auto nxtitr = itr;
    preitr--;
    nxtitr++;
    int pre = *preitr;
    int nxt = *nxtitr;

    //各コンテスト毎に、開催日の間隔を見る
    point -= getm(pre, day, oldk); //既に反映されている、【前回から今回まで】の開催間隔によるマイナスを削除する
    point -= getm(day, nxt, oldk); //既に反映されている、【今回から次回まで】の開催間隔によるマイナスを削除する
    point += getm(pre, nxt, oldk); //新たに【今回の開催が無い場合のマイナス】を付加する == 【前回から次回まで】の開催間隔によるマイナスを付加する

    mp[oldk].erase(itr);


    //コンテストの開催日リストに、変更後の開催日を挿入する
    
    mp[newk].insert(day);

    //itr = find(all(mp[newk]), day);
    itr = mp[newk].find(day);
    preitr = itr;
    nxtitr = itr;
    preitr--;
    nxtitr++;
    pre = *preitr;
    nxt = *nxtitr;

    //各コンテスト毎に、開催日の間隔を見る
    point -= getm(pre, nxt, newk); //既に反映されている、【前回から次回まで】の開催間隔によるマイナスを削除する
    point += getm(pre, day, newk); //新たに【前回から今回まで】の開催間隔によるマイナスを付加する
    point += getm(day, nxt, newk); //新たに【今回から次回まで】の開催間隔によるマイナスを付加する

    return point;
}
//コンテストの変更を行う
int chp(int day, int newk) {
    int oldk = sce[day];
    sce[day] = newk;
    ans += plsf(day, oldk, newk);
    ans -= mnsf(day, oldk, newk);
    return ans;
}

int main() {

    int D;
    cin >> D;
    in_data(D);
    //最前に 0 を、最後に D+1 を追加
    rep(i, 1, 27) {
        mp[i].insert(0);
        mp[i].insert(D + 1);
    }
    rep(day, 1, D + 1) {
        int kind;
        cin >> kind;
        sce[day] = kind;
        mp[kind].insert(day);
    }
    //初期スコアを計算
    //for (auto mpitr = mp.begin(); mpitr != mp.end(); ++mpitr) {
    for(int f=1; f<27;f++){
        // auto f = mpitr->first;
        // auto s = mpitr->second;
        auto& s = mp[f];

        // auto itr = s.begin();
        // int pre = *itr;
        // itr++;
        //開催間隔を見てスコアを計算
        // while (itr != s.end()) {
        //     if (*itr != D + 1) {
        //         ans += pls[*itr][f];
        //     }
        //     ans -= getm(pre, *itr, f);
        //     pre = *itr;
        //     itr++;
        // }
        for(auto it=next(s.begin()); it!=s.end();it++){
            if (*it != D + 1) {
                ans += pls[*it][f];
            }
            ans -= getm(*prev(it), *it, f);
        }
    }
    
    int Q;
    cin >> Q;
    //クエリ
    rep(i, 0, Q) {
        int day, kind;
        cin >> day >> kind;
        int point = 0;
        int oldk = sce[day];
        cout<<chp(day, kind)<<"\n";
    }
    return 0;
}
