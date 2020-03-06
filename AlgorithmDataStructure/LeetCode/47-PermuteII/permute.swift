class Solution {
    
    //方法一：和上一题一样的解法，回溯，交换。通过记录使用过的数字
    func backtrack0(_ nums: [Int], _ retrunArray: inout [[Int]], _ first: Int) {
        if first == nums.count {
            retrunArray.append(nums)
            return;
        }
        
        var unique = [Int]() //记录已经交换过的，重复的
        for i in first ..< nums.count {
            //两个重复的之前已经交换过来
            if unique.contains(nums[i]) { continue; }
            
            var tempNums = nums
            tempNums.swapAt(first, i)
            backtrack0(tempNums, &retrunArray, first + 1)
            tempNums.swapAt(first, i)
            unique.append(tempNums[i]);
        }
    }
    
    func permuteUnique0(_ nums: [Int]) -> [[Int]] {
        if nums.count < 2 {  return [nums] }
        
        var res = [[Int]]()
        backtrack0(nums, &res, 0);
        return res
    }
    
    //方法二，回溯，新的空数组，在数组后添加得到一个解。通过剪枝去重
    func backtrack(_ nums: [Int], _ retrunArray: inout [[Int]], _ item: inout [Int], _ visited: inout [Int]) {
        if item.count == nums.count {
            retrunArray.append(Array(item))
            return
        }
        
        //每次都遍历一遍，保证原数组元素都添加进去，通过标志位 防止重复添加
        //0- 0 1 2, 1-0 1 2 , 2-0 1 2
        for i in 0 ..< nums.count {
            if visited[i] == 1 { continue }
            
            //剪枝条件。和上一题，就多了这个判断。就是这个和上一个元素相等，这条路不走了
            //visited[i - 1] == 0 是因为不能见到重复的两个就跳过，
            //还要判断前一个是否刚刚已添加过了，刚走完分支撤销。如果没走，就不重复，继续添加
            if (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 0) {
                continue
            }
            
            visited[i] = 1 //已经添加到数组中的标志
            item.append(nums[i])
            backtrack(nums, &retrunArray, &item, &visited)
            visited[i] = 0
            //当前分支已遍历完，后退一位，遍历其他情况的分支
            item.remove(at: item.endIndex - 1)
        }
        
        
    }
    func permuteUnique(_ nums: [Int]) -> [[Int]] {
        if nums.count < 2 {  return [nums] }
        
        //先进行排序，后面才能剪枝去重
        let sortedNums = nums.sorted()
        
        var res = [[Int]]()
        var visisted = Array(repeating: 0, count: nums.count)
        var item = [Int]()
        backtrack(sortedNums, &res, &item, &visisted);
        return res
    }
    
}

let s = Solution()
print(s.permuteUnique([1,1,2,1]))
