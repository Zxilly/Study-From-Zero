using System;
using System.Diagnostics;

namespace MainFunc
{
    internal class Program
    {
        public static int Main(string[] args)
        {
            var envArgs = Environment.GetCommandLineArgs();

            Debug.Assert(args.Length == envArgs.Length - 1);

            for (int i = 0; i < args.Length - 1; i++)
            {
                Debug.Assert(args[i] == envArgs[i + 1]);
            }

            return 0;
        }
    }
}