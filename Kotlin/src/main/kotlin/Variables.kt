package top.learningman.study

val PI = 3.14 // 静态变量，不能被修改 const
var x = 0 // 和 Java 一致，可被修改，自动类型推断 let

fun test(): Unit {
    val a: Int = 1  // immediate assignment
    val b = 2   // `Int` type is inferred
    val c: Int  // Type required when no initializer is provided
    c = 3       // deferred assignment
}