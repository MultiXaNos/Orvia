using Orvia.Services;

namespace Orvia.Console // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var instance = NidsManager.CreatePeriphRFID("COM1", 9600, 8,
                1, 1, string.Empty,
                0, "C:\\Users\\proje\\Desktop", "Tag");
            
        }
    }
}