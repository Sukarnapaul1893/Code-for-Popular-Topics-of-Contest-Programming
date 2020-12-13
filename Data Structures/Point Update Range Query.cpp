#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll xorr[1200020];
ll a[300005];

int query(int at, int L, int R, int l, int r){
    if(L>r || R<l)return 0;

    if(l<=L and r>=R)return xorr[at];

    int mid = (L+R)/2;

    return query(at*2,L,mid,l,r)^query(at*2+1,mid+1,R,l,r);
}

void update(int at, int L, int R, int pos, ll u ){
    if(L>pos || R<pos)return ;

    if(L==R){
        xorr[at]^=u;
        return ;
    }

    int mid = (L+R)/2;
    update(at*2,L,mid,pos,u);
    update(at*2+1,mid+1,R,pos,u);
    xorr[at] = xorr[at*2]^xorr[at*2+1];
}

ll build(int at , int L, int R){

    if(L==R){
        xorr[at]=a[L];
        return xorr[at];
    }
    int mid = (L+R)/2;
    ll u = build(at*2,L,mid);
    ll v = build(at*2+1,mid+1,R);

    xorr[at] = u^v;
    return xorr[at];
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);


    for(int i=0;i<q;i++){
        int type ;
        cin>>type;

        if(type==1){
            int x,y;
            cin>>x>>y;
            update(1,1,n,x,y);
        }
        else{
            int L,R;
            cin>>L>>R;
            cout<<query(1,1,n,L,R)<<"\n";
        }
    }

}
