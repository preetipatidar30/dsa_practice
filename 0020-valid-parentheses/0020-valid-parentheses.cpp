class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
    int n=s.size();
    if(n==0){
        return true;
    }
        for(int i=0;i<n;i++){
           if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                s1.push(s[i]);
            
            }else
            {
                if (s1.empty()) {
                    return false;
                }if ((s[i] == '}' && s1.top() == '{') ||
                    (s[i] == ']' && s1.top() == '[') ||
                    (s[i] == ')' && s1.top() == '(')){
                
                s1.pop();

            }else{
                return false;
            }
        }

        }
        return s1.empty();
        
    }
};