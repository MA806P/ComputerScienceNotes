
import Foundation

class Solution {
    
    func waysToChange(_ n: Int) -> Int {
        var ans = 0, i = 0
        let mod = 1000000007
        
        while i * 25 <= n {
            let res = n - i * 25, a = res/10, b = res%10/5
            ans = (ans + (a + 1) * (a + b + 1) % mod) % mod
            i += 1
        }
        
        return ans
    }
    
}

let s = Solution()
print(s.waysToChange(100))
