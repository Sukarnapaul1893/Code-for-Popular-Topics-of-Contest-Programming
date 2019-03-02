#include<bits/stdc++.h>

using namespace std;
vector <long long> prime;
bitset <10000010> bs;

void sieve ()
{
	bs.set ();

	for (long long i = 2; i < 10000000; i++)
	{
		if (bs[i])
		{
			prime.push_back(i);
			for (long long j = i * i; j < 10000000; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
int main(){

    sieve();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<prime[i]<<"\n";
    }
}
