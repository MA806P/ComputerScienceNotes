import Foundation

func bubbleSort<T>(_ elements: [T]) -> [T] where T: Comparable {
    var array = elements
    guard array.count > 1 else {
        return array
    }
    
    var flag = true
    for i in 0..<array.count {
        flag = true
        for j in 0 ..< array.count - i - 1 {
            if array[j] > array[j + 1] {
                array.swapAt(j, j + 1)
                flag = false
            }
        }
        if flag { break; }
    }
    return array
}

func insertSort<T>(_ elements: [T]) ->[T] where T: Comparable {
    var array = elements
    guard array.count > 1 else {
        return array
    }
    
    for i in 1 ..< array.count {
        let value = array[i]
        var j = i - 1
        while j >= 0 {
            if array[j] > value  {
                array[j + 1] = array[j]
                j -= 1
            } else {
                break
            }
        }
        array[j + 1] = value
    }
    return array
}


func selectSort<T>(_ elements: [T]) ->[T] where T: Comparable {
    var array = elements
    guard array.count > 1 else {
        return array
    }
    
    for i in 0 ..< array.count {
        var min = i
        for j in i ..< array.count {
            if array[j] < array[min] {
                min = j
            }
        }
        if min != i {
            array.swapAt(i, min)
        }
    }
    return array
}



var array = [1,8,6,5,7,3,2,0,9,4,0,2,1,1,9]
var bubbleSortArray = bubbleSort(array)
print(bubbleSortArray)

var insertSortArray = insertSort(array)
print(insertSortArray)

var selectSortArray = selectSort(array)
print(selectSortArray)


