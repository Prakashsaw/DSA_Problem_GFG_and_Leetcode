/*
Q_Name:- Maximum Possible Value
Platform:- gfg
*/
class Solution {
  public:
    long long maxPossibleValue(int n, vector<int> len_arr_a, vector<int> cnt_arr_b) {
        
        //TC = O(N)
        //SC = O(1)
        
        long long int ans = 0, sticks = 0, mini = INT_MAX;
        long long int len, cnt;
        
        for(int i = 0; i < n; i++) {
            len = len_arr_a[i];
            cnt = cnt_arr_b[i];
            
            //if cnt == odd then make it even
            if(cnt % 2 == 1) {
                cnt -= 1;
            }
            //if cnt >= 2 then candidate for mini among all len
            if(cnt >= 2) {
                mini = min(mini, len);
            }
            
            ans += (len * cnt);
            sticks += cnt; 
        }
        
        if(sticks % 4 != 0) {
            ans -= 2l * mini;
        }
        
        return ans;
        
    }
};