ll nCr(int n, int k)
{
    ll ans[n+1][k+1];
    int i,j;

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= min(i,k); j++){

            if(j == 0 || j == i)
                ans[i][j] = 1;
            else{
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
    }
    return ans[n][k];
}
