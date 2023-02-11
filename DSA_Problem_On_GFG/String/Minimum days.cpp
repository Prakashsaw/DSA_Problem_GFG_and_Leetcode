/*
Q_Name:- Minimum Days
platform:- GFG

*/
class Solution {
    // bool allAreDifferent(string str) {
    //     int n = str.length();
    //     for(int i = 0; i < n; i++) {
    //         if(i+1 < n && str[i] != '?' && str[i] == str[i+1]) return false;
    //     }
    //     return true;
    // }
  public:
    int getMinimumDays(int n, string s, vector<int> &p) {
        
        //Brute force
        
        // if(allAreDifferent(s)) return 0;
        // int day = 0;
        // for(int i = 0; i < n; i++) {
        //     s[p[i]] = '?';
        //     day++;
        //     if(allAreDifferent(s)) return day;
        // }
        // return -1;
        //TC = O(N*N)
        //SC = O(1)
        
        
        int cnt = 0;
        for(int i = 0; i < n-1; i++) {
            while(s[i] != '?' && s[i] == s[i+1]) {
                s[p[cnt]] = '?';
                cnt++;
            }
        }
        return cnt;
        //TC = O(N)
        //SC = O(1)
        
        
    }
};
