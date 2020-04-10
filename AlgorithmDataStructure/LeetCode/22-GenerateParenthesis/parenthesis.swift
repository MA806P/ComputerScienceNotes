class Solution {
    
    //方法一，动态规划
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
                for left in generateParenthesis2(i) {
                    for right in generateParenthesis2(n - 1 - i) {
                        ans.append("(" + left + ")" + right)
                    }
                }
            }
        }
        return ans
    }
    
    
    //方法三，深度优先 回溯算法，树+剪枝
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
            print("--- \(cur) --- ")
            ans.append(cur)
            return;
        }

        print(ans, cur, open, close, max)
        if open < max {
            backtrack(&ans, cur+"(", open+1, close, max)
        }
        if close < open {
            backtrack(&ans, cur+")", open, close+1, max)
        }
    }
    
    
    //方法四，广度优先遍历
    struct Node {
        var str: String
        var left: Int
        var right: Int
    }
    func generateParenthesis4(_ n: Int) -> [String] {
        var ans = [String]()
        var queue = [Node]()
        queue.append(Node(str: "", left: n, right: n))
        while queue.isEmpty == false {
            let node = queue.removeFirst()
            if node.left == 0 && node.right == 0 {
                ans.append(node.str)
            }
            if node.left > 0 {
                queue.append(Node(str: node.str + "(", left: node.left - 1, right: node.right))
            }
            if node.right > 0 && node.left < node.right {
                queue.append(Node(str: node.str + ")", left: node.left, right: node.right - 1))
            }
            print(ans, node)
        }
        return ans
    }
    
}

let s = Solution()
print(s.generateParenthesis3(3))

/**
 深度优先
 []  0 0 3
 [] ( 1 0 3
 [] (( 2 0 3
 [] ((( 3 0 3
 [] ((() 3 1 3
 [] ((()) 3 2 3
 --- ((())) ---
 ["((()))"] (() 2 1 3
 ["((()))"] (()( 3 1 3
 ["((()))"] (()() 3 2 3
 --- (()()) ---
 ["((()))", "(()())"] (()) 2 2 3
 ["((()))", "(()())"] (())( 3 2 3
 --- (())() ---
 ["((()))", "(()())", "(())()"] () 1 1 3
 ["((()))", "(()())", "(())()"] ()( 2 1 3
 ["((()))", "(()())", "(())()"] ()(( 3 1 3
 ["((()))", "(()())", "(())()"] ()(() 3 2 3
 --- ()(()) ---
 ["((()))", "(()())", "(())()", "()(())"] ()() 2 2 3
 ["((()))", "(()())", "(())()", "()(())"] ()()( 3 2 3
 --- ()()() ---
 ["((()))", "(()())", "(())()", "()(())", "()()()"]
 
 */

/**
广度优先
 [] Node(str: "", left: 3, right: 3)
 [] Node(str: "(", left: 2, right: 3)
 [] Node(str: "((", left: 1, right: 3)
 [] Node(str: "()", left: 2, right: 2)
 [] Node(str: "(((", left: 0, right: 3)
 [] Node(str: "(()", left: 1, right: 2)
 [] Node(str: "()(", left: 1, right: 2)
 [] Node(str: "((()", left: 0, right: 2)
 [] Node(str: "(()(", left: 0, right: 2)
 [] Node(str: "(())", left: 1, right: 1)
 [] Node(str: "()((", left: 0, right: 2)
 [] Node(str: "()()", left: 1, right: 1)
 [] Node(str: "((())", left: 0, right: 1)
 [] Node(str: "(()()", left: 0, right: 1)
 [] Node(str: "(())(", left: 0, right: 1)
 [] Node(str: "()(()", left: 0, right: 1)
 [] Node(str: "()()(", left: 0, right: 1)
 ["((()))"] Node(str: "((()))", left: 0, right: 0)
 ["((()))", "(()())"] Node(str: "(()())", left: 0, right: 0)
 ["((()))", "(()())", "(())()"] Node(str: "(())()", left: 0, right: 0)
 ["((()))", "(()())", "(())()", "()(())"] Node(str: "()(())", left: 0, right: 0)
 ["((()))", "(()())", "(())()", "()(())", "()()()"] Node(str: "()()()", left: 0, right: 0)
 ["((()))", "(()())", "(())()", "()(())", "()()()"]

 
 */
