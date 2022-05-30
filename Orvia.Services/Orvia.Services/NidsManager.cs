using Orvia.Services.Core;
using System.Runtime.InteropServices;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;
using Timer = System.Timers.Timer;

namespace Orvia.Services;
[XmlRoot(ElementName = "NidsManager", Namespace = "")]
public sealed class NidsManager : IDisposable
{

    #region Fields

    private static NidsManager _instance;
    private static XDocument _document;
    private Timer _timer;

    #endregion Fields

    #region Properties

    public static NidsManager Instance
    {
        get
        {
            if(_instance == null)
            {
                _instance = new NidsManager();
            }

            return _instance;
        }
    }

    [XmlElement(ElementName  = "Nids", Namespace = "")]
    public Dictionary<string,Nid> Nids { get; private set; }

    #endregion Properties

    #region Constructor

    private NidsManager()
    {
        _timer = new Timer(100);
        _timer.Elapsed += Timer_Elapsed;

        Nids = new Dictionary<string,Nid>();
        MySqlServices.Instance.OpenCommunication();
        var test = MySqlServices.Instance.SendReadRequest("SELECT * FROM NID");
        for(int i = 0; i < test.FieldCount; i++)
        {
            Nids.Add($"Nid{i+1}", new Nid());
        }

        _timer.Start();
    }

    private void Timer_Elapsed(object? sender, System.Timers.ElapsedEventArgs e)
    {
        _timer.Stop();

        foreach(var value in Nids.Values.Where(x => x.IsConfigured))
        {
            value.getStatut();
            value.
        }

        _timer.Start();
    }

    #endregion Constructor

    #region Public Methods

    public void RegisterInFile(string name, Nid nid)
    {
        if(_document == null)
        {
            throw new Exception("Xml file has not been instianted");
        }

        _document?.Root?.Elements().Remove();

        var nidXml = new XElement(name,
                        new XElement("PortBalance", nid.PortBalance),
                        new XElement("PortRFID", nid.PortRFID),
                        new XElement("BaudRate", (int)nid.BaudRate)
                        );

        _document?.Root?.Add(nidXml);
        _document?.Save(Constants.XmlFile.NidsFilePath);
    }

    public List<KeyValuePair<string, Nid>> GetNidsNonConfig()
    {
        return Nids.Where(x => !x.Value.IsConfigured).ToList();
    }

    public void AppendFromFile(string filePath)
    {
        _document = XDocument.Load(filePath);

        foreach(var element in _document.Descendants("NidsManager").Descendants())
        {
            if (element.Name.ToString().Contains("Nid"))
            {
                string name = element.Name.ToString();
                string portBalance = element.Element("PortBalance")?.Value.ToString();
                string portRFID = element.Element("PortRFID")?.Value.ToString();
                BaudRate baudRate = BaudRate.NEUFMILLE;
                baudRate = (BaudRate)Enum.Parse(baudRate.GetType(), element.Element("BaudRate")?.Value);
                int nbDataBits = int.Parse(element.Element("NbDataBits")?.Value);
                Parity parity = Parity.NOPARITY;
                parity = (Parity)Enum.Parse(parity.GetType(), element.Element("Parity")?.Value);
                int nbStopBits = int.Parse(element.Element("NbStopBits")?.Value);
                string SNAntenne = element.Element("SNAntenne")?.Value.ToString();
                string SNBalance = element.Element("SNBalance")?.Value.ToString();
                double minPoidsOeuf = double.Parse(element.Element("MinPoidsOeuf")?.Value);
                double maxPoidsOeuf = double.Parse(element.Element("MaxPoidsOeuf")?.Value);
                double minPoidsPoule = double.Parse(element.Element("MinPoidsPoule")?.Value);
                double maxPoidsPoule = double.Parse(element.Element("MaxPoidsPoule")?.Value);

                Nids[name] = new Nid(portBalance,
                                       portRFID,
                                       baudRate,
                                       nbDataBits,
                                       parity,
                                       nbStopBits,
                                       SNAntenne,
                                       SNBalance,
                                       minPoidsOeuf,
                                       maxPoidsOeuf,
                                       minPoidsPoule,
                                       maxPoidsPoule);
                Nids[name].WakeUpThread();
            }
        }
    }

    #endregion Public Methods

    #region IDisposable

    public void Dispose()
    {
        foreach(var threadNid in NidsManager.Instance.Nids.Values.Where(x => x.IsConfigured))
        {
            threadNid.Dispose();
        }
    }

    #endregion IDisposable

}