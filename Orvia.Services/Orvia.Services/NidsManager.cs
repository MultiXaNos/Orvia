using System.Runtime.InteropServices;

namespace Orvia.Services;

public class NidsManager
{

    #region Fields



    #endregion Fields

    #region Properties

    public Dictionary<string,Nid> Nids { get; set; }

    #endregion Properties

    #region Constructor

    public NidsManager()
    {
        Nids = new Dictionary<string,Nid>();
    }

    #endregion Constructor

    #region Public Methods


    #endregion Public Methods


}