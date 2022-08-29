using AliasNS = System;
using AliasClass = System.Console;
using System;


namespace Namespace
{
    /// <summary>Test Namespace</summary>
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Console.WriteLine("Hello World!");
            AliasClass.WriteLine("Hello World!");
            AliasNS::Console.WriteLine("Hello World!");
            ShadowTest();
        }
        
        static void ShadowTest()
        {
            int Console = 0;
            global::System.Console.WriteLine(Console);
        }
    }
}