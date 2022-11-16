class Solution {    
public:
    vector<int> findAnagrams(string s, string p) {
    
    int n = s.length(), m = p.length();
	
    if(m>n)
	    return {};
	
	vector<int> p_vector(26,0), s_vector(26,0), ans;
    
    for(int i=0;i<m;i++)
        p_vector[p[i]-'a']++;
    
    int i=0, j=0;
    
    while(j<n){
        s_vector[s[j]-'a']++;
        
		if((j-i+1)<m){            //When the current window size is smaller, just move ahead.
            j++;
        }
        
        else if((j-i+1)==m){                //On hitting the window.

            if(p_vector == s_vector)
                ans.push_back(i);

            s_vector[s[i]-'a']--;

            i++;
            j++;
        }
    }
    return ans;
	}
};