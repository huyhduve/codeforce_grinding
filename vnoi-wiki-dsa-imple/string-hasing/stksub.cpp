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
const int MAXN = 5e4, MOD_ = 1e9 + 2277, base = 32;
int POW[MAXN + 4], invPOW[MAXN + 4];

int bi_pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = 1LL*res*a % MOD_;
        a = 1LL*a*a % MOD_;
        b /= 2;
    }
    return res;
}

void preprocess(){
    POW[0] = 1;
    invPOW[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        POW[i] = 1LL*POW[i - 1]*base % MOD_;
    }
    invPOW[MAXN] = bi_pow(POW[MAXN], MOD_ - 2);
    for(int i = MAXN - 1; i >= 1; i--){
        invPOW[i] = 1LL*invPOW[i + 1]*base % MOD_;
    }
}

struct Hash{
    int n;
    vector<int> hs;

    Hash(string &s){
        int n = s.size() + 1;
        hs.assign(n, 0);
        for(int i = 1; i < n; i++){
            hs[i] = (1LL*(s[i - 1] - 'a' + 1)*POW[i - 1] + hs[i - 1]) % MOD_;
        }
    }

    int get_hash(int l, int r){
        int tmp = hs[r] - hs[l - 1];
        if(tmp < 0) tmp += MOD_;
        return 1LL*tmp*invPOW[l - 1] % MOD_;

    }
};

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    Hash hs_s(s);

    int l = 1, r = n, ans = 0;
    while(l <= r){
        int m = (l + r)/2;
        vector<int> hs_val;
//
        for(int i = 1; i <= n - m + 1; i++){
            hs_val.push_back(hs_s.get_hash(i, i + m - 1));
        }
        sort(all(hs_val));

        int mx = 0;
        for(int i = 0; i < (int) hs_val.size(); ){
            int j = i + 1;
            while(j < (int) hs_val.size() && hs_val[i] == hs_val[j]) j ++;
            mx = max(mx, j - i);
            i = j;
        }
        if(mx >= k){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    if(fopen(IN, "r")){
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
        freopen("CERR.txt", "w", stderr);
    }
    preprocess();
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
