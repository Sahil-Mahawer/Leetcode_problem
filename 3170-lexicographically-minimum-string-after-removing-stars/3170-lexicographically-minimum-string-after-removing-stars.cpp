class Solution {
public:

typedef pair<char,int> p;

struct compare{

    bool operator()(p &p1, p &p2){

        if(p1.first == p2.first){

            return p1.second < p2.second;
        }

        return p1.first > p2.first;
    }
};

    string clearStars(string s) {

        int n = s.size();
        string result;
        
        priority_queue<p, vector<p> , compare> pq;  // here it is minheap on the basis of character , means smallest character at the top of heap . but if the smallest character are same then it will sort on the basis of index means larger index at the top or we can say the smallest char which appears at last should be at top becoz we want samallest lexogrphically string .. so smallest char at smallest index should remain as it is.   

        for(int i=0; i<n; i++){

            if(s[i] != '*'){
                pq.push(make_pair(s[i], i));
            }
            else{
                int idx = pq.top().second;
                pq.pop();

                s[idx] = '*';
            }
        }


        for(int i=0; i<n; i++){

            if(s[i] != '*' ){

                result.push_back(s[i]);
            }
        }

        return result;
    }
};