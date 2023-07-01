#include<bits/stdc++.h>

using namespace std;

bitset<300000001>prime;

void sieve(){
    for(long long i=2;i*i<=300000001;i++){
        if(i>2)i++;
        for(long long j=i*i;j<=300000001 && !prime[i];j+=i){
            prime[j]=1;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(!prime[a]){
            cout<<a<<" is a Prime number\n";
        }
        else{
            cout<<a<<" is a not Prime number\n";
        }
    }

}
