#include<iostream>
using namespace std;

class Node{
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node(){
		data = 0;
		prev = NULL;
		next = NULL;
	}
	Node(int d){
		data = d;
		next = NULL;
		prev = NULL;
	}

	void set_data(int x){ 
		data = x; 
	}
	void set_next(Node* n){
		next = n;
	}
	void set_prev(Node* p){
		prev = p;
	}
	int get_data(){ return data;}
	Node* get_next(){ return next; }
	Node* get_prev(){ return prev; }
};


class double_linked
{
private:
	Node* head;
	Node* tail;
public: 
	double_linked(){
		head = tail =NULL;
		//head->set_next(tail);
		//tail->set_prev(head);
	}
	void insert_ele(int d){ 
		Node* newNode = new Node(d);
		Node* temp = head;
		if(temp != NULL){
		
			while(temp -> get_next() !=NULL){
				temp = temp->get_next();
			}
			temp->set_next(newNode);
			newNode->set_prev(temp);
			tail = newNode;
		}
		else
		{
			head = tail = newNode;
		}	
		display();
	}
	void insert_beg(int d){
		Node* newNode = new Node(d);
		if (head == NULL)
		{
			insert_ele(d);
			/* code */
		}
		else{
			newNode->set_next(head);
			head->set_prev(newNode);
			head = newNode;
			display();
		}
	}
	void insert_after(int value, int d){
		Node* newNode = new Node(d);
		Node* temp = head;
		if(temp != NULL){
			while(temp != NULL && temp->get_data() != value){
					temp = temp->get_next();
			}
			if (temp == NULL)
			{
				cout<<"\nThe value not found";
				/* code */
			}
			else{
				//cout<<"next: "<<temp->get_next();
				Node* n = temp->get_next();
				newNode->set_next(n);
				n->set_prev(newNode);
				newNode->set_prev(temp);
				temp->set_next(newNode);
				display();
			}
		}
		else{
			cout<<"\nThe value not found";
		}
	}
	void display(){
		Node* temp = head;
		if(temp == NULL)
			cout<<"\nNo elements in the linked list";
		else{
			cout<<"\nlinked list\n";
			while(temp != NULL){
				cout<<temp->get_data()<<"\n";
				temp = temp->get_next();
			}
			//cout<<temp->get_data();
		}
	}

	void display_backward(){
		Node* temp = tail;
		if (temp == NULL)
		{	
			cout<<"\nNo elements in the linked list";
			/* code */
		}
		else{
			cout<<"\nlinked list displayed backward\n";
			while(temp!=head){
				cout<<temp->get_data()<<"\n";
				temp=temp->get_prev();
			}
			cout<<head->get_data();
		}
	}
	void delete_beg(){
		Node* temp = head;
		if(head == NULL){
			cout<<"\nNo elements in the linked list";
		}
		else{
			head = temp->get_next();
			delete temp;
			cout<<"\ndeleted";
			display();
		}
	}
	void delete_end(){
		Node* temp = tail;
		if (tail == NULL)
		{	
			cout<<"\nNo elements in the linked list";
		}
		else{
			tail = temp->get_prev();
			tail->set_next(NULL);
			delete temp;
			cout<<"\ndeleted";
			display();
		}
	}

	void delete_value(int value){
		Node* temp = head;
		if(temp != NULL){
			while(temp != NULL && temp->get_data() != value){
					temp = temp->get_next();
			}
			if (temp == NULL)
			{
				cout<<"\nThe value not found";
				/* code */
			}
			else{
				if (temp == head)
				{
					delete_beg();
				}
				else if (temp == tail)
				{
					delete_end();
				}
				else{
					Node* n = temp->get_next();
					Node* p = temp->get_prev();
					n->set_prev(p);
					p->set_next(n);
					delete temp;
					cout<<"\ndeleted";
					display();
				}	
			}
		}
		else{
			cout<<"\nThe value not found";
		}
	}
};

int main(int argc, char const *argv[])
{
	double_linked dl;
	dl.insert_beg(1);
	dl.display_backward();
	dl.insert_ele(4);
	dl.insert_ele(5);
	dl.insert_after(4,10);
	dl.delete_value(4);
	return 0;
}