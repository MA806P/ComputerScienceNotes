
import Foundation

class Solution {
    
    func singleNumbers(_ nums: [Int]) -> [Int] {
        
        //用字典统计数字出现的次数
        var map = [Int:Int]()
        for num in nums {
            if map[num] == nil {
                map[num] = 1
            } else {
                map[num]! += 1
            }
        }
        print(map)
        
        //获取出现一次的数
        var ans = [Int]()
        for (num, count) in map {
            if count == 1 {
                ans.append(num)
            }
        }
        
        return ans
    }
    
}

let s = Solution()
print(s.singleNumbers([1,2,10,4,1,4,3,3]))

