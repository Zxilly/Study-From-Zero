using System;

namespace Test.Homework1;

public static class Homework2
{
    public static void Four()
    {
        double total = 0;
        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine("第{0}件商品销售数量和单价：", i + 1);
            int count = int.Parse(Console.ReadLine()!);
            double price = double.Parse(Console.ReadLine()!);
            total += count * price;
        }

        Console.WriteLine("销售总金额是：￥{0:N2}", total);
    }
}