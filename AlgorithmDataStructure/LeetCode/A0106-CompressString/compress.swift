
class Solution {
    func compressString(_ S: String) -> String {
        if S.count < 3 { return S }
        
        var ans = String()
        var count = 1
        for i  in 1 ..< S.count {
            if S[S.index(S.startIndex, offsetBy: i - 1)] == S[S.index(S.startIndex, offsetBy: i)] {
                count += 1
            } else {
                ans.append("\(S[S.index(S.startIndex, offsetBy: i - 1)])\(count)")
                count = 1
            }
        }
        ans.append("\(S.last!)\(count)")
        return ans.count < S.count ? ans : S
    }
}

let s = Solution()
print(s.compressString("abcd"))
