using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public class Person
    {
        public string? name;
        public int age;
    }

    public class Reason
    {
        public string? reason;
    }

    public class Employee : Person
    {
        public int work_experience;
    }
}


