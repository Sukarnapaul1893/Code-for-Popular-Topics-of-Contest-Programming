#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int lp[10000001];

vector<int>prime;

void FindLowestPrimeFactor(){
    for(int i=2;i<=10000001;i++){
        if(lp[i]==0){
            lp[i]=i;
            prime.pb(i);
        }
        for(int j=0;j<prime.size();j++){
            if(lp[i]<prime[j])break;
            if(i*prime[j]>10000000)break;

            lp[i*prime[j]]=prime[j];
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    FindLowestPrimeFactor();

}
