package top.learningman.study.service

import android.app.NotificationChannel
import android.app.NotificationManager
import android.app.PendingIntent
import android.app.Service
import android.content.Context
import android.content.Intent
import android.os.Binder
import android.os.IBinder
import android.util.Log
import androidx.core.app.NotificationCompat
import top.learningman.study.MainActivity
import top.learningman.study.R
import kotlin.concurrent.thread

class FrontendService : Service() {

    private val binder = Binder()

    override fun onBind(intent: Intent): IBinder {
        return binder
    }

    override fun onCreate() {
        super.onCreate()
        val manager = getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        val channel =
            NotificationChannel("foreground", "ForeGround", NotificationManager.IMPORTANCE_DEFAULT)
        manager.createNotificationChannel(channel)

        val intent = Intent(this, MainActivity::class.java)
        val pi = PendingIntent.getActivity(this, 1, intent, PendingIntent.FLAG_IMMUTABLE)
        val notification = NotificationCompat.Builder(this, "foreground")
            .setContentTitle("Title")
            .setContentText("Content text")
            .setSmallIcon(R.drawable.ic_launcher_foreground)
            .setContentIntent(pi)
            .build()
        startForeground(1000, notification)
        thread {
            Thread.sleep(5000);
            this.stopSelf()
        }
    }

    override fun onDestroy() {
        Log.d("ForeGround", "Suicide")
        super.onDestroy()
    }
}