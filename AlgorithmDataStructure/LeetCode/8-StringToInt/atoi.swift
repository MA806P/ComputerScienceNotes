
class Solution {
    
    let INT_MAX = 2147483647
    let INT_MIN = -2147483648
    
    
    //自动机
    //每个时刻有一个状态 s，每次从序列中输入一个字符 c，并根据字符 c 转移到下一个状态 s'。
    //这样只需要建立一个覆盖所有情况的从 s 与 c 映射到 s' 的表格即可解决题目中的问题。
    
    private var state = "start"
    private let map = ["start":["start", "signed", "in_number", "end"],
    "signed":["end", "end", "in_number", "end"],
    "in_number":["end", "end", "in_number", "end"],
    "end":["end", "end", "end", "end"]]
    
    var ans = 0
    var sign = 1
    
    func get_col(_ c: Character) -> Int {
        if c == " " { return 0; }
        if c == "+" || c == "-" { return 1 }
        let i = Int("\(c)")
        if i != nil {
            if  i! >= 0 && i! <= 9 { return 2 }
        }
        return 3
    }
    
    func get(_ c: Character) {
        state = map[state]![get_col(c)]
        if state == "in_number" {
            ans = ans * 10 + Int("\(c)")!
            ans = sign == 1 ? min(ans, INT_MAX) : min(ans,-1 * INT_MIN)
        } else if state == "signed" {
            sign = c == "+" ? 1 : -1
        }
    }
    
    
    func myAtoi(_ str: String) -> Int {
        for c in str {
            get(c)
        }
        return sign * ans
    }
}
let s = Solution()
print(s.myAtoi("-2147483648"))
