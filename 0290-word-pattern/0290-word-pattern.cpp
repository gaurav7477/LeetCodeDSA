#include <bits/stdc++.h>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mpp1;
        map<string,char> mpp2;
        s.push_back(' ');
        string hehe = "";
        int i=0;
        int j=0;
        for(i=0,j=0;i<s.size();i++){
              if(s[i]==' '){
                  if(mpp1.find(pattern[j]) == mpp1.end() && mpp2.find(hehe) == mpp2.end()){
                     mpp1[pattern[j]]=hehe;
                     mpp2[hehe]=pattern[j];
                     hehe="";
                     j++;
                  }
                  else if(mpp1[pattern[j]]==hehe && mpp2[hehe]==pattern[j]){
                      hehe="";
                      j++;
                  }
                  else return false;
              }
              else hehe.push_back(s[i]);

        }
        if(i==s.size() && j==pattern.size()) return true;
        return false;
    }
};