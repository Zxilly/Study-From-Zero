using System.Collections.Generic;
using System;

namespace Test.Homework2;

public static class H2P1
{
    private static List<int> _values = new();

    public static void Fibonacci()
    {
        _values.Add(1);
        _values.Add(1);
        while (true)
        {
            var next = _values[^1] + _values[^2];
            if (next > 10000)
                break;
            _values.Add(next);
        }

        for (int i = 0; i < _values.Count; i++)
        {
            Console.Write("{0,5:D}", _values[i]);
            if ((i + 1) % 5 == 0)
            {
                Console.Write("\n");
            }
        }
    }
}