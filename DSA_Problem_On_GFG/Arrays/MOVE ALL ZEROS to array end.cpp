/*
Q_Name:- Move all zeroes to end of array
gfg
Q_Description:- 
    Given an array arr[] of N positive integers. 
    Push all the zeros of the given array to the 
    right end of the array while maitaining the 
    order of non-zero elements.
    
*/
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	   // //brute force 
	   // //taking extra space
	   // //TC = O(N)
	   // //SC = O(N)
	   // vector<int> non_zero;
	   // int cnt = 0;
	   // for(int i = 0; i < n; i++) {
	   //     if(arr[i] == 0) {
	   //         cnt++;
	   //     }
	   //     else{
	   //         non_zero.push_back(arr[i]);
	   //     }
	   // }
	   // int k = 0;
	   // for(int i = 0; i < non_zero.size(); i++) {
	   //     arr[k++] = non_zero[i];
	   // }
	   // for(int i = 0; i < cnt; i++) {
	   //     arr[k++] = 0;
	   // }
	    
	    //Optimize 
	    //By inplace approach
	    //by two pointer approach
	    
	    int j = 0;
	    int i = 0;
	    while(i < n && j < n) {
            if(arr[j] != 0) {
                j++;
            } else {
                if(arr[i] == 0 || i <= j) {
                    i++;
                } else {
                    swap(arr[i], arr[j]);
                    i++;
                    j++;
                }
            }
	    }
	}
};