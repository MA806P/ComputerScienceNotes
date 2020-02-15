
class Solution {
    
    func search(_ nums: [Int], _ target: Int, _ flag: Int) -> Int {
        if nums.count == 0 { return -1 }
        if nums.count == 1 { return nums[0] == target ? 0 : -1 }
        
        var left = 0, right = nums.count - 1, mid = 0
        while left <= right {
            mid = left + (right - left)/2
            if nums[mid] > target {
                right = mid - 1
            } else if nums[mid] < target {
                left = mid + 1
            } else if nums[mid] == target{
                if flag == 1 {
                    if mid == 0 || nums[mid - 1] != target {
                        return mid
                    } else {
                        right = mid - 1
                    }
                } else {
                    if mid == nums.count - 1 || nums[mid + 1] != target {
                        return mid
                    } else {
                        left = mid + 1
                    }
                }
            }
        }
        return -1
    }
    
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        return [search(nums, target, 1), search(nums, target, 2)]
    }
    
}

let s = Solution()
 print(s.searchRange([1], 2))

