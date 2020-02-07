class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        guard nums.count > 0 else {
            return 0
        }
        
        var i = 0
        for j in 0 ..< nums.count {
            if nums[i] != nums[j] {
                i += 1
                if i < j {
                    nums[i] = nums[j]
                }
            }
        }
        return i + 1
    }
}

let s = Solution()
var a = [0,0,1,1,1,1,1,1,1,2,2,3,3,4]
let b = s.removeDuplicates(&a)
print("\(a) = \(b)");
