#include <iostream>
#include <list>

using namespace std;

class HashTable{
private:
  list<int> *table;
  int total_elements;

  // Hash function to calculate hash for a value:
  int getHash(int key){
    return key % total_elements;
  }

public:
  // Constructor to create a hash table with 'n' indices:
  HashTable(int n){
    total_elements = n;
    table = new list<int>[total_elements];
  }

  // Insert data in the hash table:
  void insertElement(int key){
    table[getHash(key)].push_back(key);
  }

  // Remove data from the hash table:
  void removeElement(int key){
    int x = getHash(key);

    list<int>::iterator i; 
    for (i = table[x].begin(); i != table[x].end(); i++) { 
      // Check if the iterator points to the required item:
      if (*i == key) 
        break;
    }

    // If the item was found in the list, then delete it:
    if (i != table[x].end()) 
      table[x].erase(i);
  }

  void printAll(){
    // Traverse each index:
    for(int i = 0; i < total_elements; i++){
      cout << "Index " << i << ": ";
      // Traverse the list at current index:
      for(int j : table[i])
        cout << j << " => ";

      cout << endl;
    }
  }
};

int main() {
  // Create a hash table with 3 indices:
  HashTable ht(3);

  // Declare the data to be stored in the hash table:
  int arr[] = {2, 4, 6, 8, 10,8,8};

  // Insert the whole data into the hash table:
  for(int i = 0; i < 7; i++)
    ht.insertElement(arr[i]);

  cout << "..:: Hash Table ::.." << endl;
  ht.printAll();
  
  ht.removeElement(4);
  cout << endl << "..:: After deleting 4 ::.." << endl;
  ht.printAll();

  return 0;
}

/* #include <iostream>
#include <list>

using namespace std;

struct Cell // ячейка хеш-таблицы
{
    // "N/A" символизирует пустоту поля 
    string key_ = "N/A"; 
    string phoneNo_ = "N/A";
 
    bool isEmpty() const // ячейка пустая?
    {
        return key_ == "N/A" && phoneNo_ == "N/A";
    }
    void output() // вывести поля ячейки
    {
        cout << " " << key_ << endl;
        cout << " " << phoneNo_ << endl;
        cout << "-------------------------" << endl;
    }
};
 
int hashIndex(string key, int hashLen) // хеш-функция
{ // алгоритм взял из гарвардского видео-курса
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += key[i];
    return sum % hashLen; 
}
 
struct HashTable // хеш-таблица
{
    const int LEN_ = 10; // максимальный размер
    Cell *H_; // массив, что хранит элементы таблицы
    
    HashTable() // конструктор
    {
        H_ = new Cell[LEN_];
    }
    ~HashTable() // деструктор
    {
        delete[] H_;
    }
    void add(Cell cell) // добавить новый элемент
    {
        int index = hashIndex(cell.key_, LEN_); // находим его индекс
        
        // сдвигаемся, если место занято
        int i; 
        for (i = index; i < LEN_ && !H_[i].isEmpty(); i++);
 
        if (!H_[i].isEmpty()) return; // если найденное место не пустое, значит мы дошли до конца 
 
        H_[i] = cell; // даем значение элементу по найденному индексу
    }
    int find(string key) // найти индекс элемента с заданным ключом
    {
        int index = hashIndex(key, LEN_); // находим его индекс
 
        for (int i = index; i < LEN_; i++) // начинаем сдвигаться с указанного места, 
            if (H_[i].key_ == key) // пока не найдем элемент с таким же ключом
                return i;
        return -1; // -1 значит, что мы не нашли такой элемент
    }
    string ext(string key) // извлечь элемент по заданному ключу (по сути, удалить его)
    {
        int index = find(key); // ищем такой элемент в таблице
        if (index == -1) return "error"; // если не нашли вернуть строку "ошибка"
        string phoneNo = H_[index].phoneNo_; // вытаскиваем значение
        
        H_[index].key_ = H_[index].phoneNo_ = "N/A"; // "обнуляем" элемент
 
        return phoneNo;
    }
    void output() // вывести не пустые элементы
    {
        for (int i = 0; i < LEN_; i++) 
            if (!H_[i].isEmpty()) // если элемент не пустой
            {
                cout << " i: " << i << endl; 
                H_[i].output();
            }
    }
};

int main(){
  HashTable HT;
  Cell CL1,CL2,CL3;
  CL1.key_ = "Bob";
  CL1.phoneNo_ = "12345";
  CL2.key_ = "Billy";
  CL2.phoneNo_ = "56789";
  CL3.key_ = "Bob";
  CL3.phoneNo_ = "578134";

  HT.add(CL1);
  HT.add(CL2);
  HT.add(CL3);
  HT.output();
  cout<<"!!!!!!!!!!!!!!!!!!!!"<<endl;
  HT.output();
} */