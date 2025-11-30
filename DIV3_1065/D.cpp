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

/*
// Observation:
    1. If the sets create by mutually reachable nodes, are intersect
    -> Exist a tree
    2. One way to create a set: node_i + the smallest node before i, the largest node after i 
*/
const int MAXN = 2e5 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 2), mi(n + 2), mx(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i];
    mi[0] = a[1];
    mx[n + 1] = a[n];


    for(int i = 1; i <= n; i++) mi[i] = min(mi[i - 1], a[i]);
    for(int i = n; i >= 1; i--) mx[i] = max(mx[i + 1], a[i]);

    bool f = 1;
    for(int i = 1; i <= n; i++){
        if(mi[i - 1] > mx[i + 1]){
            f = 0;
        }
    }

    cout << (f ? "YES\n" : "NO\n");
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
