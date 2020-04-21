
import Foundation

class Solution {
    func canJump(_ nums: [Int]) -> Bool {
        let n = nums.count
        var k = 0
        for i in 0 ..< n {
            if i <= k {
                k = max(k, i + nums[i])
                if k >= n - 1 { return true }
            }
        }
        return false
    }
}
let s = Solution()
print(s.canJump([1,2,3,9,0,0,0,0]))
