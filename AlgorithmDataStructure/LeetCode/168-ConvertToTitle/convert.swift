class Solution {
    func convertToTitle(_ n: Int) -> String {
        var ans = String()
        let dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        var a = n, b = 0;
        while a > 0 {
            a -= 1
            b = a%26
            ans.insert(dict[dict.index(dict.startIndex, offsetBy: b)], at: ans.startIndex)
            a /= 26
            print(a, b)
        }
        return ans
    }
}
let s = Solution()
print(s.convertToTitle(28))
