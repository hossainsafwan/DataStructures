/*************************

Lab Project -1
Safwan Hossain 
Date: 29 MAY 2017

***************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
        List* list=(List*)malloc(sizeof(List));

        list->compare=compareFunction;
        list->printData=printFunction;
        list->deleteData=deleteFunction;
        list->head=NULL;
        list->tail=NULL;



        return list;

}
Node *initializeNode(void *data)
{

        Node* new = (Node*)malloc(sizeof(Node*));

        new->data=data;
        new->next =NULL;
        new->previous=NULL;

        return new;
}

void insertFront(List *list, void *toBeAdded)
{

        Node* new = initializeNode(toBeAdded);
        if(list == NULL)
        {
            free(new);
            return;
        }
        if(list->head == NULL && list != NULL)
        {

                list->head=new;
                list->tail=new;
                new=list->head;

                return;
        }
        else if(list->head != NULL && list != NULL)
        {
                new->next = list->head; /*new node point to old head*/
                list->head=new;/*set new head*/


                if( new->next != NULL)
                {
                        new=new->next;
                        new->previous=list->head;

                }
                new=list->head;

                while(new->next != NULL)/*Set list tail*/
                {
                        new=new->next;
                }

                list->tail=new;

        }

}

void insertBack (List *list, void *toBeAdded)
{
        Node* new = initializeNode(toBeAdded);

        if(list == NULL)
        {
            free(new);
            return;
        }

        if(list->head == NULL)
        {
               
                list->tail=new;
                list->head=new;
        }
        else
       {

                new->previous=list->tail;
                Node* temp=new;


                new=new->previous;
                new->next=temp;

                new=new->next;
                list->tail=new;

        }




}

void deleteList(List *list)
{
        if(list == NULL)
        {
            return;
        }

        if (list->head == NULL)
        {

                return;
        }

        while(list->head != NULL)
        {
             Node* temp=list->head;
             list->head=temp->next;

             temp->next =NULL;
             temp->previous=NULL;

             list->deleteData(temp->data);
             free(temp);


        }
        free(list);
        printf("List Deleted\n");
        return;

}

void insertSorted(List *list, void *toBeAdded)
{

        Node * new = initializeNode(toBeAdded);

        if(list == NULL)
        {
            free(new);
            return;
        }

        if (list->head == NULL)
        {
                list->head=new;
                list->tail=new;
        }
        else
        {
                Node* temp = list->head;

                while(temp != NULL)
                {

                        if (list->compare((const void*) new->data, (const void*) temp->data) > 0)
                        {

                                if (temp->next == NULL)
                                {

                                        temp->next=new;
                                        new->previous=temp;
                                        list->tail=new;

                                        temp=NULL;

                                }
                                else
                                { 
					               temp=temp->next;
                                }

                        }
                        else if (list->compare((const void*) new->data, (const void*) temp->data) <= 0)
                        {
                                if (temp->previous == NULL)
                                {

                                        temp->previous=new;
                                        new->next=temp;
                                        list->head=new;

                                        temp=NULL;
                                }
                                else if(temp->previous != NULL)
                                {



                                        Node *temp2 = temp->previous;

                                        temp2->next=new;
                                        new->next=temp;
                                        new->previous=temp2;
                                        temp->previous=new;

                                        temp=NULL;

                                }

                        }



                }

        }

}

int deleteDataFromList(List *list, void *toBeDeleted)
{

        if(list == NULL)
        {
            return 0;
        }

        if (list-> head == NULL)
        {

                return 0;
        }
        else
        {
                Node * temp=list->head;
                while(*(int*)(temp->data) != *(int*)toBeDeleted  )
                {

                        if(temp->next != NULL)
                        {
                                temp=temp->next;
                        }
                        else
                        {
                                return 0;
                        }
                }

                if (list->tail == temp)
                        {

                                Node* temp2=temp;

                                temp=temp->previous;
                                temp->next = NULL;
                                list->deleteData(temp2->data);  
                                free(temp2);

                        }

                        else if (list->head == temp)
                        {

                                Node* temp2=temp;

                                if (temp->next != NULL)
                                {
                                        list->head=temp->next;
                                        temp=temp->next;
                                        temp->previous=NULL;
                                        temp2->next=NULL;

                                        list->deleteData(temp2->data);
                                        free(temp2);
                                }
                                else
                                {
                                        list->head=NULL;
                                        list->deleteData(temp2->data); 
                                        free(temp2);
                                }

                        }
                        else
                        {

                                Node* temp2=temp;

                                temp=temp->previous;
                                temp->next=temp2->next;

                                temp=temp->next;
                                temp->previous=temp2->previous;

                                list->deleteData(temp2->data);
                                free(temp2);

                        }
                }


        printf("Data Deleted\n");
        return 1;

}


void *getFromFront(List *list)
{

        if(list == NULL)
        {
            return NULL;
        }
        if (list->head == NULL)
        {

                return NULL;
        }

        Node *temp=list->head;
        return temp->data;
}

void *getFromBack(List *list)
{
        if(list == NULL)
        {
            return NULL;
        }

        if (list->head == NULL)
	    {
            return NULL;
        }

        Node *temp=list->tail;
        return temp->data;
}

void printForward(List *list)
{
        Node* new = list->head;

    while(new != NULL)/* This will take you to the last node*/
    {

        list->printData(new->data);
        new=new->next;

        }

}

void printBackwards(List *list)
{
        Node* new = list->head;

    while(new->next != NULL)/* This will take you to the last node*/
    {
  
        new=new->next;

    }

     while(new !=NULL) 
     {

        list->printData(new->data);
        new = new->previous;
     
     }


}
Node* dequeue (List *list)
{


    if(list == NULL)
    {
       return NULL;
    }

    if (list-> head == NULL)
    {

       return NULL;
    }

    //Get the head of list
    Node* temp = list->head;

    //get memory for new data
    Data* dataSave = (Data*)malloc(sizeof(Data*));

    //put the data from old node to the new node
    dataSave = temp->data;

    //make new node with new data
    Node* new = initializeNode(dataSave);

    //get the previous of the head of the list
    Node* temp2 = temp->previous;
    //make that the new head of the list
    list->head = temp2;

    //delete old data
    list->deleteData(temp->data); 
    //delete old node
    free(temp);

    //return new node
    return new;


}









