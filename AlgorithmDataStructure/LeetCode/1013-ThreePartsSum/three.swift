class Solution {
    func canThreePartsEqualSum(_ A: [Int]) -> Bool {
        if A.count < 3 { return false }
        var sum = 0
        for i in A { sum += i }
        if sum%3 != 0 { return false }
        sum /= 3
        var part = 0, count = 0
        for i in 0 ..< A.count - 1 {
            part += A[i]
            if part == sum {
                count += 1
                if count == 2 { return true }
                part = 0
            }
        }
        return false
    }
    
    
}

let s = Solution()
print(s.canThreePartsEqualSum([0,2,1,-6,6,-7,9,1,2,0,1]))

