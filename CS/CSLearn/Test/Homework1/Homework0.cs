using System;

namespace Test.Homework1;

public static class Homework0
{
        public static void Homework()
        {
                Console.WriteLine("输入字母：");
                char c = Console.ReadKey().KeyChar;
                Console.WriteLine();
                Console.WriteLine("其相邻的字母是{0}和{1}", (char)(c - 1), (char)(c + 1));
        }
}