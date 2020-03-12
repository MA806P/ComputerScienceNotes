
class Solution {
    func gcdOfInt(_ a: Int, _ b: Int) -> Int {
        return b == 0 ? a : gcdOfInt(b, a % b)
    }
    
    func gcdOfStrings(_ str1: String, _ str2: String) -> String {
        if str1 + str2 != str2 + str1 { return "" }
        
        let xl = gcdOfInt(str1.count, str2.count)
        return String(str2.prefix(xl))
    }
}

let s = Solution()
print(s.gcdOfStrings("1212", "12"))
