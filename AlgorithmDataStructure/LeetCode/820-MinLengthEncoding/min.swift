
class Trie {
    var child = [Character:Trie]()
    init() {
        let str = "abcdefghijklmnopqrstuvwxyz";
        for s in str { child[s] = nil }
    }
    
    func insert(_ word: String) -> Int {
        var next = self
        var isNew = false
        //单词倒序插入
        for c in word.reversed() {
            if(next.child[c] == nil) {
                isNew = true
                next.child[c] = Trie()
            }
            next = next.child[c]!
        }
        return isNew ? (word.count + 1) : 0
    }
}

class Solution {
    
    //方法一，后缀去重
    func minimumLengthEncoding0(_ words: [String]) -> Int {
        //去重
        var uniqueWords = Set(words)
        //单词按长短排序，从短到长
        let tempWords = uniqueWords.sorted { (str1, str2) -> Bool in
            return str1.count < str2.count
        }
        
        //去除包含项
        let l = tempWords.count
        for i in 0 ..< l {
            for j in i+1 ..< l {
                if tempWords[j].hasSuffix(tempWords[i]) {
                    uniqueWords.remove(tempWords[i])
                }
            }
        }
        
        //剩下的就是，单独的单词，累加就性
        var ans = 0
        for uw in uniqueWords {  ans += uw.count + 1 }
        return ans;
    }
    
    
    //方法二，字典树，数据结构 参考题目 208
    func minimumLengthEncoding(_ words: [String]) -> Int {
        
        //单词按长短排序，从长到短，防止重复计算
        let tempWords = words.sorted { (str1, str2) -> Bool in
            return str1.count > str2.count
        }
        print(tempWords)
        
        var ans = 0
        let obj = Trie()
        for w in tempWords {
            ans += obj.insert(w)
        }
        
        return ans;
    }
}
let s = Solution()
print(s.minimumLengthEncoding(["time", "me", "ime", "time"]))

