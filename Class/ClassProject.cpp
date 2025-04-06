#include<iostream>
using namespace std;

class student
{
    public:
        string name,course,studentId;
        int age;
        int marks[4]={3,4,5,6};
        void inputDetails(){

            cout<<"Enter your name: ";
            cin>>name;
            cout<<name;
            cout<<"Enter your course: ";
            cin>>course;
            cout<<course;
            cout<<"Enter your marks for 3 subjects: - "<<endl;
            for (int i = 0; i < 3; i++)
            {
                cout<<"Subject "<<i+1<<" :";
                cin>>marks[i];
            }
            
        }

        void calculateGrade(){

        }
};


class Teacher:public student
{
    public:
        string teacherId,name,subject;

        void assignMarks(int subject){
            cout<<"Marks of the student: ";
            cin>>subject;
            cout<<endl;
        }
        void display(){
            cout<<"The marks of the student is : "<<subject<<endl;
        }
};



class Admin:public Teacher,public student
{
    public:
        string name,adminId;

        void addStudent(string name){
            cout<<"Enter student's name to add: ";
            cin>>name;
            cout<<endl;
        }
        void addTeacher(string name){
            cout<<"Enter teacher's name to add: ";
            cin>>name;
            cout<<endl;
        }
        void removeStudent(string name){
            cout<<"Enter student's name to remove: ";
            cin>>name;
            cout<<endl;
        }
        void removeTeacher(string name){
            cout<<"Enter teacher's name to remove: ";
            cin>>name;
            cout<<endl;
        }

};

int main(){
    student s1;
    s1.inputDetails();
}




