#include<bits/stdc++.h>
using namespace std;
int T;
long long x,y,z;
void slv(){
    
    scanf("%lld %lld %lld",&x,&y,&z);
    if(x>y)swap(x,y);
    if(z<=1){
        printf("%lld\n",y-x);
        return;
    }
    
    long long k=1;
    while(k<=z)k<<=1;
    long long t=y/k-x/k;
    // printf("__%lld\n",t);
    if(t==0){
        long long w=y^x;
        if(w==0)puts("0");
        else if(w<=z)puts("1");
        else printf("%lld\n",min(y-x,2ll));
        return;
    }else {
        long long rs=0;
        x&=k-1,y&=k-1;
        if(x==k-1)rs=1;
        else if(((k-1)^x)<=z)rs=2;
        else rs=3;
        if(z==k-1)rs+=2*(t-1);
        else rs+=3*(t-1);
        if(y==0)rs+=0;
        else if(y<=z)rs+=1;
        else rs+=2;
        printf("%lld\n",rs);
        return;
    }
}
int main(){
    #ifdef _DEBUG
        freopen("data.txt", "r", stdin);
    #endif
    scanf("%d",&T);
    while(T--)slv();
}