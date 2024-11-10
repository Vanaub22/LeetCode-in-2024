class Solution {
private:
    int make(auto& v) { 
        int val=0,ans=1; 
        for(int i=0;i<30;i++) { 
            if(v[i]>=1) val+=ans; 
            ans*=2; 
        } 
        return val; 
    } 
    void inc(auto& v, int num) { 
        int i=0; 
        while(num>0) { 
            int rem=num%2; 
            if(rem==1) v[i]+=1;
            num/=2; 
            i++;
        } 
    } 
    void dec(auto& v, int num) { 
        int i=0; 
        while(num>0) { 
            int rem=num%2; 
            if(rem==1) v[i]-=1; 
            num/=2; 
            i++; 
        } 
    }
public:
    int minimumSubarrayLength(auto& nums, int k) { 
        vector<int> v(32,0); 
        int i,j=0,val=0,ans=INT_MAX,n=nums.size(); 
        for(i=0;i<n;i++) { 
            val=val|nums[i]; 
            inc(v,nums[i]); 
            while(i>=j && val>=k) { 
                ans=min(ans,i-j+1); 
                dec(v,nums[j]);  
                val=make(v); 
                j++; 
            } 
        } 
        return ans==INT_MAX?-1:ans; 
    } 
};