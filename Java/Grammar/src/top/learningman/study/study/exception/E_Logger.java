package top.learningman.study.study.exception;

import java.util.logging.Logger;

public class E_Logger { // 需要在 JVM 启动时传递参数 -Djava.util.logging.config.file=<config-file-name>
    public static void main(String[] args) {
        Logger logger = Logger.getGlobal();
        logger.info("start process...");
        logger.warning("memory is running out...");
        logger.fine("ignored.");
        logger.severe("process will be terminated...");
    }
}
