/* problem statement:-
  
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note:- that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces. */

#include<bits/stdc++.h>
using namespace std;

//O(1) space and O(n) time
/*
logic:-

we move to whole string and whenever we get break or space between two words then at that point
add that word to our res.

use two string str and res and initialize both of them with null.

str used to store current word and res for final results.

we update res in such a way that cur word got first position. 

like res= str+res;

in this situation res get updated and value which are on res got after str.
for maintaning proper space and escape space for empty section we only update res only those time 
when we have something on our str.
str should not be empty
and also add space whenever we add any string to our results.


*/
 string reverseWords(string s) {
      string str="";
      string res="";
      for(int i=0;i<s.size();i++)
      {
        if(s[i]==' '){
          if(str.size()>=1)
          {
            if(res.size()>=1)
            res=' '+res;
            res=str+res;
          }
          str="";
          continue;
        }
        str+=s[i];
      }
      if(str.size()>=1){
        if(res.size()>=1)
            res=' '+res;
      res=str+res;
      }
      return res;
}

//O(n) space O(n) time
/*
logic:-
 
 maintain a stack and every time when we got any string with size > 0 push that to stack 
 and after that maintain pop 
 because stack follow fifo that so string come first out last.
 
*/
string reverseWords1(string s) {
      stack<string>st;
      string str="";
      for(int i=0;i<s.size();i++)
      {
        if(s[i]==' '){
          if(str.size()>=1)
          st.push(str);
          str="";
          continue;
        }
        str+=s[i];
      }
      if(str.size()>=1)
      st.push(str);
      s="";
      while(!st.empty())
      {
        
        s+=st.top();
        if(st.size()>1)
          s+=' ';
        st.pop();
      }
      return s;
}

int main()
{
    string s;
    cin>>s;
    getline(cin, s);
    cout<<reverseWords(s)<<endl;
    cout<<reverseWords1(s)<<endl;
    return 0;
}
