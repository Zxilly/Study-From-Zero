package top.learningman.study

class Test {
    companion object {
        fun static_util() {
            println("print something")
        }

        @JvmStatic
        fun true_static_util() {
            println("Can be static in Java.")
        }
    }
}

fun static() {
    println("Top level function will be static function in StaticKt")
}