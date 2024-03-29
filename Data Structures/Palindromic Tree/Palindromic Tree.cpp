#include<bits/stdc++.h>

using namespace std;

const int N = 200005;
int tree[N][26],idx;
int len[N], link[N], t;
char s[N];

int cas;
int vis[N][26];

void intitialization(){
    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    cas++;
    idx = t = 2;
}

void extend(int p) {
  while(s[p - len[t] - 1] != s[p]) t = link[t];
  int x = link[t], c = s[p] - 'a';
  while(s[p - len[x] - 1] != s[p]) x = link[x];
  if(vis[t][c]!=cas) {
    vis[t][c]=cas;
    tree[t][c] = ++idx;
    len[idx] = len[t] + 2;
    link[idx] = (len[idx] == 1) ? 2 : tree[x][c];
  } t = tree[t][c];
}


int main(){

    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++){
        intitialization();
        scanf(" %s",s+1);
        int l = strlen(s+1);
        for(int i=1;i<=l;i++){
            extend(i);
        }
        printf("Case #%d: %d\n",tt,idx-2); //number of distinct palindrome substrings
    }
}
