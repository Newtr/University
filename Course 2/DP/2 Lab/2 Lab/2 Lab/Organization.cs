using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public class Organization : IStaff
    {
        public int id { get; private set;}
        public string? name { get; protected set;}
        public Type? shortname { get; protected set;}
        public string? address { get; protected set;}
        public DateTime timeStamp { get; protected set;}


        public Organization() { }
        public Organization(Organization new_organization)
        {
            new_organization.id = id;
            new_organization.name = name;
            new_organization.shortname = shortname;
            new_organization.address = address;
            new_organization.timeStamp = timeStamp;
        }
        public Organization(string name, string shortname, string address)
        {
            Random rnd = new Random();
            this.name = name;
            this.address = address;
            this.shortname = shortname.GetType();
            timeStamp = DateTime.Now;
            id = rnd.Next(0,100);
        }

        public virtual void printfinfo()
        {
            Console.WriteLine($"ID = {id}");
            Console.WriteLine($"NAME = {name}");
            Console.WriteLine($"SHORTNAME = {shortname}");
            Console.WriteLine($"ADDRESS = {address}");
            Console.WriteLine($"TIMESTAMP = {timeStamp}");
        }

        public List<JobVacancy> getJobVacancies()
        {
            List<JobVacancy> vacancies = new List<JobVacancy>();
            return vacancies;
        }
        public bool dismiss(int count, Reason why)
        {
            Console.WriteLine($"Число уволеных = {count}, по причине = {why.reason}");
            return true;
        }
        public Employee recruit(JobVacancy vacancy, Person person)
        {
            Employee employee = new Employee();
            Console.WriteLine($"На вакансию {vacancy.Vacancy_name} был назначен {person.name}");
            return employee;

        }
        public void openJobVacancy(int id)
        {
            JobVacancy jobvacancy = new();
            jobvacancy.openVacancy = true;
        }

        public bool closeJobVacancy(int count)
        {
            JobVacancy vacancy = new JobVacancy();
            vacancy.openVacancy = false;
            Console.WriteLine($"Для {count} вакансий было установлено состояние закрыто");
            return true;
        }

        public string printJobVacancies()
        {
            List<JobVacancy> jobvacancies = new();
            return jobvacancies.ToString();
        }
        public bool delJobTitle(int count)
        {
            Console.WriteLine($"Для {count} вакансий были удалены названия");
            return true;
        }

        public int addJobTitle(JobTitle title)
        {
            JobVacancy vacancy = new JobVacancy(title);
            Console.WriteLine($"Для вакансии была добавлено название {title.Title}");
            return 1;
        }

        public List<JobTitle> GetJobTitles() 
        {
            List<JobTitle> jobTitles = new();
            return jobTitles;
        }

        public List<Employee> getEmployees()
        {
            List<Employee> employees = new();
            return employees;
        }
    }
}
