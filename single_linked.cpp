#include<iostream>
using namespace std;

class Node{
private:
	int data;
	Node* next;
public:
	Node(){
		data = 0;
		next = NULL;
	}
	Node(int d){
		data = d;
		next = NULL;
	}

	void set_data(int x){ 
		data = x; 
	}
	void set_next(Node* n){
		next = n;
	}
	int get_data(){ return data;}
	Node* get_next(){ return next; }
};
class Single_linked{
private:
	Node *head;
public:
	Single_linked(){
		head = NULL;
	}
	void insert_end(int d){
		Node* newNode = new Node(d);

    	Node* temp = head;
    	if(temp != NULL){
    		while(temp->get_next() != NULL){
    			temp = temp->get_next();
    		}
	    	temp->set_next(newNode);
		}
		else
			head = newNode;
		cout<<"\ninserted at end.successful";
		display();
	}

	void insert_beg(int d){
		Node* newNode = new Node(d);
		Node* temp = head;
		if(temp == NULL)
			head = newNode;
		else{
			newNode->set_next(temp);
			head = newNode;
		}
		cout<<"\ninserted at begining. successful";
		display();
	}

	void display(){
		Node* temp = head;
		if(temp == NULL)
			cout<<"\nNo elements in the linked list";
		else{
			cout<<"\n";
			while(temp != NULL){
				cout<<temp->get_data()<<"\n";
				temp = temp->get_next();
			}
		}
	}

	void insert_after(int d, int value){
		Node* newNode = new Node(d);
		Node* temp = head;
		if(temp == NULL){
			cout<<"\nThe value not found";
		}
		else{
			while(temp != NULL && temp->get_data() != value){
					temp = temp->get_next();
			}
			if (temp == NULL)
			{
				cout<<"\nThe value not found";
				/* code */
			}
			else{
				newNode->set_next(temp->get_next());
				temp->set_next(newNode);
				display();
			}
		}
	}
	void delete_beg(){
		Node* temp = head;
		if (temp==NULL)
		{
			cout<<"\nNo elements in the linked list";
			/* code */
		}
		else{
			head = temp -> get_next();
			delete temp;
			cout<<"\ndeleted";
			display();
		}
	}
	void delete_end(){
		Node* temp = head;
		if (temp==NULL) //no elements
		{
			cout<<"\nNo elements in the linked list";
			/* code */
		}
		else if(temp->get_next()==NULL){ // only one element
			head = NULL;
			cout<<"\ndeleted";
			display();
		}
		else{
			while(temp->get_next()->get_next()!=NULL){
				temp = temp->get_next();
			}
			Node* n = temp->get_next();
			temp->set_next(NULL);
			delete n;
			cout<<"\ndeleted";
			display();
		}
	}

	void delete_value(int value){
		Node* temp = head;

		if(temp == NULL){
			cout<<"\nThe value not found";
		}
		else if(temp->get_next()==NULL){//one element
			if (temp->get_data()==value)
			{
				head = NULL;
				delete temp;
				cout<<"deleted";
				display();
			}
			else{
				cout<<"\nThe value not found";
			}

		}
		else{

			while(temp->get_next()->get_data() != value && temp->get_next()->get_next() != NULL){
					temp = temp->get_next();
			}
			if (temp -> get_data() == value) // the first element is the value
			{
				head = temp->get_next();
				delete temp;
				display();
			}

			else if (temp->get_next()->get_data() == value){
				cout<<temp->get_data();
				Node* newNode = temp->get_next();
				temp->set_next(newNode->get_next());
				cout<<"delting "<<newNode->get_data();
				delete newNode;
				
				display();
				
				return;

			}
			else{
				cout<<"\nThe value not found";
				display();
			}

		}


	}
};
int main(int argc, char const *argv[])
{
	Single_linked sl1;
//	sl1.display();
	sl1.insert_end(2);
//	sl1.delete_beg();
	sl1.insert_beg(5);
//	sl1.insert_after(10,2);
//	sl1.delete_end();
//	sl1.delete_value(10);
	/* code */
	return 0;
}
