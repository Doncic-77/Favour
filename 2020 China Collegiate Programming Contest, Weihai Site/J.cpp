//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
struct Linear_base
{
	bool zero ;
	int cnt ;
	ll b[75] , p[75] ;
	void init()
	{
		zero = 0 ;
		cnt = 0 ;
		memset(b , 0 , sizeof(b)) ;
		memset(p , 0 , sizeof(p)) ;
	}
	bool insert(ll x)
	{
		for(int i = 60 ; i >= 0 ; i --)
		if(x & (1ll << i))
		{
			if(b[i])  x ^= b[i] ;
			else  
			{
				b[i] = x ;
				return 1 ;
			}
		}
		zero = 1 ;
		return 0 ;
	}
	ll get_max()
	{
		ll ans = 0 ;
		for(int i = 60 ; i >= 0 ; i --)
		if((ans ^ b[i]) > ans)  ans ^= b[i] ;
		return ans ;
	}
	ll get_min()
	{
		if(zero)  return 0 ;
		for(int i = 0 ; i <= 60 ; i ++)
		if(b[i])  return b[i] ;
		return 0 ;
	}
	void rebuild()
	{
		cnt = 0 ;
		for(int i = 60 ; i >= 0 ; i --)
		if(b[i])
		{
			for(int j = i - 1 ; j >= 0 ; j --)
			if(b[i] & (1ll << j))  b[i] ^= b[j] ;
		}
		for(int i = 0 ; i <= 60 ; i ++)
		if(b[i])  p[cnt ++] = b[i] ;
	}
	ll kth(ll k)
	{
		ll ans = 0 ;
		if(zero)  k -- ;
		if(k == 0)  return 0 ;
		if(k >= (1ll << cnt))  return -1 ;
		for(int i = 0 ; i <= cnt - 1 ; i ++)
		if(k & (1ll << i))  ans ^= p[i] ;
		return ans ;
	}
} linear_base ;
const int mod = 1e9 + 7 ;
int norm(int x)
{
    if(x < 0)  x += mod ;
    if(x >= mod)  x -= mod ;
    return x ;
}
template<class T>
T power(T a , int b) //一定记得加强制类型转换power(mint(2),x)
{
    T res = 1 ;
    for( ; b ; b /= 2 , a *= a)
    if(b % 2)  res *= a ;
    return res ;
}
template<class T>
T print(T a , int b)
{
    T res = 1 ;
    for( ; b ; b /= 2 , a *= a)
    if(b % 2)  res *= a ;
    return res ;
}
struct mint
{
    int x ;
    mint(int x = 0) : x(norm(x)) {}
    int val() const
    {
        return x ;
    }
    mint operator-() const
    {
        return mint(norm(mod - x)) ;
    }
    mint inv() const
    {
        assert(x != 0);
        return power(*this, mod - 2) ;
    }
    mint &operator*=(const mint &rhs)
    {
        x = (long long)x * rhs.x % mod ;
        return *this ;
    }
    mint &operator+=(const mint &rhs)
    {
        x = norm(x + rhs.x) ;
        return *this ;
    }
    mint &operator-=(const mint &rhs)
    {
        x = norm(x - rhs.x) ;
        return *this ;
    }
    mint &operator/=(const mint &rhs)
    {
        return *this *= rhs.inv() ;
    }
    friend mint operator*(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res *= rhs ;
        return res ;
    }
    friend mint operator+(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res += rhs ;
        return res ;
    }
    friend mint operator-(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res -= rhs ;
        return res ;
    }
    friend mint operator/(const mint &lhs , const mint &rhs)
    {
        mint res = lhs ;
        res /= rhs ;
        return res ;
    }
} ;
vector<mint> fac ;
vector<mint> inv ;
void init(int n)
{
    n <<= 1 ;
    fac.resize(0) ;
    fac.resize(n + 10 , mint(1)) ;
    inv.resize(0) ;
    inv.resize(n + 10 , mint(1)) ;
    for(int i = 2 ; i <= n ; i ++)  fac[i] = fac[i - 1] * i ;
    inv[n] = fac[n].inv() ;
    for(int i = n - 1 ; i >= 1 ; i --)  inv[i] = inv[i + 1] * (i + 1) ;
}
mint C(int n , int m)
{
    if(n < 0 || m < 0 || n < m)  return mint(0) ;
    return fac[n] * inv[m] * inv[n - m] ;
}
int main() 
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;
    
    int n ;
    cin >> n ;
    vector<long long> a(n + 1 , 0ll) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    linear_base.init() ;
    int one = 0 ;
    for(int i = 1 ; i <= n ; i ++)  
        if(a[i] == 1)  one += 1 ;
        else  linear_base.insert(a[i]) ;
    init(100000 + 10) ;
    mint ans = 0 ;
    auto go = [&](int c , int op)
    {
        mint z = C(one , c) ;
        // op = 0  loss
        // op = 1  win

        // black  c's one  op
        // white  (one - c)'s one  1 - op
        if(op == 0)
        {
            
        }
        else
        {

        }


    } ;
    for(int i = 0 ; i <= one ; i ++)
        for(int j = 0 ; j <= 1 ; j ++)
            ans += go(i , j) ;
    cout << ans.val() << '\n' ;

    return 0 ;
}