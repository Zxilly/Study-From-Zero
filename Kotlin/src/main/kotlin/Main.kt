package top.learningman.study

fun main(args: Array<String>) {
    println("Hello World!")

    // Try adding program arguments at Run/Debug configuration
    println("Program arguments: ${args.joinToString()}")

    val a = "AAA"
    val b = "AAA"

    println(a === b)
}