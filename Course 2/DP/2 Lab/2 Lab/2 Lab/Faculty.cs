using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public class Faculty : Organization, IDisposable, IStaff
    {
        public string? name;
        public void Dispose() { }

        protected List<Department> departments= new List<Department>();

        public Faculty() { }

        public Faculty(Faculty fac)
        {
            fac.name = name;
            fac.departments = departments;
        }

        public Faculty(string name, string shortname, string address) : base(name,shortname,address)
        {
            this.name = name;
            this.address = address;
            timeStamp = DateTime.Now;
        }

        public int addDepartment(Department department) 
        {
            departments.Add(department);
            Console.WriteLine($"Был добавлен новый факультет {department.name_of_department}");
            return departments.Count;
        }
        public bool delDepartment(int id)
        {
            Department dep1 = new();
            dep1 = departments.ElementAt(id);
            Console.WriteLine($"Был удален факультет: {dep1.name_of_department}");
            departments.RemoveAt(id);
            return true;
        }

        public bool updDepartment(Department department)
        {
            foreach (var item in departments)
            {
                if (item.Equals(department))
                {
                    Console.WriteLine($"Факультет {item.name_of_department} изменен");
                    item.name_of_department = "Новый департмент";
                    return true;
                }
                else
                {
                    return false;
                }    
            }
            return true;
        }

        private bool verDepartment(int id)
        {
            Department dep = new();
            dep = departments.ElementAt(id);
            if (dep != null)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public List<Department> GetDepartments() 
        {
            return departments;
        }
        public override void printfinfo()
        {
            Console.WriteLine($"ID = {id}");
            Console.WriteLine($"NAME = {name}");
            Console.WriteLine($"SHORTNAME = {shortname}");
            Console.WriteLine($"ADDRESS = {address}");
            Console.WriteLine($"TIMESTAMP = {timeStamp}");
            Console.WriteLine($"POKA");
        }

        public List<JobVacancy> getJobVacancies()
        {
            List<JobVacancy> vacancies = new List<JobVacancy>();
            return vacancies;
        }

        public int addJobTitle(JobTitle title)
        {
            JobVacancy vacancy = new JobVacancy(title);
            Console.WriteLine($"Для вакансии была добавлено название {title.Title}");
            return 1;
        }

        public bool delJobTitle(int count)
        {
            Console.WriteLine($"Для {count} вакансий были удалены названия");
            return true;
        }

        public int openJobVacancy(JobVacancy vacancy)
        {
            vacancy.openVacancy = true;
            Console.WriteLine($"Для {vacancy.Vacancy_name} было установлено состояние открыто");
            return 1;
        }

        public bool closeJobVacancy(int count)
        {
            JobVacancy vacancy = new JobVacancy();
            vacancy.openVacancy = false;
            Console.WriteLine($"Для {count} вакансий было установлено состояние закрыто");
            return true;
        }
        public Employee recruit(JobVacancy vacancy, Person person)
        {
            Employee employee = new Employee();
            Console.WriteLine($"На вакансию {vacancy.Vacancy_name} был назначен {person.name}");
            return employee;

        }

        public bool dismiss(int count, Reason why)
        {
            Console.WriteLine($"Число уволеных = {count}, по причине = {why.reason}");
            return true;
        }

    }
}
