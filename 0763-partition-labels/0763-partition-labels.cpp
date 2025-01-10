class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]] = i;           // storing the last occurences (index) of each character 
        }

        int start = 0;
        int end = -1;
        vector<int> result;
        

        for(int i=0;i<s.size();i++){
            // Update the end of the current partition based on the last occurrence of the current character
            end = max(end, mpp[s[i]]);  

           // If the current index reaches the end of the partition
            if(i==end){

                int partition_size = i-start+1;
                result.push_back(partition_size); 

                start = i+1;
            }

            
        }
        return result;
    }
};