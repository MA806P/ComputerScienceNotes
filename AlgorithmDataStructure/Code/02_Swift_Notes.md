1、
Swift 中由低至高提供了 private，fileprivate，internal，public 和 open 五种访问控制的权限  
fileprivate修饰的属性，能在当前文件内访问到，不管是否在本类的作用域;
private 只能在本类的作用域且在当前文件内能访问  


2、inout  
如果我们希望一个函数可以修改它的参数变量的值，我们可以使用 inout 关键词。这个相当于编程语言概念中所谓的传址调用  
```
func foo(_ x: inout Int) {
    x = 2
}
var x = 5
foo(&x) // x = 2
```  

但实际上 Swift 中 inout 只不过是按值传递，然后再写回原变量，而不是按引用传递：
> An in-out parameter has a value that is passed in to the function, is modified by the function, and is passed back out of the function to replace the original value.  


3、

字符串截取

```
extension StringProtocol {
    subscript(_ offset: Int)                     -> Element     { self[index(startIndex, offsetBy: offset)] }
    subscript(_ range: Range<Int>)               -> SubSequence { prefix(range.lowerBound+range.count).suffix(range.count) }
    subscript(_ range: ClosedRange<Int>)         -> SubSequence { prefix(range.lowerBound+range.count).suffix(range.count) }
    subscript(_ range: PartialRangeThrough<Int>) -> SubSequence { prefix(range.upperBound.advanced(by: 1)) }
    subscript(_ range: PartialRangeUpTo<Int>)    -> SubSequence { prefix(range.upperBound) }
    subscript(_ range: PartialRangeFrom<Int>)    -> SubSequence { suffix(Swift.max(0, count-range.lowerBound)) }
}

extension LosslessStringConvertible {
    var string: String { .init(self) }
}

extension BidirectionalCollection {
    subscript(safe offset: Int) -> Element? {
        guard !isEmpty, let i = index(startIndex, offsetBy: offset, limitedBy: index(before: endIndex)) else { return nil }
        return self[i]
    }
}

let test = "Hello USA 🇺🇸!!! Hello Brazil 🇧🇷!!!"
test[safe: 10]   // "🇺🇸"
test[11]   // "!"
test[10...]   // "🇺🇸!!! Hello Brazil 🇧🇷!!!"
test[10..<12]   // "🇺🇸!"
test[10...12]   // "🇺🇸!!"
test[...10]   // "Hello USA 🇺🇸"
test[..<10]   // "Hello USA "
test.first   // "H"
test.last    // "!"

// Subscripting the Substring
 test[...][...3]  // "Hell"

// Note that they all return a Substring of the original String.
// To create a new String from a substring
test[10...].string  // "🇺🇸!!! Hello Brazil 🇧🇷!!!"

```


"\(s[s.index(s.startIndex, offsetBy: start) ... s.index(s.startIndex, offsetBy: end)])"


4、字符串单个字符获取  
```
let greeting = "Guten Tag!"
greeting[greeting.startIndex]
// G
greeting[greeting.index(before: greeting.endIndex)]
// !
greeting[greeting.index(after: greeting.startIndex)]
// u
let index = greeting.index(greeting.startIndex, offsetBy: 7)
greeting[index]
// a
```