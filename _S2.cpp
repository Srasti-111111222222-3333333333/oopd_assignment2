#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<chrono>

using namespace std;

int B_item[100];
string B_magJ[100];
int u_id[50];
string time_b[100], time_m[100], time_j[100] ;

int size_of_b = 0, n = 0;
int size_of_mj = 0;
class electronic_items{

    int e_books;
    int elec_items;

        electronic_items()
        {
        e_books = 100;
        elec_items = 100;
        }

};
class items{

    public:
    int books_count; 
    string name_of_item;
    items()
    {
        books_count = 0;
    }

    
};



class journals{
    public:
    string name_of_item;

};


class books: public items{

    public:
    int id;
    int ISBN;
    string publication;
    string author;
};



class Magazines: public items{
    public:
    string rank;

};


books Book[100];

Magazines mag[100];

journals J[100];

class Borrow_loan
{
    public:
    string b_loc;
    string r_date;
    int id;
    int d_date;
    string type;
};

class Lib{
    
    public:



 void get_books()
    {
    ifstream ip("Books.csv");
    

  if(!ip.is_open()) 
  cout << "ERROR: File cannot be Opened" << '\n';

  string ch;
  int i=0;
  getline(ip, ch, '\n');
  while(!ip.eof())
  {

    getline(ip,ch,',');
    Book[i].id = atoi(ch.c_str());
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    Book[i].books_count = atoi(ch.c_str());
    getline(ip,ch,',');
    Book[i].ISBN = atoi(ch.c_str());
    getline(ip,ch,',');
    getline(ip,ch,',');
    Book[i].author = ch.c_str();
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    Book[i].name_of_item = ch.c_str();
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,'\n');


    i++;
  }
}



void get_journals(){
    ifstream ip("journals - journals.csv");
    

  if(!ip.is_open()) 
  cout << "ERROR: File Open" << '\n';

  string ch;
  int i=0;
  while(!ip.eof())
  {

    getline(ip,ch,',');
    J[i].name_of_item = ch.c_str();
    getline(ip,ch,'\n');

    i++;
  }

}

 void get_mags()
{

    ifstream ip("Magazines.csv");
    

  if(!ip.is_open()) 
  cout << "ERROR: File Open" << '\n';

  string ch;
  int i=0;
  getline(ip, ch, '\n');
  while(!ip.eof())
  {

    getline(ip,ch,',');
    mag[i].name_of_item = ch.c_str();
    getline(ip,ch,',');
    mag[i].rank = ch.c_str();
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,',');
    getline(ip,ch,'\n');
   
    i++;
  }

}


};


class member{
    private:
    int user_id;
    string m_name;
    int phone_no;
    string user_type;
    public: 
    void registration_member(string name, string u_type, int phone, int id);
    void Borrow_MJ(string name);
    void Borrow_b(int id);
    void Location_J(string name);
    void Location_b(int id, string author, int ISBN);
    void Location_M(string name, string mag_rank);
    void b_on_loan();
    void Bloan_loc();

};
    void member :: registration_member(string name, string u_type, int phone, int id)
    {
        m_name=name;
        user_type= u_type;
        phone_no = phone;
        int f=0;
        for(int i=0; i<n; i++)
        {
            if(u_id[i] == id)
            {             
                cout<<"User already present!!";
                f = 1;
                break;
            }  
        }
        
        if(f == 1)
        {
            ++n;
            u_id[n] = id;
        }

       ++n;
       cout<<"User with id: "<<u_id[n]<<" sucessfully added";
       

    }





   
void member :: Bloan_loc()
{
    int ch,id;
    cout<<"Enter the item id:\n";
    cin>>id;
    for(int i =0;i<100;i++)
    {
        if(Borrow[i].id == id)
        {
            ch = i;

        }
    }
    cout<<"\nItem present in library number: "<<Borrow[ch].b_loc<<endl;
} 
class Librarian
{

    private:
    int copies, ISBN;
    string name_of_item, author;
    public:
  

    void purchase_books()
    {


            cout<<"Name of new book: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, name_of_item);
            cout<<"Name of author: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, author);
            cout<<"ISBN no.: ";
            cin>>ISBN;
            cout<<"\ncopies:";
            cin>>copies;
            for(int i=0;i<100;i++)
            {
                if(Book[i].author == author && Book[i].ISBN == ISBN)
                {
                    cout<<"Book details already present";
                    Book[i].books_count += copies;
                }
            
            }

            cout<<"\nBooks with "<<copies<<" copies purchased successfully\n";
    } 



};

//main function
int main()
{
    char ch, choice;
    Lib b;
    int copies, phone, id, password;
    string name_of_book, name, type, name_of_item, author, e_item, rank, J;
    Librarian L;
    b.get_books();
    b.get_mags();
    b.get_journals();
    while(1)
    {cout<<"Welcome to the Library:\n";
    cout<<"1. Librarian\n";
    cout<<"2. Member\n";
    cout<<"3. Exit\n";
    cout<<"Enter your choice:";
    cin>>ch;
    member u;
    switch(ch)
    {
        case '1':   
                    L.purchase_books();
                    break;
        case '2': 
                while(1)
                {
                cout<<"\n1. Registeration"<<endl;
                cout<<"2. Issue some item"<<endl;
                cout<<"3. Location for some Item"<<endl;
                cout<<"4. Borrow on loan"<<endl;
                cout<<"5. check Borrow on loan location"<<endl;
                cout<<"6. Exit"<<endl;
                cout<<"Enter your choice:"<<endl;
                
                cin>>choice;
                
                switch(choice)
                {
                    case '1': 
                                cout<<"user id:";
                                cin>>id;

                                cout<<"user name:";
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                getline(cin,name);

                                cout<<"user type:";
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                getline(cin,type);

                                cout<<"user phone no.";
                                cin>>phone;

                                u.registration_member(name, type, phone, id);
                                break;
                    case '2':   int ch_item;
                                cout<<"Enter Item to be issued: \n";

                                cout<<"1.Book\n";

                                cout<<"2.Magazines\n";

                                cout<<"3.Journal\n";

                                cout<<"4.Ebooks\n";

                                cout<<"5.Electronics Items\n";

                                cout<<"Enter your choice: ";

                                cin>>ch_item;
                                switch(ch_item)
                                {
                                    case 1: 
                                              int book_id;
                                              cout<<"Enter book id: ";
                                              cin>>book_id;
                                              u.Borrow_b(book_id);
                                              break;
                                    case 2:   
                                              
                                              cout<<"Enter name of Magazine: ";
                                              getline(cin,name);
                                              u.Borrow_MJ(name);
                                              break;
                                    case 3:   
                                              cout<<"Enter name of Journal:";
                                              getline(cin,J);
                                              u.Borrow_MJ(J);
                                              break;
                                    case 4:  
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter name of Ebook:";
                                              getline(cin,name_of_item);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter name of Ebook author:";
                                              getline(cin,author);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Ebook "<<name_of_item<<" issued!";
                                              break;
                                    case 5:   
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter electronic item name:";
                                              getline(cin,e_item);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Electronic item "<<e_item<<" issued!";
                                              break;
                                    default : cout<<"Invalid option";
                                              break;
                             }
                             break;
                    case '3':   int choice_loc;
                                
                                cout<<"Enter Item to search for location: \n";
                                cout<<"1.Book\n";
                                cout<<"2.Magazines\n";
                                cout<<"3.Journal\n";
                                cin>>choice_loc;
                                switch(choice_loc)
                                {
                                    case 1: int book_id, ISBN;
                                             
                                              cout<<"Enter book id: ";
                                              cin>>book_id;
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"\nEnter book author: ";
                                              getline(cin,author);
                                              cout<<"\nEnter book ISBN: ";
                                              cin>>ISBN;
                                              u.Location_b(book_id, author, ISBN);
                                              break;
                                    case 2:   
                                              
                                              cout<<"Enter name of Magazine: ";
                                              getline(cin,name);
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter rank: ";
                                              getline(cin,rank);
                                              u.Location_M(name, rank);
                                              break;
                                    case 3:
                                              
                                              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                              cout<<"Enter name of Journal:";
                                              getline(cin,J);
                                              u.Location_J(J);
                                              break;
                                    default : 
                                              cout<<"Invalid option";
                                              break;
                             }
                             break;
                    case '4': u.b_on_loan();
                              break;
                    case '5': u.Bloan_loc();
                              break;
                    case '6': cout<<"\nThank you!";
                              exit(0);
                    default: cout<<"Invalid option";
                             break;
                }
                }
                break;
        case '3': cout<<"\nThank you!";
                  exit(0); 

        default : cout<<"Invalid option";
                  break;

    }  
    }
    return 0;

}

