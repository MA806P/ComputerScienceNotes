class Solution {

    func longestCommonPrefix(_ strs: [String]) -> String {
        guard strs.count > 0 else {
            return ""
        }
        let baseStr = strs.first!
        var endIndex = baseStr.count
        for item in strs {
            endIndex = min(endIndex, item.count)
            for i in 0 ..< min(baseStr.count, item.count) {
                //print("\(i) \(endIndex) \(baseStr[baseStr.index(baseStr.startIndex, offsetBy: i)] ) \(item[item.index(item.startIndex, offsetBy: i)])")
                if baseStr[baseStr.index(baseStr.startIndex, offsetBy: i)] != item[item.index(item.startIndex, offsetBy: i)] {
                    if i == 0 {
                        return ""
                    } else {
                        endIndex = min(i, endIndex)
                        break
                    }
                }
            }
            //print("----")
        }
        return "\(baseStr[..<baseStr.index(baseStr.startIndex, offsetBy: endIndex)])"
    }
}

let s = Solution()
print(s.longestCommonPrefix(["aac","acab","aa","abba","aa"]))
print(s.longestCommonPrefix(["flower","flow","flight"]))
