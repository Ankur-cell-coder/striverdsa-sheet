// que. no:- 2
//Given a string s, return the longest palindromic substring in s.

//solution idea:-
//we have two apporach one with time O(n^3)
//one with time O(n^2)

//first case:-
//check for every substring means create every substring and check for that whether that is palindrome or not.

// second case:-
// create a 2-D vector initialize its value to be 0
// every single character is palindrome in itself so marks every [i][i] as 1 means it is palindrome
// for 2 character check whether s[i]&& s[i+1] are equal or not if they are equal marks dp[i][i+1] as 1.
// from 3 to n-1 run a loop to check whether first character equal to last or not if they equal then check whether b/w i to i+1 string is palin
//drome or not.
// to check this we simply check dp[i+1][j-1]=1 or 0.

#include<bits/stdc++.h>
using namespace std;


 //first apporach 
 bool is_palindrome(string s)
   {
     int i=0;
     int j=s.size()-1;
     
     while(i<j)
     {
       if(s[i]!=s[j])
         break;
       i++;
       j--;
     }
     if(i<j)
       return 0;
     return 1;
   }
    string longestPalindrome1(string s) {
      
      int st=0;
      int n=s.size();
      int len=1;
      for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
           if(j-i+1>len)
           {
            if(is_palindrome(s.substr(i,j-i+1)))
             {
               st=i;
               len=j-i+1;
             }
           }
        }
      }
      
      return s.substr(st,len);
      
      
    }
//second apporach
string longestPalindrome(string s) {
      int n=s.size();
      int dp[n][n];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
          dp[i][j]=0;
      }
      string str="";
       int st=0;
      int max_length=1;
      for(int i=0;i<n;i++)
      {
        dp[i][i]=1;
      }
     
      for(int i=0;i<n-1;i++)
      {
        if(s[i]==s[i+1]){
          dp[i][i+1]=1;
           if(max_length<2)
           {
             max_length=2;
             st=i;
           }
        }
      }
      
      
      for(int i=3;i<=n;i++)
      {
        for(int j=0;j<n-i+1;j++)
        {
          if(s[j]==s[j+i-1]&&dp[j+1][j+i-2])
          {
            dp[j][j+i-1]=1;
            if(max_length<i)
           {
             max_length=i;
             st=j;
           }
          }
        }
      }
      return s.substr(st,max_length);    
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;  
    return 0;
}