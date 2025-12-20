class Solution {
public:
bool sorted_or_not(string & str){
    if(str.size()==0){
        return false;
    }
    string str_sor=str;
    sort(str_sor.begin(),str_sor.end());
    return str_sor==str;
}

    int minDeletionSize(vector<string>& strs) {
        if(strs.size()==0){
            return 0;
        }
        int n=strs.size();
        int m=strs[0].length();
        int count =0;
        for(int i=0;i<m;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+=strs[j][i];

            }
            if(sorted_or_not(str)==false){
                count++;
            }
        }
        return count;
        
    }
};