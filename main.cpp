#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
int attendanceList(string);
int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollno();
void getListOfStudentsWithTheirPresenseCount();
int getAttendanaceListSubject();
int registerStudent();
int personalInfo(string);
int adminLogin();
int registerStudent();
int markMyAttendance(string username);
int countMyAttendance(string username);
int delay();
void del(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 500 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
int delay()
{
for(int i = 0; i<3; i ++)
{
cout<<"\n Saving Records ...";
    for(int ii = 0; ii<2000; ii ++)
    {
    for(int iii = 0; iii<20000; iii ++)
        { }
    }
}

cout<<"\n Exiting Now ...";
for(int i = 0; i<3; i ++){
   for(int ii = 0; ii<2000; ii ++) {
     for(int iii = 0; iii<20000; iii ++){
}
    }
}

return 0;
}

int adminView()
{
int goBack = 0;
while(1)
{
system("cls");
system("color F0");
cout<<"\n 1 Register a Student";
cout<<"\n 2 Check List of Student registered by userame";
cout<<"\n 3 Get List of student in all subject";
cout<<"\n 4 Get attendance list subject-wise";
cout<<"\n 5 Get student detail";
cout<<"\n 0. Go Back <- \n";
int choice;

cout<<"\n Enter you choice: ";
cin>>choice;

switch(choice)
{
case 1: registerStudent();break;
case 2: checkListOfStudentsRegistered(); break;
case 3: getListOfStudentsWithTheirPresenseCount(); break;
case 4: getAttendanaceListSubject();break;
case 5:{
                cout<<"Enter name of student"<<endl;
                string n;
                cin>>n;
                personalInfo(n);
            }break;
case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
}

if(goBack == 1)
{
break; //break the loop
}

}

return 0;
}

int studentLogin()
{
system("cls");
studentView();
delay();
return 0;
}

int adminLogin()
{
system("cls");
system("color 0D");
cout<<"\n --------- Admin Login --------";

string username;
string password;

cout<<"\n Enter username : ";
cin>>username;
cout<<"\n Enter password : ";
cin>>password;

if(username=="admin" && password=="admin@2")
{
    adminView();
    getchar();
    delay();
}
else
{
cout<<"\n Error ! Invalid Credintials..";
cout<<"\n Press any key for main menu ";
getchar();getchar();
}

return 0;
}

int checkStudentCredentials(string username, string password)
{
// read file line by line & check if username-password exist?
// if it exsist return 1 else 0

ifstream read;
read.open("db");

if (read) {
// The file exists, and is open for input
int recordFound = 0;
string line;
string temp = username;
while(getline(read, line)) {
if(line == temp)
{
recordFound = 1;
ifstream st;
st.open(username.c_str(),ios::in);
string name,un,pw,usn,add,fn,mn,att;
getline(st,name);
getline(st,un);
getline(st,pw);
if (!strcmp(password.c_str(),pw.c_str()))
{
    cout<<"\nlogin success\n";
    return 1;
}
st.close();
}
}
if (recordFound==1)
{
    cout<<"\ninvalid credentials\n"<<endl;
    return 0;
}
if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}

}

int studentView()
{//system("color 0B");black blue
    //system("color 07"); black white
    //system("color 0C");
    system("color 0D");//black purple
    //system("color 0F"); black n dark white
    //system("color 0E"); black n yellow
cout<<"\n ------- Student Login-------- \n";

string username, password;

cout<<"\n Enter username : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   //cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();
   return 0;
}

int goBack = 0;
while(1)
{
system("cls");
system("color F0");
ifstream st;
st.open(username.c_str(),ios::in);
string name,un,pw,usn;
getline(st,name);
getline(st,un);
getline(st,pw);
getline(st,usn);
st.close();
cout<<"\n 1 Mark Attendance for Today ";
cout<<"\n 2 Count my Attendance";
cout<<"\n 3 Attendance list";
cout<<"\n 4 Personal info";
cout<<"\n 0. Go Back <- \n";
int choice;

cout<<"\n Enter you choice: ";
cin>>choice;

switch(choice)
{
case 1: markMyAttendance(usn); break;
case 2: countMyAttendance(usn); break;
case 3: attendanceList(usn);break;
case 4: personalInfo(username);break;
case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
}

if(goBack == 1)
{
break; //break the loop
}

}

}

int personalInfo(string name)
{
 ifstream ist;
 string na,un,pwd,usn,add,fn,mn;
 ist.open(name.c_str(),ios::in);
 if(ist)
 {
     getline(ist,na);
    getline(ist,un);
    getline(ist,pwd);
    getline(ist,usn);
    getline(ist,add);
    getline(ist,fn);
    getline(ist,mn);
    cout<<" -- personal info --"<<endl;
    cout<<"Name        :"<<name<<endl;
    cout<<"Username    :"<<un<<endl;
    cout<<"USN         :"<<usn<<endl;
    cout<<"Address     :"<<add<<endl;
    cout<<"Father name :"<<fn<<endl;
    cout<<"Mother name :"<<mn<<endl;
 }
 else
    cout<<"\n No such student\n"<<endl;
    ist.close();
    cout<<endl<<"Press any key to continue ... "<<endl;
    getchar();getchar();
}

int attendanceList(string usn)
{
    ifstream ost;
    ost.open(usn.c_str(),ios::in);
char line[50];
char sub[5],date[30];
int ch,f=0;
cout<<"\n1.FS\n2.CN\nEnter subject to get attendance list \n";
cin>>ch;
while(!ost.eof())
{
    ost>>line;
    strcpy(sub,strtok(line,"|"));
    strcpy(date,strtok(NULL,"|"));
    if(ch==1 && !strcmp(sub,"FS"))
    {
        f=1;
        cout<<date<<endl;
    }
    if(ch==2 && !strcmp(sub,"CN"))
    {
        cout<<date<<endl;
        f=1;
    }
}
ost.close();
if(f==0)
    cout<<endl<<"You have not attended classes"<<endl;
cout<<"Press any key to continue ..."<<endl;
    getchar();
    getchar();
}

int markMyAttendance(string usn)
{
cout<<"\n Mark Attendance for today !!";
int ch;
string sub;
cout<<endl<<"1.FS\n2.CN\nEnter subject"<<endl;
cin>>ch;
if(ch==1)
    sub="FS";
else if(ch==2)
    sub="CN";
else cout<<"invalid";

 time_t t = time(0);   // get time now
    tm* now = localtime(&t);

ofstream ost;
ost.open(usn.c_str(),ios::app);
ost<<endl<<sub<<"|"<<now->tm_mday<<"-"<<now->tm_mon+1<<"-"<<now->tm_year+1900<<"|";
ost.close();
cout<<"\n Please any key to continue ...";

getchar();getchar();

return 0;
}

int countMyAttendance(string usn)
{
cout<<"\n Count my attendance !!";
int f=0,c=0;
ifstream ost;
ost.open(usn.c_str(),ios::in);
char line[50];
char sub[5],date[20];
while(!ost.eof())
{
    ost>>line;
    strcpy(sub,strtok(line,"|"));
    strcpy(date,strtok(NULL,"|"));
    if(!strcmp(sub,"FS"))
        f++;
    if(!strcmp(sub,"CN"))
        c++;
}
ost.close();
cout<<endl<<"Number of classes attended "<<endl;
cout<<endl<<"FS:"<<f<<endl;
cout<<endl<<"CN:"<<c<<endl;
getchar();getchar();

return 0;
}

void getListOfStudentsWithTheirPresenseCount()
{
cout<<"\n Students list with all subject !!";
ifstream ist;
ist.open("db",ios::in);
string stu;
    ofstream mfile;
    mfile.open("att_list",ios::out);
while(!ist.eof())
{
    ist>>stu;
    ifstream st;
    st.open(stu.c_str(),ios::in);
    string name,un,pw,usn;
    getline(st,name);
    getline(st,un);
    getline(st,pw);
    getline(st,usn);
    st.close();
    ifstream sfile;
    sfile.open(usn,ios::in);
    while(!sfile.eof())
    {char line[50];
    sfile>>line;
    mfile<<endl<<usn<<"|"<<line;
}
 sfile.close();

}
cout<<"\n Please any key to continue..";
 mfile.close();
getchar(); getchar();

}

int getAttendanaceListSubject()
{
cout<<"\n Students list with all subject !!";
ifstream ist;
ist.open("db",ios::in);
string stu;
ofstream ost,oost;
ost.open("CN",ios::out);
oost.open("FS",ios::out);
oost.close();
ost.close();
while(getline(ist,stu))
{
    ifstream st;
    st.open(stu.c_str(),ios::in);
    string name,un,pw,usn;
    getline(st,name);
    getline(st,un);
    getline(st,pw);
    getline(st,usn);
    st.close();
    ifstream sfile;
    sfile.open(usn,ios::in);
    while(!sfile.eof())
    {
        char line[50];
        char sub[5],date[20];
        sfile>>line;
        strcpy(sub,strtok(line,"|"));
        strcpy(date,strtok(NULL,"|"));
        ofstream subfile;
        subfile.open(sub,ios::app);
        subfile<<endl<<usn<<"|"<<date;
            subfile.close();
    }
    sfile.close();
}
cout<<"\n Please any key to continue..";
// mfile.close();
getchar(); getchar();
return 0;
}

int checkListOfStudentsRegistered()
{
cout<<"\n - Check List of Student Registered by Username-- ";

//check if record already exist..
ifstream read;
read.open("db");

if(read)
{   int recordFound =0;
    string line;
    while(getline(read, line)) {
    cout<<" \n " << line;
    }
     read.close();
}
else
{
cout<<"\n No Record found :(";
}


cout<<"\n Please any key to continue..";
getchar(); getchar();
return 0;
}

int registerStudent()
{
    cout<<"\n ----- Register Student ---- \n";

    string name, username, password, rollno, address, father, mother;

    cout<<"\n Enter Name : ";     cin>>name;
    cout<<"\n Enter Username : ";     cin>>username;
    cout<<"\n Enter password : ";     cin>>password;
    cout<<"\n Enter rollno : ";     cin>>rollno;
    getchar();

    char add[100];
    cout<<"\n Enter address : ";     cin.getline(add, 100);
    cout<<"\n Enter father : ";     cin>>father;
    cout<<"\n Enter mother : ";     cin>>mother;

    //check if record already exist..
    ifstream read;
    read.open("db");

    if(read)
    {   int recordFound =0;
  string line;
   while(getline(read, line)) {
    if(line == username )
    {
    recordFound = 1 ;
       break;
}
        }
        if(recordFound == 1)
        {
    cout<<"\n Username already Register. Please choose another username ";
    getchar(); getchar();
    delay();
    read.close();
    return 0;
}
}
    read.close();

    ofstream out;
out.open("db", ios::app);
out<<username<<"\n";
out.close();

ofstream out1;
string temp;
temp = username;
out1.open(temp.c_str());
out1<<name<<"\n"; out1<<username<<"\n"; out1<<password<<"\n";
out1<<rollno<<"\n"; out1<<add<<"\n"; out1<<father<<"\n";
out1<<mother<<"\n";
out1.close();

cout<<"\n Student Registered Successfully !!";

    cout<<"\n Please any key to continue..";
getchar(); getchar();
return 0;
}

int main(int argc, char** argv)
{
    system("cls");
    system("color 0A");
    for(int i=0;i<3;i++)
    {
        del(1);
        cout<<"::::::::::::::::::::::::::::::::::"<<endl;
    }
    del(1);
    cout<<"::::::::::::ATTENDANCE::::::::::::"<<endl;
    for(int i=0;i<3;i++)
    {
        del(1);
        cout<<"::::::::::::::::::::::::::::::::::"<<endl;
    }
    del(1);
    system("color 0C");
    del(1);
    system("color 0E");
    del(1);
while(1)
{
system("cls");
system("color 0A");
cout<<"\n Attendance Management System \n";
cout<<"-------------------------------------\n\n";

cout<<"1. Student Login\n";
cout<<"2. Admin Login\n";

cout<<"0. Exit\n";
int choice;

cout<<"\n Enter you choice: ";
cin>>choice;

switch(choice)
{
case 1: studentLogin(); break;
case 2: adminLogin(); break;
case 0:
       while(1)
       {
   system("cls");
        cout<<"\n Are you sure, you want to exit? y | n \n";
        char ex;
        cin>>ex;
        if(ex == 'y' || ex == 'Y')
          exit(0);
        else if(ex == 'n' || ex == 'N')
             {
              break;
             }
             else{
              cout<<"\n Invalid choice !!!";
              getchar();
             }
        }
            break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
}
}
return 0;
}
