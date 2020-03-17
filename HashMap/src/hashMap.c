/*
Name: Safwan Hossain
Student ID: 0918742
Email: safwan@uoguelph.ca
*/
#include <stdio.h>
#include <stdlib.h>

#include "HashTableAPI.h"
#include "funcPointers.h"

void insertData(HTable *hashTable, int key, void *data)
{
    if (hashTable != NULL)
    {
        Node* new = createNode(key,data);
        if(hashTable->hashFunction(hashTable->size,key) <= (hashTable->size/*-1*/) && hashTable->hashFunction(hashTable->size,key) > 0)
        {
            if (hashTable->table[hashTable->hashFunction(hashTable->size,key)] == NULL )
            {


                hashTable->table[hashTable->hashFunction(hashTable->size,key)]=createNode(key,data);

            }
            else if (hashTable->table[hashTable->hashFunction(hashTable->size,key)] != NULL )
            {
                Node *temp = hashTable->table[hashTable->hashFunction(hashTable->size,key)];
                while(temp->next !=NULL)
                {
                    temp=temp->next;

                }

                temp->next=new;

            }

        }
    }



}


Node *createNode(int key, void *data)
{
    Node * new = (Node*)malloc(sizeof(Node));
    new->next=NULL;
    new->key=key;
    new->data=data;

    return new;
}

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),
                     void (*destroyData)(void *data),void (*printData)(void *toBePrinted))
{

    HTable *hTable = (HTable*)malloc(sizeof(HTable));
    hTable->size=size;

    hTable->table=(Node**)malloc(sizeof(Node)*hTable->size);

    hTable->destroyData=destroyData;
    hTable->hashFunction=hashFunction;
    hTable->printData=printData;

    return hTable;
}
void destroyTable(HTable *hashTable)
{
    int i;
    if(hashTable == NULL)
    {
        return;
    }

    for(i=0; i< hashTable->size;i++)
    {
        if(hashTable->table[i] != NULL)
        {
            Node*temp=hashTable->table[i];
            Node*temp2=hashTable->table[i];
            while(temp != NULL)
            {
                temp2=temp->next;
                hashTable->destroyData(temp->data);
                free(temp);
                temp=temp2;

            }

        }



    }
        
    free(hashTable);

}
void removeData(HTable *hashTable, int key)
{
    int position = hashTable->hashFunction(hashTable->size,key);
    Node* temp = hashTable->table[position];
    Node* temp1 = hashTable->table[position];

    if(temp == NULL)
    {
        return;
    }
    while(temp->key != key)
    {

        temp=temp->next;
    }

    if (temp->next == NULL && temp == temp1)/*only node in list*/
    {
        hashTable->table[position]=NULL;
        free(temp->data);
        free(temp);
    }
    else if (temp->next == NULL && temp != temp1)/*last node in list*/
    {
        while(temp1-> next != temp)
        {
            temp1=temp1->next;
        }
        temp1->next=NULL;
        free(temp->data);
        free(temp);
    }

    else if (temp->next != NULL && temp != temp1) /*middle of list*/
    {
        while(temp1->next != temp)
        {
            temp1=temp1->next;
        }

        temp1->next=temp->next;
        free(temp->data);
        free(temp);
    }
    else if (temp == temp1 && temp->next != NULL)/*head of list*/
    {

        hashTable->table[position]=temp->next;

        free(temp->data);
        free(temp);
    }


}
void *lookupData(HTable *hashTable, int key)
{

    int  position=hashTable->hashFunction(hashTable->size,key);

    Node*temp=hashTable->table[position];

    while(temp !=NULL && temp->key != key)
    {

        temp=temp->next;

    }

    if(temp == NULL)
    {
        return NULL;
    }
    else if(temp->key == key)
    {
        return temp->data;
    }
    return NULL;
}



