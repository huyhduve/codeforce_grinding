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
    ll h, d; cin >> h >> d;

    ll l = 0, r = d, ans = 0;
    while(l <= r){
        ll m = (l + r)/2;
        ll s = m + 1, len = d / s, re = d - len*s;
        ll cost = re*(len + 1)*(len + 2)/2 + (s - re)*len*(len + 1)/2;

        if(cost < h + m){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans + d << "\n";

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
