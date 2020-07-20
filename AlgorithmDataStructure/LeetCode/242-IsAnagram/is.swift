class Solution {
    func isAnagram0(_ s: String, _ t: String) -> Bool {
        let sl = s.count, tl = t.count
        if (sl != tl) { return false }
        
        let sortedS = s.sorted(), sortedT = t.sorted()
        print(s, sortedS)
        print(t, sortedT)
        
        return sortedS.elementsEqual(sortedT)
        
    }
    
    
    func isAnagram(_ s: String, _ t: String) -> Bool {
        let sl = s.count, tl = t.count
        if (sl != tl) { return false }
        
        var dict = [Character:Int]()
        
        for i in s {
            if dict[i] == nil {
                dict[i] = 1
            } else {
                dict[i]! += 1
            }
        }
        
        for i in t {
            if dict[i] == nil { return false }
            dict[i]! -= 1
            if dict[i]! < 0 { return false }
        }
        return true
    }
}

let s = Solution()
print(s.isAnagram("anagram", "nagaram"))
