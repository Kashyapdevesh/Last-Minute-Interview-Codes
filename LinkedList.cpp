#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* get_node(int x){
	Node* temp=new Node();
	temp->data=x;
	temp->next=NULL;
	return temp;
}

void print_node(Node* head){
	Node* temp=head;
	while(temp){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

void insert_middle_len(Node* head){
	Node* temp=new Node();
	temp=head;
	int len=0;
	while(temp){
		len++;
		temp=temp->next;
	}

	temp=head;
	int count=0;
	while(temp){
		count++;
		if(count==len/2){
			Node* mid_node=new Node();
			mid_node->data=1000000;
			mid_node->next=temp->next;
			temp->next=mid_node;
			break;
		}
		temp=temp->next;

	}
}

void insert_middle_ptr(Node* head){
	Node* fast=head;
	Node* slow=head;

	while(fast->next->next && fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node* middle_node=new Node();
	middle_node->data=1000000;
	middle_node->next=slow->next;
	slow->next=middle_node;
	// cout<<fast->data<<endl;
}
// 1->2->3->4->NULL
// 1-> rem_ll
Node* reverse_list(Node* head){
	if(head==NULL || head->next==NULL)
		return head;

	Node* rem_list=reverse_list(head->next);
	head->next->next=head;
	head->next=NULL;
	return rem_list;
}
void loop(Node* head){
	Node* fast=new Node();
	Node* slow=new Node();

	while(fast->next && fast->next->next){
		fast=fast->next->next;
		slow=slow->next;

		if(fast==slow){
			cout<<"LOOP DETECTED\n";
			break;
		}
	}
	cout<<"NO LOOP DETECTED\n";
}

void loop_start_node(Node* head){
	Node* fast=new Node();
	Node* slow=new Node();

	while(fast->next && fast->next->next){
		fast=fast->next->next;
		slow=slow->next;

		if(fast==slow){
			slow=head;
			while(slow!=fast){
				fast=fast->next;
				slow=slow->next;
			}
			cout<<fast->data<<endl;
			break;

		}
	}
	cout<<"NO LOOP DETECTED\n";

}
//1->2->3->4->5->6->NULL
//
void nth_node_from_end(int pos,Node* head,int &count){
	if(head->next==NULL){
		count--;
		return ;
	}
	nth_node_from_end(pos,head->next,count);

	if(count==1){
		cout<<head->data<<endl<<endl;
	}
	count--;
}

int len_ll(Node* head){
	int len_ll=0;
	Node* temp=head;
	while(temp!=NULL){
		len_ll++;
		temp=temp->next;
	}
	return len_ll;
}

Node* reverse_k_groups_ll(Node* head,int k){
	if(head==NULL || head->next==NULL)
		return head;

	int length=len_ll(head);

	Node* dummy=new Node();
	dummy->data=0;
	dummy->next=head;

	Node* pre_node=dummy;
	Node* curr_node;
	Node*next_node;

	while(length>=k){
		curr_node=pre_node->next;
		next_node=curr_node->next;
		for(int i=1;i<k;i++){
			curr_node->next=next_node->next;
			next_node->next=pre_node->next;
			pre_node->next=next_node;
			next_node=curr_node->next;
		}
		pre_node=curr_node;
		length-=k;
	}
	return dummy->next;
}

bool is_palindrome(Node* head) {
        if(!head || !head->next) 
        	return true;
        
        stack<int> stk;
        
        // make slow pointer on the mid of the LL
        Node* slow = head;
        Node* fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Break the links - head(start to mid) and head2 (mid+1 to end)
        Node * head2 = slow->next;
        slow->next = NULL;
        
        // Push head2 into stack i.e they become reverse - LIFO order
        while(head2){
            stk.push(head2->data);
            head2 = head2->next;
        }
        
        // Check stack top is equal to linked list val or not
        while(!stk.empty() and head){
            if(head->data != stk.top()){
                return false;
            }
            head = head->next;
            stk.pop();
        }
        
        return true;
    }
int main(){
	Node* head=get_node(1);

	int count=2;
	Node* ref=head;
	while(count<=20){
		Node* temp=new Node();
		temp->data=count;
		ref->next=temp;
		ref=temp;
		count++;
	} 



	// print_node(head);
	// insert_middle_ptr(head);
	// print_node(head);
	// cout<<endl<<endl;
	
	// print_node(reverse_list(head));
	// loop(head);
	// cout<<endl<<endl;
	// int pos,count_;
	// count_=pos=3;
	// nth_node_from_end(pos,head,count_);
	print_node(head);
	cout<<endl<<endl;
	cout<<is_palindrome(head)<<endl<<endl;
	print_node(head);
	cout<<endl<<endl;
	// print_node(reverse_k_groups_ll(head,3));


	return 0;
}
