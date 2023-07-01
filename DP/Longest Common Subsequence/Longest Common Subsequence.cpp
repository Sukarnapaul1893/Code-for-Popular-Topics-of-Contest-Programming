// Longest common subsequence (LCS)
#include<bits/stdc++.h>

#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;

string a,b;
int lena,lenb, dp[3005][3005];

int LCS(){
    string ans;
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]){
                dp[i][j] =max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    int i=lena, j=lenb;
    while(i && j){
        if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else if(dp[i][j]==dp[i][j-1]){
            j--;
        }
        else{
            ans+=a[i];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return dp[lena][lenb];
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    cin>>a>>b;
    lena=a.length();
    lenb=b.length();
    a=" "+a;
    b=" "+b;
    int lcs= LCS();
    cout<<endl<<lcs;
}
