



class Solution {
    
    //方法一，耗时未通过
    //对比两个字符串，字母是否相同
    func isSame(_ str1: String, _ str2: String) -> Bool {
        let sl = str1.count, sl2 = str2.count
        if sl != sl2 { return false }
        //标识这个位字母是否比较使用过
        var flags = Array(repeating: 0, count: sl)
        for i in 0 ..< sl {
            for j in 0 ..< sl {
                if flags[j] == 0 && str1[str1.index(str1.startIndex, offsetBy: i)]  == str2[str2.index(str2.startIndex, offsetBy: j)] {
                    flags[j] = 1; break;
                }
            }
        }
        
        for f in flags { if f == 0 { return false } }
        return true
    }
    
    func groupAnagrams0(_ strs: [String]) -> [[String]] {
        let sc = strs.count
        if sc < 2 { return [strs] }
        
        var ans = [[String]]()
        var flags = Array(repeating: 0, count: sc)
        
        for i in 0 ..< sc {
            if flags[i] == 1 { continue }
            let s1 = strs[i]
            var itemAns = [s1]
            flags[i] = 1
            for j in (i + 1) ..< sc {
                if flags[j] == 0 && isSame(strs[i], strs[j]) {
                    itemAns.append(strs[j])
                    flags[j] = 1
                }
            }
            ans.append(itemAns)
        }
        return ans
    }
    
    
    
    //方法二，用字典来统计相同字母的字符串，字符串转化成数组，然后排序，确定
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        if strs.count < 2 { return [strs] }
        
        var ans = [String: Array<String>]()
        for str in strs {
            let chars = Array(str)
            let key = String(chars.sorted());
            if ans[key] == nil {
                ans[key] = [String]()
            }
            ans[key]!.append(str)
        }
        return Array(ans.values)
    }
    
    
}

let s = Solution()
print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
