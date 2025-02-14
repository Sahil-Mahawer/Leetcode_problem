class ProductOfNumbers {
public:
// vector<int> store;  

vector<int> cummulative_prod;  
int n; 

    ProductOfNumbers() {
        n = 0;
    }
    
    void add(int num) {
        // store.push_back(num);

        if(num ==0){
            cummulative_prod = {};
            n=0;
        }
        else{
            if(cummulative_prod.empty()){ // empty hai
                cummulative_prod.push_back(num);
            }
            else{ // empty nhi hai 
                cummulative_prod.push_back(cummulative_prod[n-1]*num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        // int prod=1;
        // int i= store.size()-1;
        // while(k){
        //     prod = prod*store[i];
        //     i--;
        //     k--;
        // }

        // return prod;

        if(n<k){
            return 0;
        }

        else if(n==k){
            return cummulative_prod[n-1];
        }

        return cummulative_prod[n-1]/cummulative_prod[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */