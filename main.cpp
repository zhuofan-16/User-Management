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
student *addDetail(student *temp){
    student *returnvalue=temp;
    int id;
    cout<<"Enter new student id: ";
    cin>>id;
    char name[1000];
    cout<<"Enter new student name: ";
    cin>>name;
    temp->id=id;
    strcpy(temp->name,name);
    return returnvalue;
}
student *add(student *head,int a){
student *follow,*temp;
temp=head;
if (temp->next==NULL&&a==1){
    temp=temp->next=new student;
    temp= addDetail(temp);
    return head;
}
if (a==0){
    temp=new student;
    temp= addDetail(temp);
    temp->next=head;
    return temp;
}
for (int i=0;i<a;i++){
    temp=temp->next;

}
follow=temp->next;
temp=temp->next=new student;
temp->next=follow;
temp= addDetail(temp);
return head;
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
    int place;
    cout<<"Which place to add new student?: ";
    cin>>place;
    pointer=add(pointer,place);
    print(pointer);
    cout<<"End of program!";
    return 0;
}