
class Solution {
    
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {

        var i = nums.count - 1, size = nums.count
        while i >= 0 {
            if nums[i] == val {
                nums.remove(at: i)
                size -= 1
            }
            i -= 1
        }
        return size
    }
}

let s = Solution()
var a = [0,0,1,1,1,1,1,1,1,2,2,3,3,4]
let b = s.removeElement(&a, 1)
print("\(a) = \(b)")
