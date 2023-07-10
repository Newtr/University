using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace _2_Lab
{
    public class Book
    {
        public string type;
        public double book_size;
        public string name;
        public int UDK;
        public int count_of_page;
        public string publishing_house;
        public int year;
        public List<Author> authors = new List<Author>();
        public DateTime upload_date = DateTime.Now;
    }

    public class Author
    {
        public string FIO { get; set; }
        public string country { get; set; }
        public int ID { get; set; }
        public int age { get; set; }
    }
}
