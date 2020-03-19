
class Solution {
    
    func longestPalindrome(_ s: String) -> Int {
        let sl = s.count
        if sl < 2 { return sl }
        
        //统计字符出现的次数
        var map = [Character: Int]()
        for c in s {
            if map[c] == nil {
                map[c] = 1
            } else {
                map[c]! += 1
            }
        }
        
        var ans = 0
        //计算成对出现的字符
        for item in map {
            ans += item.value/2 * 2
        }
        if ans < sl { ans += 1 }
        return ans
    }
    
}


let s = Solution()
print(s.longestPalindrome("abccccdd"))
