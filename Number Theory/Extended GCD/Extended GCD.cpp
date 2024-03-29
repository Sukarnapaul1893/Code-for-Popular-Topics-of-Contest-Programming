//Extended GCD

#include<bits/stdc++.h>

using namespace std;

int egcd(int a,int b,int &x, int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int d = egcd(b%a,a,x1,y1);

    x = y1-(b/a)*x1;
    y=x1;

    return d;

}

int main(){
    //ax + by = __gcd(a,b);
    int a,b,x,y;

    cin>>a>>b;

    cout<<"GCD of a and b : "<<egcd(a,b,x,y)<<"\n";
    cout<<x<<" "<<y;
}
