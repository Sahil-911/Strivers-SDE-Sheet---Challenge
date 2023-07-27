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
        sort(arr,arr+n,[](Job a,Job b){
            return a.profit>b.profit; 
        });
        int cnt = 0;
        int sum = 0;
        vector<int> profit(n+1,-1);
        for(int i=0;i<n;i++)
        {
            int dLine = arr[i].dead;
            int pro = arr[i].profit;
            int Id = arr[i].id;
            int j = dLine;
            while(j>=0 && profit[j]!=-1)
                j--;
            if(j>0)
            {
                profit[j]=Id;
                cnt++;
                sum+=pro;
            }
        }
        return {cnt,sum};
    } 
};