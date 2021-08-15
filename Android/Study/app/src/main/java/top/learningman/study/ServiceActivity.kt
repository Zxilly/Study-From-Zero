package top.learningman.study

import android.content.ComponentName
import android.content.Context
import android.content.Intent
import android.content.ServiceConnection
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.IBinder
import kotlinx.android.synthetic.main.activity_service.*
import top.learningman.study.service.BindService
import top.learningman.study.service.FrontendService
import top.learningman.study.service.IntentService
import top.learningman.study.service.TestService

class ServiceActivity : AppCompatActivity() {

    lateinit var downloadBinder: BindService.DownloadBinder

    private val connection = object : ServiceConnection {
        override fun onServiceConnected(name: ComponentName?, service: IBinder?) {
            downloadBinder = service as BindService.DownloadBinder
            downloadBinder.start()
            downloadBinder.getProg()
        }

        override fun onServiceDisconnected(name: ComponentName?) {

        }

    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_service)
        serviceStart.setOnClickListener {
            val intent = Intent(this, TestService::class.java)
            startService(intent)
        }

        serviceStop.setOnClickListener {
            val intent = Intent(this, TestService::class.java)
            stopService(intent)
        }

        bindserviceStart.setOnClickListener {
            val intent = Intent(this, BindService::class.java)
            bindService(intent, connection, Context.BIND_AUTO_CREATE)
        }

        foreserviceStart.setOnClickListener {
            Intent(this, FrontendService::class.java).also { intent ->
                startService(intent)
            }
        }

        intentServiceStart.setOnClickListener {
            Intent(this, IntentService::class.java).also { intent ->
                startService(intent)
            }
        }
    }

    override fun onStop() {
        super.onStop()
        unbindService(connection)
    }
}