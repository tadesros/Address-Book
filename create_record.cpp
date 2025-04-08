/****************************************************

    This is the definition of the create_file class

******************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "create_record.h"
#include <assert.h>
#include <ostream>
#include "Time.h"
#include <iomanip>
#include <ctype.h>
#include <math.h>
//#include <crtdbg.h>

using namespace std;




   /****************************

     The Public Functions

    ****************************/




            //Constructor.
             Create_Record::Create_Record()
			 {

				 //Set the maximum values
				   max = MAX_SIZE;

			 };



            /*--------------------------------------------
              Function:  create_master_file
 
              Purpose:   This function creates a master file.

              PRE:  none

              POST: Returns true if it was created properly.
			        Otherwise returns false.
		     ---------------------------------------------*/
             bool Create_Record::create_master_file()
			 {

                    //**Local Data**
				  
				       char done;
					   bool open_check = false;
					   bool ok = false;
				
				   	//Output Stream
			           ofstream out_stream;


					   
						 

            // ****PROCEDURE****

			do
			{

				 //Get the master file name.
					 get_filename();

				 //Create the file - and open output stream.



					  //Initialize the file.
					    open_check = initialize_new_file();
				    
				    
                  //Check if created ok.
					 if (open_check == false)
					 {

						 cout<<"\n\n\tERROR: you file could not be created properly!!";
						 cout<<"\n Try another name";
					 }


				}while (open_check == false);


         //***Get the info and write to output stream.***
			

				 do
				 {

					 //Declare a new master record object.
			           master_rec   master_record;

					 do
					 {
                     

				   //Get the master file record from user.
                       input_master_record(master_record);


				   //Write the master file to the output stream.
					   ok = display_master_record(master_record);
					
                   //If ok == true then write --else reenter.
                       if(ok == false)
					   {
						   cout<<"\n\n\t Please re-enter your record. ";
					   }

   	 
          
                     }while(ok != true);


	            //Write the record to the master file.
                    write_master_record(master_record);
				  
				
					
               
          

				//Do they want to enter another record???
				   cout<<"\n\n\t If you would like to enter another record"
				       <<"\n\t Enter a 'Y' or 'y'-- any other entry will be"
					   <<"\n\t assumed to be a no: ";

				   cin>>done;

				 
				   done = toupper(done);


                 }while(done == 'Y');

                


				 //Close the ouput
				   close_output();

				   return true;

			 };





            /*--------------------------------------------
              Function: create_trans_file

              Purpose:  to create a transition file

              PRE:  none

              POST: A transition file is created, in the 
			        proper form to be used in the address_book
					class
		     ---------------------------------------------*/
             bool Create_Record::create_trans_file()
			 {

                      //**Local Data**
				  
				       char done;
					   bool open_check = false;
					   bool ok = false;
				
				   	//Output Stream
			           ofstream out_stream;

						 

         //    ****PROCEDURE****

			do
			{

				 //Get the master file name.
					    get_filename();

				 //Create the file - and open output stream.

					  //Initialize the file.
					    open_check = initialize_new_file();
				    
				    
                  //Check if created ok.
					 if (open_check == false)
					 {

						 cout<<"\n\n\tERROR: your file could not be created properly!!";
						 cout<<"\n Try another name";
					 }


				}while (open_check == false);


         //***Get the info and write to output stream.***
    			 do
				 {

					 //Declare a transaction record object.
			           trans_rec trans_record;

                     

		      //Get the transaction file record from user.
                       input_trans_record(trans_record);

 
    	            //Write the record to the master file.
                        write_transaction_record(trans_record);
				  
              
          

				//Do they want to enter another record???
				   cout<<"\n\n\t If you would like to enter another record"
				       <<"\n\t Enter a 'Y' or 'y'-- any other entry will be"
					   <<"\n\t assumed to be a no: ";

				   cin>>done;

				 
				   done = toupper(done);


                 }while(done == 'Y');

                


				 //Close the ouput
				   close_output();

				   return true;

			 
				 };





             /*--------------------------------------------
              Function:  Destructor

              Purpose:   To close down any loose ends.

              PRE:  None

              POST: all outside files are closed.
		     ---------------------------------------------*/
			 Create_Record::~Create_Record()
			 {





			 };


      


				/***    Private Functions  ***



   	        /*--------------------------------------------
              Function: get_filename

              Purpose:  To get the filename (less 30) from user

              PRE:  none

              POST: The filename is set
		     ---------------------------------------------*/
			 void Create_Record::get_filename()
			  {

                  
				 cout<<"\n\n\t Enter the name of the file you wish to create."
				     <<"\n\n\t The filename must be less than 30 char. long: ";
					
				 cin>>file_name;

				

			  };
	    




             /*--------------------------------------------
              Function:	Input_record_master

              Purpose:  Get the data for a master record.

              PRE:        

              POST:   The private member struct is filled
			          with data.
		     ---------------------------------------------*/
			  void Create_Record::input_master_record(master_rec& record)
			  {
			 			    
					  
				       cin.ignore(100, '\n');

                       cout<<"\n\n\n\tLast Name (15 char): ";
					   cin.getline(record.last, 15, '\n');


					   cout<<"\n\tFirst Name (10 char): ";
                       cin.getline(record.first, 10, '\n');

					   cout<<"\n\tSoc. Sec. (9 digits)#: ";
					   cin>>record.social;
					   cin.ignore(100, '\n');


					   cout<<"\n\tStreet (25 char.): ";
					   cin.getline(record.street, 25, '\n');


					   cout<<"\n\tCity (15 char): ";
					   cin.getline(record.city, 15, '\n');


					   cout<<"\n\tState (2 char): ";
					   cin.getline(record.state, 4, '\n');


					   cout<<"\n\tZip (5 digits): ";
					   cin>>record.zip;
					   cin.ignore(100, '\n');


					   cout<<"\n\tRate Pay (5 num, 2 decimal): ";
                       cin>>record.rate;

					   cin.ignore(100, '\n');


					   cout<<"\n\tNumber of Depend.: ";
					   cin>>record.dependents;
    				   cin.ignore(100, '\n');

  		  };



			/*-----------------------------------------------
              Function: input_trans_record(master_rec record&)

              Purpose:  to create a transition file

              PRE:  none

              POST: A transition file is created, in the 
			        proper form to be used in the address_book
					class
		     ------------------------------------------------*/
              void Create_Record::input_trans_record(trans_rec& record)
			  {


				       cin.ignore(100, '\n');

                       cout<<"\n\tEnter transaction command: ";
					   cin>>record.command;
					   cout<<"\n\tEnter record number: ";
					   cin>>record.record_number;


					  				   
					   record.command = toupper(record.command);

					   

					   switch  (record.command)
					   {

					   case 'A':

						  
							   cin.ignore(100, '\n');

							  cout<<"\n\tLast Name (15 char): ";
							  cin.getline(record.last, 15, '\n');
					   	      cout<<"\n\tFirst Name (10 char): ";
						      cin.getline(record.first, 10, '\n');

						      cout<<"\n\tSoc. Sec. (9 digits)#: ";
					          cin>>record.social;
					          cin.ignore(100, '\n');


					          cout<<"\n\tStreet (25 char.): ";
					          cin.getline(record.street, 25, '\n');


					          cout<<"\n\tCity (15 char): ";
					          cin.getline(record.city, 15, '\n');


					          cout<<"\n\tState (2 char): ";
					          cin.getline(record.state, 4, '\n');


					          cout<<"\n\tZip (5 digits): ";
					          cin>>record.zip;
					          cin.ignore(100, '\n');


					         cout<<"\n\tRate Pay (5 num, 2 decimal): ";
                             cin>>record.rate;

					         cin.ignore(100, '\n');
					         cout<<"\n\tNumber of Depend.: ";
					         cin>>record.dependents;
     				         cin.ignore(100, '\n');


					        break;
       

					   case 'D':

								  cin.ignore(100, '\n');
						      
						        //do nothing
                               
								break;

					   case 'C':

						        //Character to check.
						           char check;

                              
							   cout<<"\n\n\t Enter a '#' key if you want to leave the field as is: \n";
							   cin.ignore(100, '\n');
						
							   //Last name
							   cout<<"\n\tLast Name (15 char): ";
							   check = cin.peek();

							  

							  if(check != '#')
							  { 
								   cin.getline(record.last, 15, '\n');
								   cout<<record.last;
								   record.change[0] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[0] = false;
							  }
                   
                              
					   	      cout<<"\n\tFirst Name (10 char): ";
							  check = cin.peek();

							  if(check != '#')
							  {
									
								  cin.getline(record.first, 100, '\n');
								  record.change[1] = true;

							  }
							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
									record.change[1] = false;
							  }
							  
						  
						     //***Social Security
							   cout<<"\n\tSoc. Sec. (9 char): ";
							   check = cin.peek();


							  if(check != '#')
							  { 
								   cin>>record.social;
								   cin.ignore(100, '\n');
								   record.change[2] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[2] = false;
							  }
                   
                              

                            //***Street***
							   cout<<"\n\tEnter Street(25 char): ";
							   check = cin.peek();


							  if(check != '#')
							  { 
								   cin.getline(record.street, 25, '\n');
								   record.change[3] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[3] = false;
							  }
                   
                              
							//***City***
							   cout<<"\n\tCity (15 char): ";
							   check = cin.peek();


							  if(check != '#')
							  { 
								   cin.getline(record.city, 15, '\n');
								   record.change[4] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[4] = false;
							  }
                   


                              
                           //***State***
							   cout<<"\n\tState (2 char): ";
							   check = cin.peek();


							  if(check != '#')
							  { 
								   cin.getline(record.state, 4, '\n');
								   record.change[5] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[5] = false;
							  }
                   
							  


                             //*****Zip****
							   cout<<"\n\tZip Code (5 digits): ";
							   check = cin.peek();


							  if(check != '#')
							  { 
								   cin>>record.zip;

								   cin.ignore(100, '\n');

								   record.change[6] = true;
								 
							  }
							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[6] = false;
							  }
                   
                              

             
					          //**Rate of Pay**
							    cout<<"\n\tRate of Pay (5 integers): ";
							    check = cin.peek();


							  if(check != '#')
							  { 
							       cin>>record.rate;
								   cin.ignore(100, '\n');
								   record.change[7] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[7] = false;
							  }
                   


                             //**Number of Dependents**
							   cout<<"\n\tDependents one-digit: ";
							   check = cin.peek();


							  if(check != '#')
							  { 
								   cin>>record.dependents;
								   cin.ignore(100, '\n');
								   record.change[8] = true;
								 
							  }

							  else
							  {

                                    cin>>check;
					     			cin.ignore(100, '\n');
								    record.change[8] = false;
							  }
                       
            						        break;
					
                       default :

						   break;

					   }
					   
			  };
   
			  


        /*--------------------------------

            Function: close_input_file

        -------------------------------*/
	     void Create_Record::close_output()
		 {

             
                out_stream.clear();
                out_stream.close();

		 };



	/*-------------------------------
	  Function Initialize_new_master.
      ---------------------------------*/
      bool Create_Record::initialize_new_file()
	  {
	
  
			out_stream.open(file_name);

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


  };






	         /*--------------------------------------------

                   Function: display_record

                   Purpose: To display the contents of a Record

   

                   POST: Returns true if ok with user.
				         Returns fals if otherwis.
			 ----------------------------------------------*/
			 bool Create_Record::display_master_record(const master_rec record)
				{
                   
				     //Local Data
				       char move;
                      

               

					cout<<"\n\n\t Last Name:   "<<record.last;
					cout<<"\n\t First Name:  "<<record.first;
					cout<<"\n\t Social:      "<<record.social;
					cout<<"\n\t Street:      "<<record.street;
					cout<<"\n\t City:        "<<record.city;
					cout<<"\n\t State:       "<<record.state;
					cout<<"\n\t Zip:         "<<record.zip;
					cout<<"\n\t Rate:       $ "<<record.rate;
					cout<<"\n\t # Depend:    "<<record.dependents;
 

				  cout<<"\n\n\t Enter 'Y' or 'y' if this record is ok"
				      <<"\n\t Any other entry will allow you to re-enter the record: ";
				  cin>>move;


				  move = toupper(move);


				  if(move == 'Y')
				  {

					  return true;
				  }
				  else
				  {

					  return false;
				  }
				  
				};



			 /*-----------------------------------------
                 Function: write_master_record

                 Purpose: to write the record to the file.

                 POST: the file has been written to the file.
			-------------------------------------------------*/
			 void Create_Record::write_master_record(const master_rec record)
				{

                   //Write the record to the master_rec object.

				   

					 //Write to file.
    					   out_stream<<record.last<<"\n"
							        <<record.first<<"\n"
                                    <<record.social<<"\n"
									<<record.street<<"\n"
									<<record.city<<"\n"
									<<record.state<<"\n"
									<<record.zip<<"\n"
    								<<record.rate<<"\n"
									<<record.dependents<<"\n\n";


				};




         	/*-----------------------------------------
                 Function: write_transaction_record

                 Purpose: to write the record to the file.

                 POST: the file has been written to the file.
			-------------------------------------------------*/
			 void Create_Record::write_transaction_record(const trans_rec record)
				{

                     switch (record.command)
					 {

					 case  'A':


						    out_stream<<'A'<<record.record_number<<'\n'
								      <<record.last<<'\n'
									  <<record.first<<'\n'

								//Write to file.
                                    <<record.social<<'\n'
									<<record.street<<'\n'
									<<record.city<<'\n'
									<<record.state<<'\n'
									<<record.zip<<'\n'
    								<<record.rate<<'\n'
									<<record.dependents<<'\n'<<'\n';

						     


					        break;


					 case  'D':
						   
						        out_stream<<record.command<<record.record_number<<'\n'<<'\n';


						    break;


					 case 'C':

                                  out_stream<<record.command<<record.record_number<<'\n';

						       
                                 //Check each field for change.
						          //Check Last
						            if(record.change[0] == true)
									{
                                        out_stream<<record.last<<'\n';
									
									}
									else
									{
										out_stream<<'*'<<'\n';
									}

						          //Check First
									if(record.change[1] == true)
									{
                                        out_stream<<record.first<<'\n';
									}
									else
									{
										out_stream<<'*'<<'\n';
									}

						          //Check Social.
									if(record.change[2] == true)
									{
                                        out_stream<<record.social<<'\n';

									}
									else
									{
										out_stream<<'*'<<'\n';
									}



						          //Check Street.
									if(record.change[3] == true)
									{
                                        out_stream<<record.street<<'\n';

									}
									else
									{
										out_stream<<'*'<<'\n';
									}


						          //Check City.
									if(record.change[4] == true)
									{
                                        out_stream<<record.city<<'\n';

									}
									else
									{
										out_stream<<'*'<<'\n';
									}


						          //Check State.
									 if(record.change[5] == true)
									{
                                        out_stream<<record.state<<'\n';

									}
									else
									{
										out_stream<<'*'<<'\n';
									}


						          //check Zip.
									if(record.change[6] == true)
									{
                                        out_stream<<record.zip<<'\n';

									}
									else
									{
										out_stream<<'*'<<'\n';
									}



						          //Check Rate.
									 if(record.change[7] == true)
									{
                                        out_stream<<record.rate<<'\n';

									}
									else
									{
										out_stream<<'#'<<'\n';
									}


						          //Check dependents.
									 if(record.change[8] == true)
									{

                                     out_stream<<record.dependents<<'\n';

									}
									else
									{

										out_stream<<'#'<<'\n';

									}
            

									out_stream<<'\n';


			          			   break;


					 default:

						    exit(1);
					 }
			

};


