
import Foundation

class Solution {
    
    func isHappy(_ n: Int) -> Bool {
        
        
        var nums = n
        var exist = Set<Int>()
        while true {
            if nums == 1 { return true }
            if exist.contains(nums) { return false } else { exist.insert(nums) }
            var sum = 0
            while nums > 0 {
                let temp = nums%10
                sum += temp*temp
                nums = nums/10
                print(temp, sum, nums)
            }
            nums = sum
        }
        
    }
    
}

let s = Solution()
print(s.isHappy(9))
