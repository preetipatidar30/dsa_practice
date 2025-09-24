class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        for(int i=0;i<n;i++){
           if(freq[s[i]]==1){
            return i;
           }

        }
        return -1;
    }
};