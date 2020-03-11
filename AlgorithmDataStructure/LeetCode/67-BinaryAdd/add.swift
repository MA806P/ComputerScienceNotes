
class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        var al = a.count
        if al == 0 { return b }
        var bl = b.count
        if bl == 0 { return a }
        
        let l = al > bl ? al : bl
        var flag = 0, a1 = 0, b1 = 0, sum = 0
        var res = String()
        
        
        for _ in 0 ..< l + 1 {
            
            if flag == 0 && al < 1 && bl < 1 { break; }
            a1 = al > 0 ? Int("\(a[a.index(a.startIndex, offsetBy: al-1)])")! : 0
            b1 = bl > 0 ? Int("\(b[b.index(b.startIndex, offsetBy: bl-1)])")! : 0
            al -= 1
            bl -= 1
            
            sum = a1 + b1 + flag
            res.insert(Character("\(sum%2)"), at: res.startIndex)
            flag = sum > 1 ? 1 : 0
        }
        
        return res
    }
    
    
}

let s = Solution()
print(s.addBinary("1011", "11"))

