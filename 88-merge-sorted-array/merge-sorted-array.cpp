class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;

        // int k=m+n-1;
        while(left>=0 && right<n)
        {
            if(nums1[left]>nums2[right])
            {
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        // sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int j=0;
        for(int i=m;i<nums1.size();i++)
        {
            nums1[i]=nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
        
    }
};