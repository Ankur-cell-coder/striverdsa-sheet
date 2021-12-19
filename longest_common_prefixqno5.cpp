#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string arr[n][200];
      int minm=200;
        for(int i=0;i<n;i++)
        {
          string cur=strs[i];
          string str="";
          int n1=cur.size();
          minm=min(minm,n1);
          for(int j=0;j<cur.size();j++)
          {
            str+=cur[j];
            arr[i][j]=str;
          }
        }
      
        string ans="";
      bool f1=1;
       for(int i=0;i<minm;i++)
       {
         string per=arr[0][i];
         for(int j=0;j<n;j++)
         {
            if(arr[j][i]!=per)
            {
              return ans;
              f1=0;
              break;
            }
         }
         if(f1)
           ans=per;
         else
           break;
       }
      return ans;
      
    }

  string longestCommonPrefix2(vector<string>& strs) {
      if(strs.size()==0)
        return "";
      string res=strs[0];
      
      for(int i=1;i<strs.size();i++)
      {
        int n1=strs[i].size();
        int n=res.size();
         string cur="";
        if(n1==0||n==0)
          return "";
         for(int j=0;j<min(n,n1);j++)
         {
           if(res[j]==strs[i][j])
             cur+=res[j];
           else
             break;
         }
        res=cur;
      }
        return res;
    }

   string longestCommonPrefix3(vector<string>& strs) {
        int minm=int(strs[0].size());
        for(int i=1;i<strs.size();i++)
        {
           int n=strs[i].size();
           minm=min(minm,n);
        }
      if(minm==0)
        return "";
      int n=strs.size();
       int l=0;
       int r=minm;
       while(l<=r)
       {
          int mid=(r+l)/2;
          string per=strs[0].substr(0,mid);
         bool f1=1;
          for(int i=1;i<n;i++)
          {
            if(per!=strs[i].substr(0,mid)){
              f1=0;
              break;
            }
          }
         
         if(f1)
         {
           l=mid+1;
         }
         else
           r=mid-1;
         
       }
      return strs[0].substr(0,(l+r)/2);
      
    }