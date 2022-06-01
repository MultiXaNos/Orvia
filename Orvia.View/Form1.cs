using Orvia.Services;

namespace Orvia;

public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
        //NidsManager.Instance.AppendFromFile(Constants.XmlFile.NidsFilePath);
        foreach(var value in NidsManager.Instance.GetNidsNonConfig())
        {
            nidConfig_lb.Items.Add(value.Key);
        }
    }

    private void nidConfig_lb_SelectedIndexChanged(object sender, EventArgs e)
    {
        var selectedItem = nidConfig_lb.SelectedItem as string;
    }

    private void saveConfig_btn_Click(object sender, EventArgs e)
    {

    }


    private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }

    private void groupBox1_Enter(object sender, EventArgs e)
    {

    }
}