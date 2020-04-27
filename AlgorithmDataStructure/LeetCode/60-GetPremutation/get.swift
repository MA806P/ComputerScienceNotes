
import Foundation

class Solution {
    
    func getPermutation(_ n: Int, _ k: Int) -> String {
        if (n <= 1) { return "\(n)" }
        
        var nums = [Int]()
        nums.append(1)
        var factorial = Array(repeating: 1, count: n)
        
        for i in 1 ..< n {
            nums.append(i+1) //1 2 .. n
            factorial[i] = factorial[i - 1] * i //0! 1! 2! ... (n-1)!
        }
        print(factorial)
        /**
         3
         nums = 1 2 3
         factorial = 1  1  2
         
         i = 2 idx = 2/2 = 1 ans = 2     nums = [1,3]
         i = 1 idx = 0/1 = 0 ans = 21    nums = [3]
         i = 0 idx = 0/1 = 0 ans = 213   nums = []
         */
        
        var temp = k - 1
        var ans = String()
        for i in (0 ..< n).reversed() {
            let idx = temp/factorial[i]
            temp -= idx * factorial[i]
            print(idx, temp)
            ans.append("\(nums[idx])")
            nums.remove(at: idx)
        }
        
        return ans
    }
    
    
}

let s = Solution()
print(s.getPermutation(3,3))
