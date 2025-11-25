//  ^------^
// ( '(oo)' )
// (  u  u  )

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define int long long


#define ff first
#define sc second
#define all(x) (x).begin(), (x).end()
mt19937 rgn (chrono::steady_clock::now().time_since_epoch().count());

#define IN "A.IN"
#define OUT "A.OUT"
#define cerr if(0) cerr

int const MOD = 1e9 + 7;
int const N = 80;

/*
   dp[i][j] -> minimum cost to valid a list that end at i
   with at most j


    -- using space-saving technique
*/

void solve(){
    int n; cin >> n;
    vector<int> a(n), c(n);
    vector<int> val;
    for(int &i : a) {
        cin >> i;
        val.push_back(i);
    }
    for(int &i : c) cin >> i;


    sort(val.begin(), val.end()); // Sort the vector to arrange elements in ascending order.
    val.erase(unique(all(val)), val.end()); // Remove duplicates to keep only unique elements.
    int MAXVAL = val.size();
    auto get_id = [&](int x) -> int{
        return lower_bound(all(val), x) - val.begin();
    };

    vector<vector<int>> dp(2, vector<int> (MAXVAL + 1, 1e16));

    for(int &i : a){
        i = get_id(i);
    }

    int old_ = 0, new_ = 1;
    for(int i = 0; i <= MAXVAL; i++) dp[old_][i] = (a[0] != i)*c[0];

    for(int i = 1; i < n; i++){
        int mi_ = 1e16;
        for(int j = 0; j <= MAXVAL; j++){
            mi_ = min(mi_, dp[old_][j]);
            dp[new_][j] = mi_ + (a[i] != j)*c[i];
        }
    swap(old_, new_);
    }


    int mi = 1e16;
    for(int i = 0; i <= MAXVAL; i++){
        mi = min(mi, dp[old_][i]);
    }
    cout << mi << "\n";
}

signed main(){
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
