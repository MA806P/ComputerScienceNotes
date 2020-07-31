
class Solution {
    func wordPattern(_ pattern: String, _ str: String) -> Bool {
        
        let words = str.split(separator: " ")
        print(words)
        
        if words.count != pattern.count { return false }
        
        var map = [Character : String]()
        var values = Set<String>()
        
        for i in pattern.enumerated() {
            print(i.element)
            
            let word = String(words[i.offset])
            if map[i.element] == nil {
                if !values.contains(word) {
                    values.insert(word)
                    map[i.element] = word;
                } else {
                    return false
                }
            } else if map[i.element] != word {
                return false
            }
            
        }
        print(map, values)
        
        return true
    }
}
let s = Solution()
print(s.wordPattern("abba", "dog cat cat dog"))
//print(s.wordPattern("abba", "dog dog dog dog"))//false
