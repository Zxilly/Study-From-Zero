using System;

namespace Test.Homework1;

public static class Homework1
{
    public static void Three()
    {
        Console.WriteLine("输入第一个矩形的长和宽：");
        var tALength = double.Parse(Console.ReadLine()!);
        var tAWidth = double.Parse(Console.ReadLine()!);
        Console.WriteLine("输入第二个矩形的长和宽：");
        var tBLength = double.Parse(Console.ReadLine()!);
        var tBWidth = double.Parse(Console.ReadLine()!);

        Console.WriteLine("第一个矩形的面积是：{0,10:F2} 周长是：{1,-8:F1}", tALength * tAWidth, (tALength + tAWidth) * 2);
        Console.WriteLine("第二个矩形的面积是：{0,10:F2} 周长是：{1,-8:F1}", tBLength * tBWidth, (tBLength + tBWidth) * 2);

        char judge = (tALength * tAWidth) > (tBLength * tBWidth) ? '大' : '小';
        Console.WriteLine("第一个矩形比第二个矩形面积{0}", judge);
    }
}