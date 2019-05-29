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



