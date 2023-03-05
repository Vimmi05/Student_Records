#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class student{
     int rollno;
     char name[50];
     int dsa_marks,maths_marks,ca_marks,oops_marks,de_marks;
     double average;
     char grade;

     public:
     void getdata();
     void showdata() const;
     void calculate();
     int retrollno() const;
}; 

void student::calculate(){
average=(dsa_marks+maths_marks+ca_marks+oops_marks+de_marks)/5;
     if(average>=90)
     grade='A';
     else if(average>=75)
     grade='B';
     else if(average>=50)
     grade='C';
     else
     grade='F';
}

void student::getdata(){
     cout<<"\nEnter Student's Roll Number : ";
	cin>>rollno;
	cout<<"Enter Student Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"Marks out of 100 "<<endl;
	cout<<"Enter marks in DSA : ";
	cin>>dsa_marks;
	cout<<"Enter marks in Maths : ";
	cin>>maths_marks;
	cout<<"Enter marks in CA : ";
	cin>>ca_marks;
	cout<<"Enter marks in OOPs : ";
	cin>>oops_marks;
	cout<<"Enter marks in DE : ";
	cin>>de_marks;
     calculate();
}
void student::showdata() const
{
// cout<<"\nRoll number of student : "<<rollno;
// cout<<"\nName of student : "<<name;
// cout<<"\nEnglish : "<<eng_marks;
// cout<<"\nMaths : "<<math_marks;
// cout<<"\nScience : "<<sci_marks;
// cout<<"\nLanguage2 : "<<lang2_marks;
// cout<<"\nComputer Science :"<<cs_marks;
// cout<<"\nAverage Marks :"<<average;
// cout<<"\nGrade of student is :"<<grade;
    cout<<rollno<<setw(20)<<name<<setw(14)<<dsa_marks<<setw(13)<<maths_marks<<setw(18)<<ca_marks<<setw(13)<<oops_marks<<setw(17)<<de_marks<<setw(10)<<average<<setw(16)<<grade<<endl;	
}
int  student::retrollno() const
{
     return rollno;
}

void create();
void display(int);//to display particular record
void display_all(); // to display all the records
void del(int);//delete a particular record
void modify(int);//tomodify a particular record

int main(){
     int choice;
     cout<<setprecision(2); 
     do{
     system("cls");
	cout<<"\nMAIN-MENU - "<<endl;
	cout<<"1.Create Student Record. "<<endl;
	cout<<"2.Search Student Record. "<<endl;
	cout<<"3.Display Record of all the Students. "<<endl;
	cout<<"4.Delete a Student Record. "<<endl;
	cout<<"5.Modify a Student Record. "<<endl;
	cout<<"6.Exit. "<<endl;
	cout<<"\nEnter your choice : ";
	cin>>choice;
	int n;
	system("cls");
	switch(choice){
          case 1 : 
			create();
			break;
		case 2 : 
		    cout<<"\nEnter the Roll No. : ";
		    cin>>n;
		    display(n);
		    break;
		case 3 :
		    display_all();
			break;
		case 4 :
		    cout<<"\nEnter the Roll No. : ";
			cin>>n;  
			del(n);
			break;
		case 5 :
			cout<<"\nEnter the Roll No. : ";
			cin>>n;  
			modify(n);
			break;
		case 6 :
			cout<<"\nExiting.....Thank you!!!";
			exit(0);
		default :
			cout<<"Error - Enter a valid choice. "<<endl;
			break;
    }
    }
    while(choice!=6);
    return 0;
}
//write student details to the file
void create(){
	student stud;
	ofstream oFile;
	oFile.open("student.data",ios::binary|ios::app);
	stud.getdata();
	oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
	oFile.close();
		cout<<"Student record is created. ";
	cin.ignore();
	cin.get();
}
// read file records
void display_all(){
	student stud;
	ifstream inFile;
	inFile.open("student.data",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be opened....Press any key to exit.";
	cin.ignore();
	cin.get();
	return;
	}
	cout<<"\nDisplaying all the Student Records......."<<endl;
	cout<<"Roll No."<<setw(15)<<"Name"<<setw(15)<<"DSA"<<setw(15)<<"Maths"<<setw(15)<<"CA"<<setw(15)<<"OOPs"<<setw(15)<<"DE"<<setw(15)<<"Average"<<setw(15)<<"Grade"<<endl;
	while(inFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
	{
	stud.showdata();
	cout<<"=======================================================================================================================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}
//Reading a specific data
void display(int n){
	student stud;
	ifstream iFile;
	iFile.open("student.data",ios::binary);
	if(!iFile)
	{
	cout<<"File could not be opened....Press any Key to exit.";
	cin.ignore();
	cin.get();
	return;
	}
	bool flag=false;
	cout<<"Roll No."<<setw(15)<<"Name"<<setw(15)<<"DSA"<<setw(15)<<"Maths"<<setw(15)<<"CA"<<setw(15)<<"OOPs"<<setw(15)<<"DE"<<setw(15)<<"Average"<<setw(15)<<"Grade"<<endl;
	while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
	{
	if(stud.retrollno()==n)
	{
	stud.showdata();
	flag=true;
	}
	}
	iFile.close();
	if(flag==false)
	cout<<"\nRecord does not exist.";
	cin.ignore();
	cin.get();
}
// modifying a specific record
void modify(int n){
	bool found=false;
	student stud;
	fstream fl;
	fl.open("student.data",ios::binary|ios::in|ios::out);
	if(!fl)
	{
	cout<<"File could not be opened....Press any key to exit.";
	cin.ignore();
	cin.get();
	return;
	}
	cout<<"Roll No."<<setw(15)<<"Name"<<setw(15)<<"DSA"<<setw(15)<<"Maths"<<setw(15)<<"CA"<<setw(15)<<"OOPs"<<setw(15)<<"DE"<<setw(15)<<"Average"<<setw(15)<<"Grade"<<endl;
		while(!fl.eof() && found==false)
	{
	fl.read(reinterpret_cast<char *> (&stud), sizeof(student));
	if(stud.retrollno()==n)
	{
	stud.showdata();
	cout<<"\nEnter new details - "<<endl;
	stud.getdata();
		int pos=(-1)*static_cast<int>(sizeof(stud));
		fl.seekp(pos,ios::cur);
		fl.write(reinterpret_cast<char *> (&stud), sizeof(student));
		cout<<"\nRecord is Updated";
		found=true;
	}
	}
	fl.close();
	if(found==false)
	cout<<"\nRecord does not exist. ";
	cin.ignore();
	cin.get();
}
//Deleting a specific record
void del(int n){
	student stud;
	ifstream iFile;
	iFile.open("student.data",ios::binary);
	if(!iFile)
	{
	cout<<"File could not be opened....Press any key to exit.";
	cin.ignore();
	cin.get();
	return;
	}
	ofstream oFile;
	oFile.open("Temp.data",ios::out);
	iFile.seekg(0,ios::beg);
	while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student)))
	{
	if(stud.retrollno()!=n)
	{
	oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
	}
	}
	oFile.close();
	iFile.close();
	remove("student.data");
	rename("Temp.data","student.data");
	cout<<"\nRecord is deleted...";
	cin.ignore();
	cin.get();
}