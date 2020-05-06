
import Foundation

class Solution {
    
    func jump(_ nums: [Int]) -> Int {
        let l = nums.count
        var rightMost = 0, end = 0, steps = 0
        for i in 0 ..< l - 1 {
            rightMost = max(rightMost, i + nums[i])
            if i == end {
                end = rightMost; steps += 1;
            }
        }
        return steps
    }
    
}

let s = Solution()
print(s.jump([1,3,2,9,0,0,0]))
