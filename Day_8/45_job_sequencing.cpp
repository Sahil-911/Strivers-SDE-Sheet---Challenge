#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        if(n==1)
        return {1,arr[0].profit};
        sort(arr,arr+n,[](Job a,Job b){
            return a.profit>b.profit;
        });
        
        int mxdead=0;
        for(int i=0;i<n;i++)
            mxdead=max(mxdead+1,arr[i].dead);
        
        vector<int> slots(mxdead+1,-1);
        
        int cnt=0,pro=0;
        for(int i=0; i<n; i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slots[j]==-1)
                {
                    slots[j]=i;
                    pro+=arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt,pro};
    }
};