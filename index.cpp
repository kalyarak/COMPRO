#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <regex>
#include <stdio.h>

using namespace std;
class student
{
private:
    string firstname, lastname,number, age, sex, classyear, faculty;

public:
    void menu();
    void insert();
    void display();
    void edit();
    void search();
    void deleted();
};

void student::menu()//หน้าหลัก
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\t\t\t|    Student Management System    |" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit\n" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\t\t\tPLEAS Choose Option : [1/2/3/4/5/6]" << endl;
    cout << "\t\t\t-----------------------------------" << endl;

    cout << "\t\t\t\t Enter Your Choose : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t Add Another Student Record (Y/N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        edit();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        cout << "\n\t\t\t\t... Program Is Exit ...\n";
        remove("stuRecord.txt");
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again";
        break;
    }
    getch();
    goto menustart;
}

//หน้า เพิ่มข้อมูล (add)
void student::insert()
{
    system("cls");
    fstream file;
    cout << "------------------------------------------------------------" << endl;
    cout << "-------------------- Add Student Detail --------------------" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n\t\t\tFirst Name: ";
    cin >> firstname;
    cout << "\t\t\tLast Name: ";
    cin >> lastname;
    cout << "\t\t\tStudent Number: ";
    cin >> number;
    cout << "\t\t\tAge: ";
    cin >> age;
    cout << "\t\t\tSex [female/male]: ";
    cin >> sex;
    cout << "\t\t\tClass: ";
    cin >> classyear;
    cout << "\t\t\tFaculty: ";
    cin >> faculty;

    file.open("stuRecord.txt", ios::app | ios::out);
    file << " " << firstname << " " << lastname << " " << number << " " << age << " " << sex << " " << classyear << " " << faculty << "\n";
    file.close();
}
void student::display()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "--------------------------------------------------------------" << endl;
    cout << "-------------------- Student Record Table --------------------" << endl;
    cout << "--------------------------------------------------------------" << endl;

    file.open("stuRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data Is Present...";
        file.close();
    }
    else
    {
        file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No. " << total++ << " \n" << endl;
            cout << "\t\t\t First Name: " << firstname << "\n";
            cout << "\t\t\t Last Name: " << lastname << "\n";
            cout << "\t\t\t Student Number: " << number << "\n";
            cout << "\t\t\t Age: " << age << "\n";
            cout << "\t\t\t Sex [female/male]: " << sex << "\n";
            cout << "\t\t\t Class: " << classyear << "\n";
            cout << "\t\t\t Faculty: " << faculty << "\n";
            file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t No Data Is Present..." << endl;
        }
    }
    file.close();
}
void student::edit()
{
    system("cls");
    fstream file, file1;
    string num;
    int found=0;
    cout << "----------------------------------------------------------------" << endl;
    cout << "-------------------- Student Modify Details --------------------" << endl;
    cout << "----------------------------------------------------------------" << endl;

    file.open("stuRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        cout << "\n Enter Student Number of student which you want to modify: ";
        cin >> num;
        file1.open("record.txt", ios::app | ios::out);
        file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        while (!file.eof())
        {
            if (num != number)
            {
                file1 << " " << firstname << " " << lastname << " " << number << " " << age << " " << sex << " " << classyear << " " << faculty << "\n";
            }
            else
            {
                cout << "\n\t\t\tFirst Name: ";
                cin >> firstname;
                cout << "\t\t\tLast Name: ";
                cin >> lastname;
                cout << "\t\t\tStudent Number: ";
                cin >> number;
                cout << "\t\t\tAge: ";
                cin >> age;
                cout << "\t\t\tSex [female/male]: ";
                cin >> sex;
                cout << "\t\t\tClass: ";
                cin >> classyear;
                cout << "\t\t\tFaculty: ";
                cin >> faculty;

                file1 << " " << firstname << " " << lastname << " " << number << " " << age << " " << sex << " " << classyear << " " << faculty << "\n";
                found++;
            }

            file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        }
        if (found == 0)
        {
            cout <<"\n\t\t\t Student Number Not Found...";
        }
        file.close();
        file1.close();
        remove("stuRecord.txt");
        rename("record.txt", "stuRecord.txt");
    }
}
void student::search(){
    system("cls");
    fstream file;
    string num;
    int found=0;
    cout << "----------------------------------------------------------------" << endl;
    cout << "------------------------- Search Table -------------------------" << endl;
    cout << "----------------------------------------------------------------" << endl;

    file.open("stuRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }else{
        cout << "\nEnter Student Number of Student which you want to search: ";
        cin >> num;
        file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        while (!file.eof())
        {
            if (num == number)
            {
                cout << "\n\t\t\t First Name: " << firstname << "\n";
                cout << "\t\t\t Last Name: " << lastname << "\n";
                cout << "\t\t\t Student Number: " << number << "\n";
                cout << "\t\t\t Age: " << age << "\n";
                cout << "\t\t\t Sex [female/male]: " << sex << "\n";
                cout << "\t\t\t Class: " << classyear << "\n";
                cout << "\t\t\t Faculty: " << faculty << "\n";
                found++;
            }
            file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        }
        if (found == 0)
        {
            cout <<"\n\t\t\t Student Number Not Found...";
        }
        file.close();
    }
}
void student::deleted(){
    system("cls");
    fstream file, file1;
    int found = 0;
    string num;
    cout << "================================================================" << endl;
    cout << "|------------------  Delete Student Details  ------------------|" << endl;
    cout << "================================================================" << endl;

    file.open("stuRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }else{
        cout << "\nEnter Student Number of Student which you want Delete Data: ";
        cin >> num;
        file1.open("record.txt", ios::app | ios::out);
        file >> firstname >> lastname >> number >> age >> sex >> classyear >> faculty;
        while (num != number)
        {
            /* code */
        }

    }


}
main()
{
    student project;
    project.menu();
    return 0;
}