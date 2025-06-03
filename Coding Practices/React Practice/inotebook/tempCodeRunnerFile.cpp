#include<iostream>
using namespace std;

// class A{
//     private:
//         int a;
//     public:
//         friend class B;
// };

// class B{
//     private:
//         A objA; 
//     public:
//         void set(int b){
//             objA.a = b;
//         }
//         void show(){
//             cout << objA.a; 
//         }
// };

// int main(){
//     B obj;
//     obj.set(334);
//     obj.show();
//     return 0;
// }

// class example{
//     private:
//         static int a;
//     public:
//         static void show(){
//             cout<<"a = "<<a <<endl;
//         }
// };

// int example::a=10.45;

// int main(){
//     example::show();
// }

// class aspire{
//     public:
//         virtual void draw();
//         void display(){
//             cout<<"DISPLAY";
//         }
// };

// class circle:public aspire{
//     public:
//         void draw(){
//             cout<<"DRAWING";
//         }
// };

// int main(){
//         circle c;
//         c.draw();
//         c.display();
// }

// class aspire{
//     public:
//         virtual void draw();
//         virtual void display();
// };

// class circle:public aspire{
//     public:
//         void display(){
//             cout<<"DISPLAY";
//         }
//         void draw(){
//             cout<<"DRAWING";
//         }
// };

// int main(){
//         circle c;
//         c.draw();
//         c.display();
// }

// class aspire{
//   private:
//     int a = 0;
//   public:
//     int value(){
//         cin>>a;
//     }
//     void shopw(){
//         cout<<a;
//     }  
// };
// int main(){
//     aspire *ptr;
//     ptr = new aspire;
//     ptr->value();
//     ptr->shopw();

// }

// class aspire{
//   // private:
//   public:
//     int a = 0;
//     int b = 5;
//     virtual int add() = 0;  
// };
// class aspire1 : public aspire{
//   public:
//   int add(){
//     cout<< "c = "<< a + b;
//   }
// };
// int main(){
//   aspire1 *ptr;
//   ptr = new aspire1;
//   ptr->add();
// }

// template <class T>
// T MAX(T a  , T b){
//     if(a>b){
//         cout<<"BIG";
//     }
//     else{
//         cout<<"SMALL";
//     }
// }

// int main(){
//     MAX(10 , 50);
// }

template <class T>
class Test{
    private:
        T a;
    public:
        int input(){
            a = 10;
        }
        void output(){
            cout<<a;
        }
};
int main(){

Test <int>x;
x.input();
x.output();

}
