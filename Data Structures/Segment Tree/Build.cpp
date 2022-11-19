ll Build(int at, int L, int R){
    if(L==R){
        return sum[at] = a[L];
    }
    int mid = (L+R)/2;
    sum[at] += Build(at*2, L, mid);
    sum[at] += Build(at*2+1, mid+1, R);
    return sum[at];
}
