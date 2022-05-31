using Orvia.Services.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Orvia.Services
{
    [XmlRoot(ElementName = "Nid", Namespace = "")]
    public class Nid : IDisposable
    {

        #region Fields

        private IntPtr _threadInstance = IntPtr.Zero;
        private string _portBalance = string.Empty;
        private string _portRFID = string.Empty;
        private BaudRate _baud;
        private int _nbDataBits;
        private Parity _parity;
        private int _nbStopBits;
        private string _SNAntenne = string.Empty;
        private string _SNBalance = string.Empty;
        private double _minPoidsOeuf;
        private double _maxPoidsOeuf;
        private double _minPoidsPoule;
        private double _maxPoidsPoule;
        private int _debug;
        private string _pathDebugFile;
        private bool _isConfigured = false;
        private Status _status;
        private int _nbOeufs;

        #endregion Fields

        #region Properties

        [XmlElement(ElementName = "PortBalance")]
        public string PortBalance
        {
            get
            {
                return _portBalance;
            }
            set
            {
                if(_portBalance != value)
                {
                    _portBalance = value;
                }
            }
        }

        [XmlElement(ElementName = "PortRFID")]
        public string PortRFID
        {
            get
            {
                return _portRFID;
            }
            set
            {
                if (_portRFID != value)
                {
                    _portRFID = value;
                }
            }
        }

        [XmlElement(ElementName = "BaudRate")]
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

        [XmlElement(ElementName = "NbDataBits")]
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

        [XmlElement(ElementName = "Parity")]
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

        [XmlElement(ElementName = "NbStopBits")]
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

        [XmlElement(ElementName = "SNAntenne")]
        public string SNAntenne
        {
            get
            {
                return _SNAntenne;
            }
            set
            {
                if(_SNAntenne != value)
                {
                    _SNAntenne = value;
                }
            }
        }

        [XmlElement(ElementName = "SNBalance")]
        public string SNBalance
        {
            get
            {
                return _SNBalance;
            }
            set
            {
                if(_SNBalance != value)
                {
                    _SNBalance = value;
                }
            }
        }

        [XmlElement(ElementName = "MinPoidsOeuf")]
        public double MinPoidsOeuf
        {
            get
            {
                return _minPoidsOeuf;
            }
            set
            {
                if(_minPoidsOeuf != value)
                {
                    _minPoidsOeuf = value;
                }
            }
        }

        [XmlElement(ElementName = "MaxPoidsOeuf")]
        public double MaxPoidsOeuf
        {
            get
            {
                return _maxPoidsOeuf;
            }
            set
            {
                if (_maxPoidsOeuf != value)
                {
                    _maxPoidsOeuf = value;
                }
            }
        }

        [XmlElement(ElementName = "MinPoidsPoule")]
        public double MinPoidsPoule
        {
            get
            {
                return _minPoidsPoule;
            }
            set
            {
                if (_minPoidsPoule != value)
                {
                    _minPoidsPoule = value;
                }
            }
        }

        [XmlElement(ElementName = "MaxPoidsPoule")]
        public double MaxPoidsPoule
        {
            get
            {
                return _maxPoidsPoule;
            }
            set
            {
                if (_maxPoidsPoule != value)
                {
                    _maxPoidsPoule = value;
                }
            }
        }

        public bool IsConfigured
        {
            get { return _isConfigured; }
            set
            {
                if(_isConfigured != value)
                {
                    _isConfigured = value;
                }
            }
        }

        public Status Status
        {
            get 
            {
                getStatut();
                return _status; 
            }
            set
            {
                if(_status != value)
                {
                    _status = value;
                }
            }
        }

        public int NbOeufs
        {
            get { return _nbOeufs; }
            set
            {
                if(_nbOeufs != value)
                {
                    _nbOeufs = value;
                }
            }
        }

        #endregion Properties

        #region Constructor

        public Nid(string portBalance,
                   string portRFID,
                   BaudRate baud,
                   int nbDataBits,
                   Parity parity,
                   int nbStopBits,
                   string SNAntenne,
                   string SNBalance,
                   double minPoidsOeuf,
                   double maxPoidsOeuf,
                   double minPoidsPoule,
                   double maxPoidsPoule,
                   int debug = 1,
                   string pathDebugFile = @"C:\Users\maxen\Desktop\Logs.txt")
        {
            PortBalance = portBalance;
            PortRFID = portRFID;
            BaudRate = baud;
            NbDataBits = nbDataBits;
            Parity = parity;
            NbStopBits = nbStopBits;
            this.SNAntenne = SNAntenne;
            this.SNBalance = SNBalance;
            MinPoidsOeuf = minPoidsOeuf;
            MaxPoidsOeuf = maxPoidsOeuf;
            MinPoidsPoule = minPoidsPoule;
            MaxPoidsPoule = maxPoidsPoule;
            _debug = debug;
            _pathDebugFile = pathDebugFile;
            _isConfigured = true;
            CreateThread();
        }

        public Nid()
        { }

        #endregion Constructor

        #region DllImport

        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.CreateThreadEntryPoint)]
        public static extern IntPtr CreateThread([In, MarshalAs(UnmanagedType.LPStr)] string portBalance,
                                                 [In, MarshalAs(UnmanagedType.LPStr)] string portRFID,
                                                 int baud,
                                                 int nbDataBits,
                                                 int parity,
                                                 int nbStopBits,
                                                 [In, MarshalAs(UnmanagedType.LPStr)] string SNAntenne,
                                                 [In, MarshalAs(UnmanagedType.LPStr)] string SNBalance,
                                                 double minPoidsOeuf,
                                                 double maxPoidsOeuf,
                                                 double minPoidsPoule,
                                                 double maxPoidsPoule,
                                                 int debug,
                                                 [In, MarshalAs(UnmanagedType.LPStr)] string pathDebugFile);

        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.KillThreadEntryPoint)]
        public static extern void KillThread(IntPtr thread);

        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.WakeUpThreadEntryPoint)]
        public static extern int WakeUpThread(IntPtr thread);

        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.GetStatutEntryPoint)]
        public static extern int getStatut(IntPtr thread);
        
        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.GetErrorEntryPoint)]
        public static extern char[] getError(IntPtr thread);

        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.GetNbOeufEntryPoint)]
        public static extern int getNbOeuf(IntPtr thread);

        [DllImport(Constants.DLL.DllPath, CallingConvention = CallingConvention.Cdecl, EntryPoint = Constants.DLL.GetPontesEntryPoint)]
        public static extern int getPontes(IntPtr thread, ref string[] pontes);


        #endregion DllImport

        #region Public Methods 

        public void CreateThread()
        {
            _threadInstance = CreateThread(_portBalance, _portRFID, (int)_baud, _nbDataBits, (int)_parity, _nbStopBits, _SNAntenne, _SNBalance, _minPoidsOeuf, _maxPoidsOeuf, _minPoidsPoule, _maxPoidsPoule, _debug, _pathDebugFile);
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
        public void getStatut()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            _status = (Status)getStatut(_threadInstance);
        }

        public char[] getError()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            return getError(_threadInstance);
        }

        public void getNbOeuf()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            _nbOeufs = getNbOeuf(_threadInstance);
        }

        public int getPontes()
        {
            if (_threadInstance == IntPtr.Zero)
                throw new ArgumentNullException("Thread instance does not exists");

            string[] pontes = new string[100];

            var ret = getPontes(_threadInstance, ref pontes);

            return ret;
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
