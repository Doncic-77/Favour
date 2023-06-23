#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int T,n,a[N],p[N];
void slv(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    for(int i=1;i<n;++i){
        if(abs(p[i]-p[i+1])>2){
            puts("No");
            return;
        }
    }
    puts("Yes");
}
int main(){
    scanf("%d",&T);
    while(T--)slv();
}