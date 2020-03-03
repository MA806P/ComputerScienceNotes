
class Solution {
    func merge(_ A: inout [Int], _ m: Int, _ B: [Int], _ n: Int) {
        var pa = m - 1, pb = n - 1, r = 0, i = (m + n - 1)
        while pa >= 0 || pb >= 0 {
            if pa == -1 {
                r = B[pb]
                pb -= 1
            } else if pb == -1 {
                r = A[pa]
                pa -= 1
            } else if A[pa] < B[pb] {
                r = B[pb]
                pb -= 1
            } else {
                r = A[pa]
                pa -= 1
            }
            A[i] = r
            i -= 1
        }
    }
    
}

let s = Solution()
var a = [0]
s.merge(&a, 0, [1], 1)
print(a)
