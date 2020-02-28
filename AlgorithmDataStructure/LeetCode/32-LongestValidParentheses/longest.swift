class Solution {
    
    func longestValidParentheses(_ s: String) -> Int {
        if s.count < 2 { return 0 }
        var res = 0
        var dp = Array(repeating: 0, count: s.count)
        for i in 1 ..< s.count {
            if s[s.index(s.startIndex, offsetBy: i)] == ")" {
                if s[s.index(s.startIndex, offsetBy: i - 1)] == "(" {
                    dp[i] = i >= 2 ? dp[i-2] + 2 : 2;
                } else if i - dp[i-1] > 0 && s[s.index(s.startIndex, offsetBy: (i-dp[i-1]-1))] == "(" {
                    let temp = i - dp[i-1] - 2
                    dp[i] = dp[i-1] + (temp >= 0 ? dp[temp] : 0) + 2
                }
                res = max(res, dp[i])
            }
        }
        return res
    }
    
}

let s = Solution()
print(s.longestValidParentheses("())"))

