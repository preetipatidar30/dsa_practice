class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
      
       while( s.find(part)<s.length()){
        int a=s.find(part);
        s.erase(a,part.length());
       }
       return s;
    }
};