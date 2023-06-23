#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
struct DSU {
    int fa[N], sz[N];
    void init(int n) {
        for(int i=1;i<=n;i++) sz[i] = 1, fa[i] = i;
    }
    int find(int x) {
        return fa[x] == x ? x : find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(sz[x] > sz[y]) swap(x, y);
        fa[x] = y;
        sz[y] += sz[x];
    }
}dsu;
int a[N][N], vis[N][N];
vector<pair<int, int>> ans;
int main() {
    ios::sync_with_stdio(false);
    #ifdef _DEBUG
        freopen("data.txt", "r", stdin);
    #endif
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        if(n == 1) {
            continue;
        }
        dsu.init(n);
        ans.clear();
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++) cin>>a[i][j], vis[i][j] = 0;
        for(int i=1;i<=n;i++) {
            if(vis[a[i][1]][a[i][2]]) continue;
            vis[a[i][1]][a[i][2]] = 1;
            vis[a[i][2]][a[i][1]] = 1;
            ans.push_back({a[i][1], a[i][2]});
            dsu.merge(a[i][1], a[i][2]);
        }
        int now = dsu.find(a[1][1]);
        for(int i=2;i<=n;i++) {
            int x = dsu.find(a[1][i]);
            if(x != now){
                int y = a[1][i];
                for(int j=1;j<=n;j++) {
                    if(dsu.find(a[y][j]) == now) {
                        ans.push_back({y, a[y][j]});
                        dsu.merge(a[y][j], y);
                        break;
                    }
                }
                now = dsu.find(a[1][i]);
            }
        } 
        for(auto i:ans) 
            cout<<i.first<<" "<<i.second<<"\n";
    }
}