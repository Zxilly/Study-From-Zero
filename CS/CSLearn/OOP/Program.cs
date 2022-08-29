using System;

namespace OOP
{
    internal class Program
    {
        public static void Main(string[] args)
        {
        }

        public void swap(ref int a, ref int b)
        {
            var c = a;
            (b, a) = (a, b);

            int Temp(int ac)
            {
                return c + ++ac;
            }
            var d = Temp(1);
        }
    }

    class Easy
    {
        public int add2(int a, int b) => a + b;

        public static string ss;
        
        public string s
        {
            get;
            set;
        }

        public string this[int i]
        {
            get
            {
                return i.ToString();
            }
            set
            {
                Console.WriteLine(value.ToString());
            }
        }
        
        public static int operator +(Easy a, Easy b)
        {
            Console.WriteLine(a.s);
            Console.WriteLine(b.s);
            return 2;
        } 
        
        public static implicit operator int(Easy a)
        {
            return 1;
        }
        
        public static explicit operator string(Easy a)
        {
            return "1";
        }

        static Easy()
        {
            ss = "1";
        }
        
        public Easy()
        {
            s = "1";
        }
        
        ~Easy()
        {
            Console.WriteLine("wtf gc lang have destructor");
        }
    }
}