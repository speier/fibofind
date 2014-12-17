using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;

public class FiboFind
{
    public static void Main()
    {
        var digits = DateTime.Now.Year;

        var sw = Stopwatch.StartNew();
        var res = Fibonacci().First(x => x.Digits == digits);
        sw.Stop();

        Console.WriteLine("First Fibonacci term with {0} digits is the {1}th", digits, res.Number);
        Console.WriteLine("Found in: {0} ms", sw.ElapsedMilliseconds);
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
