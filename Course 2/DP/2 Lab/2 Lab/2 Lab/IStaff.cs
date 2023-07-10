using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public interface IStaff
    {
        List<JobVacancy> getJobVacancies();
        List<Employee> getEmployees();
        List<JobTitle> GetJobTitles();
        int addJobTitle(JobTitle title);
        string printJobVacancies();
        bool delJobTitle(int id);
        void openJobVacancy(int id);
        bool closeJobVacancy(int jobId);
        Employee recruit(JobVacancy job, Person per);
        bool dismiss(int id, Reason res);
    }
}
