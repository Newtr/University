using _2_Lab;

Console.WriteLine("--------[ORGANIATION]---------");

Organization MyOrg = new Organization("Microsoft", "Mic", "Minsk");
MyOrg.printfinfo();

Faculty ISIT = new Faculty();
ISIT.name = "ISIT";

JobTitle Teacher = new JobTitle();
Teacher.Title = "Teacher";

JobVacancy SIS_ADMIN = new();
SIS_ADMIN.Vacancy_name = "SIS ADMIN";

Person Nikita = new();
Nikita.name = "Nikita";

Reason MyReason = new();
MyReason.reason = "Плохая работа";

Console.WriteLine("--------[UNIVERSITY]--------");

University MyUniver = new University("Белорусский государственный университет", "БГУ","Minsk");
MyUniver.addFaculty(3);
MyUniver.printfinfo();
MyUniver.delFaculty(2);
MyUniver.updFaculty(ISIT);
List<Faculty> new_fac = MyUniver.getFaculties();
List<JobVacancy> new_job = MyUniver.getJobVacancies();
MyUniver.addJobTitle(Teacher);
MyUniver.delJobTitle(1);
MyUniver.openJobVacancy(SIS_ADMIN);
MyUniver.closeJobVacancy(1);
MyUniver.recruit(SIS_ADMIN, Nikita);
MyUniver.dismiss(2, MyReason);

Department newdep = new Department();
newdep.name_of_department = "POIBMS";
Department newdep2 = new Department();
newdep.name_of_department = "POIBMS2";

Console.WriteLine("--------[FACULTY]--------");

Faculty myFac = new Faculty("Программное обеспечение информационных технологий","ПОИТ","БГТУ");
myFac.addDepartment(newdep);
myFac.addDepartment(newdep2);
myFac.printfinfo();
myFac.delDepartment(1);
myFac.updDepartment(newdep);
List<Department> newdeps = myFac.GetDepartments();
List<JobVacancy> new_job2 = MyUniver.getJobVacancies();
myFac.addJobTitle(Teacher);
myFac.delJobTitle(1);
myFac.openJobVacancy(SIS_ADMIN);
myFac.closeJobVacancy(1);
myFac.recruit(SIS_ADMIN, Nikita);
myFac.dismiss(2, MyReason);

