#include<iostream>
#include<string>
#include<fstream>
#include"A5.cpp"
#include<windows.h>
using namespace std;

Gym* gymArr;
int gymsize = 0;

Equipment *eArr;
int eSize = 0;

Customer* customerArr;
int customerSize = 0;

Trainer* trainerArr;
int trainerSize = 0;




void Display();
//  Methods for adding Trainers, Customers,Equipments, and Gyms
void AddCustomer();

void AddTrainer();

void createGym(Gym* &arr,int &size,Equipment* eArr,int eSize);

void createEquipment(Equipment *&eArr,int &eSize);

// End



// Functions for Loggin Admin,Trainer, Customer
void loginAdmin();
 // Adds & Deletes Customers & Trainers
 
void CustomerPanel();

void loginTrainer();

// end

// Function for registering
void signUp();

void signIn();

void initialize();

void finalize(); 


int main() {
    
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 7);
    cout << "=============================================\n";
    SetConsoleTextAttribute(console_color, 13);
    cout << "<><><>";
    SetConsoleTextAttribute(console_color, 3);
    cout << "Welcome to GYM MANAGEMENT SYSTEM";
    SetConsoleTextAttribute(console_color, 13);
    cout << "<><><>\n";
    SetConsoleTextAttribute(console_color, 6);
    cout << "                       Faraz Majid | 20L-1162\n";
    cout << "                   Muhammad Meeran | 20L-2111\n";
    SetConsoleTextAttribute(console_color, 7);
    cout << "=============================================\n\n\n";

   // system("Color 02");
    
    do {
        int mChoice;
        SetConsoleTextAttribute(console_color, 7);
        cout << "Please select one of the Choices\n";
        SetConsoleTextAttribute(console_color, 9);
        cout << "[1]"<< " Register\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "[2]"<< " Login\n";
        SetConsoleTextAttribute(console_color, 13);
        cout << "[3]" << " Insert Equipments\n";
        SetConsoleTextAttribute(console_color, 12);
        cout << "[4]" << " Load from .txt\n";
        SetConsoleTextAttribute(console_color, 3);
        cout << "[5]" << " Print Loaded Data\n";
        SetConsoleTextAttribute(console_color, 4);
        cout << "[6]" << " Delete\n"; // ?????????
        SetConsoleTextAttribute(console_color, 2);
        cout << "[7]" <<" Exit System\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "-> ";
        SetConsoleTextAttribute(console_color, 7);
        cin >> mChoice;
        switch (mChoice) {
            case 1: {
                signUp();
                break;
            }
            case 2: {
                signIn();
                break;
            }
            case 3: {
                createEquipment(eArr,eSize);
                break;
            }
            case 4: {
                initialize();
                break;
            }
            case 5: {
                Display();
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                SetConsoleTextAttribute(console_color, 7);
                cout << "=============================================\n";
                SetConsoleTextAttribute(console_color, 6);
                cout << "                    BYE :)\n";
                SetConsoleTextAttribute(console_color, 7);
                cout << "=============================================\n"; 
                SetConsoleTextAttribute(console_color, 3);
                cout << "                       Faraz Majid | 20L-1162\n";
                cout << "                   Muhammad Meeran | 20L-2111\n";
                SetConsoleTextAttribute(console_color, 7);
                cout << "=============================================\n";
                break;
            }
            default: {
                cout << "Invalid";
                break;
            }      
        }
        if (mChoice >6) break;
    } while(1);
    finalize();
    return 0;
}

void AddCustomer(){
    cout << "Enter the Customer Name : ";
    string name; cin >>name;
    cout << "Enter the Address Name : ";
    string address; cin >>address;
    cout << "Enter the Phone : ";
    string phone; cin >>phone;
    cout << "Enter the Email : ";
    string email; cin >>email;

    Customer obj(customerSize,name,address,phone,email);
    updateArray(customerArr,customerSize);
    customerArr[customerSize-1] = obj;
    //delete[] customerArr;
}

void AddTrainer(){

    cout << "Enter the Trainer Name : ";
    string name; cin >>name;
    cout << "Enter the Trainer Email : ";
    string email; cin >>email;
    Trainer obj(trainerSize,name,email);
    updateArray(trainerArr,trainerSize);
    trainerArr[trainerSize-1] = obj;
}

void createGym(Gym* &arr,int &size,Equipment* eArr,int eSize) {
    cout << "Enter the Gym Name : " ;
    string name;
    cin >> name;
    size++;
    Gym newOne(size,name,eArr,eSize);
    Gym *newArr = new Gym[size];
    for (int i=0;i<size-1;i++) {
        newArr[i] = arr[i];
    } 
    newArr[size-1] = newOne;
   // delete [] arr;
    arr = newArr;
}

void createEquipment(Equipment *&eArr,int &eSize) {
    eSize++;
    string name;
    cout << "Enter the Equipment Name : " ; 
    cin>> name;
    Equipment obj(eSize,name);
    Equipment *newArr = new Equipment[eSize];
    for (int i=0;i<eSize-1;i++) {
        newArr[i] = eArr[i];
    } 
    newArr[eSize-1] = obj;
    //delete [] eArr;
    eArr = newArr;
}

void loginAdmin() {

    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    
    cout << "Enter the ID : " ;
    int id; cin >> id;
    gymArr[id-1].Print();
    // Show the GYM DETAILS

    do {
        int choice;
        SetConsoleTextAttribute(console_color, 7);
        cout << "Please select one of the Choices\n";
        SetConsoleTextAttribute(console_color, 9);
        cout << "[1] Add A Customer\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "[2] Add A Trainer\n";
        SetConsoleTextAttribute(console_color, 5);
        cout << "[3] Delete A Customer\n";
        SetConsoleTextAttribute(console_color, 4);
        cout << "[4] Delete A Trainer\n";
        SetConsoleTextAttribute(console_color, 10);
        cout << "[5] Return to Previous Menu\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "-> ";
        SetConsoleTextAttribute(console_color, 7);
        cin >> choice;
        switch (choice) {
            case 1: {
                int m;
                cout << "Select a customer : \n";
                for (int i=0;i<customerSize;i++) {
                    customerArr[i].Print();
                }
                cin >> m;
                gymArr[id-1].receiveCustomer(customerArr[m]);
                break;
            }
            case 2: {
                int m;
                cout << "Select a trainer : \n";
                for (int i=0;i<trainerSize;i++) {
                    trainerArr[i].Print();
                }
                cin >> m;
                gymArr[id-1].receiveTrainer(trainerArr[m]);
                break;
                break;
            }
            case 3: {
                 gymArr[id-1].DeleteCustomer();
            }
            case 4: {
                for (int i=0; i<trainerSize; i++){
                    trainerArr[i].Print(); cout << endl;
                }
                int index;
                int choice;
                cout << "Enter ID to delete\n"; cin >> choice;
                index = searchArray(trainerArr[choice].email,trainerArr,trainerSize);
                if (index != -99)
                {
                    decreaseArray(trainerArr,trainerSize,choice);
                    cout << "Deleted Successfully\n";
                    break;
                }
                else
                { cout << "Not Found :(\n"; 
                    break;
                }
            }
            default: {
                cout << "Invalid";
                break;
            }      
        }
        if (choice >3) break;
    } while(1);
}

void CustomerPanel(){
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Enter your Email : " ;
        string email; cin >> email;
        int index = searchArray(email, customerArr,customerSize);
        if (index == -99) {
            cout << "Email Not Found\n";
            return;
        } 
        while (1) {
        int choice;
        SetConsoleTextAttribute(console_color, 7);
        cout << "Please select one of the Choices\n";
        SetConsoleTextAttribute(console_color, 9);
        cout << "[1] Subscribe A Plan\n";
        SetConsoleTextAttribute(console_color, 4);
        cout << "[2] Return to Previous Menu\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "-> ";
        SetConsoleTextAttribute(console_color, 7);
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Please select a Gym Using its ID : \n";
                for (int i=0;i<gymsize;i++) {
                    cout << gymArr[i].getId() << ". " <<gymArr[i].getName() << endl;
                }
                int m;cin >>m;
                customerArr[index].createSubscription(&(gymArr[m-1]));
                break;
            }
            case 2: {
                break;
            }
            default: {
                cout << "Invalid";
                break;
            }      
        }
        if (choice >3) break;
    }

}

void loginTrainer(){
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Enter your Email : " ;
    string email; cin >> email;
    int index = searchArray(email, trainerArr,trainerSize);
   while (1) {
        int choice;
        SetConsoleTextAttribute(console_color, 7);
        cout << "Please select one of the Choices\n";
        SetConsoleTextAttribute(console_color, 9);
        cout << "[1] Create A Plan\n";
        SetConsoleTextAttribute(console_color, 4);
        cout << "[2] Return to Previous Menu\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "-> ";
        SetConsoleTextAttribute(console_color, 7);
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Please select a Gym Using its ID : \n";
                for (int i=0;i<gymsize;i++) {
                    cout << gymArr[i].getId() << ". " <<gymArr[i].getName() << endl;
                }
                int m;cin >>m;
                trainerArr[index].createPlan(eArr,eSize);
                break;
            }
            default: {
                cout << "Invalid";
                break;
            }      
        }
        if (choice >1) break;
    }
}

void signUp() {
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    do {
        int choice=0;
        SetConsoleTextAttribute(console_color, 7);
        cout << "Please select one of the Choices\n";
        SetConsoleTextAttribute(console_color, 9);
        cout << "[1] Register a GYM\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "[2] Register as Customer\n";
        SetConsoleTextAttribute(console_color, 5);
        cout << "[3] Register as Trainer\n";
        SetConsoleTextAttribute(console_color, 10);
        cout << "[4] Return to Previous Menu\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "-> ";
        SetConsoleTextAttribute(console_color, 7);
        cin >> choice;
        switch (choice) {
            case 1: {
                createGym(gymArr,gymsize,eArr,eSize);
                break;
            }
            case 2: {
                AddCustomer();
                break;
            }
            case 3: {
                AddTrainer();
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Invalid";
                break;
            }      
        }
        if (choice >3) break;
    } while(1);
}

void signIn() {
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    do {
        int choice=0;
        SetConsoleTextAttribute(console_color, 7);
        cout << "Please select one of the Choices\n";
        SetConsoleTextAttribute(console_color, 9);
        cout << "[1] Login as GYM Admin\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "[2] Login as Customer\n";
        SetConsoleTextAttribute(console_color, 5);
        cout << "[3] Login as Trainer\n";
        SetConsoleTextAttribute(console_color, 10);
        cout << "[4] Return to Previous Menu\n";
        SetConsoleTextAttribute(console_color, 6);
        cout << "-> ";
        SetConsoleTextAttribute(console_color, 7);
        cin >> choice;
        switch (choice) {
            case 1: {
                loginAdmin();
                break;
            }
            case 2: {
                CustomerPanel();
                break;
            }
            case 3: {
                loginTrainer();
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Invalid";
                break;
            }      
        }
        if (choice >3) 
          {break;}
    } while(1);
}

void finalize() {
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    fstream foo("customer.txt");
    if (foo.is_open()) {
        for (int i=0;i<customerSize;i++) {
            foo << customerArr[i].name << "\t" << customerArr[i].address << "\t" << customerArr[i].phone << "\t" << customerArr[i].email << endl;
        }
        SetConsoleTextAttribute(console_color, 6);
        cout << "Customer Written to file" << endl;
    }
    else{
        SetConsoleTextAttribute(console_color, 4);
        cout << "Unable to write to output file customer" << endl;
    }
    

    fstream writeT("trainer.txt");
    if (writeT.is_open()){
        for (int i=0; i<trainerSize;i++){
            writeT << trainerArr[i].name << "\t" << trainerArr[i].email << endl;
        }
        SetConsoleTextAttribute(console_color, 6);
        cout << "Trainer Written to file" << endl;
    }
    else {
        SetConsoleTextAttribute(console_color, 4);
        cout << "Unable to write to output file trainer.txt\n";
    }

    fstream writeE("equipments.txt");
    if (writeE.is_open()){
        for (int i=0; i<eSize;i++){
            writeE << eArr[i].name << endl;
        }
        SetConsoleTextAttribute(console_color, 6);
        cout << "Equipments Written to file" << endl;
    }
    else{
        SetConsoleTextAttribute(console_color, 4);
        cout << "Unable to write to output file" << endl;
    }
    SetConsoleTextAttribute(console_color, 7);
}

void initialize() {
    fstream readC("customer.txt");
    if (readC.is_open()) {
        string name,address,phone,email;
        while (!readC.eof()) {
            readC >> name;
            readC >> address;
            readC >> phone;
            readC >> email;
            Customer obj(customerSize,name,address,phone,email);
            updateArray(customerArr,customerSize);
            customerArr[customerSize-1] = obj;
        }
        cout << "Customer Data Loaded" << endl;
    }
    else {
        cout << "Could not Load Customers Data\n";
    }


    ifstream readT("trainer.txt");
    if (readT.is_open()) {
        while (!readT.eof()) {
            string name,email;
            readT >> name;
            readT >> email;
            Trainer obj(trainerSize,name,email);
            updateArray(trainerArr,trainerSize);
            trainerArr[trainerSize-1] = obj;
        }
        cout << "Trainer Data Loaded" << endl;
    }
    else {
        cout << "Could not Load Trainer Data\n";
    }

    ifstream readE("equipments.txt");
    if (readE.is_open()) {
        while (!readE.eof()) {
            string name;
            readE >> name;
            Equipment obj(eSize,name);
            updateArray(eArr,eSize);
            eArr[eSize-1] = obj;
        }
        cout << "Equipment Data Loaded" << endl;
    }
    else {
        cout << "Could not Load Equipment Data\n";
    }
        cout << "--------------------------" << endl;
}

void Display(){
    cout << "Customers:" << endl;
     cout << "--------------------------" << endl;
    for(int i = 0; i < customerSize; i++)
    customerArr[i].Print(); cout << "--------------------------" << endl;
    cout << "Trainers:" << endl;
     cout << endl <<"==========================" << endl;
    for(int i = 0; i < trainerSize; i++)
    trainerArr[i].Print(); cout << "--------------------------" << endl;
}