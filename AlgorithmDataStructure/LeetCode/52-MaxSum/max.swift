
class Solution {
    
    func maxSubArray0(_ nums: [Int]) -> Int {
        if nums.count == 0 { return 0; }
        
        var res = nums.first!, sum = 0
        for num in nums {
            sum = sum > 0 ? sum + num : num
            res = max(res, sum)
        }
        return res
    }
        
    func crossSum(_ nums: [Int], _ left: Int, _ right: Int, _ mid: Int) -> Int {
        if left == right { return nums[left] }
        var sum = 0
        var leftMax = nums[mid]
        for i in (left ... mid).reversed() {
            sum += nums[i]
            leftMax = max(sum, leftMax)
        }
        sum = 0
        var rightMax = nums[mid + 1]
        for i in (mid+1) ... right {
            sum += nums[i]
            rightMax = max(sum, rightMax)
        }
        return leftMax + rightMax
    }
    func helper(_ nums: [Int], _ left: Int, _ right: Int) -> Int {
        if left == right { return nums[left] }
        let mid = left + (right - left)/2
        let leftMax = helper(nums, left, mid)
        let rightMax = helper(nums, mid + 1, right)
        let crossMax = crossSum(nums, left, right, mid)
        
        var res = max(leftMax, rightMax)
        res = max(res, crossMax)
        return res
    }
    
    func maxSubArray(_ nums: [Int]) -> Int {
        if nums.count == 0 { return 0 }
        return helper(nums, 0, nums.count - 1)
    }
    
}

let s = Solution()
print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
