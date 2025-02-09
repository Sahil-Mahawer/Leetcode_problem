class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        int n = rectangles.size();
        long long count=0;

        vector<double> check(n);

        for(int i=0;i<n;i++){
            check[i] = (double) rectangles[i][0] / rectangles[i][1];
        }

        unordered_map<double,int> mp;
        mp[check[0]]=1;

        for(int i=1;i<n;i++){

            count = count+mp[check[i]];
            mp[check[i]]++;
        }

        return count;
    }
};