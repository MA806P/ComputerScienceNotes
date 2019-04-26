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
    
    private var dummy = Node<Element>() //哨兵结点
    
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
}


let list = List<Int>()
print("is empty \(list.isEmpty)")

list.insertToHead(value: 3)
list.insertToHead(value: 2)
list.insertToHead(value: 1)

let node1 = list.node(at: 1)
list.insert(before: node1!, newValue: 8)

let node2 = list.node(with: 3)
list.insert(after: node2!, newValue: 4)

list.dump()


let node3 = list.node(with: 8)
list.delete(node: node3!)
list.dump()

