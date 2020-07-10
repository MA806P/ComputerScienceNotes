

class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        var map = [Int: Int]()
        for i in nums {
            if map[i] != nil {
                return true
            } else {
                map[i] = 1;
            }
        }
        return false
    }
}
let s = Solution()
print(s.containsDuplicate([1,2,3,1]))
