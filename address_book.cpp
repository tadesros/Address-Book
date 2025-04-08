/***************************************************

  File:     address_book.cpp
  
  Purpose:  This is the implementation for the address_book
            class.

****************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "address_book.h"
#include <assert.h>
#include <ostream>
#include "Time.h"

using namespace std;



  
	         //**************************************************
             // **************** Public Functions. **************
             //**************************************************



	   /*------------------------------------------

         Function:  Constructor

         PURPOSE: To build the address_book object.

         PRE: An address_book object is declared.

         POST: The address_book input file is read in and
			   saved in an array of records (structs)


		--------------------------------------------*/
           address_book::address_book()
		   {

			   //Local Data
			     bool open_ok = false;

              //Get the filename and num. files for the master file.
                get_master_data();

			  //Set member values for largest_so_far, and max_files
				max_files = MAX_RECORDS;
			
			 //Open the master file.
                open_ok = Initialize_Input_File(master_file);

			 //Did file open ok?
			  while (open_ok == false)
			  {

				  cout<<"\n\n\t Your file failed to open Try again please!!";

				  //Get the filename and num, files for the master file.
				    get_master_data();

				  //Open the master file.
					open_ok = Initialize_Input_File(master_file);
			  }


            //Read in the data from the master file and store in 
			//the list (array of structs).
               read_master_data();
		   };


         /*-----------------------------------------

            Function: update

             PURPOSE: To update the address book.

             PRE:  A declared address_book object.

             POST: The address_book transaction file is 
			       opended.
				    
				   The records are updated according to 
				   the commands in the transaction file.

          -------------------------------------------*/
		   void address_book::update()
		   {

			   //Local Data
			     bool open_ok;  


                //Get transaction files name
			      get_trans_name();

				//Open the transaction file.
                  open_ok = Initialize_Input_File(update_file);


			 //Did file open ok?
			  while (open_ok == false)
			  {

				  cout<<"\n\n\t Your file failed to open Try again please!!";

				  //Get the filename and num, files for the master file.
				    get_trans_name();

				  //Open the master file.
				    open_ok = Initialize_Input_File(update_file);

			  }


            //Read in the data from the master file and store in 
			//the list (array of structs).
               update_master();

		   };

		  /*-----------------------------------------------

             Function: update_master

             PURPOSE: To update the master file then display
     		          results.
  
           -----------------------------------------------*/
		   void address_book::update_master()
		   {


               //Local Data
			     char command;   //Character to read in first command 
				                 //of transaction file.

			     bool  end_of_file = false; //check to see
				                           //if the end of file has 
				                           //been reached.

              do
			  {

                 //Get first character.
				  in_stream.get(command);

				 //Check to see if eof has been reached.
				   if(in_stream.eof())
				   {
					   end_of_file = true;
				   }
			
				   else
				   {
                 //If not at end  of file do appropriate action.
				   switch (command)
				   {

				      case 'A':
					  case 'a':

                             //Call the add function.
						         add();
                  
				     		      break;

					  case 'D':
					  case 'd':
						      
						  // Call delete record
						     delete_record();
						     break;



					  case 'C':
					  case 'c':
                               //Call change record
						         change();

						    break;


					  default:
						   
						    cout<<"\n\n\t Error - Invalid transaction command";
                            exit(1);


               

				   }//end of switch
				   }//end of else
			  }while(end_of_file != true);

		   };

		/*-----------------------------------------
			   Destructor: 

              PURPOSE: To deallocate all dynamic memory.
          -----------------------------------------*/
		   address_book:: ~address_book()
		   {

               //Close all input streams, and output.
                 close_output();
				 Close_File();

		   };

  
                    //$$$$$$$$$$$$$$$$  PRIVATE FUNCTIONS $$$$$$$$$$$$$$$$$$$$$

        

      //-----------------------------------------
	  // Function:  get_master_data
      //
	  // Purpose: To get the name of the master file
	  //          (less than 30 characters)
      //--------------------------------------------
		   void address_book::get_master_data()
		   {

              cout<<"\n\n\t Please enter the master file name. ";
			  cout<<"\n\t (no greater than 30 characters): ";

			  cin>>master_file;
		
		   };

	 //--------------------------------------------------------
	 //
	 // Function:  INITIALIZE INPUT FILE
	 //
     //---------------------------------------------------------
		   bool address_book::Initialize_Input_File (const char filename[])
		   {


           in_stream.open(filename);

		
		   if (in_stream.fail())
		   {

		   in_stream.close();
		   in_stream.clear();

		   return false;
		   
		   }

	       else 
		   {

		   return true;
	 
		   }


   }//##################End of Initialize.#####################

     //--------------------------------------------------------
	 //
	 // Function:  read_master_Data
	 //
  	 //---------------------------------------------------------
		   void address_book::read_master_data()
		   {
               //Local Data
			     int count = 0;
				 char end_check;
				 bool done = false;
               


               //Read in Data and assign to appropriate record.
				while(done != true)
				 {
					in_stream.getline(list[count].last, 15, '\n');

					in_stream.getline(list[count].first, 10, '\n');

                    in_stream>>list[count].social;

					in_stream.ignore(100, '\n');

					in_stream.getline(list[count].street, 25, '\n');

					in_stream.getline(list[count].city, 15, '\n');

					in_stream.getline(list[count].state, 4, '\n');

					in_stream>>list[count].zip;

					in_stream>>list[count].rate;

					in_stream>>list[count].dependents;

					list[count].in_use = true;

					in_stream.ignore(100, '\n');
					in_stream.ignore(100, '\n');


                    //Increment 
					  count++;

					

                    //Check to see if end of file has been reached.


                     //Get next character in stream.
	                  in_stream.get(end_check);
 
		            if(!in_stream.eof())
					{
			          //Put the character back into the stream.
 	            	    in_stream.putback(end_check);
		
					}

					else //if(in_stream.eof())
						{
							
				          done = true;
					}
   

				 } 
          
				  //Close the file.
				    Close_File();

				 };

	 //-------------------------------------------------------
	 //	
	 //	Close all input streams.
     //-------------------------------------------------------
		   void address_book::Close_File()
		   {
			   in_stream.close();
		   };

     //--------------------------------------------------------
	 //
	 // Function:  get_trans_name()
	 //
	 //---------------------------------------------------------
		   void address_book::get_trans_name()
		   {
			  cout<<"\n\n\t Please enter the transaction file name. ";
			  cout<<"\n\t (no greater than 30 characters): ";

			  cin>>update_file;

		   };

       /*-----------------------------
	       Function: Display 

         -----------------------------*/
		   void address_book::display()
		   {
			   //Display the records.
                 

				 for(int count = 0; count < max_files; count++)
				 {

                    if(list[count].in_use == true)
					{

                          display_record(count+1);
					}
						 }

		   };

      //-------------------------------
	  //Function: Move on.
	  //------------------------------
		   void address_book::move_on()
		   {

			   char move;


			   cout<<"\n\n\t Enter any key to move on: ";
			   cin>>move;
		   };

    /*-------------------------------
	  Function Initialize_new_master.
      ---------------------------------*/
      bool address_book::initialize_new_master(char file_name[])
	  {
	
  
			out_stream.open(new_master_file);

			if(out_stream.fail())
			{   

				out_stream.close();
				out_stream.clear();
				
				return false;
			}
            else
			{

                 return true;
			}



}//##################End of Initialize.#####################3

	  /*--------------------------------

        Function: close_input_file

        -------------------------------*/
	     void address_book::close_output()
		 {

             
                out_stream.clear();
                out_stream.close();

		 };

		 /*------------------------

            Function: add()
		   -----------------------*/
	    	 void address_book::add()
			{

                //Local Data
				  int record_number;  //the record number to add it at.
                  int index = 0;

       		    //get record #
               	  in_stream>>record_number;
                  
				  index = record_number - 1;

                //Error check: make sure not out of range or
				// already in use.
				  if(record_number > max_files)
				  {
				     cout<<"\n\n\tERROR: Your tried to add beyond the capability of this file!!";
					 cout<<"\n\tYour transaction request will be ignored.";
       
					 cout<<"\n\tNow moving on to next transaction.";
					 
					 //Function skip moves input stream pointer
					 // to next transaction command.
					   skip_record();
					 
					    Time_Delay(3);
				  
				  }

                 else if(list[index].in_use == true)
				 {

					 cout<<"\n\n\t ERROR: You tried to add on to an already"; 
					 cout<<"\n\t existing record. Your transaction request will";

					 cout<<"\n\t will be ignored!!";
                 
                     cout<<"\n\t Now moving on to next  transaction.";

					 //Function Skip moves the input stream 
					 //To point at right spot.
                     skip_record();
					 Time_Delay(3);
				 }
                 else
				 {

                  //Ok its valid add the record.
                    cout<<"\n\n\t Now inserting Record #: "<<record_number;
				   

				  //Time_Delay
					Time_Delay(3);

				    cout<<"\n\n\t Record #: "<<record_number<<" has been inserted successfully!!";
					cout<<"\n\t Here it is: ";

                  //Set the index.
					index = record_number - 1;



                  //Read in record and put it in place in array.
                    in_stream.ignore(100, '\n');
			        in_stream.getline(list[index].first, 15, '\n');
					in_stream.getline(list[index].last, 10, '\n');
                    in_stream>>list[index].social;
					in_stream.ignore(100, '\n');
					in_stream.getline(list[index].street, 25, '\n');
					in_stream.getline(list[index].city, 15, '\n');
					in_stream.getline(list[index].state, 4, '\n');
					in_stream>>list[index].zip;
					in_stream>>list[index].rate;
					in_stream>>list[index].dependents;
					list[index].in_use = true;
					in_stream.ignore(100, '\n');
					in_stream.ignore(100, '\n');
				
					//Display the record just inserted.
				      display_record(record_number);	  

				 }      
			};

             //-----------------------------------------
			 //	Function: Time_Delay
		     //-----------------------------------------
		 	 void address_book::Time_Delay(int seconds)
			 {

		        	cout.flush();
		            cout<<"\n\n\t.......";
		                   //Local data
			               time_t tm = time(NULL)+seconds;
   

	               	while(time(NULL)<tm);
	 
			 }//################## End Time Delay.########################	 

			 /*--------------------------------------------

                   Function: display_record

                   Purpose: To display the contents of a specified
				            record number.

                   PRE: an already exising record.

                   POST: Dislay the specified record.
			 ----------------------------------------------*/
			 void address_book::display_record(int record_num)
				{

                       //Set index -- one less than record_num
				         int index;

						  index = record_num -1;

                    cout<<"\n\n\n\t  Record number #"<<record_num;

					cout<<"\n\n\t Last Name:  "<<list[index].last;
					cout<<"\n\t First Name: "<<list[index].first;
					cout<<"\n\t Social:     "<<list[index].social;
					cout<<"\n\t Street:     "<<list[index].street;
					cout<<"\n\t City:       "<<list[index].city;
					cout<<"\n\t State:      "<<list[index].state;
					cout<<"\n\t Zip:        "<<list[index].zip;
					cout<<"\n\t Rate:       "<<"$"<<list[index].rate;
					cout<<"\n\t # Depend:   "<<list[index].dependents;
 

					 //Move on after viewing the record.
                      move_on();

				};

         /*---------------------------------------
			 Function: skip_record
			 Purpose: This function skips to the next record.

    		  Warning! use only with transaction files.
	      	-----------------------------------------*/
			 void address_book::skip_record()
			 {
                   
					 for(int counter = 1;  counter <= 11; counter++)
					 {
                       in_stream.ignore(100, '\n');
					 }
               
			 };// +++++++++++++++End of the Function  skip_record()++++


		   /************************************

			   Function: delete_record()

               Purpose: Delete the record. 
			 ***********************************/
			 void address_book::delete_record()
			 {
                 //Local Data
				  int record_number;  //the record number to add it at.
                  int index = 0;

				  //Get record #
               	  in_stream>>record_number;

                  index = record_number - 1;


				//Check to see if their is a record currently at 
				//that index.
				  if(list[index].in_use == true)
				  {
                     cout<<"\n\n\t Now deleting record #: "<<record_number;
					 Time_Delay(2);

                     list[index].in_use = false;

					 cout<<"Deleted";
				  }
                  else if(record_number > max_files)
				  {

                     cout<<"\n\n\tERROR: That record number is too large!!";
					 cout<<"\n\t Moving on to next transaction.";

					 Time_Delay(3);

				  }
				  else 
				  {

                      cout<<"\n\n\tERROR: Their is no record to delete!!";
                      cout<<"\n\t Moving on to next transaction.";

          				  Time_Delay(3);

				  }


                 //Move index stream to next record.
				   in_stream.ignore(100, '\n');
				   in_stream.ignore(100, '\n');

			 };//+++++++++++++++++++ Delete +++++++++++++++++++++




        /*----------------------------------------------
            Function: Change
			  
		    Purpose: To change an existing record.

            ---------------------------------------------*/
			 void address_book::change()
			 {

                 //Local Data
				   int record_number = 0;
                   int index = 0;
				   char check_next;


                 //Read in record from the stream.
				   in_stream>>record_number;
				   

                   index = record_number - 1;

				 //Check validity of record_number.
				   if(record_number > max_files)
				   {

					   cout<<"\n\n\t ERROR: That record number is too large";
					   cout<<"\n\t          It's record doesn't exists.";

					   cout<<"\n\t Moving on to next transaction";
                       
					   skip_record(); 
					   Time_Delay(3);
				   }

				   else if(list[index].in_use != true)
				   {
					   cout<<"\n\n\t ERROR: That record doesn't exist so it";
					   cout<<"\n\t          cannot be changed!!";
					   cout<<"\n\t Moving on to next transaction.";
					   
					   Time_Delay(3);

					   skip_record();

                   }

				   else if(list[index].in_use == true)
				   {

                      //skip next newline 
                       in_stream.ignore(100, '\n');

                      cout<<"\n\n\t Changing record #: "<<record_number;
					  Time_Delay(3);
                
				  
			//** Repeat these steps for every attribute in record ***
            


                  //** Last **

                      //Check the value of the next character in stream.
                        check_next =  in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream.getline(list[index].last, 15, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                        

                //**First Name**

                       //Check the value of the next character in stream.
                        check_next =  in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream.getline(list[index].first, 10, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                  
						
                //** Social **

					   //Check the value of the next character in stream.
                        check_next =  in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream>>list[index].social;
								in_stream.ignore(100, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                    
                //** Street **

                       //Check the value of the next character in stream.
                          check_next =  in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream.getline(list[index].street, 25, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                        


			//** City **

					//Check the value of the next character in stream.
                        check_next =  in_stream.peek();
						


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream.getline(list[index].city, 15, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                        
                 
				//**State**


                      //Check the value of the next character in stream.
                        check_next = in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream.getline(list[index].state, 4, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                        


                 //** ZIP **

				      //Check the value of the next character in stream.
                         check_next =  in_stream.peek();


					  //Check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream>>list[index].zip;
								in_stream.ignore(100, '\n');
                 
						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                        
                //** Rate of Pay **

                    //Check the value of the next character in stream.
                        check_next =  in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream>>list[index].rate;
								in_stream.ignore(100, '\n');

						}
                        else
						{
                           //Skip ahead.
                             in_stream.ignore(100, '\n');

						}
                 
                   //** Dependents **
                       

						 //Check the value of the next character in stream.
                           check_next =  in_stream.peek();


					  //check if it's a '*' then don't change.
					    if(check_next != '*')
						{

                              //Read in the first name.
   							    in_stream>>list[index].dependents;
                                in_stream.ignore(100, '\n');

						}
                        else
						{
                             //Skip ahead.
                                in_stream.ignore(100, '\n');

						}



                         //Skip the next newline.
						   in_stream.ignore(100, '\n');   


                        //Display the changed Record.
						   cout<<"\n\n\t Record #: "<<record_number;
						   cout<<" now looks like this. ";

                           Time_Delay(2);

						   display_record(record_number);
                      

				}
                else
				   {


                      cout<<"\n\n\t Something went wrong!!";
					  cout<<"\n\t  Moving on.";
					  Time_Delay(3);

					  skip_record();
				   }
                 

			 };



              /*-------------------------------------------------
              Function: Write_new_master
   
              Purpose: To create a new master file.
					     
					   Then writes the new info. to 
					   this file.
   		      ----------------------------------------------*/
			  void address_book::create_updated_master()
			   {
                    
            
                  //Local Data
				    bool open_check = false;

                do
				{
				  //Get new file name.
				    cout<<"\n\n\t Enter a filename up to 30 characters";
					cout<<"\n\t max for your new master file: ";
                  
					cin>>new_master_file;


                  //Initialize the file.
					 open_check = initialize_new_master(new_master_file);
				    
				    
                  //Check if created ok.
					 if (open_check == false)
					 {

						 cout<<"\n\n\tERROR: you file could not be created properly!!";
						 cout<<"\n Try another name";
					 }


				}while (open_check == false);


               //Loop to traverse through the records.
				 for(int count = 0; count < max_files; count++)
				 {


                       if (list[count].in_use == true)
					   {

						   //Write to file.
						    out_stream<<list[count].last<<"\n"
							        <<list[count].first<<"\n"
                                    <<list[count].social<<"\n"
									<<list[count].street<<"\n"
									<<list[count].city<<"\n"
									<<list[count].state<<"\n"
									<<list[count].zip<<"\n"
    								<<list[count].rate<<"\n"
									<<list[count].dependents<<"\n\n";
				
					   }
			 }


			   };















