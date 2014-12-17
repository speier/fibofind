using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            var sw = Stopwatch.StartNew();
            var res = Fibonacci().First(x => x.Digits == 2012);
            sw.Stop();

            Console.WriteLine("First Fibonacci term with 2012 digits: {0}th", res.Number);
            Console.WriteLine("Query took: {0} seconds ({1} ms)", sw.Elapsed.TotalSeconds, sw.ElapsedMilliseconds);
            Console.ReadKey();
        }

        public static IEnumerable<FibonacciTerm> Fibonacci()
        {
            int i = 1;
            BigInteger a = 0, b = 1;

            while (true)
            {
                var temp = a;
                a = b;
                b = temp + b;

                var l = Math.Floor(BigInteger.Log10(a) + 1);
                yield return new FibonacciTerm { Number = i++, Value = a, Digits = l };
            }
        }

        public class FibonacciTerm
        {
            public int Number { get; set; }
            public BigInteger Value { get; set; }
            public double Digits { get; set; }
        }
    }
}