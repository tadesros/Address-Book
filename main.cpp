/************************************************************

   File: File_Processing.cpp

   Purpose: To use the address book and create record classes
            to build a file processing system.


***************************************************************/
#include "create_record.h"
#include "address_book.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

    //Display  intro
	   cout<<"\n\n\t          WELCOME TO THE FILE PROCESSING SYSTEM";


	  
	   // Local Data
	      bool done = false;

		     //Local Data
				bool another = false;
				char  create_choice;
			    char more_rec;

	  //char check
	
		  char main_choice;
do
{
    
	     //main menu
	       cout<<"\n\n\n\n\n\t       Main Menu";

		   cout<<"\n\n\t[1] File creation";
		   cout<<"\n\n\t[2] Master File update";
		   cout<<"\n\n\t[3] Quite";


		//Get choice
		   cout<<"\n\n\n\tChoose 1,2 or 3: ";
		   cin>>main_choice;
		  

		   cin.ignore(100, '\n');


		   switch (main_choice)
		   {

		   case '1':


			     do
				 {
                

					  Create_Record new_rec;

                   //Display file input menu.
			        cout<<"\n\n\t  FILE CREATION";

					cout<<"\n\n\t[1] Create Master File";
					cout<<"\n\n\t[2] Create Transaction File";
					cout<<"\n\n\t[3] Main Menu";
					


					cout<<"\n\n\tEnter your choice from above: ";
					cin>>create_choice;



					switch   (create_choice)
					{

					case '1':


						new_rec.create_master_file();
						break;



					case '2':

						  
						new_rec.create_trans_file();
						break;

					case '3':
                           
						done = false;
						another = false;
						break;
				}

					if(create_choice != '3')
					{

					cout<<"\n\n\t Would you like to create another?";
					cout<<"\n\t Enter 'Y' for yes any other is a no: ";

					cin>>more_rec;
					
					if(more_rec == 'Y' || more_rec == 'y')
					{
						another = true;
						done = false;						
					}
					else
					{
						another = false;
					}
					}//end of check for another.



                 }while(another == true);


     			   break;


		   case '2':
						  char all_done;
						  bool checker;

	          do
				 {
			     
     		       //Declare the address book. 
					  address_book my_book;
				
					  checker = true;

			          cout<<"\n\n\t MASTER FILE UPDATE";


					//Display file
					  my_book.display();

					//Make changes by from transaction file.
					  my_book.update();

					  my_book.create_updated_master();

					 //Display
					  my_book.display();

					  cout<<"\n\n\t If you would like quite enter Q"
						  <<"\n\t Any other entry goes to main menu: ";

					  cin>>all_done;
                      cin.ignore(100, '\n');


					  if(all_done == 'q' || all_done == 'Q')
					  {
						  checker = false;

						  done = true;

						  cout<<"\n\n\t GOOD BYE!!";
					  }

				 }while(checker == true);

         			     break;


		   case '3':
			       
 
			    
			      cout<<"\n\n\t Goodbye!!";
			      done = true;

			      break;



		   default:
			     
			    cerr<<"\n\n\t Error!! Invalid entry now exiting!!";
				exit(1);

		        break;

		   }

		 

}while(done == false);
    return 0;
}

