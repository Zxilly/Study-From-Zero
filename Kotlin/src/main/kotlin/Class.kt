package top.learningman.study

class Shape1(override var height: Int, override var length: Double) : Shape() { // 使用 var 和 val 可以使得传入变量在当前类中被实例化
    var aa = height * length
}

class Shape2 constructor(var height: Int, var length: Double) {
    var aa = height * length
}

open class Shape3(height: Int, length: Double) {
    init {
        var something = height + length
    }

    open fun a():Int {
        return 1
    }
}

class Shape4(private val aa: Int, private val bb: Double) : Shape3(aa, bb) {
    init {
        var sth = aa - bb
    }

    override fun a(): Int {
        return aa
    }

}

abstract class Shape {
    abstract var height: Int
    abstract var length: Double
}