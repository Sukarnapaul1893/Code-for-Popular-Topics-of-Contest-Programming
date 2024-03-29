LightOJ-1255 - Substring Frequency
#include<bits/stdc++.h>

using namespace std;


int failure[1000001];
int cnt;
void build_failure_function(string pattern, int m) {
  failure[0] = 0;
  failure[1] = 0; //base case

  for(int i = 2; i <= m; i++) {  //i is length of the prefix we are dealing with
    // j is the index of the largest next partial match
    // (the largest suffix/prefix) of the string under index i - 1
    int j = failure[i - 1];
    while(true) {
      // check if the last character of prefix of length i "expands" the current "candidate"
      if(pattern[j] == pattern[i - 1]) {
        failure[i] = j + 1;
        break;
      }
      // if we cannot "expand" even the empty string
      if(j == 0) {
          failure[i] = 0;
          break;
      }
      // else go to the next best "candidate" partial match
      j = failure[j];
    }
  }
}


bool kmp(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  build_failure_function(pattern, m);

  int i = 0; // the initial state of the automaton is
         // the empty string

  int j = 0; // the first character of the text

  while(true) {
    if(j == n) {
        return false; //reached the end of the text
    }

    // character matched
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m) {
          cnt++;
      }
    } else {
        if (i == 0) {
            // if we reached the empty string and failed to
            // "expand" even it; we go to the next
            // character from the text, the state of the
            // automaton remains zero
            j++;
        }
        else {
             //we try to "expand" the next best (largest) match
            i = failure[i];
        }
    }
  }
  return false;
}

int main(){
	//IOS
	//freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        string a,b;
        cin>>a>>b;
        cnt=0;
        bool bl=kmp(a,b);

        cout<<"Case "<<tt+1<<": "<<cnt<<"\n";
    }
}
