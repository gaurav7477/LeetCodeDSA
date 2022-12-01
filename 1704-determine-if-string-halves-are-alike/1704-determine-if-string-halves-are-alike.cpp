class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> check = {'a','e','i','o','u','A','E','I','O','U'};
        int x = s.size()/2;
        int count = 0;
        for(int i = 0; i<x; i++){
            if(check.find(s[i])!= check.end()) count++;
        }      
        for(int i = x; i < s.size(); i++){
            if(check.find(s[i])!= check.end()) count--;
        }
        return (count==0)? true : false; 
    }
};