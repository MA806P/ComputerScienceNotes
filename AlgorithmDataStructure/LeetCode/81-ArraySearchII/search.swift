import Foundation

class Solution {
    
    func search(_ nums: [Int], _ target: Int) -> Bool {
        if nums.count == 0 { return false }
        if nums.count == 1 { return nums[0] == target ? true : false }
        
        var left = 0, right = nums.count - 1, mid = 0
        while left <= right {
            mid = left + (right - left)/2
            if nums[mid] == target { return true }
            if nums[left] == nums[mid] { left += 1; continue; }
            if nums[0] < nums[mid] {
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
        return false
    }
    
}

let s = Solution()
print(s.search([1,3,1,1,1], 3))
