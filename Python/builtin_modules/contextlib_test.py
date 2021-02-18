from contextlib import *
from urllib.request import urlopen


class test(object):
    @contextmanager
    def test(self):
        print('aa')  # 准备
        yield 'bb'  # 赋值给as target
        print('cc')  # 退出


with closing(urlopen('https://www.python.org')) as page:
    for line in page:
        print(line)
