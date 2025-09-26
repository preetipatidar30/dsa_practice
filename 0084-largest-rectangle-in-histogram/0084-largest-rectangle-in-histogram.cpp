class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;

       stack<int> s1;
       vector<int> right(n,-1);
       for(int i=n-1;i>=0;i--){
            while (!s1.empty() && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            if (s1.empty()) right[i] = n;
            else right[i] = s1.top();
            s1.push(i);
       }
       while(!s1.empty()){
        s1.pop();
       }
       vector<int> left(n,-1);
       for(int i=0;i<n;i++){
        while (!s1.empty() && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            if (s1.empty()) left[i] = -1;
            else left[i] = s1.top();
            s1.push(i);
       }
      int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] -1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
       
    }
};