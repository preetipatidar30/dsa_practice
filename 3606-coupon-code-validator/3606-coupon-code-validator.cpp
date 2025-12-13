class Solution {
public:
bool isvalid(string a){
    if(a.empty()){
        return false;
    }
    for(char c:a){
       if (!(isalnum(c) || c == '_')) {
            return false;
        }
    
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
         vector<string> electronics, grocery, pharmacy, restaurant;
       for(int i = 0; i < n; i++){
            if(isvalid(code[i]) && isActive[i]){

                if(businessLine[i] == "electronics"){
                    electronics.push_back(code[i]);
                }
                else if(businessLine[i] == "grocery"){
                    grocery.push_back(code[i]);
                }
                else if(businessLine[i] == "pharmacy"){
                    pharmacy.push_back(code[i]);
                }
                else if(businessLine[i] == "restaurant"){
                    restaurant.push_back(code[i]);
                }
            }
        }

        // sort within each category
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        // merge in required order
        vector<string> aa;
        aa.insert(aa.end(), electronics.begin(), electronics.end());
        aa.insert(aa.end(), grocery.begin(), grocery.end());
        aa.insert(aa.end(), pharmacy.begin(), pharmacy.end());
        aa.insert(aa.end(), restaurant.begin(), restaurant.end());

        return aa;
        
    }
};