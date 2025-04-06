#include<iostream>
#include<fstream>
using namespace std;

int main(){
    //Creating and Opening the file
    ofstream Myfile("FileName.txt");//Use DOUBLE QUOTES

    //Write to the file
    Myfile<<"Files can be tricky, but it is fun enough!!";

    //Close the write mode file
    Myfile.close();

    //Reading from the text file
    ifstream MyReadFile("FileName.txt");
    string myText;

    // //Using while loop with getline() function to read the file line by line
    while (getline(MyReadFile,myText))
    {
        cout<<myText<<endl;
    }
    

    //Close the read mode file
    MyReadFile.close();

    //Opnenning the file in append mode
    ofstream my_file("FileName.txt",ios::app);

    if ((!my_file))
    {
        cout<<"Failed to open the file for appending";
        return 1;
    }
    
    //Appending
    my_file<<"Line 4"<<endl;
    my_file<<"Line 5"<<endl;
    my_file<<"Line 6"<<endl;
}