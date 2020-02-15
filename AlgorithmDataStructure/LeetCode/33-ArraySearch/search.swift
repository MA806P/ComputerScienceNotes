class Solution {
    
    func search(_ nums: [Int], _ target: Int) -> Int {
        if nums.count == 0 { return -1 }
        if nums.count == 1 { return nums[0] == target ? 0 : -1 }
        
        var left = 0, right = nums.count - 1, mid = 0
        while left <= right {
            mid = left + (right - left)/2
            if nums[mid] == target {
                return mid
            }
            
            if nums[0] <= nums[mid] {
                if nums[0] <= target && target < nums[mid] {
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            } else {
                if nums[mid] < target && target <= nums[nums.count - 1] {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
        }
        return -1
    }
    
}

let s = Solution()
print(s.search([3, 1], 1))
