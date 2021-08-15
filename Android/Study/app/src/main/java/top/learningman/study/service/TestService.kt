package top.learningman.study.service

import android.app.Service
import android.content.Intent
import android.os.IBinder
import android.util.Log
import kotlin.concurrent.thread

class TestService : Service() {

    var count = 0;
    private var threadPool: MutableList<Thread> = mutableListOf<Thread>()

    override fun onBind(intent: Intent): IBinder {
        TODO("Return the communication channel to the service.")
    }

    override fun onCreate() {
        super.onCreate()
        Log.w("Service", "Service create")
    }

    override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
        val thread = thread {
            while (!Thread.currentThread().isInterrupted) {
                val intent1 = Intent("top.learningman.study.test.NOTIFICATION")
                intent1.setPackage(packageName)
                intent1.putExtra("NotifyID", count++);
                sendBroadcast(intent1)
                if (!Thread.currentThread().isInterrupted) {
                    try {
                        Thread.sleep(2000);
                    } catch (e: InterruptedException) {
                        Log.w("Service itself", "Get InterruptedException")
                        return@thread
                    }
                } else {
                    break
                }
            }
        }
        threadPool.add(thread)
        return START_NOT_STICKY
    }

    override fun onDestroy() {
        for (thread in threadPool) {
            if (!thread.isInterrupted) {
                thread.interrupt()
                Log.e("Service killer", "Kill $thread")
            }
        }
        for (thread in threadPool) {
            thread.join()
        }
        threadPool.clear()
        Log.w("Service", "Service Destroy")
        super.onDestroy()
    }
}