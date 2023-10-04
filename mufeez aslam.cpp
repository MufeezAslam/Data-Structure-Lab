#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
class Circular{
	private:
		Node *start;
	public:
		
		void insert(int val){
			Node *newNode = new Node;
			newNode->data = val;
			newNode->next = start;
			
			if(start == NULL){
				start = newNode;
				newNode->next=newNode;
			}
			else{
				
				Node *current = start;
				while(current->next!=start){
					
					current = current->next;
				}
				
				current->next = newNode;
			}
		}
		void del(){
			Node *current = start, *temp;
				while(current->next!=start){
					temp = current;
					current = current->next;
				}
				delete current;
				current = NULL;
				temp->next=start;
		}
		void disp(){
				Node *current = start;
				while(current->next!=start){
					cout<<current->data<<" ";
					current = current->next;
				}
				cout<<endl;
		}
		
};
int main(){
	Circular list;
	list.insert(1);

	list.insert(2);
		
	list.insert(3);
	list.insert(4);
	list.insert(5);
	
	cout<<"list\n";
	list.disp();
	list.del();
	cout<<"list\n";
	list.disp();
	

}
