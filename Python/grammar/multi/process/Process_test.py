import os
import time
from multiprocessing import Process


# 子进程要执行的代码
def run_proc(name, name2):
    print('Run child process %s (%s)...' % (name, os.getpid()))
    print(name2)
    time.sleep(3)


def run_proc2(name):
    print('Run child process %s (%s)...' % (name, os.getpid()))
    time.sleep(3)


if __name__ == '__main__':
    print('Parent process %s.' % os.getpid())
    p = Process(target=run_proc2, args=('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')
