package top.learningman.study

import java.lang.Integer.parseInt

fun main() {
    printProduct("23", "45")
}

abstract class Study {
    abstract fun aaa()
    abstract fun bbb()
}


fun printProduct(arg1: String, arg2: String) {
    val x: Int = parseInt(arg1)
    val y: Int = parseInt(arg2)

    println(x * y)
}

fun getLength(text: String?) = text?.length ?: 0

fun nullTest(study: Study?) {
    study?.let { stu ->
        stu.aaa()
        stu.bbb()
    }
    study?.let {
        it.aaa()
        it.bbb()
    }
}