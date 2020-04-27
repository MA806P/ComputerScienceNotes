class Solution {
    
    //方法一：回溯，由于数组中是无重复的，在原来数组上，通过交换得到新的一个解
    func backtrack0(_ nums: [Int], _ retrunArray: inout [[Int]], _ first: Int) {
        if first == nums.count {
            retrunArray.append(nums)
            return;
        }
        
        var unique = [Int]()
        for i in first ..< nums.count {
            if unique.contains(nums[i]) { continue; }
            var tempNums = nums
            tempNums.swapAt(first, i)
            backtrack0(tempNums, &retrunArray, first + 1)
            tempNums.swapAt(first, i)
            unique.append(tempNums[i]);
            print(unique, tempNums)
        }
    }
    
    func permute0(_ nums: [Int]) -> [[Int]] {
        if nums.count < 2 {  return [nums] }
        
        var res = [[Int]]()
        backtrack0(nums, &res, 0);
        return res
    }
    
    
    
    //方法二，回溯，新的空数组，在数组后添加得到一个解
    func backtrack(_ nums: [Int], _ retrunArray: inout [[Int]], _ item: inout [Int], _ visited: inout [Int]) {
        if item.count == nums.count {
            retrunArray.append(Array(item))
            return
        }
        
        //每次都遍历一遍，保证原数组元素都添加进去，通过标志位 防止重复添加
        //0- 0 1 2, 1-0 1 2 , 2-0 1 2
        /**
         i=0 [1,0,0][1] 👇
         i=0 [1,0,0]continue
         i=1 [1,1,0][1,2]  =>      i=0 continue  i=1continue   i=2[1,1,1][1,2,3]👌
         i=2 [1,0,1][1,3]  =>      i=0 continue  i=1[1,1,1][1,3,2]👌   i=2 continue
         
         
         i=1[0,1,0][2]👇
         i=0 [1,1,0][2,1]  =>      i=0 continue  i=1continue   i=2[1,1,1][2,1,3]👌
         i=1 [0,1,0]continue
         i=2 [0,1,1][2,3]  =>      i=0[1,1,1][2,3,1]👌   i=1 continue   i=2 continue
         
         
         i=2[0,0,1][3]👇
         i=0 [1,0,1][3,1]  =>      i=0 continue  i=1[1,1,1][3,1,2]👌  i=2continue
         i=1 [0,1,1][3,2]  =>      i=0[1,1,1][3,2,1]👌   i=1 continue   i=2 continue
         i=2 [0,0,1]continue
         
         */
        for i in 0 ..< nums.count {
            if visited[i] == 1 { continue }
            visited[i] = 1 //已经添加到数组中的标志
            item.append(nums[i])
            backtrack(nums, &retrunArray, &item, &visited)
            visited[i] = 0
            //当前分支已遍历完，后退一位，遍历其他情况的分支
            item.remove(at: item.endIndex - 1)
        }
        
        
    }
    func permute(_ nums: [Int]) -> [[Int]] {
        if nums.count < 2 {  return [nums] }
        
        var res = [[Int]]()
        var visisted = Array(repeating: 0, count: nums.count)
        var item = [Int]()
        backtrack(nums, &res, &item, &visisted);
        return res
    }
    
}

let s = Solution()
print(s.permute([1,2,3]))
