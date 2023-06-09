//记得看榜
//看数据范围

#include<bits/stdc++.h>
using namespace std ;
const int maxn = 2e5 + 10 ;
int a[maxn] ;
struct jls_seg
{
	int mx[maxn << 2] , se_mx[maxn << 2] ;
    array<int , 30> c[maxn << 2] ;
	int z[maxn << 2] ;
    int ls(int x)
	{
		return x << 1 ;
	}
	int rs(int x)
	{
		return x << 1 | 1 ;
	}
	void push_up(int id)
	{
		sum[id] = sum[ls(id)] + sum[rs(id)] ;
		mx[id] = max(mx[ls(id)] , mx[rs(id)] ) ;
		se_mx[id] = max(se_mx[ls(id)] , se_mx[rs(id)] ) ;
		mc[id] = 0 ;
		if(mx[ls(id)] != mx[rs(id)])  se_mx[id] = max(se_mx[id] , min(mx[ls(id)] , mx[rs(id)])) ;
		if(mx[id] == mx[ls(id)])  mc[id] += mc[ls(id)] ;
		if(mx[id] == mx[rs(id)])  mc[id] += mc[rs(id)] ;
	}
	void dec_tag(int id , int v)
	{
		if(v >= mx[id])  return ;
		sum[id] += 1ll * (v - mx[id]) * mc[id] ; 
		mx[id] = v ;
	}
	void push_down(int id)
	{
		dec_tag(ls(id) , mx[id]) ;
		dec_tag(rs(id) , mx[id]) ;
	}
	void build(int id , int l , int r)
	{
		if(l == r)
		{
			z[id] = mx[id] = a[l] ; 
			se_mx[id] = -1 ;
			for(int i = 0 ; i < 30 ; i ++)
                if((a[l] >> i) & 1)  c[id][i] = 1 ;
                else  c[id][i] = 0 ;
            return ;
		}
		int mid = (l + r) / 2 ;
		build(ls(id) , l , mid) ;
		build(rs(id) , mid + 1 , r) ;
		push_up(id) ;
	}
	void update(int id , int l , int r , int x , int y , int v)
	{
		if(v >= mx[id])  return ;
		if(l == x  &&  r == y && v > se_mx[id])
		{
			dec_tag(id , v) ;
			return ;
		}
		push_down(id) ;
		int mid = (l + r) / 2 ;
		if(y <= mid) update(ls(id) , l , mid , x , y , v) ;
		else if(x > mid) update(rs(id) , mid+1 , r , x , y , v) ;
		else update(ls(id) , l , mid , x , mid , v) , update(rs(id) , mid+1 , r , mid+1 , y , v) ;
		push_up(id) ;   
	}
    pair<int , array<int , 30>> merge(pair<int , array<int , 30>> s , const pair<int , array<int , 30>> &t)
    {
        s.first ^= t.first ;
        for(int i = 0 ; i < 30 ; i ++)  s.second[i] += t.second[i] ;
        return s ;
    }
	pair<int , array<int , 30>> query(int id , int l , int r , int x , int y)
	{
		if(l == x && r == y) return make_pair(z[id] , c[id]) ;
		push_down(id) ;
		int mid = (l + r) / 2 ;
		if(y <= mid) return query(ls(id) , l , mid , x , y) ;
		else if(x > mid) return query(rs(id) , mid + 1 , r , x , y) ;
		else return merge(query(ls(id) , l , mid , x , mid) , query(rs(id) , mid + 1 , r , mid + 1 , y)) ;
	}
} seg ;
void solve()
{
	cin >> n >> m ;
	rep(i , 1 , n)  cin >> a[i] ;
	seg.build(1 , 1 , n) ;
	while(m --)
	{
		int op ;
		cin >> op ;
		if(op == 0) //x<=i<=y,a[i]=min(a[i],t)
		{
			int x , y , t ;
			cin >> x >> y >> t ;
			seg.update(1 , 1 , n , x , y , t) ;
		}
		else if(op == 1)
		{
			int x , y ;
			cin >> x >> y ;
			cout << seg.query_max(1 , 1 , n , x , y) << '\n' ;
		}
		else
		{
			int x , y ;
			cin >> x >> y ;
			cout << seg.query_sum(1 , 1 , n , x , y) << '\n' ;
		}
	}
}
int main() 
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;
    
    int n , q ;
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    seg.build(1 , 1 , n) ;
    while(q --)
    {
        int op , l , r , x ;
        cin >> op >> l >> r >> x ;
        if(op == 1)  seg.update(1 , 1 , n , l , r , x) ;
        else  
        {
            auto [t , c] = seg.update(1 , 1 , n , l , r) ;
            x ^= t ;
            if(x == 0)  cout << 0 << '\n' ;
            else  cout << c[__lg(x)] << '\n' ;
        }
    }

    return 0 ;
}