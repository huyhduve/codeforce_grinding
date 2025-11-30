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
    int n; cin >> n;
    int res = 0, cnt_neg = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0) res += 1;
        if(x == -1) cnt_neg ++;
    }
    if(cnt_neg & 1) res += 2;
    cout << res << "\n";

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
