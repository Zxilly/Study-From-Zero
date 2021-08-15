package top.learningman.study

import android.Manifest
import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.widget.Toast
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import kotlinx.android.synthetic.main.main_activity.*
import top.learningman.study.io.IOActivity
import top.learningman.study.nested.DialogActivity

class MainActivity : AppCompatActivity() {
    private fun shortToast(text: String) {
        return Toast.makeText(this, text, Toast.LENGTH_SHORT).show()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.main_activity)
        button1.setOnClickListener {
            val intent = Intent(Intent.ACTION_VIEW)
            intent.data = Uri.parse("https://learningman.top")
            startActivity(intent)
        }
        button2.setOnClickListener {
            val intent = Intent(this, SecondActivity::class.java)
            intent.putExtra("something", "a string")
            startActivity(intent)
        }

        button3.setOnClickListener {
            val intent = Intent(this, DialogActivity::class.java)
            startActivity(intent)
        }

        button4.setOnClickListener {
            startActivity(Intent(this, WidgetActivity::class.java))
        }

        button5.setOnClickListener {
            startActivity(Intent(this, ListActivity::class.java))
        }

        button6.setOnClickListener {
            val intent = Intent("top.learningman.study.test.MY_BROADCAST")
            intent.setPackage(packageName)
            sendBroadcast(intent)
        }

        button7.setOnClickListener {
            startActivity(Intent(this, IOActivity::class.java))
        }

        button8.setOnClickListener {
            val intent = Intent("top.learningman.study.test.NOTIFICATION")
            intent.setPackage(packageName)
            sendBroadcast(intent)
        }

        button9.setOnClickListener {
            startActivity(Intent(this, ThreadActivity::class.java))
        }

        button10.setOnClickListener {
            startActivity(Intent(this, ServiceActivity::class.java))
        }

        Log.i("MainActivity", "onCreate setup.")
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.add_item -> shortToast("Add Toast")
            R.id.remove_item -> shortToast("Remove")
            R.id.finish -> finish()
            R.id.call -> {
                if (ContextCompat.checkSelfPermission(
                        this,
                        Manifest.permission.CALL_PHONE
                    ) != PackageManager.PERMISSION_GRANTED
                ) {
                    ActivityCompat.requestPermissions(
                        this,
                        arrayOf(Manifest.permission.CALL_PHONE),
                        1
                    )
                } else {
                    call()
                }
            }
        }
        return true
    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        when (requestCode) {
            1 -> {
                if (grantResults.isNotEmpty() && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    call()
                } else {
                    Toast.makeText(this, "No permission", Toast.LENGTH_SHORT).show()
                }
            }
        }
    }

    private fun call() {
        try {
            val intent = Intent(Intent.ACTION_CALL)
            intent.data = Uri.parse("tel:10086")
            startActivity(intent)
        } catch (e: SecurityException) {
            e.printStackTrace()
        }
    }
}