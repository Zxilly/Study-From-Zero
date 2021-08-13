package top.learningman.study.collections

private fun testMap() {
    val map = mutableMapOf<String, Number>("Apple" to 1, "Banana" to 2, "Orange" to 3)
}

private fun testFunctional() {
    val list = mutableListOf("a", "bb", "ccc", "dddd", "eeeee")
    val lambda = { letter: String -> letter.length }
    val max1 = list.maxByOrNull(lambda)
    val max2 = list.maxByOrNull() { letter: String -> letter.length }
    val max3 = list.maxByOrNull { letter: String -> letter.length }
    val max4 = list.maxByOrNull { letter -> letter.length }
    val max5 = list.maxByOrNull { it.length }
}

fun main(){
    testFunctional()
}