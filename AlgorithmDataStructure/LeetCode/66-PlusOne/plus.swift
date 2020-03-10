
class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {
        let n = digits.count
        if n <= 0 { return digits }
        
        var res = digits
        for i in (0 ..< n).reversed() {
            if res[i] + 1 > 9 {
                res[i] = 0
            } else {
                res[i] += 1
                break
            }
        }
        
        if res.first! == 0 {
            res.insert(1, at: 0)
        }
        return res
    }
}

let s = Solution()
print(s.plusOne([9,9]))
