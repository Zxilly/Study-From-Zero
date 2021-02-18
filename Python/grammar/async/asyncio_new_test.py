import asyncio


async def hello():
    print("Hello world!")
    r = await asyncio.sleep(3)
    print("Hello again!")


loop = asyncio.get_event_loop()

loop.run_until_complete(asyncio.wait([hello()]))
