
class Solution {
    func multiply(_ num1: String, _ num2: String) -> String {
        let len1 = num1.count, len2 = num2.count
        if len1 <= 0 || len2 <= 0 { return "" }
        
        var sums = Array(repeating: 0, count: len1 + len2)
        for i in (0 ..< len1).reversed() {
            for j in (0 ..< len2).reversed() {
                var tempSum = Int("\(num1[num1.index(num1.startIndex, offsetBy: i)])")! * Int("\(num2[num2.index(num2.startIndex, offsetBy: j)])")!
                tempSum += sums[i+j+1]
                sums[i+j+1] = tempSum % 10
                sums[i+j] += tempSum / 10
            }
        }
        
        var res = String(), n = 0
        for i in 0 ..< sums.count {
            if sums[i] == 0  { n += 1 } else { break }
        }
        
        if n == sums.count {
            res.append("0")
        } else {
            for i in n ..< sums.count { res.append("\(sums[i])")}
        }
        return res
    }
    
}
let s = Solution()
print(s.multiply("123", "456"))

