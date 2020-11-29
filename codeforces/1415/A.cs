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
                var nmrc = ReadInts();
                var n = nmrc[0];
                var m = nmrc[1];
                var r = nmrc[2];
                var c = nmrc[3];
                int max = 0;
                int[][] angles = { new int[] { 1, 1}, new int[] { 1, n }, new int[] { m, 1 }, new int[] {m , n} };
                foreach (var t in angles)
                {
                    var dist = Math.Abs(t[0] - c) + Math.Abs(t[1] - r);
                    if (dist > max) max = dist;
                }
                Output(max);
            });
        }
        
        // Kotlin-like features
        private static string _buffer = "";

        private static void Destructive(out object p1, out object p2, List<object> arr)
        {
            p1 = arr[0];
            p2 = arr[1];
        }
        
        private static void Destructive(out object p1, out object p2, out object p3, List<object> arr)
        {
            p1 = arr[0];
            p2 = arr[1];
            p3 = arr[2];
        }
        
        private static void Destructive(out object p1, out object p2, out object p3, out object p4, List<object> arr)
        {
            p1 = arr[0];
            p2 = arr[1];
            p3 = arr[2];
            p4 = arr[3];
        }
        
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