package top.learningman.study.collections

private fun testList() {
    val items = listOf("apple", "banana", "kiwifruit")
    val items2 = mutableListOf<String>("apple")
    items2.add("banana")
}

private fun testMap() {
    val map = mutableMapOf<String, Number>("Apple" to 1, "Banana" to 2)
}