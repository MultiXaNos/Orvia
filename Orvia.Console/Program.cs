using Orvia.Services;
using Orvia.Services.Core;
using System.Text;
using System.Windows.Input;

namespace Orvia.Console // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            NidsManager.Instance.AppendFromFile(Constants.XmlFile.NidsFilePath);
        }
    }
}