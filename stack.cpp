#include<iostream>
#include<exception>
using namespace std;
template <class T>
class ArrayStack{
    private:
        enum {CAPACITY = 100};
        int capacity;         //stack size
        int t;                //index of the top
        T* S;                 //the stack array

    public:
        ArrayStack(int cap = CAPACITY) {
            capacity = cap;
            S = new T[capacity];
            t = -1;
        }
        
        int size() const
        { return (t+1);}

        bool isEmpty() const
        { return (t<0);}

        T& top() {
            if (isEmpty())
            {
                cout<<"\nAccess to empty stack";
                return(0);
            } 
            return S[t];
        }

        void push(const T& elem){
            if(size()==capacity){
                cout<<"\nStack overflow";
            }
            S[++t]=elem;
        }
        T pop(){
            if(isEmpty()){
                cout<<"\nAcess to empty stack";
                return(0);
            }
            return S[t--];
        }
};
int main(){
    ArrayStack <int> intStack;
    return 0;
}
