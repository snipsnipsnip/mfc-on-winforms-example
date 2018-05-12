using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Host
{
    public class GuestControl : Control
    {
        /// <summary>Attached CWnd* from MFC</summary>
        private IntPtr CWnd { get; set; }

        [DllImport("guest")]
        private static extern IntPtr attach(IntPtr hwnd);
        [DllImport("guest")]
        private static extern void detach(IntPtr hwnd);

        public void Init()
        {
            if (CWnd == IntPtr.Zero)
            {
                CWnd = attach(Handle);
            }
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (CWnd != IntPtr.Zero)
                {
                    detach(CWnd);
                    CWnd = IntPtr.Zero;
                }
            }

            base.Dispose(disposing);
        }
    }
}
