from typing import Callable


def funcA(func: Callable):
    def wrapper(c: float = 0.33, *args, **kwargs):
        print(f"c = {c}")
        print(kwargs)
        return func(*args, **kwargs)

    return wrapper


@funcA
def test(a: str = 'abc', b: int = 5):
    print(f"a = {a}")
    print(f"b = {b}")


test('bbb', 6, 3.1)
