using System;
using System.Drawing;
using System.Windows.Forms;
//using DisplayFusionAPI;

public static class DisplayFusionFunction
{
    public static void Run(IntPtr windowHandle)
    {
        // Получить список всех окон
//        IntPtr[] allWindows = BFS.Window.BFS.GetAllWindows();
		IntPtr[] allWindows = BFS.Window.GetAllWindowHandles();
        foreach (IntPtr window in allWindows)
        {
            // Пропустить невидимые и свернутые окна
            if (!BFS.Window.IsVisible(window) || BFS.Window.IsMinimized(window))
                continue;

            // Получить монитор, на котором находится окно
            uint monitorID = BFS.Monitor.GetMonitorIDByWindow(window);

            // Переместить окна с монитора 1 на монитор 2
            if (monitorID == 1)
            {
                BFS.Window.MoveToMonitor(2, window);
            }
            // Переместить окна с монитора 2 на монитор 1
            else if (monitorID == 2)
            {
                BFS.Window.MoveToMonitor(1, window);
            }
        }
    }
}
