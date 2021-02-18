import asyncio
import threading


@asyncio.coroutine
def hello():
    print('Hello world! (%s)' % threading.currentThread())
    yield from asyncio.sleep(3)  # 程序在此处并未阻塞，而是在call另外一个协程后继续执行，直到另外一个协程执行到yield再继续执行
    print('Hello again! (%s)' % threading.currentThread())


loop = asyncio.get_event_loop()
tasks = [hello(), hello()]
loop.run_until_complete(asyncio.wait(tasks))
loop.close()
