#include<iostream>
#include<string>
#include<fstream>
// #include"Gym.cpp"
#include<windows.h>
#include <utility>
using namespace std;


class ExercisePlan;
class Customer;
class Gym;
class Trainer;
class Subscription;
class Equipment;

class DateTime {
        int Day;
        int Month;
        int Year;
        int Hours;
        int Mins;
    public:
        DateTime();
        DateTime(int Day, int Month, int Year, int, int );
};

//class ExercisePlan;

class Equipment {
    int id;
    string name;
public:
    Equipment();
    Equipment(int id, string name);
    friend ExercisePlan;
    friend void finalize();
};
// class Equipment;


class ExercisePlan {
    int id;
    pair<Equipment, int> *exerciseArr;   
    int numOfEquipments;
    public :
        ExercisePlan();
        ExercisePlan(int id,Equipment* arr,int size,int eSize);
        friend Trainer;
        friend Customer;
        void Print();
        friend void finalize();
};


class Trainer {
        string name;    
        int id;
        ExercisePlan* planArr;
        int NumOfPlans;
    public:
        string email;
        Trainer();
        friend Gym;
        friend Customer;
        Trainer(int id, string name, string email);
        Trainer(const Trainer &rhs);
        void createPlan(Equipment* &obj,int eSize);
        void Print();
        friend void finalize();
};

class Gym {
    int id;
    string name;  // ID ???
    Equipment * eqArr; // composition // Destroyed in GYM
    Customer *customerArr; // association // independent lifecycle
    Trainer *trainerArr; // association // independent lifecycle
    int numOfEquipments;
    int numOfCustomers;
    int numOfTrainers;

    public:
    friend Customer;
    friend Trainer;
    friend Subscription;
    Gym();
    Gym(int id,string name,Equipment* eq,int numOfEquipments);
    void receiveCustomer(Customer &obj);
    void receiveTrainer(Trainer &obj);
    void DeleteCustomer();
    void DeleteTrainer();
    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    void Print();
    friend void finalize();
};


class Subscription{
    private:
        int id;
        DateTime d;
        Trainer *trainer;
        ExercisePlan  *Plan;
        Gym *gym;
    public:
        Subscription();
        Subscription(int id,Gym* gym,DateTime d,Trainer* t,ExercisePlan *p);
        friend Customer;
        friend void finalize();
};


class Customer {

    int id;
    string name;
    string address;
    string phone;
    Subscription* subArr;
    int NumOfSub;
public:
    Customer();
    Customer(int id,string name,string address,string phone,string email);
    friend Gym;
    Customer(const Customer &rhs);
    void createSubscription(Gym* gm);
    void Print();
    string email;  
    friend void finalize();
};