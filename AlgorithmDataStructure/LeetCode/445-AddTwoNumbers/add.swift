
 public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
        
    }
    
    func dump() {
        var l: ListNode? = self
        while l != nil {
            print("\(l!.val)")
            l = l!.next
        }
    }
}

class Solution {
    
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var res :ListNode?
        var flag = 0, sum = 0
        
        //入栈，倒序相加
        var templ1 = l1, templ2 = l2
        var stack1 = [Int](), stack2 = [Int]()
        while templ1 != nil { stack1.append(templ1!.val); templ1 = templ1!.next }
        while templ2 != nil { stack2.append(templ2!.val); templ2 = templ2!.next }
        while stack1.isEmpty == false || stack2.isEmpty == false {
            let node = ListNode(0)
            sum = (stack1.isEmpty ? 0 : stack1.removeLast()) + (stack2.isEmpty ? 0 : stack2.removeLast()) + flag
            if sum > 9 { sum = sum%10; flag = 1; } else { flag = 0 }
            node.val = sum; node.next = res; res = node
        }
        if flag == 1 {
            let node = ListNode(1)
            node.next = res; res = node
        }
        return res
    }
    
}
 


 var l1 = ListNode(8)
 var l2 = ListNode(4)
 l2.next = l1
 var l3 = ListNode(2)
 l3.next = l2
 var l4 = ListNode(0)
 l4.next = l3
l4.dump()
print("----")

var l21 = ListNode(8)
var l22 = ListNode(8)
l22.next = l21
l22.dump()
 print("----")

let s = Solution()
var l = s.addTwoNumbers(l4, l22)
while l != nil {
    print("\(l!.val)")
    l = l!.next
}
