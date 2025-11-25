//  ^------^
// ( '(oo)' )
// (  u  u  )

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define ff first
#define sc second
#define all(x) (x).begin(), (x).end()
mt19937 rgn (chrono::steady_clock::now().time_since_epoch().count());
#define IN "A.IN"
#define OUT "A.OUT"
#define cerr if(0) cerr


int const MOD = 1e9 + 7;
int const N = 2e5 + 10;

map<int,int> trans;
vector<int> cnt[N];
int rev[N];
// coordinate compress without using sort
// map + translate_val + revert_array

int num(int x, int _l, int _r){
    int l = 0, r = cnt[x].size() - 1;

    while(l <= r){
        int m = (l + r)/2;
        if(cnt[x][m] <= _r){
            l = m + 1;
        }
        else r = m - 1;
    }

    int res = l;
    l = 0;
    r = cnt[x].size() - 1;
    while(l <= r){
        int m = (l + r)/2;
        if(cnt[x][m] < _l){
            l = m + 1;
        }
        else r = m - 1;
    }
    res = res - l;
    return res;

};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!trans.count(a[i])){
            trans[a[i]] = trans.size();
            rev[trans[a[i]]] = a[i];
        }
        a[i] = trans[a[i]];
    }
    for(int i = 0; i < n; i++){
        cnt[a[i]].push_back(i);
    }

    while(q--){
        int l, r; cin >> l >> r;
        l --;
        r --;
        int d = (r - l + 1)/3;
        vector<int> ans;
        for(int k = 0; k < 45; k++){
            int x = rgn() % (r - l + 1) + l;
            x = a[x];
//            cout << x << ' ' << num(x, l, r) << " " << d << "\n";
            if(num(x, l, r) > d){

                if(!ans.size() || (rev[x] != ans.back() && rev[x]!= ans.front()) ){
                    ans.push_back(rev[x]);
                }
            }
        }
        if(!ans.size()){
            ans.push_back(-1);
        }
        if(ans.size() == 2 && ans[0] > ans[1]){
            swap(ans[0], ans[1]);
        }

        for(int &i : ans) cout << i << ' ';
        cout << "\n";
    }

    trans.clear();
    for(int i = 0; i < n; i++){
        cnt[i].clear();
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    if(fopen(IN, "r")){
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen("CERR.txt", "w", stderr);
    }
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
