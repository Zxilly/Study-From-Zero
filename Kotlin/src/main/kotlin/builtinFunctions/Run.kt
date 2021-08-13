package top.learningman.study.builtinFunctions

fun main() {
    val list = listOf("aa", "bb", "cc", "dd")
    val result = StringBuilder().run {
        append("start")
        for (aa in list) {
            append(aa)
        }
        append("end")
    }
    println(result)
}