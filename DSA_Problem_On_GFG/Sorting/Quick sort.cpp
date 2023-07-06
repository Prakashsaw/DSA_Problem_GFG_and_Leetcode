/*
Quick sort
Medium

*/
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low > high) return;
        
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[low];
       int pivotIndex = low;
       for(int i = low; i <= high; i++) {
           if(arr[i] < pivot) {
               pivotIndex++;
           }
       }
       swap(arr[pivotIndex], arr[low]);
       //partition
       int i = low, j = high;
       while(i < pivotIndex && j > pivotIndex) {
           if(arr[i] >= pivot) {
               if(arr[j] < pivot) {
                   swap(arr[i], arr[j]);
                   i++;
                   j--;
               }
               else {
                   j--;
               }
           }
           else {
               i++;
           }
       }
       return pivotIndex;
    }
    
    //TC = O(NlogN)
    //SC = O(logN) //Recursive call stack
};
