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
// Consider an array of 1, 0: -> number of 1s is odd -> xor sum = 1, vice vers
// an list of number, consider the Largest bit i_th, if the sum of it is odd -> the sum xor contains: 2^i
// Tie: noone can change the parity of the bit at all index i
// Win: if one can modify its bit i_th parity

const int MAXBIT = 23;

void solve(){
    int n; cin >> n;

    vector<bitset<MAXBIT + 1>> a(n), b(n);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j <= 23; j++){
            a[i][j] = (x & (1 << j));
        }
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j <= 23; j++){
            b[i][j] = (x & (1 << j));
        }
    }

//
//    for(int i = 0; i < n; i++){
//        cout << a[i] << ' ' << b[i] << "\n";
//    }

    for(int bit = MAXBIT; bit >= 0; bit--){
        int cnt1 = 0, cnt2 = 0;
        for(auto &bs : a) if(bs[bit] == 1) cnt1 ++;
        for(auto &bs : b) if(bs[bit] == 1) cnt2 ++;
        if((cnt1 + cnt2) & 1){
            for(int i = n - 1; i >= 0; i--){
                if(a[i][bit] != b[i][bit]){
                    if((i + 1) & 1) cout << "Ajisai" << "\n";
                    else cout << "Mai" << "\n";
                    return;
                }
            }
        }
    }
    cout << "Tie\n";

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
