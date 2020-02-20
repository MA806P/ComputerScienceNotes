
class Solution {
    
    var result = [[Int]]()
    var stack = [Int]()
    
    func dfs(_ candidates: [Int], _ target: Int, _ start: Int) {
        if target == 0 {
            result.append(Array(stack))
            return
        }
        for i in start ..< candidates.count {
            let item = candidates[i]
            if target < item { break }
            stack.append(item)
            dfs(candidates, target - item, i)
            stack.remove(at: stack.endIndex - 1)
        }
    }
    
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        if candidates.count == 0 { return result }
        let candidatesSorted =  candidates.sorted()
        dfs(candidatesSorted, target, 0)
        return result
    }
    
}

let s = Solution()
print(s.combinationSum([2,3,5,7], 8))
