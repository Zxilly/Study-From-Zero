package top.learningman.study

class Money(val value: Int) {
    operator fun plus(money: Money): Money {
        return Money(value + money.value)
    }

    operator fun plus(money: Int): Money {
        return Money(value + money)
    }
}

fun main() {
    val a = Money(200)
    println((a + 200).value)
    println((a + Money(20)).value)
}