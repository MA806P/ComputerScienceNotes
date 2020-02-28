class Solution {
    
    func swapNums(_ nums: inout [Int], _ i:Int, _ j: Int) {
        let temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp
    }
    
    func reverseFromIndex(_ nums: inout [Int], _ start:Int) {
        var i = start, j = nums.count - 1
        while i < j {
            swapNums(&nums, i, j)
            i += 1
            j -= 1
        }
    }
    
    func nextPermutation(_ nums: inout [Int]) {
        if nums.count < 2 { return }
        var i = nums.count - 2
        while i >= 0 && nums[i] >= nums[i+1] { i -= 1 }
        if i >= 0 {
            var j = nums.count - 1
            while j >= 0 && nums[i] >= nums[j] {
                j -= 1
            }
            swapNums(&nums, i, j)
        }
        reverseFromIndex(&nums, i+1)
    }
    
}

let s = Solution()
var a = [1,8,4,7,6,5,3,1]
s.nextPermutation(&a)
print(a)
//[1, 8, 5, 1, 3, 4, 6, 7]
