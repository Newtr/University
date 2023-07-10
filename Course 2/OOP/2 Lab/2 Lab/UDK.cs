using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public class UDK
    {
        [Range(1,1000, ErrorMessage = "Error")]
        public int ID { get; set; }
        [UDCAttribute(ErrorMessage = "UDC is not correct!")]
        public string UDC { get; set; }
    }
}
