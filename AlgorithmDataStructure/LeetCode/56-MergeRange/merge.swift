

import Foundation

class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        if intervals.count < 2 { return intervals }
        
        let sortedInterval = intervals.sorted { (a, b) -> Bool in
            return a.first! < b.first!
        }
        
        var ans = [[Int]]()
        for range in sortedInterval {
            print(range)
            
            
            let l = range[0], r = range[1]
            if ans.isEmpty  || ans.last!.last! < l {
                ans.append(range)
            } else if (ans.last!.last! < r) {
                var tempLast = ans.removeLast()
                tempLast[1] = r
                ans.append(tempLast)
            }
        }
        
        return ans
    }
}
let s = Solution()
print(s.merge([[1,3],[2,6],[8,10],[15,18]]))



