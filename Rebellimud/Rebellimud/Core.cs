using System;
using System.Collections.Generic;
using System.Text;

namespace Rebellimud
{
    class Core
    {
        public static int Main(String[] args)
        {
            AsynchronousSocketListener.StartListening();
            return 0;
        }
    }
}
