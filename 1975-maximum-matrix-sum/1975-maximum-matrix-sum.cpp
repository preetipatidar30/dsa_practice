class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        int maxi=INT_MAX;
        long long sum=0;
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            if(matrix[i][j]<0){
                neg++;
                }
            maxi=min(maxi,abs(matrix[i][j]));
              sum +=abs(matrix[i][j]);
        }
       }
       if(neg%2==1){
        sum-=2LL *maxi;
       }
       return sum;
    }
};
