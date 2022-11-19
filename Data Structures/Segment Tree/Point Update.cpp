void PointUpdate(int at, int L, int R, int pos, ll u ){
    if(L>pos || R<pos)return ;

    if(L==R){
        sum[at]=u;
        return ;
    }

    int mid = (L+R)/2;
    PointUpdate(at*2,L,mid,pos,u);
    PointUpdate(at*2+1,mid+1,R,pos,u);
    sum[at] = sum[at*2]+sum[at*2+1];
}
