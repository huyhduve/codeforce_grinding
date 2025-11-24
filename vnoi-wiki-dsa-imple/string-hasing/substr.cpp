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

const int MAXN = 1e6, MOD_ = 1e9 + 2277, base = 32;
int POW[MAXN + 5], invPOW[MAXN + 5];

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
        n = s.size() + 1;
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
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    Hash hsa(a), hsb(b);
    for(int i = 1; i <= n - m + 1; i++){
        if(hsa.get_hash(i, i + m - 1) == hsb.get_hash(1, m)) cout << i << ' ';
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
//    cin >> t;
    preprocess();
    while(t--){
        solve();
    }

    return 0;
}
