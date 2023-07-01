//Light oj 1080
#include<bits/stdc++.h>

using namespace std;

int toggle[400020];
char arr[100005];

int query(int at, int L, int R, int pos){
    if(L>pos || pos>R)return 0;

    if(L == R)return toggle[at];

    int mid = (L+R)/2;
    if(pos<=mid)return toggle[at]^query(at*2,L,mid,pos);
    else return toggle[at]^query(at*2+1,mid+1,R,pos);
}

void update(int at, int L, int R, int l, int r ){
    if(L>r || R<l)return ;

    if(l<=L && r>=R){
        toggle[at]^=1;
        return ;
    }

    int mid = (L+R)/2;
    update(at*2,L,mid,l,r);
    update(at*2+1,mid+1,R,l,r);
}

void build(int at , int L, int R){
    toggle[at]=0;
    if(L==R){
        toggle[at]=arr[L]-'0';
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    //getchar();
    for(int tt=0;tt<t;tt++){
        string s;
        cin>>s;
        int n=s.length();
        for(int i=1;i<=n;i++){
            arr[i]=s[i-1];
        }
        build(1,1,n);
        int q;
        cin>>q;
        bool bl=false,bl2=false;
        printf("Case %d:\n",tt+1);
        for(int i=0;i<q;i++){
            char c;
            cin>>c;

            if(c=='I'){
                int l,r;
                cin>>l>>r;
                update(1,1,n,l,r);
            }
            else{
                int pos;
                cin>>pos;
                int x=query(1,1,n,pos);

                printf("%d\n",x);
            }

        }

    }
}
