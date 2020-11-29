using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;

namespace A
{
    internal static class Program
    {
        public static void Main(string[] args)
        {
            Repeat(i =>
            {
                var nx = ReadInts();
                var n = nx[0];
                var x = nx[1];
                var lvl = 1;
                n -= 2;
                while (n > 0)
                {
                    n -= x;
                    lvl++;
                }
                Output(lvl);
            });
        }
        
        // Kotlin-like features
        private static string _buffer = "";
        private static string ReadLn() => Console.ReadLine();
        private static void PrintLn(object v) => Console.WriteLine(v);
        private static void PrintLn(IEnumerable<object> v, string separator = " ") => Console.WriteLine(string.Join(separator, v));
        private static void PrintLn(params object[] objects) => Console.WriteLine(string.Join(" ", objects));
        private static void Output(object print) => _buffer += print + "\n";
        private static void Drop() => Console.WriteLine(_buffer);
        private static short ReadShort() => Convert.ToInt16(ReadLn());
        private static int ReadInt() => Convert.ToInt32(ReadLn());
        private static long ReadLong() => Convert.ToInt64(ReadLn());
        private static List<short> ReadShorts() => ReadLn().Split(' ').Select(e => Convert.ToInt16(e)).ToList();
        private static List<int> ReadInts() => ReadLn().Split(' ').Select(e => Convert.ToInt32(e)).ToList();
        private static List<long> ReadLongs() => ReadLn().Split(' ').Select(e => Convert.ToInt64(e)).ToList();
        private static void Repeat(Action<int> action)
        {
            var t = ReadInt();
            for (int i = 0; i < t; i++) action.Invoke(i);
            Drop();
        }
    }
}