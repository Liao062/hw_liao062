#include <iostream>
//#include "problem6.h"

using namespace std;

struct Node {
    int value;
    Node *next;
    Node* merge(Node*& first, Node*& second);

};

Node* merge(Node*& first, Node*& second){
	if(first ==NULL) return second;
	if(second ==NULL) return first;

	if(first->value < second->value){
		first->next = merge(first->next, second);
		return first;
	}
	else{
		second->next = merge(first, second->next);
		return second;
	}
	
}

using namespace std;
int main(){
	Node* head1 =NULL;
	Node* head2 =NULL;
	Node a,b,c,d,e,f,g;
	head1=&a;
	head2=&e;
	a.value=4;
	b.value=7;
	c.value=9;
	d.value=10;
	e.value=1;
	f.value=5;
	g.value=12;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=NULL;
	e.next=&f;
	f.next=&g;
	g.next=NULL;
	Node* final=merge(head1,head2);
	while(final!=NULL){
		cout<<final->value<<endl;
		final=final->next;
	}
	return 0;
}

