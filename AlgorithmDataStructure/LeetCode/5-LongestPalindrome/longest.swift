
class Solution {
    
    func expendAroundCenter(_ s: String, _ left: Int, _ right: Int) -> Int {
        let count = s.count
        var l = left, r = right;
        while l >= 0 && r < count && s[s.index(s.startIndex, offsetBy: l)] == s[s.index(s.startIndex, offsetBy: r)] {
            l -= 1
            r += 1
        }
        return r - l - 1
    }
    
    func longestPalindrome(_ s: String) -> String {
        guard !s.isEmpty else {
            return ""
        }
        var start = 0, end = 0
        for i in 0 ..< s.count {
            let l1 = expendAroundCenter(s, i, i)
            let l2 = expendAroundCenter(s, i, i + 1)
            let l = max(l1, l2)
            if l > end - start  {
                start = i - (l - 1)/2
                end = i + l/2
            }
        }
        return "\(s[s.index(s.startIndex, offsetBy: start) ... s.index(s.startIndex, offsetBy: end)])"
    }
}

let s = Solution()
print(s.longestPalindrome("aaa"))
