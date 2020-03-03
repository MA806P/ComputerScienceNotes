class Solution {
    
    func backtrack(_ nums: [Int], _ retrunArray: inout [[Int]], _ first: Int) {
        if first == nums.count {
            retrunArray.append(nums)
        }
        
        for i in first ..< nums.count {
            var tempNums = nums
            tempNums.swapAt(first, i)
            backtrack(tempNums, &retrunArray, first + 1)
            tempNums.swapAt(first, i)
        }
    }
    
    func permute(_ nums: [Int]) -> [[Int]] {
        if nums.count < 2 {  return [nums] }
        
        var res = [[Int]]()
        backtrack(nums, &res, 0);
        return res
    }
    
}

let s = Solution()
print(s.permute([1,2,3]))
