
extension StringProtocol {
    func indexDistance<S: StringProtocol>(of string: S) -> Int? { range(of: string)?.lowerBound.distance(in: self) }
}
extension Collection {
    func distance(to index: Index) -> Int { distance(from: startIndex, to: index) }
}
extension String.Index {
    func distance<S: StringProtocol>(in string: S) -> Int { string.distance(to: self) }
}

class Solution {
    
    func strStr(_ haystack: String, _ needle: String) -> Int {
        let a = haystack.indexDistance(of: needle) ?? -1
        return a
    }
}

let s = Solution()
print(s.strStr("hello", "ll"))
