package top.learningman.study

import android.content.Context
import android.content.Intent

object Util {
    inline fun <reified T> startActivity(context: Context, block: Intent.() -> Unit) {
        Intent(context, T::class.java).also {
            it.block()
            context.startActivity(it)
        }
    }
}