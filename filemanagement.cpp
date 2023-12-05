#include<iostream>
#include<fstream>
using namespace std;
int ID;
class student
{
public:

  int id;
  string name;
  int age;
  string stream;

    void addStudent()
    {
        cout<<"Enter the name    :: ";
        cin.get();
        getline(cin,name);
        cout<<"Enter Your Age    :: ";
        cin>>age;
        cout<<"Enter Your Stream :: ";
        cin.get();
        getline(cin,stream);
        ID++;

       ofstream fout;
       fout.open("C:/file/student.txt", ios :: app);
       fout<<"\n"<<ID;
       fout<<"\n"<<name;
       fout<<"\n"<<age;
       fout<<"\n"<<stream;
       fout.close();

       fout.open("C:/file/ID.txt", ios :: app);
       fout<<"\n"<<ID;
       fout.close();

       cout<<endl;
       cout<<"Record added Successfully "<<endl;
    }

    void printAllstudent()
    {
          ifstream fin;
          fin.open("C:/file/student.txt");

          student s;

          while(!fin.eof())
          {
                 fin>>s.id;
                 fin.ignore();
                 getline(fin,s.name);
                 fin>>s.age;
                 fin.ignore();
                 getline(fin,s.stream);

        cout<<"\n ID "<<s.id<<" Name "<<s.name<<" Age "
        <<s.age<<" Stream "<<s.stream;
                //  cout<<"\n ID "<<s.id;
                // cout<<"\n Name "<<s.name;
                // cout<<"\n Age "<<s.age;
                // cout<<"\n Stream "<<s.stream;
                // cout<<endl;

          }
          fin.close();
    }

    void searchstudent(int id)
    {
           ifstream fin;
          fin.open("C:/file/student.txt");

          student s;

          while(!fin.eof())
          {
                 fin>>s.id;
                 fin.ignore();
                 getline(fin,s.name);
                 fin>>s.age;
                 fin.ignore();
                 getline(fin,s.stream);

            if(id == s.id)
            {
                 cout<<"\nID->"<<s.id;
                 cout<<"\nName->"<<s.name;
                 cout<<"\nAge->"<<s.age;
                 cout<<"\nStream->"<<s.stream;
                 break;
            }
          }
          fin.close();
    }

    void deletestudent(int id)
    {
        ifstream fin;
        fin.open("C:/file/student.txt");

        ofstream fout;
        fout.open("C:/file/temp.txt");

        student s;

        while(!fin.eof())
        {
                 fin>>s.id;
                 fin.ignore();
                 getline(fin,s.name);
                 fin>>s.age;
                 fin.ignore();
                 getline(fin,s.stream);

                if(id != s.id)
                {
                 fout<<"\n"<<s.id;
                 fout<<"\n"<<s.name;
                 fout<<"\n"<<s.age;
                 fout<<"\n"<<s.stream;

               }
        }
        fin.close();
        fout.close();

        remove("C:/file/student.txt");
        rename("C:/file/temp.txt", "C:/file/student.txt");
        cout<<endl;
        cout<<"Record Deleted Successfully "<<endl;
    }

    void updatestudent(int id)
    {
        deletestudent(id);

        student s;

        cout<<"Enter the name"<<endl;
        cin.get();
        getline(cin,s.name);
        cout<<"Enter Age"<<endl;
        cin>>s.age;
        cout<<"Enter the stream"<<endl;
        cin.get();
        getline(cin,s.stream);

        ofstream fout;
        fout.open("c:/file/student.txt",ios::app);

        fout<<"\n"<<id;
        fout<<"\n"<<s.name;
        fout<<"\n"<<s.age;
        fout<<"\n"<<s.stream;

        fout.close();
        cout<<"Record Updated Successfully"<<endl;

    }
};

int main()
{
    int choice;
    ifstream fin;
    fin.open("C:/file/ID.txt");

    if(!fin)
    {
      cout<<"File Not found \n"<<endl;
    }
    else
    {
        cout<<"file created successfully"<<endl;
        while(!fin.eof())
        {
            fin>>ID;
        }
    }
    fin.close();

    while(true)
    {
        cout<<"\n\n";
        cout<<"Enter Your Choice... "<<endl;
        cout<<"\n=====================\n\n";
        cout<<"1. Add Student... "<<endl;
        cout<<"2. Print all Student "<<endl;
        cout<<"3. Search a Student "<<endl;
        cout<<"4. Update a Student "<<endl;
        cout<<"5. Delete a Student "<<endl;
        cout<<"\n=====================\n\n";

        cin>>choice;

        student s;
        int id;

        switch(choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.printAllstudent();
            break;

        case 3:
            cout<<"Enter Student id "<<endl;
            cin>>id;
            s.searchstudent(id);
            break;

        case 4:
            cout<<"Enter Student id "<<endl;
            cin>>id;
            s.updatestudent(id);
            break;

        case 5:
            cout<<"Enter Student id "<<endl;
            cin>>id;
            s.deletestudent(id);
            break;

        default:
            return 0;
        }
    }
}
 
