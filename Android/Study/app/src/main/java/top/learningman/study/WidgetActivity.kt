package top.learningman.study

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_widget.*

class WidgetActivity : AppCompatActivity(), View.OnClickListener {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_widget)
        Log.i("Widget Test", "Set View")
        test_button.setOnClickListener(this)
        test_button2.setOnClickListener(this)
    }

    override fun onClick(v: View?) {
        Log.i("Widget Test", "onClick")
        when (v?.id) {
            R.id.test_button -> {
                val text = test_edittext.text.toString()
                Log.i("WidgetTest", "Get $text, will make toast")
                Toast.makeText(this, text, Toast.LENGTH_SHORT).show()
            }
            R.id.test_button2 -> {
                Log.w("WidgetTest", "Button2")
                AlertDialog.Builder(this).apply {
                    setTitle("Dialog")
                    setMessage("Msg")
                    setCancelable(false)
                    setPositiveButton("OK") { _, _ ->
                    }
                    setNegativeButton("Cancel") { _, _ ->
                    }
                    show()
                }
            }
        }
    }
}