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

/*
Observation:
    1. From problem D, we can see that edge could
    be created from p[i], the mi[i - 1], mx[i + 1]
    2. Add edges to make it become a Connected Component. 
    Use DSU to check if new edge is valid or not. 

*/

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
int par[MAXN];

int cnt = 0;
int root(int u){
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}
bool join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return 0;
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return 1;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n + 1), mx(n + 2), mi(n + 2);

    for(int i = 1; i <= n; i++) cin >> p[i];
    mi[0] = p[1];
    mx[n + 1] = p[n];

    for(int i = 1; i <= n; i++){
        mi[i] = min(mi[i - 1], p[i]);
    }
    for(int i = n; i >= 1; i--){
        mx[i] = max(mx[i + 1], p[i]);
    }

    bool f = 1;
    for(int i = 1; i <= n; i++){
        if(mi[i - 1] > mx[i + 1]) f = 0;
    }

    if(!f){
        cout << "No" << "\n";
        return;
    }

    for(int i = 0; i <= n; i++) par[i] = -1;

    cout << "Yes" << "\n";
    for(int i = 1; i <= n; i++){
        if(p[i] < mi[i - 1]){
            if(join(p[i], mx[i + 1])) cout << p[i] << ' ' << mx[i + 1] << "\n";
        }
        else{
            if(join(p[i], mi[i - 1])) cout << p[i] << ' ' << mi[i - 1] << "\n";

        }
        if(join(mi[i - 1], mx[i + 1])) cout << mi[i - 1] << ' ' << mx[i + 1] << "\n";

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

