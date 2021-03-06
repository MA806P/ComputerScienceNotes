import Foundation

class Node<T> {
    var value: T?
    var next: Node?
    
    init() {}
    
    init(value: T) {
        self.value = value
    }
}

class List<Element: Equatable> {
    
    var dummy = Node<Element>() //哨兵结点
    
    var size: Int {
        var num = 0
        var tmpNode = dummy.next
        while tmpNode != nil {
            num += 1
            tmpNode = tmpNode?.next
        }
        return num
    }
    
    var isEmpty: Bool {
        return size <= 0
    }
    
    func node(with value: Element) -> Node<Element>? {
        var node = dummy.next
        while node != nil {
            if  node!.value == value {
                return node
            }
            node = node!.next
        }
        return nil
    }
    
    func node(at index: Int) -> Node<Element>? {
        var num = 1
        var node = dummy.next
        while node != nil {
            if num == index {
                return node
            }
            node = node!.next
            num += 1
        }
        return nil
    }
    
    func insertToHead(node: Node<Element>) {
        node.next = dummy.next
        dummy.next = node
    }
    
    func insertToHead(value: Element) {
        let newNode = Node(value: value)
        return insertToHead(node: newNode)
    }
    
    
    func insert(after node: Node<Element>, newNode: Node<Element>) {
        newNode.next = node.next
        node.next = newNode
    }
    
    func insert(after node: Node<Element>, newValue: Element) {
        let newNode = Node(value: newValue)
        return insert(after: node, newNode: newNode)
    }
    
    
    func insert(before node: Node<Element>, newNode: Node<Element>) {
        var lastNode = dummy
        var tmpNode = dummy.next
        
        while tmpNode != nil {
            if tmpNode === node {
                newNode.next = tmpNode
                lastNode.next = newNode
                break
            }
            lastNode = tmpNode!
            tmpNode = tmpNode!.next
        }
    }
    
    func insert(before node: Node<Element>, newValue: Element) {
        let newNode = Node(value: newValue)
        return insert(before: node, newNode: newNode)
    }
    
    
    func delete(node: Node<Element>) {
        var lastNode = dummy
        var tmpNode = dummy.next
        
        while tmpNode != nil {
            if tmpNode === node {
                lastNode.next = tmpNode!.next
                break
            }
            lastNode = tmpNode!
            tmpNode = tmpNode!.next
        }
    }
    
    func delete(value: Element) {
        var lastNode = dummy
        var tmpNode = dummy.next
        
        while tmpNode != nil {
            if tmpNode!.value == value {
                lastNode.next = tmpNode!.next
                break
            }
            lastNode = tmpNode!
            tmpNode = tmpNode!.next
        }
    }
    
    func dump() {
        var tmpNode = dummy.next
        while tmpNode != nil {
            print("\(String(describing: tmpNode!.value))")
            tmpNode = tmpNode!.next
        }
        print("list is empty: \(isEmpty). size: \(size)")
    }
    
    
    //链表反转
    func reverse() {
        var reverseHead: Node<Element>?, currentNode: Node<Element>?, prevNode: Node<Element>?
        
        reverseHead = dummy
        if reverseHead != nil {
            currentNode = reverseHead!.next
            if currentNode != nil {
                prevNode = currentNode!.next
                while prevNode != nil {
                    currentNode!.next = prevNode!.next
                    prevNode!.next = reverseHead!.next
                    reverseHead!.next = prevNode
                    
                    prevNode = currentNode!.next
                }
            }
        }
    }
    
    //检测环
    func hasCircle() -> Bool {
        var fast = dummy.next
        var slow: Node<Element>? = dummy
        while fast != nil {
            if fast === slow {
                return true
            }
            fast = fast!.next?.next
            slow = slow!.next
        }
        return false
    }
    
    //中间节点
    func halfNode() -> Node<Element>? {
        var fast: Node<Element>? = dummy.next
        var slow: Node<Element>? = dummy.next
        
        while fast?.next != nil, fast?.next?.next != nil {
            fast = fast!.next?.next
            slow = slow!.next
        }
        return slow
    }
    
    //删除倒数第n个节点
    func deleteLastNode(at lastNum: Int) {
        var fast: Node<Element>? = dummy
        var slow: Node<Element>? = dummy
        var num = 0
        while fast != nil, num < lastNum {
            fast = fast!.next
            num += 1
        }
        
        var prevNode: Node<Element>?
        while fast != nil {
            prevNode = slow
            fast = fast!.next
            slow = slow!.next;
        }
        prevNode?.next = slow?.next
    }
    
}


//合并两个有序链表
func mergeTwoList(list1: List<Int>, list2: List<Int>) -> Node<Int>? {
    guard !list1.isEmpty else {
        return list2.dummy.next
    }
    guard !list2.isEmpty else {
        return list1.dummy.next
    }
    
    var head: Node<Int>?,  tail: Node<Int>?
    var node1: Node<Int>? = list1.dummy.next
    var node2: Node<Int>? = list2.dummy.next
    
    if node1!.value! <= node2!.value! {
        head = node1
        node1 = node1!.next
    } else {
        head = node2
        node2 = node2!.next
    }
    tail = head
    
    while node1 != nil, node2 != nil {
        if node1!.value! <= node2!.value! {
            tail!.next = node1
            node1 = node1!.next
        } else {
            tail!.next = node2
            node2 = node2!.next
        }
        tail = tail!.next
    }
    
    if node1 != nil {
        tail?.next = node1
    } else {
        tail?.next = node2
    }
    
    return head
}




let list = List<Int>()
print("is empty \(list.isEmpty)")
list.insertToHead(value: 9)
list.insertToHead(value: 6)
list.insertToHead(value: 3)
let node1 = list.node(at: 1)
list.insert(before: node1!, newValue: 1)
let node2 = list.node(with: 3)
list.insert(after: node2!, newValue: 5)
list.dump()

//let node3 = list.node(with: 8)
//list.delete(node: node3!)
//list.dump()

//list.reverse()
//list.dump()

//print("list has circle: \(list.hasCircle())")
//print("half node: \(String(describing: list.halfNode()?.value))\n")

//list.deleteLastNode(at: 0)
//list.dump()



let list2 = List<Int>()
list2.insertToHead(value: 8)
list2.insertToHead(value: 4)
list2.insertToHead(value: 2)
list2.insertToHead(value: 0)
list2.dump()

print("\n**************\n")
var node = mergeTwoList(list1: list, list2: list2)
while node != nil {
    print("\(String(describing: node!.value))")
    node = node!.next
}
