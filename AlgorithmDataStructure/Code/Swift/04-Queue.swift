import Foundation

protocol Queue {
    associatedtype Element
    var isEmpty: Bool { get }
    var size: Int { get }
    var peek: Element? { get }
    mutating func enqueue(newElement: Element) -> Bool
    mutating func dequeue() -> Element?
}

struct ArrayQueue<Element>: Queue {
    
    private var items: [Element]
    private var capacity = 0
    private var head = 0
    private var tail = 0
    
    /// 构造方法
    init(defaultElement: Element, capacity: Int) {
        self.capacity = capacity
        items = [Element](repeating: defaultElement, count: capacity)
    }
    
    var isEmpty: Bool { return head == tail }
    
    var size: Int { return tail - head }
    
    var peek: Element? { return isEmpty ? nil : items[head] }
    
    mutating func enqueue(newElement: Element) -> Bool {
        // 如果队列满了，队列末尾没有空间了
        if tail == capacity {
            if head == 0 { return false }
            // 数据搬移
            for i in head ..< tail {
                items[i - head] = items[i]
            }
            tail -= head
            head = 0
        }
        
        items[tail] = newElement
        tail += 1
        return true
    }
    
    mutating func dequeue() -> Element? {
        if isEmpty {
            return nil
        }
        
        let item = items[head]
        head += 1
        return item
    }
}


/// 使用两个数组实现无界队列
struct ArrayQueue2<Element>: Queue {
    
    var inArray = [Element]() //输入数组，主要负责入队
    var outArray = [Element]() //输出数组，主要负责出队
    
    var isEmpty: Bool { return inArray.isEmpty && outArray.isEmpty }
    
    var size: Int { return inArray.count + outArray.count }
    
    var peek: Element? { return outArray.isEmpty ? inArray.first : outArray.last }
    
    mutating func enqueue(newElement: Element) -> Bool {
        inArray.append(newElement)
        return true
    }
    
    mutating func dequeue() -> Element? {
        if outArray.isEmpty {
            outArray = inArray.reversed() //倒序
            inArray.removeAll()
        }
        return outArray.popLast()
    }
}


/// 循环队列
struct CircleQueue<Element>: Queue {
    
    private var items: [Element]
    private var capacity = 0
    private var head = 0
    private var tail = 0
    
    /// 构造方法
    init(defaultElement: Element, capacity: Int) {
        self.capacity = capacity
        items = [Element](repeating: defaultElement, count: capacity)
    }
    
    var isEmpty: Bool { return head == tail }
    
    var size: Int {
        if tail >= head {
            return tail - head
        } else {
            return (tail + 1) % (capacity - head) //<<<<<<
        }
    }
    
    var peek: Element? { return isEmpty ? nil : items[head] }
    
    mutating func enqueue(newElement: Element) -> Bool {
        // 如果队列满了，队列末尾没有空间了
        print("capacity = \(capacity), tail = \(tail), head = \(head), \((tail+1) % capacity) , element = \(newElement)")
        if (tail + 1) % capacity == head {
            //这个需要改进，没有考虑倒数第一个入队还没满
            return false
        }
        
        items[tail] = newElement
        tail = (tail + 1) % capacity
        return true
    }
    
    mutating func dequeue() -> Element? {
        if isEmpty {
            return nil
        }
        
        let item = items[head]
        head = (head + 1) % capacity
        return item
    }
    
}



//var arrayQueue = ArrayQueue(defaultElement: -1, capacity: 2)
//arrayQueue.enqueue(newElement: 2)
//arrayQueue.enqueue(newElement: 3)
//arrayQueue.enqueue(newElement: 4)
//print("queue size = \(arrayQueue.size), is empty = \(arrayQueue.isEmpty)")
//print("\(String(describing: arrayQueue.dequeue())), \(String(describing: arrayQueue.dequeue())), \(String(describing: arrayQueue.dequeue()))")


//var arrayQueue2 = ArrayQueue2<Int>()
//arrayQueue2.enqueue(newElement: 2)
//arrayQueue2.enqueue(newElement: 3)
//arrayQueue2.enqueue(newElement: 4)
//print("queue size = \(arrayQueue2.size), is empty = \(arrayQueue2.isEmpty)")
//print("\(String(describing: arrayQueue2.dequeue())), \(String(describing: arrayQueue2.dequeue())), \(String(describing: arrayQueue2.dequeue()))")


//var circleQueue = CircleQueue(defaultElement: -1, capacity: 3)
//circleQueue.enqueue(newElement: 2)
//circleQueue.enqueue(newElement: 3)
//circleQueue.enqueue(newElement: 4)
//print("queue size = \(circleQueue.size), is empty = \(circleQueue.isEmpty)")
//print("\(String(describing: circleQueue.dequeue())) ")


class Node<T> {
    var value: T?
    var next: Node?
    init() { }
    init(value: T) {
        self.value = value
    }
}


struct LinkedListQueue<Element>: Queue {
    
    var head: Node<Element>?
    var tail: Node<Element>?
    
    var isEmpty: Bool { return head == nil }
    
    var size: Int {
        if isEmpty { return 0 }
        
        var count = 1
        var cur = head?.next
        while cur != nil {
            count += 1
            cur = cur?.next
        }
        return count
    }
    
    var peek: Element? { return head?.value }
    
    mutating func enqueue(newElement: Element) -> Bool {
        if isEmpty {
            let node = Node(value: newElement)
            head = node
            tail = node
        } else {
            tail!.next = Node(value: newElement)
            tail = tail!.next
        }
        return true
    }
    
    mutating func dequeue() -> Element? {
        if isEmpty {
            return nil
        }
        
        let node = head
        head = head!.next
        return node?.value
    }
}

//var listQueue = LinkedListQueue<Int>()
//listQueue.enqueue(newElement: 3)
//listQueue.enqueue(newElement: 4)
//print("queue size = \(listQueue.size), is empty = \(listQueue.isEmpty)")
//print("\(String(describing: listQueue.dequeue())), \(String(describing: listQueue.dequeue())), \(String(describing: listQueue.dequeue()))")

