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


#define IN "A.IN"
#define OUT "A.OUT"
#define cerr if(0) cerr

int const MOD = 1e9 + 7;

/* ========== Solution ============= 

    Try to move all 'a' to the side or all 'b' to the side.
    For each position i, we can calculate the cost to move all 'a's before it to the left side (1) and all 'a's after it to the right side. (2)
    The answer will be the minimum of (1) + (2) for all i.
    We can do the same for 'b's and take the minimum.

   =================================
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    auto func = [&](char c){
        vector<int> l(n, 0), r(n, 0);

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == c){
                l[i] = (i - cnt);
                cnt ++;
            }

        }

        cnt = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == c){
                r[i] = (cnt - i);
                cnt --;
            }
        }
        for(int i = 1; i < n; i++){
            l[i] += l[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            r[i] += r[i + 1];
        }

        int mi = LLONG_MAX;
        for(int i = 0; i < n; i++){
            mi = min(mi, l[i] + r[i]);
        }
        return mi;
    };

    cout << min(func('a'), func('b')) << "\n";
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