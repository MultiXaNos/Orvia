using Orvia.Services;

namespace Orvia;

public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
        nidConfig_lb.Items.Add("Bonjour");
        NidsManager.Instance.AppendFromFile(Constants.XmlFile.NidsFilePath);
    }

    private void nidConfig_lb_SelectedIndexChanged(object sender, EventArgs e)
    {
        var selectedItem = nidConfig_lb.SelectedItem as string;
    }
}