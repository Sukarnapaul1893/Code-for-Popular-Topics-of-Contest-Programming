ll RangeQuery(int at, int L, int R, int l, int r){
    if(L>r || R<l)return 0;

    if(l<=L and r>=R)return sum[at];

    int mid = (L+R)/2;

    return RangeQuery(at*2,L,mid,l,r)
            + RangeQuery(at*2+1,mid+1,R,l,r);
}
