class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int,int> pair;
        int count=0;
        int min_length = INT_MAX;
        
        for(int i=0;i<cards.size();i++){

            if(pair.find(cards[i])!=pair.end()){
                count = (i-pair[cards[i]]+1);
                min_length = min(min_length, count);
            }
            pair[cards[i]]=i;
            
        }
        if(min_length  == INT_MAX)
        return -1;
        else
        return min_length;
    }
};