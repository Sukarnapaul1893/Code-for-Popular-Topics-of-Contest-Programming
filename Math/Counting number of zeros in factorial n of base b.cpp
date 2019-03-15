#include<bits/stdc++.h>
#define ll long long
using namespace std;

int count_zeros(int n,int b){
    int ans=n;
    int temp = b;
    for(int i=2;i<=b;i++){
        int power =0;

        if(temp%i==0){

            while(temp%i==0){
                power++;
                temp/=i;
            }

            int tempn=n;
            int sum=0;
            while(tempn/i>0){
                sum+=tempn/i;
                tempn/=i;

            }
            sum/=power;
            ans= min(ans,sum);
        }
    }
    return ans;
}

int main(){
    ll n,b;
    cin>>n>>b;
    cout<<count_zeros(n,b);
}
