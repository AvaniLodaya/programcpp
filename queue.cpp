#include<iostream>
using namespace std;

template <class T>
class CircularQueue
{
private:
	enum { CAPACITY = 5 };
	int capacity;
	bool cir;
	int head, tail;
	T* Q;
public:
	CircularQueue(int c = CAPACITY){
		cir = false;
		capacity = c;
		Q = new T[capacity];
		head = -1;
		tail = -1;
	}
	void insert_ele(const T& element){
		if(head == -1 && tail == -1)
		{
			head = tail = 0;
			Q[tail++] = element;
		}
		else if (tail == capacity && head == 0){
			cout << "\noverflow occured tail\n";
		}
		else if(head >0 && tail ==capacity){
			cir = true;
			tail = 0;
			Q[tail++] = element;
		}
		else
		{
			Q[tail++] = element;
		}
	}

	void delete_ele(){
		if (tail == head && !cir)
		{
			/* code */
			cout<<"\n No elements in the queue";
		}
		else if (head!=capacity-1)
		{
			cout<<"\n"<<Q[head++] <<" deleted";
		}
		else {//(head == capacity-1)
			if (tail==0)
			{
				cout<<"\n No elements in the queue";
			}
			else
			{
				cir = false;
				cout<<"\n"<<Q[head] <<" deleted\n";
				head = 0;
			}
		}
		

	}

	void display_queue(){
		cout<<"\n";
		if((head == tail && !cir )|| tail == -1){
			cout<<"\nNo elements in the queue";
		}
		else if(head < tail){
			cout<<"\nelements\n";
			for (int i = head; i < tail; ++i)
			{
				cout<<Q[i]<<"\t";
			}
		}
		else{

			cout<<"\nelements\n";
			for (int i = head; i < capacity; ++i)
			{
				cout<<Q[i]<<"\t";
			}
			for (int i = 0; i < tail; ++i)
			{
				cout<<Q[i]<<"\t";
			}
		
		}
	}


}; 
int main(){
	CircularQueue <int> intQueue(3);
	/*intQueue.insert_ele(2);
	intQueue.insert_ele(3);
	intQueue.insert_ele(4);
	intQueue.insert_ele(5);
	intQueue.display_queue();
	intQueue.delete_ele();
	intQueue.display_queue();
	intQueue.insert_ele(3);
	intQueue.display_queue();
	*/
	return 0;

}