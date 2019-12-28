
func reverse(x: Int) -> Int {
    var a = x, b = 0, result = 0;
    while a != 0 {
        b = a%10
        if (result > 2147483647/10 || result < -2147483648/10) {
            return 0;
        }
        result = result * 10 + b;
        a /= 10
    }
    return result;
}
print(reverse(x: 1534236469)) //0
