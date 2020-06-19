class Solution {
    
    func getRow(_ rowIndex: Int) -> [Int] {
        var ans = Array(repeating: 1, count: rowIndex + 1)
        for i in 0 ... rowIndex {
            ans[i] = 1
            if i > 1 {
                for j in (2 ... i).reversed() {
                    ans[j - 1] = ans[j-2] + ans[j-1]
                }
            }
        }
        return ans
    }
}




let s = Solution()
print(s.getRow(3))
