package top.learningman.study

class Shape(var height: Int, var length: Double) { // 使用 var 和 val 可以使得传入变量在当前类中被实例化
    var aa = height * length
}

class Shape2 constructor(var height: Int, var length: Double) {
    var aa = height * length
}

open class Shape3(height: Int, length: Double) {
    init {
        var something = height + length
    }
}

class Shape4(val aa: Int, val bb: Double) : Shape3(aa, bb) {
    init {
        var sth = aa - bb
    }
}