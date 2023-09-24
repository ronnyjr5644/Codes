//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = g.duplicates(a, n);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    public static ArrayList<Integer> duplicates(int arr[], int n) {
        
        ArrayList<Integer> result =new ArrayList<>() ;
        // code here
        
        Map<Integer,Integer> freq = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            freq.put(arr[i],freq.getOrDefault(arr[i],0)+1);
        }
        
        for(Map.Entry<Integer,Integer> x : freq.entrySet()){
            if(x.getValue()>1){
                result.add(x.getKey());
            }
        }
        if(result.size()==0){
            result.add(-1);
        }
        Collections.sort(result);
        return result;
    }
}
