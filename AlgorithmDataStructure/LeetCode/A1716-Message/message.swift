
class Solution {
    
    func massage(_ nums: [Int]) -> Int {
        let n = nums.count
        if n < 1 { return 0; }
        if n < 2 { return nums[0]; }
        
        var dp0 = 0, dp1 = nums[0], tdp0 = 0, tdp1 = 0
        for i in 1 ..< n {
            tdp0 = max(dp0, dp1)
            tdp1 = dp0 + nums[i]
            dp0 = tdp0
            dp1 = tdp1
        }
        return max(dp0, dp1)
    }
}

let s = Solution()
print(s.massage([1,1,1,1,3,5]))
