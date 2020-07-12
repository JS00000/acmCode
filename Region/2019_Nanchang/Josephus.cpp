LL Josephus(LL n , int k)  //n个人围城一个圈，报到k的出圈
{                    //函数返回的答案是[0~n-1]
    LL ans;
    if ( n == 1 ) return 0;
    if ( n < k )
    {
        ans = 0;
        rep(i,2,n) ans = ( ans + k ) % i; //小规模直接倒推
        return ans;
    }
    else
    {
        ans = Josephus( n - n/k , k );
        if ( ans < n % k )
        {
            ans = ans - n % k + n;
        }
        else ans = ans - n % k + ( ans - n % k )/( k - 1 );
    }
    return ans;
}
