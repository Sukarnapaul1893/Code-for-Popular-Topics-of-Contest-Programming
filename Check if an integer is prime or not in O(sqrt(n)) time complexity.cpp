#include<bits/stdc++.h>

using namespace std;

//check_Prime fucntion returns true if n is a prime number, otherwise returns fasle
bool check_Prime(int n){
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;

    scanf("%d",&n);
    if(check_Prime(n)==true){
        printf("%d is a Prime number",n);
    }
    else{
        printf("%d is not a Prime number",n);
    }
}
