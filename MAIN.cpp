#include <iostream>
#include <fstream>
#include <conio.h>
#include <cmath>
#include <windows.h>
using namespace std;

// _____________________Prototypes________________

//______START MENU______//

void start();
char startmenu();

//______HEADINGS______//

void header();
void owner();
void admin();
void patient();

//______OWNER FUNCTIONS______//

char ownermain();
void ownerop1();
void ownerop2();
char ownerop3();
void ownerop4();
char ownerop6();
double calculator();
void ownerpassedit();
void adminpassedit();

//______ADMIN FUNCTIONS______//

char adminmain();
char adminop1();
char adminop2();
char adminop3();
void adminop4();
void adminop5();
char adminstaff();

//______PATIENT FUNCTIONS______//

char patientMenu();
char patientop1();
void patientop2();
void doctorchoose();
void feesrange();

//______DISPLAYING FUNCTIONS______//

void staffdisplay();
void ownerDdisplay();
void patientDdisplay();
void OwnerwardDisplay();
void patientwardDisplay();

//______SORTING FUNCTIONS______//

int salarysorting(int s);
int feessorting(int s);
int costsorting(int s);
void putDoctorsintoarray(string name, float salary, float fees, string time, float appointments);
void addWardintoarrays(string name, float cost, float expense, float room, float performed);

//______FILE HANDLING FUNCTIONS______//

void putdoctorintofile();
void putwardsintofiles();
void readdoctorsfromfiles();
void readwardsfromfiles();
string pareseRecord(string record, int field);
void addNameintofile();
void readNamefromfile();
void readStafffromfile();
void readpasswordsfromfile();
void putStaffintofile();
void addpasswordsintofile();
void WardAdd();

//______OTHER FUNCTIONS______//

void doctoredit();
void nurseedit();
void staffedit();
void manageredit();
void DoctorAdd();
void wardedit();
void StaffAdd();
void addWard();
void clearscreen();

//______COLOR FUNCTIONS______//

void red();
void white();
void yellow();
// end

//_____________________Data Structures_______________________//

string cname = " ";
int const max_records = 20;
string Dname[max_records];
double Dsalary[max_records];
double Dfees[max_records];
string Dtiming[max_records];
double Dappointments[max_records];
int dcount = 0;

int wcount = 0;
string Wname[max_records];
double Wcost[max_records];
double Wexpense[max_records];
double Wrooms[max_records];
double Wperformed[max_records];

double nurses;
double nsalary;

double staff;
double ssalary;

int management;
double msalary;

double electricity, gas, water, other;
string password;
double profit = 0;
string ownerpass = "owner", adminpass = "admin";

main()
{
    //_____________________MAIN_______________________//
    white();
    readdoctorsfromfiles();
    readwardsfromfiles();
    readNamefromfile();
    readpasswordsfromfile();
    readStafffromfile();
    while (true)
    {
        char option = ' ';
        option = startmenu();
        if (option == '1')
        {
            //_____________________OWNER_______________________//
            header();
            cout << "Enter Password: ";
            cin >> password;
            if (password == ownerpass)
            {
                while (true)
                {
                    char option = ' ';
                    option = ownermain();
                    if (option == '1')
                    {
                        //_______CHANGE NAME_______//
                        ownerop1();
                    }
                    else if (option == '2')
                    {
                        //_______VIEW STAFF_______//
                        ownerop2();
                        clearscreen();
                    }
                    else if (option == '3')
                    {
                        //_______EDIT STAFF_______//
                        while (true)
                        {
                            char option = ' ';
                            option = ownerop3();
                            if (option == '1')
                            {
                                doctoredit();
                            }
                            else if (option == '2')
                            {
                                nurseedit();
                            }
                            else if (option == '3')
                            {
                                staffedit();
                            }

                            else if (option == '4')
                            {
                                manageredit();
                            }

                            else if (option == '5')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                red();
                                cout << "INVALID INPUT" << endl;
                                clearscreen();
                                white();
                            }
                        }
                    }
                    else if (option == '4')
                    {
                        //_______VIEW WARDS_______//
                        ownerop4();
                    }
                    else if (option == '5')
                    {
                        //_______PROFIT CALCULATOR_______//
                        header();
                        owner();
                        profit = calculator();

                        if (profit >= 0)
                        {
                            cout << "Total Profit: " << profit << " Rupees" << endl;
                        }
                        else
                        {
                            cout << "Total Loss: " << profit * (-1) << " Rupees" << endl;
                        }
                        clearscreen();
                    }

                    else if (option == '6')
                    {
                        //_______EDIT PASSWORDS_______//
                        while (true)
                        {
                            char edit = ' ';
                            edit = ownerop6();

                            if (edit == '1')
                            {
                                ownerpassedit();
                            }
                            else if (edit == '2')
                            {
                                adminpassedit();
                            }

                            else if (edit == '3')
                            {
                                clearscreen();
                                break;
                            }

                            else
                            {
                                red();
                                cout << "INVALID INPUT " << endl;
                                clearscreen();
                                white();
                            }
                        }
                    }

                    else if (option == '7')
                    {
                        //_______EXIT_______//
                        clearscreen();
                        break;
                    }

                    else
                    {
                        red();
                        cout << "INVALID INPUT" << endl;
                        clearscreen();
                        white();
                    }
                }
            }
            else
            {
                red();
                cout << "Wrong Password..." << endl;
                clearscreen();
                white();
            }
        }
        else if (option == '2')
        {
            //_____________________ADMIN_______________________//
            header();
            cout << "Enter Password: ";
            cin >> password;
            if (password == adminpass)
            {
                while (true)
                {
                    char option = ' ';
                    option = adminmain();
                    if (option == '1')
                    {
                        //_______VIEW / EDIT DOCTORS_______//
                        while (true)
                        {
                            char op = ' ';
                            op = adminop1();
                            if (op == '1')
                            {
                                DoctorAdd();
                            }
                            else if (op == '2')
                            {
                                doctoredit();
                            }
                            else if (op == '3')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                red();
                                cout << "INVALID INPUT" << endl;
                                clearscreen();
                                white();
                            }
                        }
                    }
                    else if (option == '2')
                    {
                        //_______VIEW / EDIT WARDS_______//
                        while (true)
                        {
                            char w = ' ';
                            w = adminop2();
                            if (w == '1')
                            {
                                WardAdd();
                            }
                            else if (w == '2')
                            {
                                wardedit();
                            }
                            else if (w == '3')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                red();
                                cout << "INVALID INPUT" << endl;
                                clearscreen();
                                white();
                            }
                        }
                    }
                    else if (option == '3')
                    {
                        //_______VIEW / EDIT STAFF_______//
                        while (true)
                        {
                            char c = ' ';
                            c = adminop3();
                            if (c == '1')
                            {
                                StaffAdd();
                            }
                            else if (c == '2')
                            {
                                while (true)
                                {
                                    char edit = ' ';
                                    edit = adminstaff();
                                    if (edit == '1')
                                    {
                                        doctoredit();
                                    }
                                    else if (edit == '2')
                                    {
                                        nurseedit();
                                    }
                                    else if (edit == '3')
                                    {
                                        staffedit();
                                    }

                                    else if (edit == '4')
                                    {
                                        manageredit();
                                    }

                                    else if (edit == '5')
                                    {
                                        clearscreen();
                                        break;
                                    }
                                    else
                                    {
                                        red();
                                        cout << "INVALID INPUT" << endl;
                                        clearscreen();
                                        white();
                                    }
                                }
                            }
                            else if (c == '3')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                red();
                                cout << "INVALID INPUT" << endl;
                                clearscreen();
                                white();
                            }
                        }
                    }
                    else if (option == '4')
                    {
                        //_______AVAILABLE ROOMS EDIT_______//
                        adminop4();
                    }

                    else if (option == '5')
                    {
                        //_______APPOINTMENTS EDIT_______//
                        adminop5();
                    }

                    else if (option == '6')
                    {
                        //_______EXIT_______//
                        clearscreen();
                        break;
                    }

                    else
                    {
                        red();
                        cout << "INVALID INPUT" << endl;
                        clearscreen();
                        white();
                    }
                }
            }
            else
            {
                red();
                cout << "Wrong Password..." << endl;
                clearscreen();
                white();
            }
        }
        else if (option == '3')
        {
            //_____________________PATIENT_______________________//
            while (true)
            {
                char option = ' ';
                option = patientMenu();
                if (option == '1')
                {
                    //_______TAKE APPOINTMENT WITH DOCTOR_______//
                    while (true)
                    {
                        char option;
                        option = patientop1();

                        if (option == '1')
                        {
                            //_______CHOOSE DOCTOR IN FEES RANGE_______//
                            feesrange();
                        }
                        else if (option == '2')
                        {
                            //_______CHOOSE FROM ALL DOCTORS_______//
                            doctorchoose();
                        }
                        else if (option == '3')
                        {
                            //_______EXIT_______//
                            clearscreen();
                            break;
                        }
                        else
                        {
                            red();
                            cout << "INVALID INPUT" << endl;
                            clearscreen();
                            white();
                        }
                    }
                }
                else if (option == '2')
                {
                    //_______APPLY FOR TREATMENT_______//
                    patientop2();
                }
                else if (option == '3')
                {
                    //_______EXIT_______//
                    clearscreen();
                    break;
                }
                else
                {
                    red();
                    cout << "INVALID INPUT" << endl;
                    clearscreen();
                    white();
                }
            }
        }
        else if (option == '4')
        {
            //_______EXIT_______//
            yellow();
            cout << "Thank You for using my application :)" << endl;
            clearscreen();
            white();
            break;
        }
        else
        {
            red();
            cout << "INVALID INPUT" << endl;
            clearscreen();
            white();
        }
    }
    putdoctorintofile();
    putwardsintofiles();
    addpasswordsintofile();
    putStaffintofile();
}

//__________________________ Function definitions_____________//

//______START MENU______//

void start()
{
    system("cls");
    cout << "Please Enter the Name of the Clinic: ";
    cin >> cname;
    system("cls");
    addNameintofile();
}

char startmenu()
{
    char op;
    header();
    cout << endl;
    cout << endl;
    cout << "1. Owner" << endl;
    cout << "2. Admin" << endl;
    cout << "3. Patient" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Which Option you want to Choose: " << endl;
    cout << endl;
    cin >> op;
    return op;
}

//______HEADINGS______//

void header()
{
    system("cls");
    cout << "                        *******************************************************************************" << endl;
    cout << endl;
    cout << "                                               " << cname << " CLINIC MANAGEMENT SYSTEM" << endl;
    cout << endl;
    cout << "                        *******************************************************************************" << endl;
}

void owner()
{
    yellow();
    cout << endl;
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "-----------------------OWNER-----------------------" << endl;
    cout << endl;
    cout << endl;
    white();
}

void admin()
{
    yellow();
    cout << endl;
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "-----------------------ADMIN-----------------------" << endl;
    cout << endl;
    cout << endl;
    white();
}

void patient()
{
    yellow();
    cout << endl;
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "-----------------------PATIENT-----------------------" << endl;
    cout << endl;
    cout << endl;
    white();
}

//______OWNER FUNCTIONS______//

char ownermain()
{
    char opt;
    header();
    owner();
    cout << endl;
    cout << "1. Change name of Clinic " << endl;
    cout << "2. View Staff" << endl;
    cout << "3. Edit staff" << endl;
    cout << "4. View Wards" << endl;
    cout << "5. Total Profit" << endl;
    cout << "6. Change Password" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Which option you want to choose: ";
    cin >> opt;
    return opt;
}

void ownerop1()
{
    header();
    owner();
    cout << "Enter Name Of The Clinic: ";
    cin.clear();
    cin.sync();
    getline(cin, cname);
    addNameintofile();
}

void ownerop2()
{
    header();
    owner();
    ownerDdisplay();
    staffdisplay();
}

char ownerop3()
{
    char staffedit;
    header();
    owner();
    cout << endl;
    cout << endl;
    cout << "Which staff you want to edit?" << endl;
    cout << endl;
    cout << endl;
    cout << "1. Doctors" << endl;
    cout << "2. Nurses" << endl;
    cout << "3. Cleaning" << endl;
    cout << "4. Management" << endl;
    cout << "5. Exit" << endl;
    cin >> staffedit;
    return staffedit;
}

void ownerop4()
{
    header();
    owner();
    OwnerwardDisplay();
    clearscreen();
}

char ownerop6()
{
    char passedit;
    header();
    owner();
    cout << endl;
    cout << endl;
    cout << "Which password you want to change" << endl;
    cout << endl;
    cout << "1. Owner Password" << endl;
    cout << "2. Admin Password" << endl;
    cout << "3. Exit" << endl;
    cin >> passedit;
    return passedit;
}

double calculator()
{
    cout << "Enter Electricity Bills: ";
    cin >> electricity;
    cout << "Enter Gas Bills: ";
    cin >> gas;
    cout << "Enter Water Bills: ";
    cin >> water;
    cout << "Enter Other Bills: ";
    cin >> other;

    // profit formula
    double d = 0;
    for (int i = 0; i < dcount; i++)
    {
        d = d + (Dsalary[i] - (Dfees[i] * Dappointments[i]));
    }
    double w = 0;
    for (int i = 0; i < wcount; i++)
    {
        w = w + ((Wcost[i] - Wexpense[i]) * Wperformed[i]);
    }
    double expenditure = gas + water + electricity + other + nsalary + msalary + ssalary;
    double earning = d + w;
    double profit = earning - expenditure;
    return profit;
}

void ownerpassedit()
{
    int flag = 0;
    string oldpass, newpass;
    header();
    owner();
    cout << endl;
    cout << endl;
    cout << "Enter current password: ";
    cin >> oldpass;

    if (oldpass == ownerpass)
    {
        cout << endl;
        cout << "Enter new password: ";
        cin >> newpass;

        for (int i = 0; newpass[i] != '\0'; i++)
        {
            if (newpass[i] == '!' || newpass[i] == '@' || newpass[i] == '#' || newpass[i] == '$' || newpass[i] == '%' || newpass[i] == '^' || newpass[i] == '&' || newpass[i] == '*' || newpass[i] == '(' || newpass[i] == ')')
            {
                flag = 1;
            }
        }

        if (flag != 1)
        {
            while (flag != 1)
            {
                cout << "Please Use Special Characters in your Password" << endl;
                cin >> newpass;
                for (int k = 0; newpass[k] != '\0'; k++)
                {
                    if (newpass[k] == '!' || newpass[k] == '@' || newpass[k] == '#' || newpass[k] == '$' || newpass[k] == '%' || newpass[k] == '^' || newpass[k] == '&' || newpass[k] == '*' || newpass[k] == '(' || newpass[k] == ')')
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        ownerpass = newpass;
    }

    else
    {
        red();
        cout << "Wrong Password" << endl;
        clearscreen();
        white();
    }
}

void adminpassedit()
{
    int flag = 0;
    string oldpass, newpass;
    header();
    owner();
    cout << endl;
    cout << endl;
    cout << "Enter current password: ";
    cin >> oldpass;

    if (oldpass == adminpass)
    {
        cout << endl;
        cout << "Enter new password: ";
        cin >> newpass;

        for (int i = 0; newpass[i] != '\0'; i++)
        {
            if (newpass[i] == '!' || newpass[i] == '@' || newpass[i] == '#' || newpass[i] == '$' || newpass[i] == '%' || newpass[i] == '^' || newpass[i] == '&' || newpass[i] == '*' || newpass[i] == '(' || newpass[i] == ')')
            {
                flag = 1;
            }
        }

        if (flag != 1)
        {
            while (flag != 1)
            {
                cout << "Please Use Special Characters in your Password" << endl;
                cin >> newpass;
                for (int k = 0; newpass[k] != '\0'; k++)
                {
                    if (newpass[k] == '!' || newpass[k] == '@' || newpass[k] == '#' || newpass[k] == '$' || newpass[k] == '%' || newpass[k] == '^' || newpass[k] == '&' || newpass[k] == '*' || newpass[k] == '(' || newpass[k] == ')')
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        adminpass = newpass;
    }

    else
    {
        red();
        cout << "Wrong Password" << endl;
        clearscreen();
        white();
    }
}

//______ADMIN FUNCTIONS______//

char adminmain()
{
    char A = ' ';
    header();
    admin();
    cout << endl;
    cout << endl;
    cout << "1. Add / Edit Doctors" << endl;
    cout << "2. Add / Edit Types of Wards" << endl;
    cout << "3. Add / Edit Staff" << endl;
    cout << "4. Edit Available Rooms in Wards" << endl;
    cout << "5. Edit Appointments of Doctors" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "Which Option you want to Chose: ";
    cin >> A;
    return A;
}

char adminop1()
{
    char o;
    header();
    admin();
    ownerDdisplay();
    cout << endl;
    cout << endl;
    cout << "1. Add Doctor " << endl;
    cout << "2. Edit Doctor" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Choose any option: ";
    cin >> o;
    return o;
}

char adminop2()
{
    char t = ' ';
    header();
    admin();
    OwnerwardDisplay();
    cout << endl;
    cout << endl;
    cout << "1. Add Ward" << endl;
    cout << "2. Edit Ward" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Choose any option: ";
    cin >> t;
    return t;
}

char adminop3()
{
    header();
    char a;
    admin();
    staffdisplay();
    cout << endl;
    cout << endl;
    cout << "1. Add Staff" << endl;
    cout << "2. Edit Staff" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Choose any option: ";
    cin >> a;
    return a;
}

void adminop4()
{
    while (true)
    {
        int edit;
        header();
        admin();
        for (int i = 0; i < wcount; i++)
        {
            cout << i + 1 << " " << Wname[i] << '\t' << "Available Rooms: " << Wrooms[i] << endl;
        }

        cout << endl;
        cout << endl;
        cout << "Which Ward's Rooms You Want to Edit(press 0 to exit): ";
        cin >> edit;

        if (edit <= wcount && edit > 0)
        {
            cout << "Enter Rooms Available in " << Wname[edit - 1] << " :";
            cin >> Wrooms[edit - 1];
            clearscreen();
            break;
        }
        else if (edit == 0)
        {
            clearscreen();
            break;
        }

        else
        {
            red();
            cout << "INVALID INPUT" << endl;
            clearscreen();
            white();
        }
    }
}

void adminop5()
{
    while (true)
    {
        int edit;
        header();
        admin();
        for (int i = 0; i < dcount; i++)
        {
            cout << i + 1 << " " << Dname[i] << '\t' << " Appointments: " << Dappointments[i] << endl;
        }

        cout << endl;
        cout << endl;
        cout << "Which Doctor's Appointments You Want To Edit(press 0 to exit): ";
        cin >> edit;

        if (edit <= dcount && edit > 0)
        {
            cout << "Enter Appointments of " << Dname[edit - 1] << " :";
            cin >> Dappointments[edit - 1];
            clearscreen();
            break;
        }
        else if (edit == 0)
        {
            clearscreen();
            break;
        }
        else
        {
            red();
            cout << "INVALID INPUT" << endl;
            clearscreen();
            white();
        }
    }
}

char adminstaff()
{
    char staffedit;
    header();
    owner();
    cout << endl;
    cout << endl;
    cout << "Which staff you want to edit?" << endl;
    cout << endl;
    cout << endl;
    cout << "1. Doctors" << endl;
    cout << "2. Nurses" << endl;
    cout << "3. Cleaning" << endl;
    cout << "4. Management" << endl;
    cout << "5. Exit" << endl;
    cin >> staffedit;
    return staffedit;
}

//______PATIENT FUNCTIONS______//

char patientMenu()
{
    char c;
    header();
    patient();
    cout << "1. Take an Appointment" << endl;
    cout << "2. Apply for a Treatment" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Choose any option: ";
    cin >> c;
    return c;
}

char patientop1()
{
    char option;
    header();
    patient();
    cout << "Choose one option" << endl;
    cout << endl;
    cout << "1. Choose Doctors in your Fees Range" << endl;
    cout << "2. Choose from all Doctors" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
    return option;
}

void feesrange()
{
    while (true)
    {
        int range, appointment, count = 0;
        header();
        patient();
        cout << "Enter You Fees Range: ";
        cin >> range;
        for (int i = 0; i < dcount; i++)
        {
            if (Dfees[i] <= range)
            {
                cout << i + 1 << "- " << Dname[i] << '\t';
                cout << "Fees: " << Dfees[i] << '\t';
                cout << "Timing: " << Dtiming[i] << endl;
                count++;
            }
        }
        if (count == 0)
        {
            red();
            cout << "There are no Doctors in that Range" << endl;
            clearscreen();
            white();
            break;
        }
        cout << endl;
        cout << endl;
        cout << "With which Doctor do you want to take an appointment (press 0 to exit): ";
        cin >> appointment;
        if (appointment <= dcount && appointment > 0)
        {
            if (Dfees[appointment - 1] <= range)
            {
                Dappointments[appointment - 1] = Dappointments[appointment - 1] + 1;
                yellow();
                cout << "You Appointment has been made." << endl;
                clearscreen();
                white();
                break;
            }
            else
            {
                red();
                cout << "INVALID INPUT" << endl;
                clearscreen();
                white();
            }
        }
        else if (appointment == 0)
        {
            break;
        }
        else
        {
            red();
            cout << "INVALID INPUT" << endl;
            clearscreen();
            white();
        }
    }
}

void doctorchoose()
{
    while (true)
    {
        int appointment;
        header();
        patient();
        patientDdisplay();
        cout << endl;
        cout << endl;
        cout << "With which Doctor do you want to take an appointment (press 0 to exit): ";
        cin >> appointment;
        if (appointment <= dcount && appointment > 0)
        {
            Dappointments[appointment - 1] = Dappointments[appointment - 1] + 1;
            yellow();
            cout << "You Appointment has been made." << endl;
            clearscreen();
            white();
            break;
        }
        if (appointment == 0)
        {
            clearscreen();
            break;
        }
        else
        {
            red();
            cout << "INVALID INPUT" << endl;
            clearscreen();
            white();
        }
    }
}

void patientop2()
{
    while (true)
    {
        int treatment;
        header();
        patient();
        patientwardDisplay();
        cout << endl;
        cout << endl;
        cout << "Which treatment you want to apply (press 0 to exit): ";
        cin >> treatment;
        if (treatment <= dcount && treatment > 0)
        {
            Wperformed[treatment - 1] = Wperformed[treatment - 1] + 1;
            Wrooms[treatment - 1] = Wrooms[treatment - 1] - 1;
            yellow();
            cout << "You Appointment has been made." << endl;
            clearscreen();
            white();
            break;
        }
        else if (treatment == 0)
        {
            clearscreen();
            break;
        }
        else
        {
            red();
            cout << "INVALID INPUT" << endl;
            clearscreen();
            white();
        }
    }
}

//______DISPLAYING FUNCTIONS______//

void staffdisplay()
{
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "                      NURSES" << endl;
    cout << endl;
    cout << endl;
    cout.setf(ios::left);
    cout << "Total Nurses: ";
    cout.width(60);
    cout << nurses;
    cout << "Salary: ";
    cout.width(60);
    cout << nsalary << endl;
    cout << endl;
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "                    CLEANING STAFF" << endl;
    cout << endl;
    cout << endl;
    cout << "Total Cleaning Staff: ";
    cout.width(52);
    cout << staff;
    cout << "Salary: ";
    cout.width(30);
    cout << ssalary << endl;
    cout << endl;
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "                   MANAGEMENT STAFF" << endl;
    cout << endl;
    cout << endl;
    cout << "Total Management Staff: ";
    cout.width(50);
    cout << management;
    cout << "Salary: ";
    cout.width(30);
    cout << msalary << endl;
    cout << endl;
    cout << endl;
}

void ownerDdisplay()
{
    string temps = " ", timing = " ";
    double temp, fees, appointments;
    int index;
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "                      DOCTORS" << endl;
    cout << endl;
    cout << endl;
    for (int s = 0; s < dcount; s++)
    {
        index = salarysorting(s);
        temp = Dsalary[index];
        Dsalary[index] = Dsalary[s];
        Dsalary[s] = temp;

        temps = Dname[index];
        Dname[index] = Dname[s];
        Dname[s] = temps;

        timing = Dtiming[index];
        Dtiming[index] = Dtiming[s];
        Dtiming[s] = timing;

        fees = Dfees[index];
        Dfees[index] = Dfees[s];
        Dfees[s] = fees;

        appointments = Dappointments[index];
        Dappointments[index] = Dappointments[s];
        Dappointments[s] = appointments;
    }

    for (int i = 0; i < dcount; i++)
    {
        cout.setf(ios::left);
        cout << i + 1 << "- ";
        cout.width(30);
        cout << Dname[i];
        // cout.width(30);
        cout << "Fees: ";
        cout.width(30);
        cout << Dfees[i];
        cout << "Appointments: ";
        cout.width(30);
        cout << Dappointments[i];
        cout << "Timing: ";
        cout.width(30);
        cout << Dtiming[i];
        cout << "Salary: ";
        cout.width(30);
        cout << Dsalary[i] << endl;
    }
    cout << endl;
}

void patientDdisplay()
{
    string temps = " ", timing = " ";
    double temp, fees, appointments;
    int index;
    for (int s = 0; s < dcount; s++)
    {
        index = feessorting(s);
        temp = Dsalary[index];
        Dsalary[index] = Dsalary[s];
        Dsalary[s] = temp;

        temps = Dname[index];
        Dname[index] = Dname[s];
        Dname[s] = temps;

        timing = Dtiming[index];
        Dtiming[index] = Dtiming[s];
        Dtiming[s] = timing;

        fees = Dfees[index];
        Dfees[index] = Dfees[s];
        Dfees[s] = fees;

        appointments = Dappointments[index];
        Dappointments[index] = Dappointments[s];
        Dappointments[s] = appointments;
    }

    for (int i = 0; i < dcount; i++)
    {
        cout.setf(ios::left);
        cout << i + 1 << "- ";
        cout.width(30);
        cout << Dname[i];
        // cout.width(30);
        cout << "Fees: ";
        cout.width(30);
        cout << Dfees[i];
        cout << "Timing: ";
        cout.width(30);
        cout << Dtiming[i] << endl;
    }
}

void OwnerwardDisplay()
{
    int index;
    double temp, expense, room, performed;
    string temps = " ";
    cout << endl;
    cout << "\t"
         << "\t"
         << "\t"
         << "\t"
         << "                      WARDS" << endl;
    cout << endl;
    cout << endl;
    for (int s = 0; s < wcount; s++)
    {
        index = costsorting(s);
        temp = Wcost[index];
        Wcost[index] = Wcost[s];
        Wcost[s] = temp;

        temps = Wname[index];
        Wname[index] = Wname[s];
        Wname[s] = temps;

        expense = Wexpense[index];
        Wexpense[index] = Wexpense[s];
        Wexpense[s] = expense;

        room = Wrooms[index];
        Wrooms[index] = Wrooms[s];
        Wrooms[s] = room;

        performed = Wperformed[index];
        Wperformed[index] = Wperformed[s];
        Wperformed[s] = performed;
    }

    for (int i = 0; i < wcount; i++)
    {
        cout.setf(ios::left);
        cout << i + 1 << "- ";
        cout.width(30);
        cout << Wname[i];
        cout << "Cost(for patient): ";
        cout.width(30);
        cout << Wcost[i];
        cout << "Expenses: ";
        cout.width(30);
        cout << Wexpense[i];
        cout << "Available Rooms: ";
        cout.width(30);
        cout << Wrooms[i];
        cout << "Performed: ";
        cout.width(30);
        cout << Wperformed[i] << endl;
    }
    cout << endl;
}

void patientwardDisplay()
{
    int index;
    double temp, expense, room, performed;
    string temps = " ";
    for (int s = 0; s < wcount; s++)
    {
        index = costsorting(s);
        temp = Wcost[index];
        Wcost[index] = Wcost[s];
        Wcost[s] = temp;

        temps = Wname[index];
        Wname[index] = Wname[s];
        Wname[s] = temps;

        expense = Wexpense[index];
        Wexpense[index] = Wexpense[s];
        Wexpense[s] = expense;

        room = Wrooms[index];
        Wrooms[index] = Wrooms[s];
        Wrooms[s] = room;

        performed = Wperformed[index];
        Wperformed[index] = Wperformed[s];
        Wperformed[s] = performed;
    }

    for (int i = 0; i < wcount; i++)
    {
        cout.setf(ios::left);
        cout << i + 1 << "- ";
        cout.width(30);
        cout << Wname[i];
        cout << "Cost: ";
        cout.width(30);
        cout << Wcost[i] << '\t';
        cout << "Available Rooms: ";
        cout.width(30);
        cout << Wrooms[i] << endl;
    }
}
//______SORTING FUNCTIONS______//

int salarysorting(int s)
{
    int largest = -1;
    int idx;
    for (int i = s; i < dcount; i++)
    {
        if (largest < Dsalary[i])
        {
            largest = Dsalary[i];
            idx = i;
        }
    }
    return idx;
}

int feessorting(int s)
{
    int largest = -1;
    int idx;
    for (int i = s; i < dcount; i++)
    {
        if (largest < Dfees[i])
        {
            largest = Dfees[i];
            idx = i;
        }
    }
    return idx;
}

int costsorting(int s)
{
    int largest = -1;
    int idx;
    for (int i = s; i < wcount; i++)
    {
        if (largest < Wcost[i])
        {
            largest = Wcost[i];
            idx = i;
        }
    }
    return idx;
}

void putDoctorsintoarray(string name, float salary, float fees, string time, float appointments)
{
    Dname[dcount] = name;
    Dsalary[dcount] = salary;
    Dfees[dcount] = fees;
    Dtiming[dcount] = time;
    Dappointments[dcount] = appointments;
    dcount++;
}

void addWardintoarrays(string name, float cost, float expense, float room, float performed)
{
    Wname[wcount] = name;
    Wrooms[wcount] = room;
    Wcost[wcount] = cost;
    Wperformed[wcount] = performed;
    Wexpense[wcount] = expense;
    wcount++;
}

//______FILE HANDLING FUNCTIONS______//

void putdoctorintofile()
{
    fstream file;
    file.open("doctors.txt", ios::out);
    for (int i = 0; i < dcount; i++)
    {
        if (i > 0)
        {
            file << endl;
        }

        file << Dname[i] << "," << Dsalary[i] << "," << Dfees[i] << "," << Dtiming[i] << "," << Dappointments[i];
    }
    file.close();
}

void putwardsintofiles()
{
    fstream file;
    file.open("wards.txt", ios::out);
    for (int i = 0; i < wcount; i++)
    {
        if (i > 0)
        {
            file << endl;
        }
        file << Wname[i] << "," << Wcost[i] << "," << Wexpense[i] << "," << Wrooms[i] << "," << Wperformed[i];
    }
    file.close();
}

void readdoctorsfromfiles()
{
    string name, time, value;
    float salary, fees, appointment;
    fstream file;
    dcount = 0;
    file.open("doctors.txt", ios::in);
    while (!file.eof())
    {
        getline(file, value);
        name = pareseRecord(value, 1);
        salary = stof(pareseRecord(value, 2));
        fees = stof(pareseRecord(value, 3));
        time = pareseRecord(value, 4);
        appointment = stof(pareseRecord(value, 5));
        putDoctorsintoarray(name, salary, fees, time, appointment);
    }
    file.close();
}

void readwardsfromfiles()
{
    string name, value;
    float room, cost, expense, performed;
    fstream file;
    wcount = 0;
    file.open("wards.txt", ios::in);
    while (!file.eof())
    {
        getline(file, value);
        name = pareseRecord(value, 1);
        cost = stof(pareseRecord(value, 2));
        expense = stof(pareseRecord(value, 3));
        room = stof(pareseRecord(value, 4));
        performed = stof(pareseRecord(value, 5));
        addWardintoarrays(name, cost, expense, room, performed);
    }
    file.close();
}

string pareseRecord(string record, int field)
{
    int commacount = 1;
    string item;

    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            commacount++;
        }
        else if (commacount == field)
        {
            item = item + record[i];
        }
    }
    return item;
}

void addNameintofile()
{
    fstream file;
    file.open("name.txt", ios::out);
    file << cname;
    file.close();
}

void readNamefromfile()
{
    fstream file;
    file.open("name.txt", ios::in);
    getline(file, cname);
    file.close();
}

void putStaffintofile()
{
    fstream file;
    file.open("staff.txt", ios::out);
    file << nurses << "," << nsalary << "," << staff << "," << ssalary << "," << management << "," << msalary;
    file.close();
}

void readStafffromfile()
{
    fstream file;
    string value;
    file.open("staff.txt", ios::in);
    getline(file, value);
    nurses = stod(pareseRecord(value, 1));
    nsalary = stod(pareseRecord(value, 2));
    staff = stod(pareseRecord(value, 3));
    ssalary = stod(pareseRecord(value, 4));
    management = stod(pareseRecord(value, 5));
    msalary = stod(pareseRecord(value, 6));
    file.close();
}

void addpasswordsintofile()
{
    fstream file;
    file.open("passwords.txt", ios::out);
    file << ownerpass << ',' << adminpass;
    file.close();
}

void readpasswordsfromfile()
{
    fstream file;
    string value;
    file.open("passwords.txt", ios::in);
    getline(file, value);
    ownerpass = pareseRecord(value, 1);
    adminpass = pareseRecord(value, 2);
    file.close();
}

//______OTHER FUNCTIONS______//

void doctoredit()
{
    int doctoredit;
    cout << "Which Doctor you want to edit: ";
    cin >> doctoredit;
    cout << endl;
    if (doctoredit <= dcount && doctoredit > 0)
    {
        cout << "Enter Doctor's Name: ";
        cin.clear();
        cin.sync();
        getline(cin, Dname[doctoredit - 1]);
        cout << "Enter Salary: ";
        cin >> Dsalary[doctoredit - 1];
        cout << "Enter Appointment Fees: ";
        cin >> Dfees[doctoredit - 1];
        cout << "Enter On Duty Hours: ";
        cin.clear();
        cin.sync();
        getline(cin, Dtiming[doctoredit - 1]);
        cout << "Enter Total Appointments: ";
        cin >> Dappointments[doctoredit - 1];
    }
    else
    {
        cout << "INVALID INPUT" << endl;
        clearscreen();
    }
}

void nurseedit()
{
    cout << "Enter Total Nurses: ";
    cin >> nurses;
    cout << "Enter Salary of a Nurse: ";
    cin >> nsalary;
}

void staffedit()
{
    cout << "Enter Total Cleaning Staff: ";
    cin >> staff;
    cout << "Enter Salary of 1 Cleaner: ";
    cin >> ssalary;
}

void manageredit()
{
    cout << "Enter Total Management Staff: ";
    cin >> management;
    cout << "Enter Salary of a Manager: ";
    cin >> msalary;
}

void DoctorAdd()
{
    string Dname, dtime;
    float Dsalary, Dfees, appointments = 0;
    cout << "Enter Doctor Name: ";
    cin.clear();
    cin.sync();
    getline(cin, Dname);
    cout << "Enter Salary: ";
    cin >> Dsalary;
    cout << "Enter Appointment Fees: ";
    cin >> Dfees;
    cout << "Enter On Duty Hours: ";
    cin.clear();
    cin.sync();
    getline(cin, dtime);
    putDoctorsintoarray(Dname, Dsalary, Dfees, dtime, appointments);
}

void WardAdd()
{
    string ward;
    float expense, wrooms, wcost, performed = 0;
    cout << endl;
    cout << endl;
    cout << "Enter Name of Ward : ";
    cin.clear();
    cin.sync();
    getline(cin, ward);
    cout << "Enter Available Rooms in Ward : ";
    cin >> wrooms;
    cout << "Enter the Treatment Cost: ";
    cin >> wcost;
    cout << "Enter Treatment Expenses For Clinic: ";
    cin >> expense;
    addWardintoarrays(ward, wcost, expense, wrooms, performed);
}

void wardedit()
{
    int doctoredi;
    cout << "Which Ward you want to edit: ";
    cin >> doctoredi;
    cout << endl;
    if (doctoredi <= wcount && doctoredi > 0)
    {
        cout << "Enter Ward's Name: ";
        cin.clear();
        cin.sync();
        getline(cin, Wname[doctoredi - 1]);
        cout << "Enter Cost for Patients: ";
        cin >> Wcost[doctoredi - 1];
        cout << "Enter Expenses for Clinic: ";
        cin >> Wexpense[doctoredi - 1];
        cout << "Enter Available Rooms: ";
        cin >> Wrooms[doctoredi - 1];
        cout << "Enter Treatment Performed: ";
        cin >> Wperformed[doctoredi - 1];
    }
    else
    {
        red();
        cout << "INVALID INPUT" << endl;
        clearscreen();
        white();
    }
}

void StaffAdd()
{
    cout << "Enter Total Nurses: " << endl;
    cin >> nurses;
    cout << "Enter Salary of a Nurse: " << endl;
    cin >> nsalary;
    cout << "Enter Total Cleaning Staff: " << endl;
    cin >> staff;
    cout << "Enter Salary of a Cleaner: " << endl;
    cin >> ssalary;
    cout << "Enter Total Managers: " << endl;
    cin >> management;
    cout << "Enter Salary of a Manager: " << endl;
    cin >> msalary;
}

void addWard()
{
    header();
    for (int i = 0; i < wcount; i++)
    {
        cout << "Enter Ward's Name: ";
        cin >> Wname[i];
        cout << "Enter Cost: ";
        cin >> Wcost[i];
        cout << "Enter Expenses for the Clinic: ";
        cin >> Wexpense[i];
        cout << "Enter Available Rooms: ";
        cin >> Wrooms[i];
        cout << "Enter Treatments Performed: ";
        cin >> Wperformed[i];
    }
    wcount++;
}

void clearscreen()
{
    cout << "Enter Any Key to Continue...." << endl;
    getch();
    system("cls");
}

void red()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        console_color, 4);
}

void yellow()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        console_color, 6);
}

void white()
{
    system("Color 07");
}