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

const int MOD = 1e9 + 7;
// Observation: 
// in a array, if there is odd number of 1s -> it's xor sum = 1, vice versa
// Tie: number of 1s is the same parity.
// Win: the one who can last modify it's parity.

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    if((accumulate(all(a), 0) + accumulate(all(b), 0)) % 2 == 0){
        cout << "Tie" << "\n";
        return;
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] + b[i] == 1){
            if((i + 1) & 1){
                cout << "Ajisai" << "\n";
            }
            else cout << "Mai" << "\n";
            return;

        }
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
