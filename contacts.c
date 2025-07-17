#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
int choice(int);
int phone_number_validation(char *num,AddressBook *addressBook);
int email_validation(char *email,AddressBook *addressBook);
void dot_pattern()
{
	int i;
	for(i = 0;i<75;i++) // function to print '_' pattern on the promt;
	{
		printf("-");
	}
	printf("\n");
}
void listContacts(AddressBook *addressBook) 
{
	dot_pattern(); // function to list all existing contacts in the file;
	printf("%-5s %-20s %-15s %30s\n","S.No","Name","Phone Number","Email id");
        for(int i =0; i<addressBook->contactCount;i++)
        {
         printf("%-5d %-20s %-15s %30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }

      dot_pattern();
    /* Define the logic for print the contacts */
    //printf("%s\n", addressBook->contacts[addressBook->contactCount].name);
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
void createContact(AddressBook *addressBook)
{
	if(addressBook->contactCount>MAX_CONTACTS)
	{
		printf("AddressBook is filled\n"); // function for creating a contacts;
        }
        printf("Enter your name:\n");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

             char number[11];
              int validation;
           do
	   {
            printf("Enter the contact:\n");
            scanf("%s",number);
               validation = phone_number_validation(number,addressBook);
                switch(validation)
	    {
            case 1:
		    printf("Invalid phone number: phone number should contain 10 digits\n");
		    break;
	     case 2:
		    printf("Invalid phone number: phone number shound contain only numeric digits\n");
		    break;
             case 3:
		    printf("duplicates are not allowed please enter unique phone number\n");
		    break;
	      case 4:  
                    strcpy(addressBook->contacts[addressBook->contactCount].phone,number); // if phone number is valid then copy that number to contact structure;
	    }
	   }while(validation!=4);
	   
     
     // Read the contact
     // - Check whether the count is 10 or not
     // - Check all 10 characters are digits or not.
     // - Check the given number is already exist or not
    char mail[50];
    int temp;

   do
   {	   
     printf("Enter your email id\n");
     scanf(" %[^\n]",mail);
     temp = email_validation(mail,addressBook);
     switch(temp)
     {
	   case 1:
              printf("email id should contain '@' character and .com at the end of email id\n");
	      break;
	   case 2:
              printf("email id should contain aleast single character before and after '@' character\n");
	      break;
	   case 3:
               printf("Email should not contain uppercase letters. Please try again:\n");
	       break;
            case 4:
	        printf("Email should not contain space characters. Please try again:\n");
		break;
	    case 5:
                printf("Email must be unique. Please try again:\n");
		 break;
             case 0:
		 strcpy(addressBook->contacts[addressBook->contactCount++].email,mail); // if email id is valid then copy to contact structure;
		 break;
     }
    }while(temp!=0);
   printf("Contact created successfully\n"); 
}

void searchContact(AddressBook *addressBook)
{

	int choice1,i;
	dot_pattern(); // function to search your contact;
        printf(":🔍 search menu:\n");
	dot_pattern();
        printf("1:👤 search by your name\n");
        printf("2:📞 search by your mobile number\n");
        printf("3:✉️  search by your email id\n");
	dot_pattern();
        printf("Enter your choice:\n");
        scanf("%d",&choice1);
     int temp = choice(choice1);
     int found = 0;
     if(temp==1)
     {
	     char name[50];
	     printf("Enter your name:\n");
	     scanf(" %[^\n]",name);
	     for(i = 0;i<addressBook->contactCount;i++)
	     {
		     
		     if(strcmp(name,addressBook->contacts[i].name)==0)
		      {
                         dot_pattern();
                         printf("%-5s %-20s %-15s %30s\n","S.No","Name","Phone Number","Email id");
                         dot_pattern();
                      printf("%-5d %-20s %-15s %30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->                      contacts[i].email);
                           found = 1;
		      }
		       // if the name is found , it will print assocated details in the file;
		       
	     }
	     dot_pattern();
	     if(!found)
	     {
		     printf("Not found\n");
             }
	     
     }
       else if(temp==2)
      {
	      char phone[15];
	      printf("Enter your mobile number:\n"); // search by your mobile number;
	      scanf("%s",phone);
	      
               if(phone_number_validation(phone,addressBook)==3) // for validation;
	       {
                  
                   for(i = 0;i<addressBook->contactCount;i++)
                  {
                     if(strcmp(addressBook->contacts[i].phone,phone)==0)
                      {                                                                                                              
                         
                    dot_pattern();
                    printf("%-5s %-20s %-15s %30s\n","S.No","Name","Phone Number","Email id");
                    dot_pattern();

		    printf("%-5d %-20s %-15s %30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->
                    contacts[i].email); // if the mobile number is found , it print the associated details in the file; 				    
                       found = 1;
                      }

                  }
		   dot_pattern();
                  if(!found)
                  { 
                     printf("Not found\n");
	          }
	       }

	      else
	     {
                printf("Invalid mobile number: please enter valid phone number\n");
	     }
       }
       else if(temp==3)
      {
              char email[50];
	      printf("Enter your email id:\n");
              scanf(" %[^\n]",email);
               if(email_validation(email,addressBook)==5) // search  by your email id;
							  // email id send for validation;
               {
		      
                    for(i = 0;i<addressBook->contactCount;i++)
                  {
                     if(strcmp(email,addressBook->contacts[i].email)==0)
                      {                                                                                                                                
		      dot_pattern();                                                                                                                       printf("%-5s %-20s %-15s %30s\n","S.No","Name","Phone Number","Email id");                                                           dot_pattern();
                      printf("%-5d %-20s %-15s %30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->                      contacts[i].email);
                      // if the email id is valid, it will print the associated details in the file;
                           found = 1;
                      }

                  }
		  dot_pattern();  
		    
                  if(!found)
                  {
                     printf("Not found\n");
                  }
               }

                else
               {
                 printf("Invalid mail id: please enter mail id\n");
               }
       }
       else
       {
	       printf("Invalid choice: please try again\n");
       }
      
}
void editContact(AddressBook *addressBook)
{
    int choice1,arr_index = 0,arr[20],found = 0,i,edit_index; 
    char input[50];
        dot_pattern();
        printf("Edit menu:\n");  // function for edit contact;
        dot_pattern();
        printf("1: search by your name\n");
        printf("2: search by your mobile number\n"); 
        printf("3: search by your email id\n");
	dot_pattern();
        printf("Enter the choice to search your contact:\n");
        scanf("%d",&choice1);
    switch(choice1) // choice the option to search your contact;
    {
	    case 1:
		    printf("Enter the name to search:\n"); // search by name;
		    break;
	     case 2:
                    printf("Enter the phone to search:\n"); // search by phone number;

                    break;
	     case 3:
		    printf("Enter the email to search:\n"); // search by email id;
		    break;
    }
    scanf(" %[^\n]",input); // read the input from a user;
    // if user enter phone number or email id check for validation;
    if(choice1 == 2&&phone_number_validation(input,addressBook)!=3)
    {
	     printf("Invalid phone number please enter a valid phone number to search:\n");
	     return;

    }
    else if(choice1 == 3&&email_validation(input,addressBook)!=5)
    {
	    printf("Invalid email id please enter a valid email id to search:\n");
	    return;
    }
   
       for(i = 0; i < addressBook->contactCount; i++)
       {	  if ((choice1 == 1 && strcmp(input, addressBook->contacts[i].name) == 0) ||
            (choice1 == 2 && strcmp(input, addressBook->contacts[i].phone) == 0) ||
            (choice1 == 3 && strcmp(input, addressBook->contacts[i].email) == 0))
	    {   
		    dot_pattern();
                    printf("%-5s %-20s %-15s %30s\n", "S.No", "Name", "Phone Number", "Email Id");
                    dot_pattern();                                                                                                                                                             
       	     printf("%d(%d) %-20s %-15s %30s\n\n", arr_index + 1, i + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,
			addressBook->contacts[i].email);
		    arr[arr_index++] = i;
		    found = 1;
	    }
       
       }
           dot_pattern();
           if(!found)
	   {
		   printf("NOT Found\n");
	   }
	   else
	   {
		   printf("Enter which details you want to edit [1 to %d]:  ",arr_index);
		   int user_index;
		   scanf("%d",&user_index);
		   
		   edit_index = arr[user_index-1]; // get actual index value;
		     // ask user what they want to edit;
		    printf("1.Edit Name\n2.Edit Phone\n3.Edit email\n");
		    int edit_by;
		    dot_pattern();
                    printf("Enter what you whish to edit:\n");
		    scanf("%d",&edit_by);
		    if(edit_by==1)
		    {
			  
				
				    printf("Enter your new name:\n");
				    scanf(" %[^\n]",addressBook->contacts[edit_index].name);
				    dot_pattern();
				    printf("%43s\n","name updated!");
				    dot_pattern();
				   
		    }
		    else if(edit_by==2)
		    {
                       while(1)
		       {
			       char new_phone[15];
			       printf("Enter your new mobile number:\n");
			       scanf("%s",new_phone);
			       if(phone_number_validation(new_phone,addressBook)==4)
			       {
				       strcpy(addressBook->contacts[edit_index].phone,new_phone);
				       dot_pattern();
				       printf("%43s\n","phone number updated!");
				       dot_pattern();
                                       break;
			       }
			     
		       }
		    }
                    else if(edit_by==3)
		    {
                         while(1)
                       {
                               char new_email[50];
                               printf("Enter your New Email Id:\n");
                               scanf(" %[^\n]",new_email);
                               if(email_validation(new_email,addressBook)==0)
                               {
                                       strcpy(addressBook->contacts[edit_index].email,new_email);
                                       dot_pattern();
                                       printf("%43s\n","email id updated!");
                                       dot_pattern();
                                       break;
                               }

                       }
		    }
           }
            // Display updated contacts
printf("%-5d %-20s %-15s %30s\n",edit_index+1,addressBook->contacts[edit_index].name,addressBook->contacts[edit_index].phone, addressBook->contacts[edit_index].email);
              dot_pattern();
}

void deleteContact(AddressBook *addressBook)
{
    int i,j,match = 0;
    dot_pattern();
    printf("Delete menu:\n"); // function to delete your contact;
    dot_pattern();
    printf("1. detete by your name\n");
    printf("2. delete by your phone number\n");
    printf("3. delete by your email id\n");
    dot_pattern();
    int choice4; // choice your choice to delete your contact;
    printf("Enter the choice to delete your contact\n");
    scanf("%d",&choice4);
    switch(choice4)
    {
	    case 1:
		    printf("Enter your name to delete your contact:\n");
		    break;
	    case 2:
		    printf("Enter your mobile number to delete your contact:\n");
		    break;
	    case 3:
		    printf("Enter your email id to delete your contact:\n");
		    break;
	    default:
		    printf("invalid input please choice range [1-3]\n");
    }
		  char temp[50];
		  scanf(" %[^\n]",temp); // read the input from user;
		int found1 = 0;
     for(i = 0; i<addressBook->contactCount;i++)
     {
	     if(choice4==1&&strcmp(addressBook->contacts[i].name,temp)==0)
	     {
		     match = 1;
	     }else if(choice4 == 2&&strcmp(addressBook->contacts[i].phone,temp)==0)
	     {
		     match = 1;
	     }
	     else if(choice4 == 3&&strcmp(addressBook->contacts[i].email,temp)==0)
             {
		     match = 1;
	     }
	     if(match)
	     {
		     found1 = 1;
		     for(j = i; j<addressBook->contactCount-1;j++)
		     {
			     addressBook->contacts[j] = addressBook->contacts[j+1]; // contact is deleted;
		     }
		     addressBook->contactCount--;
		     
	     }
     }  
     if(!found1)
     {
	     printf("Not Found\n");
     }
     else
     {
	     printf("contact successfully deleted\n");
     }



}
int phone_number_validation(char num[],AddressBook *addressBook)
{
	// function for email validation;
   int validation = 0,i = 0;
                    if(strlen(num)==10)
                   {
                           validation = 1;
		         if(validation==1)
			{
			  while(num[i]!='\0')
			  {
				  if(!isdigit(num[i]))
				  {
				    
		                     return 2;
				  }
				  else
				  {
			 
					  validation = 2;
				  }
				  i++;
			  }
			  if(validation==2)
			  {
					 for(i = 0;i<addressBook->contactCount;i++)
					 {
						 if(strcmp(addressBook->contacts[i].phone,num)==0)
						 {
						   return 3;
						   
						 }
						 
			                 }
					 validation = 3;
		          }
			  
		        }
		  }
                  else
		  {
		    return 1;
		  }
		  if(validation == 3)
		  {
		     return 4;
		  }
                     			    
		   // if phone number is valid return 4;
}                   
int choice(int temp)
{         
	   switch(temp) // choice for search contact;
	  {
		  case 1:
			  return 1;
			  break;
	           case 2:
			  return 2;
			  break;
		   case 3:
			   return 3;
			   break;
		   default:
			   printf("Invalid input: please choice your number range:(1,3)\n");

          }
}

int email_validation(char *email,AddressBook *addressBook)
{
    // function for email validation;
int i = 0,flag = 0,success = 0;


               if (!strstr(email, "@") || strcmp(&email[strlen(email)-4], ".com") != 0)
               {
                   return 1;  // Invalid format
               }
               else
               {      
                    for(i = 0; i < strlen(email); i++)
		    {
			    if(i>0&&email[i]=='@')
		            {
			             if(isalnum(email[i-1])&&isalnum(email[i+1]))
				    {
					    flag = 1;
					    break;
				    }
				  
			   }
			    
	           }
		   if(flag==0)
		   {
			   return 2;
		   }

			     
			   i = 0;  
			 while(email[i] != '\0')
		      {
                         if (isupper(email[i]))
                         {
                           return 3;
                         }
                          if (isspace(email[i]))
                         {
                            return 4;
                         }
                          i++;
                     }

                      for (i = 0; i < addressBook->contactCount; i++)
                     {
                            if(strcmp(addressBook->contacts[i].email, email) == 0)
                          {
                             return 5;
                          }
                     }
		      success = 1;
              }
    if(success==1)
    {
      return 0;  // Email is valid
    }
}



           








       

	




