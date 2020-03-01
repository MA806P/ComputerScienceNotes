class Solution {
    func lengthOfLastWord(_ s: String) -> Int {
        if s.count == 0 { return 0 }
        var res = 0
        for i in (0 ..< s.count).reversed() {
            if s[s.index(s.startIndex, offsetBy: i)] == " " {
                if res > 0 { break }
            } else {
                res += 1
            }
        }
        return res
    }
}
let s = Solution()
print(s.lengthOfLastWord("abcdef g    "))
