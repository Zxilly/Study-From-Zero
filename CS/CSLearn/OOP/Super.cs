using System;

namespace OOP
{
    public class Super
    {
        public Super()
        {
            Console.WriteLine("Super");
        }

        public Super(int i)
        {
            Console.WriteLine("Super " + i.ToString());
        }
    }

    public class Child : Super
    {
        public Child()
        {
            Console.WriteLine("Child");
        }

        public Child(int i) : base(i + 1)
        {
        }
    }
}