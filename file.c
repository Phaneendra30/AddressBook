#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
	FILE *fp;
	fp = fopen("contact.csv","w"); // this is a function for saving contacts into the file;
	if(fp == NULL)
	{
		perror("Error : ");
		return;
	}
	fprintf(fp,"#%d\n",addressBook->contactCount);
	for(int i = 0;i<addressBook->contactCount;i++)
	{
		fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}
	fclose(fp);	
}
void loadContactsFromFile(AddressBook *addressBook) 
{
	FILE *fp;
	fp = fopen("contact.csv","r"); // this is a function for loading contacts from the file;
	if(fp == NULL)
      	{
        	perror("Error : ");
        	return;
     	}
	fscanf(fp,"#%d\n",&addressBook->contactCount);
	for(int i = 0;i<addressBook->contactCount;i++)
	{
 		fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);       
	}
	fclose(fp);
}

