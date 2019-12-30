
import Foundation

class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        guard x >= 0 else {
            return false
        }
        var num = x, temp = 0;
        while num != 0 {
            temp = temp * 10 + num % 10
            num /= 10
        }
        return temp == x
    }
}

let s = Solution()
print(s.isPalindrome(100000))
