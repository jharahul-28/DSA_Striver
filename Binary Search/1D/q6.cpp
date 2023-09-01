// first aaproach
vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    vector<int> ans(2, -1);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans[0] = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans[1] = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

// second apporach
int lowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = high + 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = high + 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2. - 1);
    int first = lowerBound(nums, target);
    if (nums[first] == target || first != nums.size())
    {
        return {first, upperBound(nums, target) - 1};
    }
    else
        return {-1, -1};
}