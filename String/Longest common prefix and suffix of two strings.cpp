#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;
//returns the longest prefix length of b which exists as the a suffix of a
//z[i] holds the length of the longest substring of which is also prefix
int largest_prefix_suffix(string a, string b) {

	b+='$';
	b+=a;
	vector<int>Z(b.length(),0);
	int l=0,r=0,pre;
	for(int i=1;i<b.length();i++){
		int c=0;
		if(i>r){
			l=r=i;
			while(r<b.length()&&b[r]==b[r-l]){
				c++;
				r++;
			}
		}
		else{
			if(Z[i-l]>r-i){
				c=r-i;
				l=i;
				while(r<b.length()&&b[r]==b[r-l]){
					c++;
					r++;
				}
			}
			else c=Z[i-l];
		}
		r--;
		Z[i]=c;
	}
	int x=0;
	for(int i=0;i<b.length();i++){
		if(Z[i]+i==b.length()){
			x=Z[i];
			break;
		}
	}
	return x;

}
int main(){
	IOS
	//freopen("output.txt","w",stdout);
    string s1,s2;
    cin>>s1>>s2;
    int x = largest_prefix_suffix(s1,s2);
    cout<<x;

}
