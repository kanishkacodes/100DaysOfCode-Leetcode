//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int l = sc.nextInt();
            int n = sc.nextInt();
            
            int arr[] =  new int[l];
            
            for(int i = 0;i<l;i++)
                arr[i] = sc.nextInt();
            
            Solution ob = new Solution();
                
            if(ob.findPair(arr, l, n)==true)
                System.out.println(1);
                
            else
                System.out.println(-1);    
                
        }
        
    }
}
// } Driver Code Ends


//User function Template for Java



class Solution {
    public boolean findPair(int arr[], int size, int n) {
        // Sort the array in ascending order
        Arrays.sort(arr);
        
        // Initialize low and high pointers
        int left = 0;  // low pointer
        int right = 1;  // high pointer
        
        // Iterate until low and high pointers are within array bounds
        while (left < size && right < size) {
            int diff = arr[right] - arr[left];  // Calculate the difference between elements
            
            // Check if the difference matches the given value n
            if (diff == n)
                return true;
            
            // If the difference is smaller than n, move the high pointer
            else if (diff < n)
                right++;
            
            // If the difference is greater than n, move the low pointer
            else
                left++;
            
            // If low and high pointers are pointing to the same element, move the high pointer
            if (right == left)
                right++;
        }
        
        // No pair with the given difference found
        return false;
    }
}
