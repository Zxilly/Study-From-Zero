package top.learningman.study

import java.lang.Integer.parseInt

fun main() {
    printProduct("23", "45")
}


fun printProduct(arg1: String, arg2: String) {
    val x: Int = parseInt(arg1)
    val y: Int = parseInt(arg2)

    // Using `x * y` yields error because they may hold nulls.
    println(x * y)
}
