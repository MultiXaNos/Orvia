using Orvia.Services;
using Orvia.Services.Core;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Input;
using Timer = System.Timers.Timer;


namespace Orvia.Console // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        private static CancellationTokenSource _tokenSource = new CancellationTokenSource();
        private static CancellationToken _cancellationToken = _tokenSource.Token;
        private static bool _disposed = false;

        static void Main(string[] args)
        {
            System.Console.CancelKeyPress += Console_CancelKeyPress;
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;
            AppDomain.CurrentDomain.ProcessExit += CurrentDomain_ProcessExit;

            try
            {
                NidsManager.Instance.AppendFromFile(Constants.XmlFile.NidsFilePath, ref _cancellationToken);
            }
            catch(Exception ex)
            {
                System.Console.WriteLine(ex.Message);
                if(!_cancellationToken.IsCancellationRequested)
                {
                    _tokenSource.Cancel();
                }
            }

            while(!_cancellationToken.IsCancellationRequested)
            {
                System.Console.WriteLine("Appuyez sur D pour désactiver ou A pour activer le nid : ");

                var key = System.Console.ReadKey().Key;

                switch(key)
                {
                    case ConsoleKey.D:
                        DesactivateThread();
                        break;
                    case ConsoleKey.A:
                        ActivateThread();
                        break;
                }

                System.Console.Clear();
            }
        }

        private static void CurrentDomain_ProcessExit(object? sender, EventArgs e)
        {
            if (!_disposed)
            {
                ExitApplication();
            }
        }

        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            ExitApplication();
        }

        private static void Console_CancelKeyPress(object? sender, ConsoleCancelEventArgs e)
        {
            ExitApplication();
        }

        private static void ExitApplication()
        {
            _tokenSource.Cancel();
            _disposed = true;
            Environment.Exit(0);
        }

        private static void ActivateThread()
        {
            string? nidString = null;

            while (!CheckNidName(nidString))
            {
                System.Console.Clear();
                System.Console.WriteLine("Nids disponibles : ");

                if (NidsManager.Instance.Nids.Where(x => x.Value.IsConfigured && x.Value.Status == Status.SOMMEIL).Count() > 0)
                {
                    foreach (var nid in NidsManager.Instance.Nids.Where(x => x.Value.IsConfigured && x.Value.Status == Status.SOMMEIL))
                    {
                        System.Console.WriteLine(nid.Key);
                    }

                    System.Console.WriteLine("Nid à activer : ");

                    nidString = System.Console.ReadLine();

                    if (CheckNidName(nidString) && NidsManager.Instance.Nids.ContainsKey(nidString))
                    {
                        NidsManager.Instance.Nids[nidString].WakeUpThread();
                    }
                }
                else
                {
                    System.Console.WriteLine("Aucun nid à activer");
                    Thread.Sleep(1000);
                    return;
                }
            }
        }

        private static void DesactivateThread()
        {
            string? nidString = null;

            while (!CheckNidName(nidString))
            {
                System.Console.Clear();
                System.Console.WriteLine("Nids disponibles : ");

                if (NidsManager.Instance.Nids.Where(x => x.Value.IsConfigured && x.Value.Status == Status.MARCHE).Count() > 0)
                {
                    foreach (var nid in NidsManager.Instance.Nids.Where(x => x.Value.IsConfigured && x.Value.Status == Status.MARCHE))
                    {
                        System.Console.WriteLine(nid.Key);
                        System.Console.WriteLine("Nid à désactiver : ");

                        nidString = System.Console.ReadLine();

                        if (CheckNidName(nidString) && NidsManager.Instance.Nids.ContainsKey(nidString))
                        {
                            NidsManager.Instance.Nids[nidString].KillThread();
                        }
                    }
                }
                else
                {
                    System.Console.WriteLine("Aucun nid à désactiver");
                    return;
                }
            }
        }

        private static bool CheckNidName(string? nidName)
        {
            return nidName !=null && nidName.Contains("Nid");
        }
    }
}