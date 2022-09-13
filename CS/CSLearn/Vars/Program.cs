using System;

namespace Vars
{
    internal class Program
    {
        private static int a = 20;

        public static void Main(string[] args)
        {
            float b;
            double c;
            const int d = 10;
            ref int e = ref a;

            int? f = null;
            Nullable<double> g = null;

            int h = Int32.MaxValue;
            try
            {
                checked
                {
                    h++;
                    Console.WriteLine(h);
                }
            }
            catch (OverflowException exp)
            {
                Console.WriteLine(exp);
            }

            var i = new Tuple<int>(2);
            var j = Tuple.Create(3);
            var (k, _) = (20, 40);

            var arr = new[] { 1, 2, 3, 4, 5 };
            var arr2 = new int[] { 1, 2, 3, 4, 5 };
            var arr3 = new int[5] { 1, 2, 3, 4, 5 };
            var arr4 = new int[5];
            var arr5 = new int[4, 2];
            
            Unsafe();
        }
        
        static unsafe void Unsafe()
        {
            var t = 1.2345;
            int a = 1;
            int b = 2;
            int* ap = &a;
            int* bp = &b;
            int c = *ap;
            *ap = *bp;
            *bp = c;
            
            Console.WriteLine(a);
            Console.WriteLine(b);
        }
        
    }
}