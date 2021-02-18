class test:

    def __init__(self, ta, tb):
        self.__ta = ta
        self.__tb = tb

    @property
    def ta(self):
        return self.__ta

    @ta.setter
    def ta(self, value):
        self.__ta = value

    @property
    def tb(self):
        return self.__tb

    @tb.setter
    def tb(self, value):
        self.__tb = value

    @property
    def tc(self):
        return self.ta * self.tb


if __name__ == '__main__':
    a = test(20, 60)

    print(a.tc)
    a.ta = 60

    print(a.tc)
