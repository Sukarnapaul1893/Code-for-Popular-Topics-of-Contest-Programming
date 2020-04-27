LL phi(LL x) {
    LL ans = x;
 
    for (LL i=2; i*i <= x; i++) {
        if (x%i)    continue;
        while (x%i==0)  x/=i;
        ans = (ans/i)*(i-1);
    }
 
    if (x > 1)  ans = (ans/x)*(x-1);
    return ans;
}
