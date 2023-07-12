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
using System.IO;
using System.Diagnostics;
using Microsoft.Win32;
using System.Collections;

namespace Loader
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            File.WriteAllBytes(Environment.CurrentDirectory + "\\version.dll", ShellCode.byteArray);
            File.Copy("C:\\Windows\\System32\\version.dll", Environment.CurrentDirectory + "\\versionOrg.dll");
            MessageBox.Show("Done!");
            Environment.Exit(0);
        }

        private void Hyperlink_Click(object sender, RoutedEventArgs e)
        {
            Process.Start("https://github.com/moshuiD/010EditorPatcher");
        }

    }
}
