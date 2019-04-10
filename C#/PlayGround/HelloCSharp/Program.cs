using System;
using System.IO;

namespace HelloCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var stream = File.Create(@"D:\learn\C#\PlayGround\Hello.txt");
            var writer = new StreamWriter(stream);
            writer.WriteLine("Hello c# world!");
            writer.Flush();
            writer.Close();

            Console.WriteLine("Done!");
        }
    }
}
