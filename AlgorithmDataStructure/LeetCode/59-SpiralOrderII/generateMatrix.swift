import Foundation

class Solution {
    func generateMatrix(_ n: Int) -> [[Int]] {
//        if n <= 0 { return [[]]}
//        if n == 1 { return [[1]]}
        
        //一圈一圈的循环，一圈四条边
        var ans = Array(repeating: Array(repeating: 0, count: n), count: n)
        var q = 0, r = n - 1, s = 0, t = n - 1, val = 1
        while val <= n*n {
            if q <= r { for i in q ... r { ans[s][i] = val; val += 1 } }
            s += 1
            if s <= t { for i in s ... t { ans[i][r] = val; val += 1 } }
            r -= 1
            if q <= r { for i in (q ... r).reversed() { ans[t][i] = val; val += 1 } }
            t -= 1
            if s <= t { for i in (s ... t).reversed() { ans[i][q] = val; val += 1 } }
            q += 1
        }
        
        return ans
    }
}
let s = Solution()
print(s.generateMatrix(2))
