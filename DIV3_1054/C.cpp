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


#define IN "A.IN"
#define OUT "A.OUT"
#define cerr if(0) cerr

int const MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x] ++;
    }

    int cnt_mis = 0;
    for(int i = 0; i < k; i++){
        if(cnt[i] == 0) cnt_mis ++;
    }

    cout << max(cnt[k], cnt_mis) << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    if(fopen(IN, "r")){
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen("CERR.txt", "w", stderr);
    }
    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
