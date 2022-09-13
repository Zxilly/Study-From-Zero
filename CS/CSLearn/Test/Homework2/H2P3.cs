namespace Test.Homework2;

using System;

public class H2P3
{
    private static int[] _primes = new int[105];

    private static void GeneratePrimes()
    {
        for (int i = 2; i < 105; i++)
        {
            if (_primes[i] == 0)
            {
                for (int j = i + i; j < 105; j += i)
                {
                    _primes[j] = 1;
                }
            }
        }
    }

    private static bool IsPrime(int n)
    {
        if (n < 2)
        {
            return false;
        }

        return _primes[n] == 0;
    }

    public static void TestMain()
    {
        GeneratePrimes();

        var random = new Random();
        int[] a = new int[100];

        for (int i = 0; i < 100; i++)
        {
            a[i] = random.Next(0, 101);
        }

        for (int i = 0; i < 100; i++)
        {
            Console.Write("{0,2} ", a[i]);
            if ((i + 1) % 10 == 0)
            {
                Console.WriteLine();
            }
        }

        Console.WriteLine();

        int primeCount = 0;
        for (int i = 0; i < 100; i++)
        {
            if (IsPrime(a[i]))
            {
                Console.Write("{0,2} ", a[i]);
                primeCount++;
                if (primeCount % 5 == 0)
                {
                    Console.WriteLine();
                }
            }
        }

        if (primeCount == 0)
        {
            Console.WriteLine("无素数");
        }
    }
}