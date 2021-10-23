#include<iostream>
#include<string>
#include<fstream>
#include"A5.h"
#include<windows.h>
#include <utility>
using namespace std;



template<class T1,class T2>
int searchArray(T1 key, T2* arr,int size) {
    for (int i=0;i<size;i++) {
        if (arr[i].email == key) {
            return i;
        }
    }
    return -99;
}

template<class T1> 
void updateArray(T1* &arr,int &size) {
    size++;
    T1* bigArr = new T1[size];
    for (int i=0;i<size-1;i++) {
        bigArr[i] = arr[i];
    }
    arr = bigArr;
}

template<class T1>
void decreaseArray(T1* arr, int &size,int id) {
        size--;
        T1 *newArr = new T1[size];
        int l=0;
        for (int i=0;i<size+1;i++) {
            if (i !=  id) {
                newArr[l] = arr[i];
                l++;
            }
        }
        arr =  newArr;
}


Customer::Customer() {
    id=-99;
    name="";
    address="";
    phone="";
    email="";
    subArr = nullptr;
}

Customer::Customer(const Customer &rhs) {
    
    this->id = rhs.id;
    this->name = rhs.name;
    this->address = rhs.address;
    this->phone = rhs.phone;
    this->email = rhs.email;
    NumOfSub=0;
}

Customer::Customer(int id,string name,string address,string phone,string email) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->email = email;
    NumOfSub=0;
}

void Customer::createSubscription(Gym* gm) {
    cout << "Select A Trainer through his id \n";
    for (int i=0;i<(*gm).numOfTrainers;i++) {
        cout << "[" << (*gm).trainerArr[i].id+1 << "]" <<  (*gm).trainerArr[i].name << endl;
    }
    int trainerId; cin >> trainerId;
    cout << "The trainer info is " <<(*gm).trainerArr[trainerId-1].NumOfPlans << endl;
    (*gm).trainerArr[trainerId-1].planArr[0].Print();
    cout << "Select a Plan \n";
    for (int i=0;i<(*gm).trainerArr[trainerId-1].NumOfPlans;i++){
        (*gm).trainerArr[trainerId-1].planArr[i].Print();
    }
    int pID;cin >> pID;
    NumOfSub++;

    cout << "Enter the day of Joining. 1-30/31 : ";
    int day;cin >>day;

    cout << "Enter the month of Joining. 1-30/31 : ";
    int month;cin >>month;

    cout << "Enter the year of Joining. 1-30/31 : ";
    int year;cin >>year;
    DateTime dt(day,month,year,0,0);
    Trainer * t = &(((*gm).trainerArr[trainerId]));
    ExercisePlan* c = &((*gm).trainerArr[trainerId].planArr[pID]);
    int n = NumOfSub;
    Subscription obj(n,gm,dt, t,c);
    //Subscription test(12,gm,dt,t,c);
    //(int id,Gym* gym,DateTime d,Trainer* t,ExercisePlan *p)
    //id//datetime//trainer//explan
}

void Customer :: Print(){
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 7);
    cout << "Customer ID : " << (this->id) << endl;
    SetConsoleTextAttribute(console_color, 9);
    cout << "Customer Name : " << this->name << endl;
    SetConsoleTextAttribute(console_color, 11);
    cout << "Address : " << this->address << endl;
    SetConsoleTextAttribute(console_color, 12);
    cout << "Phone : " << this->phone << endl;
    SetConsoleTextAttribute(console_color, 13);
    cout << "Email : " << this->email << endl;
    //Subscription* subArr;
    //int NumOfSub;
}



// Functions for Subscription

Subscription :: Subscription() {
    id=-99;
    gym = nullptr;
    trainer = nullptr;
    Plan = nullptr;
}

Subscription :: Subscription(int id,Gym* gym,DateTime d,Trainer* t,ExercisePlan *p) {
    this->id = id;
    this->gym = gym;
    trainer = t;
    Plan = p;
    this->d = d;
}

//END






//END

//
ExercisePlan ::ExercisePlan() {
    id=0;
    exerciseArr = nullptr;
}

ExercisePlan ::ExercisePlan(int id,Equipment* arr,int size,int eSize) {
    this->id=id;
    exerciseArr = new pair<Equipment,int>[size];
    numOfEquipments = size;
    for (int i=0;i<size;i++) {
        cout << "Select an equiment through its ID\n";
        int eChoice;
        for (int i=0;i<eSize;i++) {
            cout << arr[i].id << ". " << arr[i].name << endl;
        }
        cin >> eChoice;
        exerciseArr[i].first = arr[eChoice];
        cout << "Enter the duration for the Equipment : " << arr[eChoice].name << endl;
        cin >> exerciseArr[i].second;
    }
}

void ExercisePlan:: Print() {
    cout << "Plan ID : " << this->id;
    cout << "Details : \n";
    for (int i=0;i<numOfEquipments;i++) {
        cout << "\t" << exerciseArr[i].first.name << exerciseArr[i].second << endl; 
    }
}

//END

// Function for DATETIME

DateTime::DateTime()
{
    this->Day = 1;
    this->Month = 1;
    this->Year = 2001;

}

DateTime :: DateTime(int Day, int Month, int Year,int Hours=0, int Mins=0)
{
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
    this->Hours = Hours;
    this->Mins = Mins;
}


// Functions for Trainer

Trainer::Trainer()
{
    id=-99;
    name="";
    planArr=nullptr;
    NumOfPlans=0;
}

Trainer :: Trainer(int id, string name, string email){
    this-> id = id;
    this-> name = name;
    this-> email = email;
    NumOfPlans=0;
    planArr=nullptr;
}

Trainer :: Trainer(const Trainer &rhs){
    this->id = rhs.id;    
    this->name = rhs.name;
}

void Trainer::createPlan(Equipment* &obj,int eSize) {
    int ID;
    cout << "Enter the Plan ID" << endl;
    cin >> ID;
    cout << "Enter the number of exercises in this plan : ";
    int size; cin >> size;
    ExercisePlan EX(ID,obj,size,eSize);
    
    NumOfPlans++;
    //Include plan in planArr
    ExercisePlan *temp = new ExercisePlan[NumOfPlans];
    for (int i =0 ; i < NumOfPlans-1; i++) {
        temp[i] = planArr[i];
    }
    temp[NumOfPlans-1] = EX;
    //delete[]
    planArr = temp;
}


void Trainer :: Print(){
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(console_color, 6);
    cout << "Trainer Name : " << this->name << endl;
    SetConsoleTextAttribute(console_color, 5);
    cout << "Trainer ID : " << (this->id) << endl;
    SetConsoleTextAttribute(console_color, 4);
    cout << "Number Of Plans : " << this->NumOfPlans << endl;
    SetConsoleTextAttribute(console_color, 3);
    cout << "Plans : " << endl;
    for (int i=0; i<NumOfPlans; i++) 
    {
        planArr[i].Print();
        cout << endl;
    }   
  
}
// END


// Functions for GYM




Gym :: Gym(int id,string name,Equipment* eq,int numOfEquipments){
    this->id = id;
    this->name = name;
    this->numOfEquipments = numOfEquipments;
    eqArr = new Equipment[numOfEquipments]; 
    for (int i=0;i<numOfEquipments;i++) {
        eqArr[i] = eq[i];
    }
    numOfTrainers=0;
}

void Gym::DeleteCustomer(){
        for (int i=0; i<numOfCustomers; i++){
        customerArr[i].Print(); cout << endl;
        }
        int index;
        int choice;
        cout << "Enter ID to delete\n"; cin >> choice;
        index = searchArray(customerArr[choice].email,customerArr,numOfCustomers);
        if (index != -99)
        {
            decreaseArray(customerArr,numOfCustomers,choice);
            cout << "Deleted Successfully\n";
        }
        else
        { cout << "Not Found :(\n";}
}

void Gym::receiveCustomer(Customer &obj){
        updateArray(customerArr,numOfCustomers);
        customerArr[numOfCustomers-1] = obj;
       // delete [] customerArr;
}

void Gym::receiveTrainer(Trainer &obj){
        updateArray(trainerArr,numOfTrainers);
        trainerArr[numOfTrainers-1] = obj;
//        delete [] trainerArr;

}



void Gym :: Print(){
     HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 3);
    cout << "ID : " << this->id << endl;
    SetConsoleTextAttribute(console_color, 12);
    cout << "Name : " << this->name << endl;
    SetConsoleTextAttribute(console_color, 13);
    cout << "Num of Customers : " << numOfCustomers << endl;
    SetConsoleTextAttribute(console_color, 14);
    cout << "Customer Details : \n";
    SetConsoleTextAttribute(console_color, 2);
    for (int i = 0; i < numOfCustomers; i++)
    {
        cout << customerArr[i].name << endl;
        cout << customerArr[i].id << endl;
    }
    cout << endl;
    SetConsoleTextAttribute(console_color, 4);
    cout << "Num of Trainers : " << numOfTrainers << endl;
    SetConsoleTextAttribute(console_color, 3);
    cout << "Trainer Details : \n";
    SetConsoleTextAttribute(console_color, 6);
    for (int i = 0; i < numOfTrainers; i++) {
        cout << trainerArr[i].id << ". " <<trainerArr[i].name << endl;
    }

}

// END



// end




Equipment :: Equipment() {
    id=-99;
    name = "";
}

Equipment:: Equipment(int id, string name) {
    this->id = id;
    this->name = name;
}

Gym:: Gym() {
    id=-99;
    name = "";
    customerArr = nullptr;
    trainerArr = nullptr;
    eqArr = nullptr;
    numOfTrainers=0;
}