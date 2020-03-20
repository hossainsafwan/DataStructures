/*
Name: Safwan Hossain
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTableAPI.h"
#include "funcPointers.h"

#define SIZE 101
void printfunction(HTable *hashTable);
int main()
{
	HTable * hashMap;
   hashMap =createTable(SIZE,&hashFunction,&destroyData,&printData);
	  
   /*Billy-123, Bob and Tom are the data being sent Billy-123 and Bob should be in collision*/
   char * string =malloc(sizeof("Billy-123")+1);
   strcpy(string,"Billy-123");	
   insertData(hashMap, 102, (void*)string);
   char * string1 =malloc(sizeof("first-collision")+1);
	strcpy(string1,"Bob");
   insertData(hashMap, 203, (void*)string1);
   char * string2=malloc(sizeof("second -collision")+1);
	strcpy(string2,"Tom");
   insertData(hashMap, 509, (void*)string2);
  
   printf("\nTest insert with collsion -Billy-123 and Bob are in collision-\n\n");
	
   /*Print hash table*/
   printfunction(hashMap);
printf("**********************************\n\n");
removeData(hashMap,102);


   printf("Test removing Data in collision should remove -Billy-123-\n\n");
   removeData(hashMap,219); 
   /*Print hash table*/
   printfunction(hashMap);

printf("**********************************\n\n");

   printf("Test removing all Data -should print nothing-\n\n");
   removeData(hashMap,203); 
   removeData(hashMap,509); 
   /*Print hash table*/
   printfunction(hashMap);
   printf("**********************************\n\n");

   printf("Test basic insert with no collision\n\n");

   string =malloc(sizeof("Billy-123")+1);
   strcpy(string,"Billy-123");   
   string1 =malloc(sizeof("first ")+1);
   strcpy(string1,"Bob");
   string2=malloc(sizeof("second ")+1);
   strcpy(string2,"Tom");
   insertData(hashMap, 102, (void*)string);
   insertData(hashMap, 204, (void*)string1);
   insertData(hashMap, 509, (void*)string2);

   /*Print hash table*/
   printfunction(hashMap);

   printf("**********************************\n\n");

   printf("Test looking up with no collision-should print 'Billy-123'-\n\n");

   printData(lookupData(hashMap,102));

   printf("**********************************\n\n");
   
   printf("Test looking up with collision- should print 'BOb'\n\n");
   insertData(hashMap, 203, (void*)string1);//inserted Bob
   printData(lookupData(hashMap,203));/*Should print 'BOb'*/

   printf("**********************************\n\n");
   printf("Test looking up with nothing\n\n");
   printData(lookupData(hashMap,103));/*Should print nothing or garbage value*/

   printf("**********************************\n\n");

   printf("Test destroyTable\n\n");

   destroyTable(hashMap);

   printfunction(hashMap);

   printf("**********************************\n\n");




	return 0;
}

void printfunction(HTable *hashMap)
{
   int i;
   /*Print hash table*/
   for(i=0;i<hashMap->size;i++)
   {
      Node*temp=hashMap->table[i];
      if(temp != NULL)
      {
         while(temp != NULL)
         {
            printData(temp->data);
            temp=temp->next;
         }
      }
      
   }

}