class Solution {
    int binarySearch_Recursive(int arr[], int s, int e, int k) {
        if(s > e) return -1;
        int mid = s+(e-s)/2;
        
        if(arr[mid] == k) return mid;
        
        else if(arr[mid] > k) return binarySearch_Recursive(arr, s, mid-1, k);
        
        else binarySearch_Recursive(arr, mid+1, e, k);
    }

  public:
    int binarysearch(int arr[], int n, int k) {
        
        //Recursive
        int s = 0;
        int e = n-1;
        return binarySearch_Recursive(arr, s, e, k);

        /*
        //Iterative version
        int s = 0;
        int e = n-1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            if(arr[mid] == k) {
                return mid;
            }
            else if(arr[mid] < k) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        return -1;
        */
        
        
    }
};
