using Orvia.Services.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Orvia.Services
{
    public class Nid : IDisposable
    {

        #region Fields

        private IntPtr _threadInstance = IntPtr.Zero;
        private string _port = string.Empty;
        private BaudRate _baud;
        private int _nbDataBits;
        private Parity _parity;
        private int _nbStopBits;

        #endregion Fields

        #region Properties

        public string Port
        {
            get
            {
                return _port;
            }
            set
            {
                if(_port != value)
                {
                    if(Regex.IsMatch(value, "^COM[0 - 9][0 - 9]$"))
                    {
                        _port = value;
                    }
                }
            }
        }

        public BaudRate BaudRate
        {
            get
            {
                return _baud;
            }
            set 
            {
                if(_baud != value)
                {
                    _baud = value;
                }
            }
        }

        public int NbDataBits
        {
            get
            {
                return _nbDataBits;
            }
            set
            {
                if(_nbDataBits != value)
                {
                    _nbDataBits = value;
                }
            }
        }

        public Parity Parity
        {
            get
            {
                return _parity;
            }
            set
            {
                if(_parity != value)
                {
                    _parity = value;
                }
            }
        }

        public int NbStopBits
        {
            get
            {
                return _nbStopBits;
            }
            set
            {
                if(_nbStopBits != value)
                {
                    _nbStopBits = value;
                }
            }
        }

        #endregion Properties

        #region Constructor

        public Nid()
        { }

        #endregion Constructor

        #region DllImport

        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateThread(string port,
                                                 int baud,
                                                 int nbDataBits,
                                                 int parity,
                                                 int nbStopBits,
                                                 string SNAntenne,
                                                 string SNBalance,
                                                 double minPoidsOeuf,
                                                 double maxPoidsOeuf,
                                                 double minPoidsPoule,
                                                 double maxPoidsPoule,
                                                 int debug,
                                                 string pathDebugFile);

        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void KillThread(IntPtr thread);

        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int WakeUpThread(IntPtr thread);

        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int getStatut(IntPtr thread);
        
        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern char[] getError(IntPtr thread);

        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int getNbOeuf(IntPtr thread);

        [DllImport(Constants.DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int getPontes(IntPtr thread);


        #endregion DllImport

        #region Public Methods

        public IntPtr Create(string port,
                             int baud,
                             int nbDataBits,
                             int parity,
                             int nbStopBits,
                             string SNAntenne,
                             string SNBalance,
                             double minPoidsOeuf,
                             double maxPoidsOeuf,
                             double minPoidsPoule,
                             double maxPoidsPoule,
                             int debug,
                             string pathDebugFile)
        {
            _threadInstance = CreateThread(port, baud, nbDataBits, parity, nbStopBits, SNAntenne, SNBalance, minPoidsOeuf, maxPoidsOeuf, minPoidsPoule, maxPoidsPoule, debug, pathDebugFile);
            return _threadInstance;
        }
        public void KillThread()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            KillThread(_threadInstance);
        }

        public int WakeUpThread()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            return WakeUpThread(_threadInstance);
        }
        public int getStatut()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            return getStatut(_threadInstance);
        }

        public char[] getError()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            return getError(_threadInstance);
        }

        public int getNbOeuf()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            return getNbOeuf(_threadInstance);
        }

        public int getPontes()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            return getPontes(_threadInstance);
        }


        #endregion Public Methods

        #region IDisposable

        public void Dispose()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            KillThread();
        }

        #endregion IDisposable
    }
}
