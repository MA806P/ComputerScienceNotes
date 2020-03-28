
class Trie {
    
    var child = [Character:Trie]()
    var end: Int
    
    /** Initialize your data structure here. */
    init() {
        let str = "abcdefghijklmnopqrstuvwxyz";
        for s in str {
            child[s] = nil
        }
        end = 0
    }
    
    /** Inserts a word into the trie. */
    func insert(_ word: String) {
        var next = self
        for c in word {
            if(next.child[c] == nil) {
                next.child[c] = Trie()
            }
            next = next.child[c]!
        }
        next.end = 1
    }
    
    /** Returns if the word is in the trie. */
    func search(_ word: String) -> Bool {
        var next = self
        for c in word {
            if(next.child[c] == nil) {
                return false
            }
            next = next.child[c]!
        }
        return next.end > 0
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    func startsWith(_ prefix: String) -> Bool {
        var next = self
        for c in prefix {
            if(next.child[c] == nil) {
                return false
            }
            next = next.child[c]!
        }
        return true
    }
}

let obj = Trie()
let word = "hello", prefix = "hel"

 obj.insert(word)
 let ret_2: Bool = obj.search(word)
 let ret_3: Bool = obj.startsWith(prefix)
 print(ret_2, ret_3)

