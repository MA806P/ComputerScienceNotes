
class Solution {
    
    func minIncrementForUnique0(_ A: [Int]) -> Int {
        if A.count < 2 { return 0; }
        let array = A.sorted()
        var ans = 0, taken = 0
        
        for i in 1 ..< array.count {
            if array[i - 1] ==  array[i] {
                taken += 1
                ans -= array[i]
            } else {
                let give = min(taken, array[i] - array[i - 1] - 1)
                ans += give * (give + 1) / 2 + give * array[i-1]
                taken -= give;
            }
        }
        
        if array.count > 0 {
            ans += taken * (taken + 1) / 2 + taken * array[array.count - 1]
        }
        
        return ans
    }
    
    
    func minIncrementForUnique(_ A: [Int]) -> Int {
        if A.count < 2 { return 0; }
        var array = A.sorted()
        var ans = 0
        for i in 1 ..< array.count {
            if array[i] <= array[i-1] {
                ans += array[i-1] - array[i] + 1
                array[i] = array[i - 1] + 1
            }
        }
        return ans
    }
}

let s = Solution()
print(s.minIncrementForUnique0([1,1,1,1,3,5]))
print(s.minIncrementForUnique([1,1,1,1,3,5]))
print(s.minIncrementForUnique0([5,5,5,6,6]))
print(s.minIncrementForUnique([5,5,5,6,6]))
