vector <int> prime;
bitset <10000010> bs;

void sieve (int N){
	bs.set ();
    //prime.pb(2);
	for (int i = 2; i <= N; i++){
		if (bs[i])prime.pb(i);

		for (int j = 0; j<prime.size() && i*prime[j]<=N; j++){
		    bs[i*prime[j]] = 0;
		    if(i%prime[j]==0)break;
		}
	}
}
