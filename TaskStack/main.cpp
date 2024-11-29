#include <iostream>
#include <string>
using namespace std;

class Employee{
private:
    int id;
    string name;
    double salary;
public:
    Employee *pNext; Employee *pPervious;
    Employee(){
      id=0;
      name=" ";
      salary=0.0;
      pNext=NULL;
      pPervious=NULL;
    }
    Employee(int _id , string _name,double _s){
        id =_id;
        name=_name;
        salary=_s;
        pNext=NULL;
        pPervious=NULL;
    }
    Employee (const Employee& old){
        id = old.id;
        name = old.name;
        salary= old.salary;
    }
    void setID(int _id){
        id=_id;
    }
    int getID(){
        return id;
    }
    void setName(string _name){
        name=_name;
    }
    string getName(){
        return name;
    }
    void setSalary(double _s){
        salary=_s;
    }
    double getSalary(){
        return salary;
    }
    void PrintDetails(){
        cout << "Employee Information:\n";
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
        cout<<"****************************************************"<<endl;
    }

   ~Employee(){

   }

};


class LinkedList{
protected:
    Employee *pStart;
    Employee *pEnd;
public:
    LinkedList(){
        pStart=NULL;
        pEnd=NULL;
    }
    LinkedList(Employee* _start,Employee* _end){
        pStart = _start;
        pEnd = _end;
    }
    ~LinkedList(){
        freeList();
    }
    void setPStart(Employee* _pStart){
        pStart=_pStart;
    }
    Employee* getPStart(){
       return pStart;
    }
    void setPEnd(Employee* _pEnd){
        pEnd=_pEnd;
    }
    Employee* getPEnd(){
       return pEnd;
    }

    //Add in LinkedList
    void AddList(Employee* pItem){
        if(!pStart){
            pItem->pNext=NULL;
            pItem->pPervious=NULL;
            pStart=pEnd=pItem;
        }
        else{
            pEnd->pNext = pItem;
            pItem->pPervious = pEnd;
            pItem->pNext = NULL;
            pEnd = pItem;
        }
    }
    //Search in LinkedList
    Employee* searchList(int key){
        Employee* pItem=NULL;
        pItem=pStart;
        while(pItem && pItem->getID()!= key){

            pItem=pItem->pNext;
        }
        return pItem;
    }

    //Delete From LinkedList
    int DeleteList(int Key){
        Employee *pItem;
        int flag=1;
        pItem = searchList(Key);
        if(!pItem){
            flag=0;
        }
        else{
            if(pStart==pEnd){
                pStart=pEnd=NULL;
            }
                //First Case
            else if(pItem==pStart){
                pStart=pStart->pNext;
                pStart->pPervious=NULL;
            }

            //End Case
            else if(pItem == pEnd){
                pEnd =pEnd->pPervious;
                pEnd->pNext=NULL;
            }
            //Intermediate Case
            else {
                pItem->pPervious->pNext=pItem->pNext;
                pItem->pNext->pPervious=pItem->pPervious;
            }
            delete pItem;
        }
        return flag;
    }

    //Delete List
    void freeList(){
        Employee*pItem;

        while(pStart){
            pItem =pStart;
            pStart = pStart->pNext;
            delete pItem;
        }
        pEnd=NULL;
    }

   //Display All Employees
    void displayAll(){
        if(!pStart){
            cout<<"Stack Is Empty!";
        }
         else{
            Employee *pItem;
            pItem=pStart;
            while(pItem){
            pItem->PrintDetails();
            pItem = pItem->pNext;
         }
        }
    }
};

class StackList : public LinkedList{
private:
    Employee *employee;
    int SizeOfStack;
    int top;
public:
    StackList(){
        int SizeOfStack=5;
        int top=0;
        employee = new Employee[5];
    }
    StackList(int _size){
        int SizeOfStack=_size;
        int top=0;
        employee = new Employee[_size];
    }
    ~StackList(){
    }
    Employee* Push(Employee* emp){
        if(!FullStack()){
            //top=emp.AddLi;
            AddList(emp);
            top++;
            return emp;
        }
         else
        {
            cout<<"FULL!!!"<<endl;
        }
    }
   Employee* POP(){
     Employee* pNode;
     if(!EmptyStack()){
        pNode=pEnd;
        DeleteList(pNode->getID());
        top--;
        return pNode;
     }
     else{
        cout<<"Stack is Empty!"<<endl;
        //return NULL;
     }


   }
   int FullStack(){
       return top==SizeOfStack;
   }
   int EmptyStack(){
       return top==0;
   }

};


int main() {
    StackList stackEmployee;

    char flag='y';
    cout << "Enter Info Of Employee you want to Push (y/n): "<<endl;
    cout << "****************************************************" << endl;
    while(flag=='y'){
        int id;
        string name;
        double salary;
        cout<<"Enter Employee ID : ";
        cin >>id;
        cout<<"Enter Employee Name : ";
        cin >> name;
        cout<<"Enter Employee Salary : ";
        cin >> salary;
        Employee* emp = new Employee(id,name,salary);
        stackEmployee.Push(emp);
        cout << "****************************************************" << endl;
        cout << "Do you want to add another employee? (y/n): ";
        cin >> flag;
        cout << "****************************************************" << endl;
    }

    cout << "Do you want to POP Employee? (y/n): "<<endl;
    cout << "****************************************************" << endl;
    cin >> flag;
    cout << "****************************************************" << endl;
    if (flag == 'y') {
        stackEmployee.POP();
        cout <<"List all employees : ";
        stackEmployee.displayAll();
    }
    else {
            cout <<"List all employees : "<<endl;
            stackEmployee.displayAll();
            cout << "Thank you!" << endl;
            cout << "****************************************************" << endl;
    }



    return 0;
}

