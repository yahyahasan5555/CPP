#include<iostream>
using namespace std;

int specializations[20] = {0};// there are only 20 specialization
string names[20][5];
bool status[20][5];

int menu()
{
    int choice = -1;
    while(true)
    {
        cout << "\nEnter your choice: \n"
             << "1) Add new patient.\n"
             << "2) Print all patients.\n"
             << "3) Get next patient.\n"
             << "4) Exit.\n";
        cin >> choice;

        // If the user entered a character
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, Please enter a number.\n";
            continue;
        }

        // If the usre entered a wrong number
        if(!(choice >= 1 && choice <= 4))
        {
            cout << "invalid choice, Try again.\n";
            continue;
        }

        return choice;
    }
}

void add_new_patient()
{
    int special;
    string name;
    bool st;
    
    while(true)
    {
        cout << "Enter specialization, name, and status (0 = regular, 1 = urgent): ";
        cin >> special >> name >> st;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, Try again.\n";
            continue;
        }
        
        if(!(special >= 1 && special <= 20))
        {
            cout << "Invalid specialization, there are only 20 ones.\n\t Try again\n";
            continue;
        }
        --special;// convert from 1-based to 0-based
        if(specializations[special] > 4)
        {
            cout << "There are not any places in this specialization.\n";
            break;
        }
      
        if(st)
        {
            for(int i = specializations[special] - 1; i >= 0; --i)// 0 1 1 2 3
            {
                names[special][i + 1] = names[special][i];
                status[special][i + 1] = status[special][i];
            }
            names[special][0] = name; 
            status[special][0] = st;
        }
        else
            names[special][specializations[special]] = name,
                status[special][specializations[special]] = st;

        ++specializations[special];
        break;
    } 
}

void print_patients()
{
    cout << "\n********************************************\n";
    for(int i = 0; i < 20; ++i)
    {
        if(specializations[i])
        {
            cout << "There are " << specializations[i] << " patients in specialization " << i + 1 << "\n";
            for(int j = 0; j < specializations[i]; ++j)
            {
                cout << names[i][j] << " ";

                if(status[i][j])
                    cout << "urgent.\n";
                else
                    cout << "regular.\n";
            }
            cout << "\n";
        }
    }
}

void get_next_patient()
{
    int sp;
    while(true)
    {
        cout << "Enter specialization: ";
        cin >> sp;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, Please enter a number of specialization.\n";
            continue;
        }

        if(!(sp >= 1 && sp <= 20))
        {
            cout << "Invalid number, Try again.\n";
            continue;
        }

        break;
    }
    
    if(specializations[--sp] == 0)
        cout << "No patient in this specialization at the moment.\n"
             << "You can have a rest, Dr.\n";
    else
    {
        cout << names[sp][0] << " Please, Go with the Dr.\n";
        for(int i = 0; i < specializations[sp] - 1; ++i)
        {
            names[sp][i] = names[sp][i + 1];
            status[sp][i] = status[sp][i + 1];
        }
        --specializations[sp];// remove this patient
    }

}

void hospital_system()
{
    while(true)
    {
        int ch = menu();
        if(ch == 1)
            add_new_patient();
        else if(ch == 2)
            print_patients();
        else if(ch == 3)
            get_next_patient();
        else
            break;  
    }

}

int main()
{
    hospital_system();
    return 0;
}