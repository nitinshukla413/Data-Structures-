class Solution {
public:
    int removeDuplicates(vector<int>&arr, int n)
    {
        if (n==0 || n==1)
            return n;
 
        // To store index of next unique element
        int j = 0;
 
        // maintaining another updated index i.e. j
        for (int i=0; i < n-1; i++)
            if (arr[i] != arr[i+1])
                arr[j++] = arr[i];
 
        arr[j++] = arr[n-1];
 
        return j;
}    
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums.size()==1 && nums[0]<=0){
            return 1;
        }
        
			sort(nums.begin(),nums.end());   //you can use cyclic sort instead of this for more reduced complexity
		
		
        int ans=0;
		//making all negative values zero
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=0;
            }
            else{
                break;
            }
        }
        
		//removing all of the zeroes from the vector
        while(*nums.begin()==0 && nums.size()){
            nums.erase(nums.begin());
        }
        
		//case check if the test case contains only negative numbers
        if(nums.size()==0){
            return 1;
        }
        
        int n=nums.size();
		//removing duplicates from the vector
        n=removeDuplicates(nums,n);
		
		//printing vector just to check
        // for(auto it:nums){
        //     cout<<it<<" ";
        // }
        
		//checking if i is less than the value of nums[i]
        for(int i=1;i<=nums.size();i++){
            if(i<nums[i-1]){
                ans=i;
                break;
            }           
        }
        
		//if there is no i less than nums[i] exist in the vector then returning the 1+greatest value of the vector
        if(ans==0){
            return nums[nums.size()-1]+1;
        }
        
		//stores value of i less than nums[i] if exist
    return ans;
    }
};
