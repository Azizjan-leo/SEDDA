using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SEDDA
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var ccount = 600 / 20;
            var rcount = 600 / 20;

            Window1 objWelcome = new Window1(ccount, rcount)
            {
                Height = 600,
                Width = 600
            };
            this.Visibility = Visibility.Hidden;
            objWelcome.Show(); //Sending value from one form to another form.
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var ccount = Convert.ToInt32(Convert.ToInt32(Y.Text) / 20);
            var rcount = Convert.ToInt32(Convert.ToInt32(X.Text) / 20);
            Window1 objWelcome = new Window1(ccount, rcount)
            {
                Height = Double.Parse(X.Text),
                Width = Double.Parse(Y.Text)
            };
            objWelcome.Show(); //Sending value from one form to another form.
        }
    }
}
