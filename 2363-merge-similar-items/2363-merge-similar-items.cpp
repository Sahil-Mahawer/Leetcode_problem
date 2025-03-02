class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
      sort(begin(items1), end(items1));
      sort(begin(items2), end(items2));

      int n = items1.size();
      int m = items2.size();

      int i = 0, j = 0;

      vector<vector<int>> result;

      while(i<n && j<m)
      {

        if(items1[i][0] < items2[j][0]){
            result.push_back(items1[i]);
            i++;
        }
        else if(items2[j][0] < items1[i][0]){
            result.push_back(items2[j]);
            j++;
        }

        else{  // both first value are same 
            result.push_back({items1[i][0], items1[i][1] + items2[j][1]});
            i++;
            j++;
        }
      }

      while(i<n){
            result.push_back(items1[i]);
            i++;
      }

      while(j<m){
            result.push_back(items2[j]);
            j++;
      }

      return result;
    }
};