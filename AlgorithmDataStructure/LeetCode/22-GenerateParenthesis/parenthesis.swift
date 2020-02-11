class Solution {
    
    func generateParenthesis(_ n: Int) -> [String] {
        if n == 0 { return [""] }
        if n == 1 { return ["()"] }
        
        var dp = [[""], ["()"]]
        
        for i in 2 ... n {
            var array = [String]()
            for j in 0 ..< i {
                let array1 = dp[j]
                let array2 = dp[i - 1 - j]
                for str1 in array1 {
                    for str2 in array2 {
                        array.append("(" + str1 + ")" + str2);
                    }
                }
            }
            dp.append(array)
        }
        return dp[n]
    }
    
    //方法二
    func generateParenthesis2(_ n: Int) -> [String] {
        var ans = [String]()
        if n == 0 {
            ans.append("")
        } else {
            for i in 0 ..< n {
                for left in generateParenthesis(i) {
                    for right in generateParenthesis(n - 1 - i) {
                        ans.append("(" + left + ")" + right)
                    }
                }
            }
        }
        return ans
    }
    
    
    //方法三
    /*
     只有在我们知道序列仍然保持有效时才添加 '(' or ')'
     可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点，
     如果我们还剩一个位置，我们可以开始放一个左括号。 如果它不超过左括号的数量，我们可以放一个右括号。
     */
    func generateParenthesis3(_ n: Int) -> [String] {
        var ans = [String]()
        backtrack(&ans, "", 0, 0, n)
        return ans
    }
    
    func backtrack(_ ans: inout [String], _ cur: String, _ open: Int, _ close: Int, _ max: Int) {
        if cur.count == max * 2 {
            ans.append(cur)
            return;
        }

        if open < max {
            backtrack(&ans, cur+"(", open+1, close, max)
        }
        if close < open {
            backtrack(&ans, cur+")", open, close+1, max)
        }
    }
    
    
    
}

let s = Solution()
print(s.generateParenthesis3(3))
