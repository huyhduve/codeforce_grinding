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
    vector<int> a(n);
    int odd = 0, even = 0;
    for(int &i : a) {
        cin >> i;
        if(i & 1) odd = 1;
        else even = 1;
    }
    if(odd + even == 2){
        sort(all(a));
    }

    for(int &i : a) cout << i << ' ';
        cout << "\n";
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
