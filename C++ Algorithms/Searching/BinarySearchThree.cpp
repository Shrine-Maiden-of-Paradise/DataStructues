int binarySearch(vector<int>& nums, int target){
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right){
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}

/* 
Key attributes 
An alternative way to implement Binary Search

Search Condition needs to access element's immediate left and right neighbors

Use element's neighbors to determine if condition is met and decide whether to go left or
right 

Gurantees Search Space is at least in size at each step

Post-processing required. Loop/Recursion ends when you 2 elements left. Need to assess 
if the remaining elements meet the condition.

Distinguishing Syntax
Initial Condition : left= 0, right = length-1
Termination : left + 1 == right
Searching Left : right = mid
Searching Right : left = mid

*/
