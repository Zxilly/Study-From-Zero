class Chain(object):

    def __init__(self, path=''):
        self._path = path

    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))
        # return Chain(f'{self._path}/{path}')

    def __str__(self):
        return self._path

    __repr__ = __str__

    # def __call__(self, *args, **kwargs):
    #     self.__str__()

    __call__ = __str__


if __name__ == '__main__':
    print(Chain().test.notabc.locale())


