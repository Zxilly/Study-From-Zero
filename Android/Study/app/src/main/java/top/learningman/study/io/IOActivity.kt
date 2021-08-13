package top.learningman.study.io

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_ioactivity.*
import top.learningman.study.R
import java.io.*
import java.lang.StringBuilder
import java.util.*

class IOActivity : AppCompatActivity() {
    private fun save(input: String) {
        try {
            val output = openFileOutput("data", Context.MODE_PRIVATE)
            val writer = BufferedWriter(OutputStreamWriter(output))
            writer.use {
                it.write(input)
            }
        } catch (e: IOException) {
            e.printStackTrace()
        }
    }

    private fun read(): String {
        val output = StringBuilder()
        try {
            val input = openFileInput("data")
            val reader = BufferedReader(InputStreamReader(input))

            input.use {
                reader.forEachLine {
                    output.append(it)
                }
            }
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return output.toString()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_ioactivity)

        // Read from file
        val content = read()
        if (content.isNotEmpty()) {
            ioText.setText(content, TextView.BufferType.EDITABLE)
            ioText.setSelection(content.length)
            Toast.makeText(this, "Restore $content", Toast.LENGTH_SHORT).show()
        }

        // Read from Preference
        val editor = getPreferences(MODE_PRIVATE)
        val content2 = editor?.getString("content", "");
        content2?.let {
            if (it.isNotEmpty()) {
                ioText2.setText(it)
                ioText2.setSelection(it.length)
            }
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        val text = ioText.text.toString()
        val text2 = ioText2.text.toString()

        save(text)

        val editor = getPreferences(MODE_PRIVATE)
        editor?.let {
            it.edit().apply {
                putString("content", text2)
                apply()
            }
        }
    }
}