using System;

namespace Statements;

internal class Program
{
    public static void Main(string[] args)
    {
        // using 上下文管理器
        // yield 提供
        // goto label

        // null safe
        int? a = null;
        var b = a ?? 20;

        string[] names = { "Tom", "Dick", "Harry" };
        var first = names?[0];

        object integer = 32;

        if (integer is int)
        {
            Console.WriteLine("is int");
        }

        switch (integer)
        {
            case int i when i==0:
                Console.WriteLine("is int and =0");
                break;
            case int o:
                Console.WriteLine("is int");
                break;
        }
    }
}