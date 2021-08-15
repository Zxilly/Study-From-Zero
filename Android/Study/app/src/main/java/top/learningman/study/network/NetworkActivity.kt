package top.learningman.study.network

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_network.*
import okhttp3.OkHttpClient
import okhttp3.Request
import top.learningman.study.R
import java.lang.Exception
import kotlin.concurrent.thread

class NetworkActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_network)
        getContent.setOnClickListener {
            sendRequest()
        }
    }

    private fun sendRequest() {
        thread {
            try {
                val client = OkHttpClient()
                val request = Request.Builder()
                    .url("https://learningman.top")
                    .build()
                val response = client.newCall(request).execute()
                val responseData = response.body?.string()
                if (responseData != null) {
                    runOnUiThread {
                        networkText.text = responseData
                    }
                }
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
    }
}