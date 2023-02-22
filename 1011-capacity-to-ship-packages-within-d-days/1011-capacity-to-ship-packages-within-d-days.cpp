class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
       
       int lo = *max_element(weights.begin(), weights.end());
       int hi = accumulate(weights.begin(), weights.end(), 0);
       int res = hi;

       while(hi>=lo)
       {
           int mid = lo + (hi - lo)/2;
           int temp = 0;
           int val = 0;
           int curr = 0;

           for(int i = 0; i < n; ++i)
           {
               if(val>mid)
               {
                  temp++;
                  val = curr;    
               }

               else if(val == mid)
               {
                   val = 0;
                   temp++;
               }
               
               val += weights[i];
               curr = weights[i];

           }

           if(val > 0) temp += ((val+mid-1)/mid);

           if(temp <= days)
           {
              hi = mid - 1;
              res = min(mid, res);
           }

           else lo = mid + 1;

       }

        return res;
    }
};