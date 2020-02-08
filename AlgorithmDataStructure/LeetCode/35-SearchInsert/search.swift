class Solution {
    
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var low = 0, high = nums.count - 1, mid = 0
        while low <= high {
            mid = low + (high - low)/2
            if nums[mid] == target {
                return mid
            } else if nums[mid] < target {
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
        return low
    }
}

let s = Solution()
print(s.searchInsert([1], 0))
