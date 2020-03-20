
class Solution {
    
    //方法一，先排序然后取前k个数
    func getLeastNumbers(_ arr: [Int], _ k: Int) -> [Int] {
        if k <= 0 { return [] }
        let arrSorted = arr.sorted()
        var ans = Array(repeating: 0, count: k)
        for i in 0 ..< k { ans[i] = arrSorted[i]  }
        return ans
    }
    
}

let s = Solution()
print(s.getLeastNumbers([3,4,1,2,6,5], 3))
