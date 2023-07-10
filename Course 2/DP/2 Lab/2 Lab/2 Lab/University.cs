using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2_Lab
{
    public class University : Organization, IStaff
    {
        protected List<Faculty> faculties = new List<Faculty>();

        public University() { }
        public University(University new_university)
        {
            new_university.faculties = faculties;
        }
        public University(string name, string shortName, string address) : base(name,shortName,address)
        {
            this.name = name;
            this.address = address;
            timeStamp = DateTime.Now;
        }

        public int addFaculty(int count_of_added_faculties)
        {
            string? _name;
            for (int i = 0; i < count_of_added_faculties; i++)
            {
                Faculty facul = new Faculty();
                Console.WriteLine($"Name of faculty: ");
                _name = Console.ReadLine();
                facul.name = _name;
                faculties.Add(facul);
                facul.Dispose();
            }
            Console.WriteLine($"Было добавлено: {count_of_added_faculties}, Всего: {faculties.Count}");
            return count_of_added_faculties;
        }

        public bool delFaculty(int id_of_faculties)
        {
            Faculty fac1 = new();
            fac1 = faculties.ElementAt(id_of_faculties);
            Console.WriteLine($"Был удален факультет: {fac1.name}");
            faculties.RemoveAt(id_of_faculties);
            return true;
        }

        public bool updFaculty(Faculty fac)
        {
            foreach (var item in faculties)
            {
                if (item.Equals(fac))
                {
                    Console.WriteLine($"Имя факультета: {item.name}, было изменено на {fac.name}");
                    item.name = fac.name;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        private bool verFaculty(int id)
        {
            Faculty is_exist = new Faculty();
            is_exist = faculties.ElementAt(id);
            if (is_exist != null)
            {
                return true;
            }
            else
            { return false; }
        }

        public List<Faculty> getFaculties()
        {
            return faculties;
        }

        public override void printfinfo()
        {
            base.printfinfo();
            Console.WriteLine($"COUNT OF FACULTIES = {faculties.Count}");
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
