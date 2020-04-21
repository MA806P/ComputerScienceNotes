

import Foundation

class Solution {
    
    func numberOfSubarrays(_ nums: [Int], _ k: Int) -> Int {
        let n = nums.count
        if n <= 0 || n < k { return 0}
        
        var count = Array(repeating: 0, count: n + 1)
        var odd = 0, ans = 0
        
        count[0] = 1
        for i in 0 ..< n {
            odd += nums[i] & 1
            print(odd)
            ans += odd >= k ? count[odd - k] : 0
            print(ans, count)
            count[odd] += 1
            print(count)
            print("----------------------")
        }
        
        return ans
    }
}

let s = Solution()
print(s.numberOfSubarrays([2,2,2,1,2,2,1,2,2,2], 2))
