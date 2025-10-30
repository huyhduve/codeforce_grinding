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
//#define cerr if(0) cerr

int const MOD = 1e9 + 7;

/* ================ Solution ================
The task is to find way to place k teleport among people so that the minimum distance from a person to the nearest teleport is maximized.
We can use binary search to find the maximum minimum distance d. For each mid value in binary search, we can count how many teleports 
are needed to ensure that each person is at least mid distance away from the nearest teleport.

Place the teleports at the beginning and end of the range if necessary, 
and for each pair of consecutive people, try to put the teleports in the middle of them to cover the gap.

============================================*/



void solve(){
    ll n, x, k; cin >> n >> k >> x;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    sort(a.begin(), a.end());

    ll l = 0, r = 1e9 + 500, ans = 0;
    while(l <= r){
        ll m = (l + r)/2;

        int cnt = 0;
        if(a[0] >= m) cnt += a[0] - m + 1;
        cnt += max(0LL, (x - a[n - 1]) - m + 1);

        for(int i = 1; i < n; i++){
            ll d = a[i] - a[i - 1] - 1;
            cnt += max(0LL, d - 2*(m - 1));
            if(cnt >= k) break;
        }

        if(cnt >= k){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    if(ans == 0){
        for(int i = 0; i < k; i++) cout << i << ' ';
        cout << "\n";
        return;
    }

    int cnt = 0;
    for(int i = 0; i <= a[0] - ans; i++){
        cout << i << ' ';
        cnt ++;
        if(cnt == k) break;
    }
    for(int i = 1; i < n; i++){
        for(int j = a[i - 1] + ans; j <= a[i] - ans; j++){
            if(cnt == k) break;
            cout << j << ' ';
            cnt ++;
        }
    }


    for(int i = a[n - 1] + ans; i <= x; i++){
        if(cnt == k) break;
        cout << i << ' ';
        cnt ++;
    }
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