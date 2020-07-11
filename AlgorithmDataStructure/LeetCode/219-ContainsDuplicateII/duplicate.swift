

class Solution {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        var map = [Int: Int]()
        for (i, value) in nums.enumerated() {
            if map[value] != nil && i - map[value]! <= k {
                return true
            } else {
                map[value] = i;
            }
        }
        return false
    }
}
let s = Solution()
print(s.containsNearbyDuplicate([1,2,3,1,2,3],2))

