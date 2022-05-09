#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back

using namespace std;

ll a,b;

void Input();

void Solve(){
    cout<<a+b<<"\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        Input();
        Solve();
        Clear();
    }
    
}

void Input(){
    cin>>a>>b;
}
