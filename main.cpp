#include <iostream>
#include <cstring>
using namespace std;
struct student{
    char name[1000];
    int id;
    student *next;
};

student *create(){
    student *head,*temp;int num,n=0;char name[1000];
    head=new student;
    temp=head;
    cout<<"Enter a ID:(-1 to exit) ";
    cin>>num;
    cout<<"Enter a name: ";
    cin>>name;

    while (num!=-1){
        n++;
//       temp->id=num;
        (*temp).id=num;
        strcpy(temp->name,name);
        temp->next=new student;
        temp =temp->next;
        cout<<"Enter a ID:(-1 to exit) ";
        cin>>num;
        if (num!=-1){
        cout<<"Enter a name: ";
        cin>>name;

        }

    }
    if (n==0) head=NULL;else temp->next=NULL;
    return head;


};
student *deletes(student *head,int n){
    student *temp,*follow;
    temp=head;

    if (head->id==n) {
        head = head->next;
        delete temp;
        return head;

    }else {
        while (temp->id!=n){
            follow=temp;
            temp=temp->next;
        }
        if (temp==NULL){
            cout<<"Not found!!"<<endl;
        }
        else{
            follow->next=temp->next;
            delete temp;

        }
        return head;

    }


};
student *print(student * head){
    student *temp=head;
    while (temp->next!=NULL){
        cout<<temp->id<<"\t"<<temp->name<<endl;
        temp=temp->next;
    }
}
int main(){
    student * pointer=create();
    int choice;
   print(pointer);
    cout<<"Which id to delete?: ";
    cin>>choice;
    pointer=deletes(pointer,choice);
    cout<<"Result: "<<endl;
    print(pointer);
    cout<<"End of program!";
    return 0;
}