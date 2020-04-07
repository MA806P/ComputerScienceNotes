
class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        let r = matrix.count
        if r <= 0 { return [] }
        let c = matrix.first!.count
        
        var ans = [Int]()
        var r1 = 0, r2 = r - 1, c1 = 0, c2 = c - 1
        
        //注意边界值
        while r1 <= r2 && c1 <= c2 {
            for ci in c1 ... c2 { ans.append(matrix[r1][ci]) }
            if r1 < r2 { for ri in r1 + 1 ... r2 { ans.append(matrix[ri][c2]) } }
            
            if r1 < r2 && c1 < c2 {
                if c1 < c2 - 1 { for ci in (c1 + 1 ... c2 - 1).reversed() { ans.append(matrix[r2][ci]) } }
                for ri in (r1 + 1 ... r2).reversed() { ans.append(matrix[ri][c1]) }
            }
            
            r1 += 1; r2 -= 1; c1 += 1; c2 -= 1;
        }
        
        return ans
    }
}
let s = Solution()
print(s.spiralOrder([[1,2],[3,4]]))
