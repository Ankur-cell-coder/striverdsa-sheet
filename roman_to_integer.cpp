//Given a roman numeral, convert it to an integer.

//There are six instances where subtraction is used:
/*
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
*/

#include<bits/stdc++.h>
using namespace std;


/*
logic:-
just split all character according to their value
after that if previous value is less than current than substract that from 
current otherwise add.
*/

int romanToInt1(string s) {
     map<char,int>mp;
      mp['I']=1;
      mp['V']=5;
      mp['X']=10;
      mp['L']=50;
      mp['C']=100;
      mp['D']=500;
      mp['M']=1000;
      int ans=0;
      
      if(s.size()==1)
      {
        return mp[s[0]];
      }   
      int i=0;
      while(i<s.size())
      {
         if(i+1<s.size()&&mp[s[i]]<mp[s[i+1]])
         {
           ans+=mp[s[i+1]]-mp[s[i]];
           i+=2;
         }
        else
        {
          ans+=mp[s[i]];
          i++;
        }
      }
      return ans;
      
      
    }


    int romanToInt2(string s) {
     map<char,int>mp;
      mp['I']=1;
      mp['V']=5;
      mp['X']=10;
      mp['L']=50;
      mp['C']=100;
      mp['D']=500;
      mp['M']=1000;
      int ans=0;
      
      if(s.size()==1)
      {
        return mp[s[0]];
      }
      
      vector<int>v1;
     for(int i=0;i<s.size();i++)
     {
       v1.push_back(mp[s[i]]);
     }
    
      vector<int>v2;
      for(int i=1;i<v1.size();i++)
      {
        if(v1[i-1]<v1[i])
        {
          v2.push_back(v1[i]-v1[i-1]);
          i++;
          if(i==v1.size()-1){
            v2.push_back(v1[i]);
            break;
          }
        }
        else if(i==v1.size()-1)
        {
          v2.push_back(v1[i-1]);
          v2.push_back(v1[i]);
        }
        else 
         v2.push_back(v1[i-1]);
        
      }
      
      for(int i=0;i<v2.size();i++)
      {
      //  cout<<v2[i]<<" ";
        ans+=v2[i];
      }
      
      return ans;
      
      
    }

    int romanToInt3(string s) {
     unordered_map<char,int>mp;
      mp['I']=1;
      mp['V']=5;
      mp['X']=10;
      mp['L']=50;
      mp['C']=100;
      mp['D']=500;
      mp['M']=1000;
      int ans=0;
      
      if(s.size()==1)
      {
        return mp[s[0]];
      }    
      for(int i=1;i<s.size();i++)
      {
        if(mp[s[i-1]]<mp[s[i]])
        {
         ans+=(mp[s[i]]-mp[s[i-1]]);
          i++;
          if(i==s.size()-1){
            ans+=(mp[s[i]]);
            break;
          }
        }
        else if(i==s.size()-1)
        {
          ans+=(mp[s[i-1]]);
          ans+=(mp[s[i]]);
        }
        else 
         ans+=(mp[s[i-1]]);
        
      }
      return ans;
      
      
    }



int main()
{
    string s;
    cin>>s;
   
    return 0;
}