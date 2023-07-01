#include<bits/stdc++.h>

using namespace std;
int sod[1000001]={0};
void sieve ()
{
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j =  i; j <= 1000000; j+=i)
			{
				sod[j] += i;
			}
	}
}
int main(){
    ios::sync_with_stdio(false);


    sieve();

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<"Sum of divisors for "<<a<<" is "<<sod[a]<<endl;
    }

}
