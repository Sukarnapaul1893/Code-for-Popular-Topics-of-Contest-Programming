//Counting number of digits in factorial n of base b

#include<bits/stdc++.h>

using namespace std;

void counting_digits(int n, int b){
    double x=0;
    for(int i=2;i<=n;i++){
        x += log(i);
    }
    x = x/log(b);
    x+=1.0;
    x = floor(x);
    cout<<(int)x<<"\n";
}

int main(){
    int n,b;
    cin>>n>>b;
    counting_digits(n,b);
}
