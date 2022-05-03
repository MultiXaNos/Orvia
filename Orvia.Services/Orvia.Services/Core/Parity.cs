using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Orvia.Services.Core
{
    public enum Parity
    {
        NOPARITY = 0,
        PARITY_ODD = 0x200,
        PARITY_EVEN = 0x400
    }
}
