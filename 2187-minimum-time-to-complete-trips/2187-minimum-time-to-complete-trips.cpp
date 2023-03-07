class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         sort(time.begin(),time.end());
        
        long long l=0,h=(long long)time.back()*totalTrips;
        long long ans;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            long long cnt=0;
            for(int i=0;i<time.size();i++)
            {
                if(time[i]>mid)
                    break;
                cnt+=(mid/time[i]);
            }
            if(cnt>=totalTrips)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};