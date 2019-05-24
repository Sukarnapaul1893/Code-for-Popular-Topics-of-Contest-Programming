#include<bits/stdc++.h>

using namespace std;

int sum[400020];
int arr[100005];

int query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r)return sum[at];

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);

    return (x+y);
}

void update(int at, int L, int R, int pos, int u ){
    if(L==R){
        sum[at]+=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }

    sum[at] = sum[at*2] + sum[at*2+1];
}

void build(int at , int L, int R){
    sum[at]=0;
    if(L==R){
        sum[at]=arr[L];
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    sum[at] = sum[at*2] + sum[at*2+1];

}


int main(){
    int n;
    n=8;


    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    build(1,1,8);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,8,3,1);
    cout<<query(1,1,n,1,3)<<endl;
    cout<<endl;
    for(int i=1;i<=15;i++){
        cout<<sum[i]<<"\n";
    }
}
