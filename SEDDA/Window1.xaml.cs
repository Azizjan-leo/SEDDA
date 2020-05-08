using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace SEDDA
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public int CCount { get; set; } // Column count
        public int RCount { get; set; } // Row count
  
        private Button[,] Buttons;
        public Window1(int ccount, int rcount)
        {
            InitializeComponent();
            CCount = ccount-1;
            RCount = rcount-1;
            Buttons = new Button[CCount, RCount];
            DrawCanvas();
            this.Title = RCount.ToString();
            int verticalCenter = RCount / 2;
            int horizontalCenter = CCount / 2;
            Buttons[horizontalCenter, 0].Background = Brushes.Red;
            Buttons[0, verticalCenter/2].Background = Brushes.Orange;
            Buttons[0, verticalCenter + (verticalCenter / 2) - 1].Background = Brushes.Black;
            Buttons[CCount - 1, verticalCenter / 2].Background = Brushes.Green;
            Buttons[CCount - 1, verticalCenter + (verticalCenter / 2) - 1].Background = Brushes.Yellow;
            Buttons[horizontalCenter, CCount-1].Background = Brushes.Brown;

            int firsX = verticalCenter;
            int secondY = (verticalCenter - (verticalCenter / 2))-1;

            DrawSide(firsX, 0, 0, secondY);
            DrawSide(0, secondY, 0, (verticalCenter + (verticalCenter / 2)));
            DrawSide(0, (verticalCenter + (verticalCenter / 2)), firsX, 28);
        }



        private void DrawSide(int x1, int y1, int x2, int y2)
        {
            Buttons[x1, y1].Background = Brushes.Orange;
            Buttons[x2, y2].Background = Brushes.Orange;

            double deltaX = x2 - x1;
            double deltaY = y2 - y1;
            double D = 0;
            bool axeIsX = false;
            double yNExt = y1;
            double xNExt = x1;

            if(deltaX == 0)
            {
                while (yNExt != y2 + 1)
                {
                    if (deltaY > 0)
                    {
                        yNExt++;
                    }
                    else if (deltaY == 0)
                    {

                    }
                    else
                    {
                        yNExt--;
                    }

                    Buttons[Convert.ToInt32(x1), Convert.ToInt32(yNExt)].Background = Brushes.Orange;
                }
            }
            else if (deltaY == 0)
            {
                while (xNExt != x2 + 1)
                {
                    if (deltaX > 0)
                    {
                        xNExt++;
                    }
                    else if (deltaX == 0)
                    {

                    }
                    else
                    {
                        xNExt--;
                    }

                    Buttons[Convert.ToInt32(xNExt), Convert.ToInt32(y1)].Background = Brushes.Orange;
                }
            }
            else if (Math.Abs(deltaY) > Math.Abs(deltaX))
            {
                while (yNExt != y2 +1)
                {


                    D = Math.Abs(deltaX / deltaY);
                    
                    if (deltaY > 0)
                    {
                        yNExt++;
                    }
                    else if (deltaY == 0)
                    {

                    }
                    else
                    {
                        yNExt--;
                    }

                    xNExt += D;


                    Buttons[Convert.ToInt32(xNExt), Convert.ToInt32(yNExt)].Background = Brushes.Orange;
                }
            }
            else
            {
                while (xNExt != x2 +1)
                {
                    D = Math.Abs(deltaY / deltaX);

                    if (deltaX > 0)
                    {
                        xNExt++;
                    }
                    else if (deltaX == 0)
                    {
                    }
                    else
                    {
                        xNExt--;
                    }

                    yNExt += D;
                    int y = Convert.ToInt32(yNExt);
                    int x = Convert.ToInt32(xNExt);
                    Buttons[x, y].Background = Brushes.Orange;
                }
            }


            //while (xNExt != x2 || yNExt != y2)
            //{

            //    if (Math.Abs(deltaY) > Math.Abs(deltaX)) // Вдоль Y
            //    {
            //        D = Math.Abs(deltaY / deltaX);

            //        if (y1 < 0)
            //        {
            //            yNExt++;
            //        }
            //        else if (y1 == 0)
            //        {
            //        }
            //        else
            //        {
            //            yNExt--;
            //        }

            //        xNExt += D;


            //        Buttons[Convert.ToInt32(xNExt), Convert.ToInt32(yNExt)].Background = Brushes.Orange;
            //    }
            //    else // Вдоль Х
            //    {
            //        D = Math.Abs(deltaY / deltaX);

            //        if (x1 < 0)
            //        {
            //            xNExt++;
            //        }
            //        else if (x1 == 0)
            //        {
            //        }
            //        else
            //        {
            //            xNExt--;
            //        }

            //        yNExt += D;

            //        Buttons[Convert.ToInt32(xNExt), Convert.ToInt32(yNExt)].Background = Brushes.Orange;

            //    }
            //}




        }

        private void DrawCanvas()
        {
            for (int j = 0; j < RCount - 1; j++)
            {
                var row = new RowDefinition { Name = $"r{j}", Height = new GridLength(20) };
                myGrid.RowDefinitions.Add(row);
            }

            for (int i = 0; i < CCount; i++)
            {
                myGrid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(20) });
                for (int j = 0; j < RCount; j++)
                {
                    Button btn = new Button { Name = $"x{i}y{j}" };
                    myGrid.Children.Add(btn);

                    Grid.SetColumn(btn, i);
                    Grid.SetRow(btn, j);
                    Buttons[i, j] = btn;
                }
            }

        }

      
        public static T FindChild<T>(DependencyObject parent, string childName) where T : DependencyObject
        {
            // Confirm parent and childName are valid. 
            if (parent == null) return null;
            T foundChild = null;
            int childrenCount = VisualTreeHelper.GetChildrenCount(parent);
            for (int i = 0; i < childrenCount; i++)
            {
                var child = VisualTreeHelper.GetChild(parent, i);
                // If the child is not of the request child type child
                T childType = child as T;
                if (childType == null)
                {
                    // recursively drill down the tree
                    foundChild = FindChild<T>(child, childName);
                    // If the child is found, break so we do not overwrite the found child. 
                    if (foundChild != null) break;
                }
                else if (!string.IsNullOrEmpty(childName))
                {
                    var frameworkElement = child as FrameworkElement;
                    // If the child's name is set for search
                    if (frameworkElement != null && frameworkElement.Name == childName)
                    {
                        // if the child's name is of the request name
                        foundChild = (T)child;
                        break;
                    }
                }
                else
                {
                    // child element found.
                    foundChild = (T)child;
                    break;
                }
            }
            return foundChild;
        }
    }
}
