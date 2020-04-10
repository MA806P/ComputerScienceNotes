
import Foundation

class Solution {
    
    func reverseChars<T>(_ chars: inout [T], _ start: Int, _ end: Int) {
        var start = start, end = end
        while start < end {
            chars.swapAt(start, end); start += 1; end -= 1;
        }
    }
    
    func reverseWords0(_ s: String) -> String {
        
        let sl = s.count
        if sl < 1 { return s }
        var chars = Array(s)
        
        //先把字符串整个的翻转
        reverseChars(&chars, 0, sl - 1)
        
        //然后再把单词翻转
        var start = 0
        for i in 0 ..< sl {
            if i == sl - 1 || chars[i+1] == " " {
                reverseChars(&chars, start, i)
                start = i + 2
            }
        }
        
        //去除多余的空格
        var ans = String()
        var needSpace = false
        for i in 0 ..< sl {
            if chars[i] != " " {
                ans += "\(chars[i])"; needSpace = true
            } else if needSpace {
                ans += " "; needSpace = false
            }
        }
        if ans.last == " " {
            ans.removeLast()
        }
        
        return ans
    }
    
    
    func reverseWords(_ s: String) -> String {
        
        var chars = Array(s)
        
        //先把字符串整个的翻转
        reverseChars(&chars, 0, chars.count - 1)
        
        let wordSpaces = String(chars).components(separatedBy: " ")
        
        var ans = String()
        for i in wordSpaces {
            if i.count > 0 { ans += i.reversed() + " "}
        }
        if ans.last == " " { ans.removeLast() }
        return ans
    }
    
    
}
let s = Solution()
print("---\(s.reverseWords("   hello        word!  "))----")
