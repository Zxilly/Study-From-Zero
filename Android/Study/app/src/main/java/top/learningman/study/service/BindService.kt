package top.learningman.study.service

import android.app.Service
import android.content.Intent
import android.os.Binder
import android.os.IBinder
import android.util.Log

class BindService : Service() {

    private val mBinder = DownloadBinder()

    class DownloadBinder : Binder() {
        fun start() {
            Log.d("BindService", "Start Service")
        }

        fun getProg(): Int {
            Log.d("BindService", "Get Progress")
            return 0
        }
    }

    override fun onBind(intent: Intent): IBinder {
        return mBinder
    }
}