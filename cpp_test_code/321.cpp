#include <iostream>
#include <vector>

using namespace std;

vector<int> maxVector(vector<int> &nums, int k)
{
    int drop = (int)nums.size() - k;
    vector<int> res;
    for (int num : nums)
    {
        while (drop > 0 && !res.empty() && res.back() < num)
        {
            res.pop_back();
            --drop;
        }
        res.push_back(num);
    }
    res.resize(k);
    return res;
}
vector<int> mergeVector(vector<int> nums1, vector<int> nums2)
{   
    for(int i = 0; i < nums1.size(); i++)
    {
        cout << "nums1: " << nums1[i] << " ";
    }
    cout << endl;


    for(int i = 0; i < nums2.size(); i++)
    {
        cout << "nums2: " << nums2[i] << " ";
    }
    cout << endl;

    vector<int> res;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] > nums2[j])
            res.push_back(nums1[i++]);
        else
            res.push_back(nums2[j++]);
    }
    if (i < nums1.size())
        res.push_back(nums1[i++]);
    if (j < nums2.size())
        res.push_back(nums2[j++]);

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return res;
}

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    
    
    
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> res;
    for (int i = max(0, k - n2); i <= min(k, n1); ++i)
    {
        res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
    }
    return res;
}

int main()
{
    vector<int> nums1 = {6, 7};
    vector<int> nums2 = {6, 0, 4};

    maxNumber(nums1, nums2, 5);

    return 0;
}