
import Foundation


class Solution {
    
    func singleNumber(_ nums: [Int]) -> Int {
        var set = Set<Int>()
        for i in nums {
            if set.contains(i) {
                set.remove(i)
            } else {
                set.insert(i)
            }
        }
        return set.first!
    }
    
}

let s = Solution()
print(s.singleNumber([2,1,2]))
