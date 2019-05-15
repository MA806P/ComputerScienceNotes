import Foundation

protocol Stack {
    
    /// 持有的数据类型
    associatedtype Element
    
    var isEmpty: Bool { get }
    var size: Int { get }
    var peek: Element? { get } // 返回队列头部元素
    mutating func push(newElement: Element) ->Bool
    mutating func pop() -> Element?
}

class Node<T> {
    var value: T?
    var next: Node?
    init() { }
    init(value: T) {
        self.value = value
    }
}

struct LinkedListStack<Element>: Stack {
    private var head = Node<Element>() //哨兵结点
    
    var isEmpty: Bool { return head.next == nil }
    var size: Int {
        var count = 0
        var cur = head.next
        while cur != nil {
            count += 1
            cur = cur?.next
        }
        return count
    }
    
    var peek: Element? { return head.next?.value }
    
    func push(newElement: Element) -> Bool {
        let newNode = Node(value: newElement)
        newNode.next = head.next
        head.next = newNode
        return true
    }
    
    func pop() -> Element? {
        let node = head.next
        head.next = node?.next
        return node?.value
    }
}


struct BrowserPage {
    private var forwardArray = [String]()
    private var backArray = [String]()
    
    var currentURL: String? { return forwardArray.last }
    
    init(url: String) {
        forwardArray.append(url)
    }
    
    mutating func goForward(url: String) {
        forwardArray.append(url)
    }
    mutating func goBack() {
        backArray.append(forwardArray.popLast()!)
    }
}




var listStack = LinkedListStack<Int>()
listStack.push(newElement: 6)
listStack.push(newElement: 3)

print("stack size = \(listStack.size). peek = \(String(describing: listStack.peek))")
let a = listStack.pop()
let b = listStack.pop()
let c = listStack.pop()
print("a = \(String(describing: a)). b = \(String(describing: b)). c = \(String(describing: c))")

