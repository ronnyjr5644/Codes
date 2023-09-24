//{ Driver Code Starts
//Initial Template for Java



import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function Template for Java


class GFG
{
    ArrayList<Integer> find(int arr[], int n, int x)
    
    {
        ArrayList<Integer> result= new ArrayList<>();
        int low=0;
        int high = n-1;
        // code here
       
         
        // Calculate mid inside the loop

            int f1 = binarySearch(arr, low, high, x);
            int l1 = binarySearch1(arr, low, high, x);
            if (f1 == -1 && l1 == -1) {
                result.add(-1);
                   result.add(-1);
                return result;
            }

            result.add(f1);
            result.add(l1);
            return result;
        
    
 
            
        
    }
    static int binarySearch(int[] arr, int low, int high,int target){
        int res=-1;
        while(low<=high){
                int mid = low + (high - low) / 2; 
            if(arr[mid]==target){
                res=mid;
                high=mid-1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            
            }else{
                high=mid-1;
            }
        }
        return res;
    }
     static int binarySearch1(int[] arr, int low, int high,int target){
        int res=-1;
        while(low<=high){
                int mid = low + (high - low) / 2; 
            if(arr[mid]==target){
                res=mid;
                low=mid+1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            
            }else{
                high=mid-1;
            }
        }
        return res;
    }
}



//{ Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
//            int n = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] q = line.trim().split("\\s+");
            int n =Integer.parseInt(q[0]);
            int x =Integer.parseInt(q[1]);
//            //int y =Integer.parseInt(q[2]);
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(a1[i]);
            }
            GFG ob = new GFG();
            ArrayList<Integer> ans=ob.find(arr,n,x);
            System.out.println(ans.get(0)+" "+ans.get(1));
        }
    }
}

// } Driver Code Ends