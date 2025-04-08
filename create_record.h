/****************************************************

  File:  create_record.h

  Purpose: To describe the create_record class


  The create record class builds records in a format 
  to be used with the address_book class


  The maximum size of the records by default is 100.

  This can be changed but must also coincide with any
  change in the address_book class.

******************************************************/
#ifndef CREATE_RECORD_H
#define CREATE_RECORD_H
#define MAX_SIZE 100


#include <fstream>

class Create_Record
{


 public:

              //**** PUBLIC FUNCTIONS ***


            //Constructor.
	          Create_Record();


            /*--------------------------------------------
              Function:  create_master_file
 
              Purpose:   This function creates a master file.

              PRE:  none

              POST: the master file is created in the proper 
			        form to be used in the address_book class
		     ---------------------------------------------*/
			  bool create_master_file();



            /*--------------------------------------------
              Function: create_trans_file

              Purpose:  to create a transition file

              PRE:  none

              POST: A transition file is created, in the 
			        proper form to be used in the address_book
					class
		     ---------------------------------------------*/
             bool  create_trans_file();





              /*--------------------------------------------
              Function:  Destructor

              Purpose:   To close down any loose ends.

              PRE:  None

              POST: all outside files are closed.
		     ---------------------------------------------*/
                ~Create_Record();


 private:



             /**************************
	              Private Data
			  **************************/


			  //Filename
			    char file_name[30];

			  //Maximum # files
				int max;

			  //Output Stream
				std::ofstream out_stream;

			  
			  //* Structure for master_rec
				struct master_rec
				{
                    char last[15];
					char first[10];
					int  social;
					char street[25];
					char city[15];
					char state[4];
                    int  zip;
					float rate;
					int  dependents;
				};


			  //* Structure for transition record
				struct trans_rec
				{
                    char command;
				    int  record_number;
					bool change[9];

				    char last[15];
					char first[10];
					int  social;
					char street[25];
					char city[15];
					char state[4];
                    int  zip;
					float rate;
					int  dependents;
			   
				};
//****************************************************************	     



	                   /********Private Functions***********/



			 /*--------------------------------------------
              Function: get_filename

              Purpose:  To get the filename (less 30) from user

              PRE:  none

              POST: The filename is set
		     ---------------------------------------------*/
              void get_filename();
	    


             /*--------------------------------------------
              Function:   Input_record_master

              Purpose:  Get the data for a master record.

              PRE:        

              POST:   The private member struct is filled
			          with data.
		     ---------------------------------------------*/
             void input_master_record(master_rec& record);



			/*-----------------------------------------------
              Function: input_trans_record(master_rec record&)

              Purpose:  to create a transition file

              PRE:  none

              POST: A transition file is created, in the 
			        proper form to be used in the address_book
					class
		     ------------------------------------------------*/
              void input_trans_record(trans_rec& record);


              
		/*--------------------------------

        Function: close_input_file

        -------------------------------*/
	     void close_output();
	



	  /*-------------------------------
	     Function Initialize_new_master.
      ---------------------------------*/
         bool initialize_new_file();


		     /*--------------------------------------------

                   Function: display_record

                   Purpose: To display the contents of a Record

   

                   POST: Returns true if ok with user.
				         Returns fals if otherwis.
			 ----------------------------------------------*/
			 bool display_master_record(const master_rec record);
				
       
			 

			/*-----------------------------------------
                 Function: write_master_record

                 Purpose: to write the record to the file.

                 POST: the file has been written to the file.
			-------------------------------------------------*/
			    void write_master_record(const master_rec record);


			/*-----------------------------------------
                 Function: write_transaction_record

                 Purpose: to write the record to the file.

                 POST: the file has been written to the file.
			-------------------------------------------------*/
			    void write_transaction_record(const trans_rec record);




};



#endif /* CREATE_RECORD_H */

