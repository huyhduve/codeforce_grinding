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
#define int long long 

#define IN "A.IN"
#define OUT "A.OUT"
#define cerr if(0) cerr

/* ======== Solution ========

    Main 4 pointers:

    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
            ^     ^       ^       ^
            b     a       l       r


=========================== */


int const MOD = 1e9 + 7;

void solve(){
    int n, k, l, r; cin >> n >> k >> l >> r;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    map<int,int> cnt;

    int imp = -1, s = 0, res = 0;
    for(int b = 0, c = 0; c < n; c++){
        if(cnt[a[c]] == 0){
            s ++;
        }
        cnt[a[c]] ++;


        while(s > k || c - b > r){
            cnt[a[b]] --;
            if(cnt[a[b]] == 0){
                s--;
                imp = b;
            }
            b++;
        }

        while(cnt[a[b]] > 1 && s == k) {

            cnt[a[b++]] --;

        }

        if(c - b + 1 > r || s != k || c + 1 < l) continue;

        int e = min(c - l + 1, b);
        int st = max(c - r, imp);
        if(e < st) continue;

        res += e - st;
    }
    cout << res << "\n";
}

signed main(){
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