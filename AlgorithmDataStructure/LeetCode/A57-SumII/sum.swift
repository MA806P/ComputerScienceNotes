
class Solution {
    func findContinuousSequence(_ target: Int) -> [[Int]] {
        var ans = [[Int]]()
        
        var l = 1, r = 2, sum = 0
        while l < r {
            sum = (l + r) * (r - l + 1) / 2
            if sum == target {
                let item = Array(l ... r)
                ans.append(item)
                l += 1
            } else if sum < target {
                r += 1
            } else {
                l += 1
            }
        }
        
        return ans
    }
}
let s = Solution()
print(s.findContinuousSequence(15))

