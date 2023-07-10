using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public class JobVacancy
    {
        public string? Vacancy_name;

        public JobVacancy(JobTitle title)
        {
            Vacancy_name = title.Title;
        }

        public string? who;

        public JobVacancy() { }

        public bool openVacancy = false;
    }

    public class JobTitle
    {
        public string? Title { get; set; }
    }
}
