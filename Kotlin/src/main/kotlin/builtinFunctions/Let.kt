package top.learningman.study.builtinFunction

fun test(a: String?) {
    a?.let {
        it.plus("a")
        it.plus("b")
    }
}