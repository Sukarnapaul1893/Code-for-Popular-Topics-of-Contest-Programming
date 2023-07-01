//collected from : https://github.com/hackerkid/LightOJ-Solutions/blob/master/1110-An-Easy-LCS.cpp
#include<bits/stdc++.h>
using namespace std;

string Minstring(string x, string y)
{
	if(x.length() < y.length()) {
		return y;
	}

	if(x.length() > y.length()) {
		return x;
	}

	for (int i = 0; i < x.length(); i++) {
		if(x[i] < y[i]) {
			return x;
		}

		if(x[i] > y[i]) {
			return y;
		}

	}

	return x;

}



int main()
{


	string x;
	string y;

	char xx[110];
	char yy[110];
	char ans[110];

	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; cs++) {

		string a[110][110];

		scanf("%s", xx);
		scanf("%s", yy);

		x = xx;
		y = yy;
        int n;
        int m;
		n = x.length();
		m = y.length();

		for (int i = n; i >= 0; i--) {
			for (int j = m; j >= 0; j--) {
				if(i == n or j == m) {
					a[i][j] = "";
					continue;
				}

				if(x[i] == y[j]) {
					a[i][j] = x[i] + a[i+1][j+1];
					continue;
				}

				a[i][j] = Minstring(a[i+1][j],a[i][j+1]);
			}


		}

		for (int i = 0; i < a[0][0].length(); i++) {
			ans[i] = a[0][0][i];
		}

		ans[a[0][0].length()] = '\0';

		if(a[0][0].length() != 0) {
			printf("Case %d: %s\n", cs, ans);

		}

		else {
			printf("Case %d: :(\n", cs); //If length is 0;
		}

	}

}
