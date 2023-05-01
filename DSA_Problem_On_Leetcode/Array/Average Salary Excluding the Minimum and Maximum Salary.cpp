/*
Q_Id:- 1491.
Q_Name:- Average Salary Excluding the Minimum and Maximum Salary
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 

Constraints:

3 <= salary.length <= 100
1000 <= salary[i] <= 106
All the integers of salary are unique.


*/

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        if(n <= 2) return 0;

        int mx = INT_MIN;
        int mn = INT_MAX;

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += salary[i];

            if(mx < salary[i]) {
                mx = salary[i];
            }

            if(mn > salary[i]) {
                mn = salary[i];
            }
        }

        sum -= (mx+mn);

        double ans = (double)sum/(n-2);

        return ans;

        
    }
};