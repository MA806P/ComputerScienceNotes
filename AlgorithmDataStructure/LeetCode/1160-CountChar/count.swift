
class Solution {
    
    func countCharacters(_ words: [String], _ chars: String) -> Int {
        if words.count <= 0 || chars.count <= 0 { return 0 }
        
        var ans = 0
        var charMap = [Character:Int]()
        for c in chars {
            if charMap[c] == nil { charMap[c] = 1 } else { charMap[c]! += 1 }
        }
        
        for w in words {
            if w.count > chars.count { continue }
            var wordMap = [Character:Int]()
            var isAns = true
            for c in w {
                if wordMap[c] == nil { wordMap[c] = 1} else { wordMap[c]! += 1 }
                if charMap[c] == nil || charMap[c]! < wordMap[c]! {
                    isAns = false; break;
                }
            }
            if isAns { ans += w.count }
        }
        return ans
    }
    
}

let s = Solution()
print(s.countCharacters(["catt","bt","hat","tree"],"atach"))
