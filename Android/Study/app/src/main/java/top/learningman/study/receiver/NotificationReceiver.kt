package top.learningman.study.receiver

import android.app.NotificationChannel
import android.app.NotificationManager
import android.app.PendingIntent
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.util.Log
import androidx.core.app.NotificationCompat
import top.learningman.study.ListActivity
import top.learningman.study.R


class NotificationReceiver : BroadcastReceiver() {
    companion object CountID {
        private var value = 1
        fun get(): Int {
            return value++
        }
    }

    override fun onReceive(context: Context, intent: Intent) {
        val manager = context.getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        val channel =
            NotificationChannel("normal", "Normal", NotificationManager.IMPORTANCE_DEFAULT)
        manager.createNotificationChannel(channel)

        val priIntent = Intent(context, ListActivity::class.java)
        val pi = PendingIntent.getActivity(context, 0 ,priIntent,PendingIntent.FLAG_IMMUTABLE)

        val notification = NotificationCompat.Builder(context, "normal")
            .setContentTitle("This is title")
            .setContentText("This is text")
            .setSmallIcon(R.drawable.ic_stat_name)
            .setContentIntent(pi)
            .setAutoCancel(true)
            .build()
        manager.notify(get(), notification)

        Log.w("Notify", "ID is ${get()}")
    }
}