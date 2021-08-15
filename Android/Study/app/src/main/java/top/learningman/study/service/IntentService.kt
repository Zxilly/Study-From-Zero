package top.learningman.study.service

import android.app.IntentService
import android.content.Intent
import android.content.Context
import android.util.Log

class IntentService : IntentService("IntentService") { // WorkManager 作为替代

    override fun onHandleIntent(intent: Intent?) {
        Log.d("IntentService", "Thread id is ${Thread.currentThread().name}")
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.d("IntentService", "Suicide")
    }

}