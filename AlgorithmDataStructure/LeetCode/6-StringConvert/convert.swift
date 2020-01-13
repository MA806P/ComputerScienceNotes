
class Solution {
    
    func convert(_ s: String, _ numRows: Int) -> String {
        if (numRows == 1) { return s }
        var rowArray = Array(repeating: "", count: numRows)
        var x = 0, flag = 1;
        for item in s {
            rowArray[x] += "\(item)"
            x += flag
            if x == numRows - 1 || x == 0 { flag *= -1 }
        }
        var result = String()
        for item in rowArray { result += item }
        return result
    }
    
}

let s = Solution()
print(s.convert("abcdefghijklmnopq", 3))
