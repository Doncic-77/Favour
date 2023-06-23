#include<bits/stdc++.h>
using namespace std ;
int main()
{
    ios::sync_with_stdio(false) , cin.tie(0) ;
    int T ;
    cin >> T ;
    while(T --)
    {
        string s ;
        cin >> s ;
        int n = s.size() ;
        vector<int> pre(n , -1) ;
        int lst = -1 ;
        for(int i = 0 ; i < n ; i ++)
        {
            pre[i] = lst ;
            if(s[i] == 'p')  lst = i ;
        }
        vector<int> suf(n , -1) ;
        lst = -1 ;
        for(int i = n - 1 ; i >= 0 ; i --)
        {
            suf[i] = lst ;
            if(s[i] == 'p')  lst = i ;
        }
        long long res = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
            if(s[i] == 'c')  continue ;
            int l = 0 ;
            int r = 0 ;
            if(pre[i] == -1)  l = i ;
            else  l = i - pre[i] - 1 ;
            if(suf[i] == -1)  r = n - 1 - i ;
            else  r = suf[i] - i - 1 ; 
            res += min(l / 2 , r) ;
            // cout << i << ' ' << l << ' ' << r << ' ' << res << '\n' ;
        }
        cout << res << '\n' ;
    }

}