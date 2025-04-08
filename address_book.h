#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H
#define MAX_RECORDS 200
/************************************************************************
  File:     address_book.h

  Purpose:  To define the address_book class.
     
    This class reads in personal records from a text
	file then stores them in a dynamic array of structs.

    Changes to the records can be made from another 
	text file (transaction) by the use of the 
	UPDATE function.

     Functionality:

     constructor - opens, and reads in the data from 
	                 the master file.


      update  -  opens transaction file, performs updates.
  
      display  - displays the contents of array.
    
      create_updated_master - writes contents of list to a new 
	                          file. The filename is inputted 
							  by user.

     WARNING:  This class does not display an error message if your
	           input files are not it the proper format!!!!

     PLEASE NOTE:  Your filenames cannot excede 30 characters in lenght.

                  This program cannot hold more than the specified
				  number of files. Default is: 200 unless changed 
				  in the code.
************************************************************************/
#include<fstream>
#include<iostream>
#define MAX_FILE 31

using namespace std;

class address_book
{

   public:
   
	         //*************** Public Functions. ***********

	   /*------------------------------------------

         Function:  Constructor

         PURPOSE: To build the address_book object.

         PRE: An address_book object is declared.

         POST: The address_book input file is read in and
			   saved in an array of records (structs)
	     --------------------------------------------*/
	        address_book();


         /*-----------------------------------------
            Function: update

             PURPOSE: To update the address book.

             PRE:  A declared address_book object.

             POST: The address_book transaction file is 
			       opended.
				    
				   The records are updated according to 
				   the commands in the transaction file.
          -------------------------------------------*/
		   void update();
     
          //------------------ 
	      // Function: Display   
	      //---------------
	         void display();

          /*-------------------------------------------------
              Function: Write_new_master
   
              Purpose: To create a new master file.
					     
					   Then writes the new info. to 
					   this file.

              PRE:  An already declared List.

              POST: A new file is created with the filename
			        inputted from the user. 
					It contains the new information updated
					from the transaction file.
		      ----------------------------------------------*/
		       void create_updated_master();


              /*-----------------------------------------
			   Destructor: 

              PURPOSE: To deallocate all dynamic memory.
              -----------------------------------------*/
			   ~address_book();




     //**********************************
     //          PRIVATE   SECTION
	 //**********************************

     
   private:


	//*********************PRIVATE DATA*****************************************
	        //File names
    	       char  master_file[MAX_FILE];
			   char  update_file[MAX_FILE];
			   char  new_master_file[MAX_FILE];  //new filename after creation.
		   


       
			   int max_files;  //This is the maximum allowed files.
			  
            //#Struct to hold the record info.
		      struct  Record
			  {
              
				  char  last[15];   //Last name
				  char  first[10];  //First name
				  int   social;      //Social security #-up to 9;
				  char  street[25]; //Street
				  char  city[15];   //City
				  char  state[2];   //State
				  int   zip;         //5 numeric
				  float rate;        //rate of pay
				  int   dependents;  //Number of dependents.
				  bool  in_use;       //Boolean .
			                          //indicating whether record is in use.
			  };

             //List of records
			   Record list[200];

			 //Input Stream
			   ifstream in_stream;     
		   
			//Output Stream
			   ofstream out_stream;
  //***********************************************************






                //$$$$$$$$$$$$$$$$  PRIVATE FUNCTIONS $$$$$$$$$$$$$$$$$$$$$

        

      //-----------------------------------------
	  // Function:  get_master_data
      //
	  // Purpose: To get the name of the master file
	  //          (less than 30 characters)
	  //
	  //  PRE:  none
	  //  POST: master filename, and record # are set.
	  //--------------------------------------------
		 void get_master_data();

     //--------------------------------------------------------
	 //
	 // Function:  read_master_Data
	 //
     // Purpose:  To read in the master file data and store it
	 //           in the dynamically allocated array of records.
     //
	 // PRE:   The input stream has been successfully opened
	 //
	 // POST:   The records in the master file have been read in
	 //         and stored in the array of records.
	 //---------------------------------------------------------
		void read_master_data();


	 //-----------------------------------------------------------------
	 //
	 // Function:  get_trans_name()
	 //
	 // Purpose: to get the name of the transaction file.
	 //	
     //  PRE: none
     //
     //      POST: The filename for the transaction file (less than 30 characters)
	 //           is obtained from user.
     //
	 //------------------------------------------------------------------
       void get_trans_name();
  

	 //--------------------------------------------------------
	 //
	 // Function:  INITIALIZE INPUT FILE
	 //
	 // PRE:  A character arrray containing the name of the file 
 	 //       to be opened is sent to the function.
	 //
	 // POST: If the file is opened properly a boolean value
	 //       of TRUE is returned if not a boolean value 
	 //       of FALSE is returned.
	 //---------------------------------------------------------
        bool Initialize_Input_File (const char filename[]);

     

	 //-------------------------------------------------------
	 //	
	 //	Close all input streams.
     //-------------------------------------------------------
		void Close_File();

      /*------------------------------------
          Function: Add

          Purpose: To add the record to List.
          PRE: An already declared list.

		  POST: Add the record to the list.
				  Or if the that spot is full!!
			      Display an error.
	   ---------------------------------------*/
	     void add();


	       /*----------------------------------------------

            Function: Change
			  
		    Purpose: To change an existing record.

            PRE: An existing transaction file in 
			     the right format.

            POST: The specified fields have been changed in 
			      the List.

                  OR Return an error if no file exists
				     at that location.
            ---------------------------------------------*/
	         void change();



		    /*-------------------------------------------------

              Function: delete_record
   
              Purpose: To delete a record  from the list.

              PRE:  An already declared List.

              POST: The record has been deleleted from the List.
			        OR an error is returned if that record 
					does not exists.
		     ----------------------------------------------*/
		     void delete_record();



    		  /*---------------------------------------
                Function: display_record


                Purpose: To display one record.
				          Given a specific record #.
                
                PRE:  A record exists at that specific record #.

                POST: If a record exists then display it.
               ------------------------------------------------*/
		        void display_record(int record_num);


       /*--------------------------------------------------

	     Function:  initialize_new_master

         Purpose: To create a new master file.

         PRE: new master filename has been inputted.

         POST: Returns -- true if the file has been created
			   successfully.

                          false if the file was not created 
						  successfully.
         ----------------------------------------------------*/
         bool initialize_new_master(char file_name[]);




     /*-------------------------------------------
          Function: close_output

          Purpose: To close the output stream


          PRE: output stream is open
		  POST: output stream is closed.

         --------------------------------------------*/
		  void close_output();

                 
	 /*----------------------------------

         Function: Time_Delay

         Purpose: To inject a time delay in 
				  Processing

         PRE: An integer is sent which represents
			  the number of seconds which will be 
			  entered into the time delay.


         POST: The processing time is delayed by 
			   the given number of seconds.
	  ------------------------------------------*/
	  void Time_Delay(int seconds);



	  /*---------------------------------------

         Function: skip_record

         Purpose: This function skips to the next record.
				  Warning! use only with transaction files.


         PRE:  Input stream is opened. 
			   The input stream is a transaction file.

         POST: The input stream is pushed ahead
			   to the spot right before the command
			   character. (add, delete, change)

         -----------------------------------------*/
		   void skip_record();




           /*-----------------------------------------------
             Function: update_master

             PURPOSE: To update the master file then display
			          results.

 
              PRE:  none



              POST: update the master file with appropriate 
			        changes.  
	       -----------------------------------------------*/
            void update_master();




			  //---------------------
			  //  Function: move_on
			  //----------------------
			   void move_on();

	

};		   







#endif /* ADDRESS_BOOK_H */

