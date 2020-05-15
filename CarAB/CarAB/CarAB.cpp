
#include<iostream>
#include<string>
using namespace std;

/////////////////////////////CAR CLASS ////////////////////////////////////
class car{
 
 string make;
 string car_model;
 string reg_no;
 string color;
 int year;
public:
 
 car(){
  make = "";
  car_model= "";
  reg_no= "";
  color = "";
 }
 void init(){
  cout<<"\nEnter Make: "; cin>>make;
    
    cout<<"\nEnter Car MOdel: ";cin>>car_model;
    
    cout<<"\nEnter COLOR: ";cin>>color;
    
    cout<<"\nEnter Registration no: "; cin>>reg_no;
    
    cout<<"\nEnter Year: "; cin>>year;
 }
 string getReg(){
  return reg_no;
 }
 void cDisplay(){
  cout<<make<<endl;
  cout<<car_model<<endl;
  cout<<reg_no<<endl;
  cout<<color<<endl;
 }
 ~car(){
  //cout<<"\n\nDEstructor called\n";
 }
 
 
};

/////////////////////////////////GARAGE CLASS ////////////////////////////

class Garage{
 string name;
 int index;
 const int capacity;
 car  *ptr;
public:
 Garage():capacity(2){
  name = " ";
  //index = 0;this can also be done if we skip setting index
  ptr = new car[capacity];
  
 }
 void seti()//set index
 {
  index=0;
 }
 bool IsEmpty(){
  if(index != capacity)
   return true;
  else 
   return false;
 }
 bool IsFull(){
  if(index == capacity)
   return true;
  else 
   return false;
 }
 void push(){
  bool x;
  x = IsEmpty();
  if (x==1){
   cout<<"\n\nCar can be parked\n";
   ptr[index].init();
   index++;
  }
  else 
   cout<<"\n Garage is Full: \n";
 }
 bool Find(string reg){
  for(int i=0; i<capacity;i++){
   if(ptr[i].getReg() == reg){
    cout<<"\nCar found \n";
    return true;
   }
   
   
   
  } 
   return false;
 }
 bool Remove(string reg){
  for(int i=0; i<10;i++){
   if(ptr[i].getReg() == reg){
    cout<<"\nCar found  and removed\n";
    --index;
    return true;
   }
  }
    return false;
 }
 void Display(){
  for (int i=0;i<index;i++){
   ptr[i].cDisplay();
  }
  
  
 }
 
};


///////////////////////MAIN//////////////////////////////
void main(){
 Garage obj1;
 obj1.seti();
 while(1){
  int opt;
  cout<<"\n******************************************\n";
  cout<<"\nEnter \n";
  
  cout<<"1. Add car in GARAGE\n";
  
  cout<<"2. Remove car from GARAGE\n";
  
  cout<<"3. Display parked cars\n";
  
  cout<<"4. FInd a car\n";
  
  cout<<"5. Check If garage is ful\n";
  cout<<"-------------------------------------------\n";
  
 
  
  
  int year;
  
  string col,make,reg,model; 
  
  cin>>opt;
  switch(opt){
  
  case 1:
   {
    
    obj1.push();
    
   }
   break;
  case 2:
   {
    cout<<"\nEnter registration no of the car to be removed: ";
    cin>>reg;
    
    obj1.Remove(reg);
   }
   break;
  case 3:
   obj1.Display();
   break;
  case 4:
   {cout<<"\nEnter registeration no: ";
   cin>>reg;
  bool a = obj1.Find(reg);
   if (a==1)
    cout<<"\nCar found  \n";
  }
   break;
  case 5:
   {
    bool a = obj1.IsFull();
    if (a==1){
     cout<<"\nGarage is full  \n";
    }
    else
     cout<<"\nGArage is not full \n";
    
   }
   
   break;
  default:
   
   break;
   
  }
 }
 
 

}