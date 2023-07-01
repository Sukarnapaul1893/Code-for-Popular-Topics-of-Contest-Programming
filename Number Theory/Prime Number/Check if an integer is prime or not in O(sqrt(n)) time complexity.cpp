#include <bits/stdc++.h>

using namespace std;
bool Check_if_Prime (int n) {
	if(n==1)return false;
	if(n % 2 == 0 && n>2){
		return false;
}
for(int i=3; i*i<=n; i+=2){
		if(n % i == 0){
	return false;
}
}
return true;
}

int main() {

    int t;
    cin>>t;

    for(int i=0;i<t;i++){

        int x;
        cin>>x;
        if(Check_if_Prime (x)){
            cout<<x<<" eh primo\n";
        }
        else{
            cout<<x<<" nao eh primo\n";
        }
    }

    return 0;
}
