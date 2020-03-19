// Bank Management System
// Devloped by - Sanket Sonje.

//importing main files to the program

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//class Account

class Account
{
	int arrayID[100];
	int id;
	
	long int arrayAccNo[100];
	long int Acc_No;
	
	string arrayName[100];
	char Name[200];
	
	string arrayCity[100];	
	char City[20];
	
	long int arrayAdharNo[100];
	long int Adhar_No;
	
	int arrayAccountType[100];
	int Account_Type;
	
	int arrayBalance[100];
	int Balance;
	
	int arrayPassword[100];
	int Password;
	
	int count;
	
	public:
		
		Account()
		{
			count = 0;
			id = 0;
		}
		
		//Function to Initialize the values 
		void Get_Details();
		
		//Function to Display All the Details of the Account
		void Display_Details();
		
		//Update the information of Existing Account
		void Update_Info();
		
		//Transaction on Your Balance Amount on Your Own Account
		void Transaction();	
		
		//Check if the Account is Already Present or Not 
		bool Check_Existing_Account(int x);	
		
		//View All Customers List
		void CustomersList();
		
		//removing or deleting existing Account from bank
		void Delete_Account();
		
		//Checking the account is present or not
		bool Check_Existing_Account_Number(long int x);
		
		//Checking the position of the Account
		int checkPosition(long int x);
		
		//Transaction to transfer money to others account
		void Transaction_For_Other_Account();
};

//Get Details Of the Account
void Account :: Get_Details()
{
	
	long int accNo;
	cout<<"\n\t\t\tEnter the Account No to check if it is already taken or not :- ";
	cout<<"\n\t\t\tEnter the Account Number :- ";
	cin>>accNo;
	int id_entered = id+1;
	
	if(Check_Existing_Account(id_entered) == false && Check_Existing_Account_Number(accNo) == false)
	{		
		
		id++;
		id_entered = id;
		
		cout<<"\n\t\t\tEnter the details :- ";
	
		Acc_No = accNo;
		
		cout<<"\n\t\t\tEnter your 4-Digit Unique Password :- ";
		cin>>Password;
		
		cout<<"\t\t\tEnter your Name :- ";
		cin>>Name;
		
		cout<<"\t\t\tEnter your City :- ";
		cin>>City;
		
		cout<<"\t\t\tEnter your Adhar Number :- ";
		cin>>Adhar_No;
		
		cout<<"\n\t\t\tWhich type of you want to Open? (Enter the Choice as per given below)";
		cout<<"\n\t\t\t1. Current Account";
		cout<<"\n\t\t\t2. Saving Account";
		cout<<"\n\t\t\t3. Fixed Deposit Account";
		cout<<"\n\t\t\tEnter your Account Type :- ";
		cin>>Account_Type;
		
		switch(Account_Type)
		{
			char ans;
			
			case 1:
				
				//Current Account
				
				cout<<"\n\t\t\tYou have selected Account as Current Account.";
				cout<<"\n\t\t\tYou can have any number of Transaction per day.";
				cout<<"\n\t\t\tYou have to put at least Rs.5000 in Your New Account\n";
				cout<<"\n\t\t\tDo you Agree ? [Y/N] :- ";
				cin>>ans;
				
				if(ans=='Y' || ans=='y')
				{
					cout<<"\n\t\t\tEnter your Starting Amount :- ";
					cin>>Balance;
					if(Balance>=5000)
					{
						cout<<"\n\t\t\tAccount Created Successfully...!!!\n";
					}
					else
					{
						cout<<"\n\t\t\tAccount is Not Created...!!!\n";
						exit(1);
					}
				}
				else
				{
					cout<<"\n\t\t\tAccount is Not Created...!!!\n";
					exit(1);
				}
				
				break;
				
			case 2:
				
				//Saving Account
				
				cout<<"\n\t\t\tYou have selected Account as Saving Account.";
				cout<<"\n\t\t\tYou can have 4 Transaction per day.";
				cout<<"\n\t\t\tYou have to put at least Rs.500 in Your New Account\n";
				cout<<"\n\t\t\tDo you Agree ? [Y/N] :- ";
				cin>>ans;
				
				if(ans=='Y' || ans=='y')
				{
					cout<<"\n\t\t\tEnter your Starting Amount :- ";
					cin>>Balance;
					if(Balance>=500)
					{
						cout<<"\n\t\t\tAccount Created Successfully...!!!\n";
					}
					else
					{
						cout<<"\n\t\t\tAccount is Not Created...!!!\n";
						exit(1);
					}
				}
				else
				{
					cout<<"\n\t\t\tAccount is Not Created...!!!\n";
					exit(1);
				}
				
				break;
				
			case 3:
				
				//Fixed Deposit Amount
				int Duration;
				
				cout<<"\n\t\t\tYou have selected Account as Fixed Deposit Account.";
				cout<<"\n\t\t\tYou cannot withdraw the amount Until the given Period.";
				cout<<"\n\t\t\tYou have to put at least Rs.500 in Your New Account\n";
				cout<<"\n\t\t\tDo you Agree ? [Y/N] :- ";
				cin>>ans;
				
				if(ans=='Y' || ans=='y')
				{
					cout<<"\n\t\t\tEnter your Starting Amount :- ";
					cin>>Balance;
					cout<<"\n\t\t\tEnter the Duration :- ";
					cin>>Duration;
					
					if(Balance>=500 && Duration>=1)
					{
						cout<<"\n\t\t\tAccount Created Successfully...!!!\n";
					}
					else
					{
						cout<<"\n\t\t\tAccount is Not Created...!!!\n";
						exit(1);
					}
				}
				else
				{
					cout<<"\n\t\t\tAccount is Not Created...!!!\n";
					exit(1);
				}
				
				break;
			
			default:
				cout<<"\n\t\t\tAccount is Not Created...!!!\n";
				break;
		}
		
		//Storing Values into the Array.
		arrayID[id] = id;
		arrayAccNo[id] = Acc_No;
		arrayName[id] = Name;
		arrayCity[id] = City;
		arrayAdharNo[id] = Adhar_No;
		arrayAccountType[id] = Account_Type;
		arrayBalance[id] = Balance;
		arrayPassword[id] = Password;
		
		//Increament the Count
		count++;
	}
	else
	{
		cout<<"\n\t\t\tAccount Already Exists !!!";
	}
	
}

//Check position of the Account Number to get ID
int Account :: checkPosition(long int accNo)
{
	for(int i=1;i<=count;i++)
	{
		if(arrayAccNo[i] == accNo)
		{
			return i;
		}
	}
}

//Display Account Details
void Account :: Display_Details()
{
	int id_entered;
	long int accNo;
	
	cout<<"\n\t\t\tEnter the Account No. to check if it is Created or Not :- ";
	cout<<"\n\t\t\tEnter the Account Number to display all the information :- ";
	cin>>accNo;
	
	if(Check_Existing_Account_Number(accNo) == true)
	{
		
		cout<<"\n\t\t\tEnter your 4-digit Pin(Password) :- ";
		cin>>Password;
		
		id_entered = checkPosition(accNo);
	
		if(Password == arrayPassword[id_entered])
		{
			cout<<"\n\t\t\tDetails of the Account are as follows :- ";
			cout<<"\n\n\t\t\tYour ID of the Account :- ";
			cout<<arrayID[id_entered];
			
			cout<<"\n\t\t\tYour Account Number :- ";
			cout<<arrayAccNo[id_entered];
			
			cout<<"\n\t\t\tYour Name :- ";
			cout<<arrayName[id_entered];
			
			cout<<"\n\t\t\tYour City :- ";
			cout<<arrayCity[id_entered];
			
			cout<<"\n\t\t\tYour Adhar Number :- ";
			cout<<arrayAdharNo[id_entered];
			
			cout<<"\n\t\t\tYour Account Type :- ";
			if(arrayAccountType[id_entered] == 1)
			{
				cout<<"Current Account";
			}
			else if(arrayAccountType[id_entered] == 2)
			{
				cout<<"Saving Account";
			}
			else
			{
				cout<<"Fixed Deposit Account";
			}
			
			cout<<"\n\t\t\tYour Balance :- ";
			cout<<arrayBalance[id_entered];
			
			cout<<"\n\n";		
			cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
		}
		else
		{
			cout<<"\n\t\t\tPlease check your PIN (Password).";
		}
		
	}
	else
	{
			cout<<"\n\t\t\tAccount does not Exists !!!";	
	}

}

//Update the Information of the Existing Account
void Account :: Update_Info()
{
	int id_entered;
	
	long int accNo;
	
	cout<<"\n\t\t\tEnter the Account No. to check if it is Created or Not :- ";
	cout<<"\n\t\t\tEnter the Account Number to display all the information :- ";
	cin>>accNo;
	
	id_entered = checkPosition(accNo);
	
	if(Check_Existing_Account(id_entered) == true && Check_Existing_Account_Number(accNo)==true)
	{	
		
		cout<<"\n\t\t\tEnter your 4-digit Pin(Password) :- ";
		cin>>Password;
	
		if(Password == arrayPassword[id_entered])
		{
			int caseNo;
			
			id = id_entered;
			
			cout<<"\n\t\t\tThese are the choices to Update :- ";
			
			cout<<"\n\t\t\t1. Account Number";
			cout<<"\n\t\t\t2. Name";
			cout<<"\n\t\t\t3. City";
			cout<<"\n\t\t\t4. Adhar_Number";
			cout<<"\n\t\t\t5. Account_Type";
			
			cout<<"\n\t\t\tEnter the choice which you want to Update :- ";
			cin>>caseNo;
			
			switch(caseNo)
			{
				case 1:
					cout<<"\n\t\t\tEnter your Account Number :- ";
					cin>>arrayAccNo[id];
					break;
				
				case 2:
					cout<<"\n\t\t\tEnter your Name :- ";
					cin>>arrayName[id];
					break;
				
				case 3:
					cout<<"\n\t\t\tEnter your City :- ";
					cin>>arrayCity[id];
					break;
				
				case 4:
					cout<<"\n\t\t\tEnter your Adhar Number :- ";
					cin>>arrayAdharNo[id];
					break;
				
				case 5:
					cout<<"\n\t\t\tWhich type of you want to Open? (Enter the Choice as per given below)";
					cout<<"\n\t\t\t1. Current Account";
					cout<<"\n\t\t\t2. Saving Account";
					cout<<"\n\t\t\t3. Fixed Deposit Account";
					cout<<"\n\t\t\tEnter your Account Type :- ";
					cin>>Account_Type;
					
					switch(Account_Type)
					{
						char ans;
						
						case 1:
							
							//Current Account
							
							cout<<"\n\t\t\tYou have selected Account as Current Account.";
							cout<<"\n\t\t\tYou can have any number of Transaction per day.";
							cout<<"\n\t\t\tYou have to put at least Rs.5000 in Your New Account\n";
							cout<<"\n\t\t\tDo you Agree ? [Y/N] :- ";
							cin>>ans;
							
							if(ans=='Y' || ans=='y')
							{
								cout<<"\n\t\t\tEnter your Starting Amount :- ";
								cin>>Balance;
								if(Balance>=5000)
								{
									arrayBalance[id] = Balance;
									arrayAccountType[id] = Account_Type;
									cout<<"\n\t\t\tAccount Created Successfully...!!!\n";
								}
								else
								{
									cout<<"\n\t\t\tAccount is Not Created...!!!\n";
									exit(1);
								}
							}
							else
							{
								cout<<"\n\t\t\tAccount is Not Created...!!!\n";
								exit(1);
							}
							
							break;
							
						case 2:
							
							//Saving Account
							
							cout<<"\n\t\t\tYou have selected Account as Saving Account.";
							cout<<"\n\t\t\tYou can have 4 Transaction per day.";
							cout<<"\n\t\t\tYou have to put at least Rs.500 in Your New Account\n";
							cout<<"\n\t\t\tDo you Agree ? [Y/N] :- ";
							cin>>ans;
							
							if(ans=='Y' || ans=='y')
							{
								cout<<"\n\t\t\tEnter your Starting Amount :- ";
								cin>>Balance;
								if(Balance>=500)
								{
									arrayBalance[id] = Balance;
									arrayAccountType[id] = Account_Type;
									cout<<"\n\t\t\tAccount Created Successfully...!!!\n";
								}
								else
								{
									cout<<"\n\t\t\tAccount is Not Created...!!!\n";
									exit(1);
								}
							}
							else
							{
								cout<<"\n\t\t\tAccount is Not Created...!!!\n";
								exit(1);
							}
							
							break;
							
						case 3:
							
							//Fixed Deposit Amount
							int Duration;
							
							cout<<"\n\t\t\tYou have selected Account as Fixed Deposit Account.";
							cout<<"\n\t\t\tYou cannot withdraw the amount Until the given Period.";
							cout<<"\n\t\t\tYou have to put at least Rs.500 in Your New Account\n";
							cout<<"\n\t\t\tDo you Agree ? [Y/N] :- ";
							cin>>ans;
							
							if(ans=='Y' || ans=='y')
							{
								cout<<"\n\t\t\tEnter your Starting Amount :- ";
								cin>>Balance;
								cout<<"\n\t\t\tEnter the Duration :- ";
								cin>>Duration;
								
								if(Balance>=500 && Duration>=1)
								{
									arrayBalance[id] = Balance;
									arrayAccountType[id] = Account_Type;
									cout<<"\n\t\t\tAccount Created Successfully...!!!\n";
								}
								else
								{
									cout<<"\n\t\t\tAccount is Not Created...!!!\n";
									exit(1);
								}
							}
							else
							{
								cout<<"\n\t\t\tAccount is Not Created...!!!\n";
								exit(1);
							}
							
							break;
						
						default:
							cout<<"\n\t\t\tAccount is Not Created...!!!\n";
							break;
					}
					break;
				
				default:
					cout<<"\n\t\t\tEnter the Valid Choice !!! ";
					break;
			}
			
			cout<<"\n";		
			cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
			
			Display_Details();
			
			cout<<"\n";		
			cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
		
			cout<<"\n\t\t\tInformation Successfully Updated\n";
		}
		else
		{
			cout<<"\n\t\t\tPlease check your PIN (Password).";
		}
		
	}
	else
	{
			cout<<"\n\t\t\tAccount does not Exists !!!";	
	}
}

//Transaction On your Balance Amount on your Own Account
void Account :: Transaction()
{	
	int id_entered;
	
	long int accNo;
	
	
	cout<<"\n\t\t\tEnter the Account No. to check if it is Created or Not :- ";
	cout<<"\n\t\t\tEnter the your Account Number for Transaction :- ";
	cin>>accNo;
	
	id_entered = checkPosition(accNo);
	
	if(Check_Existing_Account(id_entered) == true && Check_Existing_Account_Number(accNo)==true)
	{
		
		cout<<"\n\t\t\tEnter your 4-digit Pin(Password) :- ";
		cin>>Password;
	
		if(Password == arrayPassword[id_entered])
		{
			
			switch(arrayAccountType[id_entered])
			{
				char ans;
				
				case 1:
					
					//Current Account
					
					cout<<"\n\t\t\tYour Options for your Current Account :- ";
					cout<<"\n\t\t\t1. Withdraw Amount";
					cout<<"\n\t\t\t2. Deposit Amount";
					cout<<"\n\t\t\t3. View Balance Amount\n";
					
					int choice;
					cout<<"\n\t\t\tEnter your Option :- ";
					cin>>choice;
					
					cout<<"\n";
					if(arrayBalance[id_entered] < 500)
					{
						cout<<"\n\t\t\tYou cannot withdraw amount.";
						cout<<"\n\t\t\tLOW BALANCE";
						
						cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
					}
					else
					{
						switch(choice)
						{
							case 1:
								
								//Withdraw Amount Transaction
								int Withdraw_Amount;
								
								cout<<"\n\t\t\tEnter the Amount you want to Withdraw :- ";
								cin>>Withdraw_Amount;
								arrayBalance[id_entered] = arrayBalance[id_entered] - Withdraw_Amount;
								if(arrayBalance[id_entered] < 500)
								{
									cout<<"\n\t\t\tYou cannot withdraw amount.";
									cout<<"\n\t\t\tLOW BALANCE";
									arrayBalance[id_entered] = arrayBalance[id_entered] + Withdraw_Amount;
									cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
								}
								else
								{
									cout<<"\n\t\t\tTransaction Successfull ...!!!\n";
								}
								
								break;
							
							case 2:
								
								//Deposit Amount Transaction
								int Deposit_Amount;
								
								cout<<"\n\t\t\tEnter the Amount you want to Deposit :- ";
								cin>>Deposit_Amount;
								arrayBalance[id_entered] = arrayBalance[id_entered] + Deposit_Amount;
								if(arrayBalance[id_entered] > 5000000)
								{
									cout<<"\n\t\t\tYou cannot deposit this amount.";
									cout<<"\n\t\t\tHIGH BALANCE";
									arrayBalance[id_entered] = arrayBalance[id_entered] - Deposit_Amount;
									cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
								}
								else
								{
									cout<<"\n\t\t\tTransaction Successfull ...!!!\n";
								}
				
								break;
							
							case 3:
								
								//Show Balance Amount
								
								cout<<"\n\t\t\tBalance Amount :- "<<arrayBalance[id_entered];
								break;
								
							default:
								cout<<"\n\t\t\tEnter the Valid Choice ...!!! \n";
								break;
						}
					}
					
					break;
					
				case 2:
					
					//Saving Account
					
					cout<<"\n\t\t\tYour Options for your Saving Account:- ";
					cout<<"\n\t\t\t1. Withdraw Amount";
					cout<<"\n\t\t\t2. Deposit Amount";
					cout<<"\n\t\t\t3. View Balance Amount\n";
					
					int choice1;
					cout<<"\n\t\t\tEnter your Option :- ";
					cin>>choice1;
					
					cout<<"\n";
					if(arrayBalance[id_entered] < 500)
					{
						cout<<"\n\t\t\tYou cannot withdraw amount.";
						cout<<"\n\t\t\tLOW BALANCE";
						
						cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
					}
					else
					{
						switch(choice1)
						{
							case 1:
								
								//Withdraw Amount Transaction
								int Withdraw_Amount;
								
								cout<<"\n\t\t\tEnter the Amount you want to Withdraw :- ";
								cin>>Withdraw_Amount;
								arrayBalance[id_entered] = arrayBalance[id_entered] - Withdraw_Amount;
								if(arrayBalance[id_entered] < 500)
								{
									cout<<"\n\t\t\tYou cannot withdraw amount.";
									cout<<"\n\t\t\tLOW BALANCE";
									arrayBalance[id_entered] = arrayBalance[id_entered] + Withdraw_Amount;
									cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
								}
								else
								{
									cout<<"\n\t\t\tTransaction Successfull ...!!!\n";
								}
								
								break;
							
							case 2:
								
								//Deposit Amount Transaction
								int Deposit_Amount;
								
								cout<<"\n\t\t\tEnter the Amount you want to Deposit :- ";
								cin>>Deposit_Amount;
								arrayBalance[id_entered] = arrayBalance[id_entered] + Deposit_Amount;
								if(arrayBalance[id_entered] > 5000000)
								{
									cout<<"\n\t\t\tYou cannot deposit this amount.";
									cout<<"\n\t\t\tHIGH BALANCE";
									arrayBalance[id_entered] = arrayBalance[id_entered] - Deposit_Amount;
									cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
								}
								else
								{
									cout<<"\n\t\t\tTransaction Successfull ...!!!\n";
								}
				
								break;
							
							case 3:
								
								//Show Balance Amount
								
								cout<<"\n\t\t\tBalance Amount :- "<<arrayBalance[id_entered];
								break;
								
							default:
								cout<<"\n\t\t\tEnter the Valid Choice ...!!! \n";
								break;
						}
					}
					
					break;
					
				case 3:
					
					//Fixed Deposit Amount
					
					cout<<"\n\t\t\tYou can Withdraw or deposite the amount until your Period is Over.";
					
					break;
				
				default:
					cout<<"\n\t\t\tAccount is Not Created...!!!\n";
					break;
			}
		}
		else
		{
			cout<<"\n\t\t\tPlease check your PIN (Password).";
		}
		
	}
	else
	{
			cout<<"\n\t\t\tAccount does not Exists !!!";	
	}
}

//Transaction for Transfering Money From Your Account to Other's Account
void Account :: Transaction_For_Other_Account()
{	
	int id_entered1,id_entered2;
	
	long int accNo1, accNo2;
	
	
	cout<<"\n\t\t\tEnter the Account No. to check if it is Created or Not :- ";
	cout<<"\n\t\t\tEnter the your Account Number for Transaction :- ";
	cin>>accNo1;
	
	id_entered1 = checkPosition(accNo1);
	
	if(Check_Existing_Account(id_entered1) == true && Check_Existing_Account_Number(accNo1)==true)
	{
		
		cout<<"\n\t\t\tEnter your 4-digit Pin(Password) :- ";
		cin>>Password;
	
		if(Password == arrayPassword[id_entered1])
		{
			
			cout<<"\n\t\t\tEnter the Account No. to check if it is Created or Not :- ";
			cout<<"\n\t\t\tEnter the your Receiver's' Account Number for Transaction :- ";
			cin>>accNo2;
				
			id_entered2 = checkPosition(accNo2);
			
			if(Check_Existing_Account(id_entered2) == true && Check_Existing_Account_Number(accNo2)==true)
			{
				switch(arrayAccountType[id_entered1])
				{
					char ans;
					
					case 1:
						
						//Current Account
						
						cout<<"\n\t\t\tYour Options for your Current Account :- ";
						cout<<"\n\t\t\t1. Transfer Amount";
						cout<<"\n\t\t\t2. Balance Enquiry";
						
						int choice;
						cout<<"\n\t\t\tEnter your Option :- ";
						cin>>choice;
						
						cout<<"\n";
						if(arrayBalance[id_entered1] < 500)
						{
							cout<<"\n\t\t\tYou cannot do Transaction on your account with this amount.";
							cout<<"\n\t\t\tLOW BALANCE";
							
							cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
						}
						else
						{
							switch(choice)
							{
								case 1:
									
									//Transaction of Transfering Money From One account to Another Account
									int Money_Transfer;
									
									cout<<"\n\t\t\tEnter the Amount you want to Transfer :- ";
									cin>>Money_Transfer;
									
									arrayBalance[id_entered1] = arrayBalance[id_entered1] - Money_Transfer;
									arrayBalance[id_entered2] = arrayBalance[id_entered2] + Money_Transfer;
									
									if(arrayBalance[id_entered1] < 500)
									{
										cout<<"\n\t\t\tYou cannot withdraw amount.";
										cout<<"\n\t\t\tLOW BALANCE";
										
										arrayBalance[id_entered1] = arrayBalance[id_entered1] + Money_Transfer;
										arrayBalance[id_entered2] = arrayBalance[id_entered2] - Money_Transfer;
										
										cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
									}
									else
									{
										cout<<"\n\t\t\tTransaction Successfull ...!!!\n";
									}
									
									break;
								
								case 2:
									
									//Show Balance Amount
									
									cout<<"\n\t\t\tBalance Amount :- "<<arrayBalance[id_entered1];
									break;
									
								default:
									cout<<"\n\t\t\tEnter the Valid Choice ...!!! \n";
									break;
							}
						}
						
						break;
						
					case 2:
						
						//Saving Account
						
						cout<<"\n\t\t\tYour Options for your Current Account :- ";
						cout<<"\n\t\t\t1. Transfer Amount";
						cout<<"\n\t\t\t2. Balance Enquiry";
						
						int choice1;
						cout<<"\n\t\t\tEnter your Option :- ";
						cin>>choice1;
						
						cout<<"\n";
						if(arrayBalance[id_entered1] < 500)
						{
							cout<<"\n\t\t\tYou cannot do Transaction on your account with this amount.";
							cout<<"\n\t\t\tLOW BALANCE";
							
							cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
						}
						else
						{
							switch(choice1)
							{
								case 1:
									
									//Transaction of Transfering Money From One account to Another Account
									int Money_Transfer;
									
									cout<<"\n\t\t\tEnter the Amount you want to Transfer :- ";
									cin>>Money_Transfer;
									
									arrayBalance[id_entered1] = arrayBalance[id_entered1] - Money_Transfer;
									arrayBalance[id_entered2] = arrayBalance[id_entered2] + Money_Transfer;
									
									if(arrayBalance[id_entered1] < 500)
									{
										cout<<"\n\t\t\tYou cannot withdraw amount.";
										cout<<"\n\t\t\tLOW BALANCE";
										
										arrayBalance[id_entered1] = arrayBalance[id_entered1] + Money_Transfer;
										arrayBalance[id_entered2] = arrayBalance[id_entered2] - Money_Transfer;
										
										cout<<"\n\t\t\tTransaction Unsucessfull ...!!!\n";	
									}
									else
									{
										cout<<"\n\t\t\tTransaction Successfull ...!!!\n";
									}
									
									break;
								
								case 2:
									
									//Show Balance Amount
									
									cout<<"\n\t\t\tBalance Amount :- "<<arrayBalance[id_entered1];
									break;
									
								default:
									cout<<"\n\t\t\tEnter the Valid Choice ...!!! \n";
									break;
							}
						}
						
						break;
						
					case 3:
						
						//Fixed Deposit Amount
						
						cout<<"\n\t\t\tYou can Withdraw or deposite the amount until your Period is Over.";
						
						break;
					
					default:
						cout<<"\n\t\t\tAccount is Not Created...!!!\n";
						break;
				}
			}
			else
			{
				cout<<"\n\t\t\tAccount does not Exists !!!";
			}			
		}
		else
		{
			cout<<"\n\t\t\tPlease check your PIN (Password).";
		}	
	}
	else
	{
			cout<<"\n\t\t\tAccount does not Exists !!!";	
	}
}


//Check if the Account is Already Present or Not 
bool Account :: Check_Existing_Account(int x)
{
	int id_entered = x;
	int counter=0;
	
	for(int i=1;i<=count;i++)
	{
		if(arrayID[i] == id_entered)
		{
			counter++;
		}
	}
	
	if(counter==1)
	{
			return true;
	}
	else
	{
			return false;
	}
}

//Check if the Account Number is Already Present or Not 
bool Account :: Check_Existing_Account_Number(long int x)
{
	long int accNo = x;
	int counter=0;
	
	for(int i=1;i<=count;i++)
	{
		if(arrayAccNo[i] == accNo)
		{
			counter++;
		}
	}
	
	if(counter==1)
	{
			return true;
	}
	else
	{
			return false;
	}
}

//View All Customers List
void Account :: CustomersList()
{
	if(count == 0)
	{
		cout<<"\n\t\t\tCurrently no Account Present in the Bank.\n";
	}
	else
	{
		cout<<"\n\t\t\tCustomers List is as Follows :- ";
		cout<<"\n\t\t\t|----------------------|------------------------|--------------------------|";
		cout<<"\n\t\t\t|        Name          |     Account_Number     |       Account_Type       |";
		cout<<"\n\t\t\t|----------------------|------------------------|--------------------------|";
		
		string x;
		
		for(int i=1;i<=count;i++)
		{
			if(arrayAccountType[i] == 1)
			{
				x = "Current acc";
			}
			else if(arrayAccountType[i] == 2)
			{
				x = "Saving";
			}
			else if(arrayAccountType[i] == 3)
			{
				x = "Fixed Deposit";
			}
			else
			{
				x = "";
			}
			cout<<"\n\t\t\t"<<"|"<<setw(13)<<arrayName[i]<<setw(10)<<"|"<<setw(15)<<arrayAccNo[i]<<setw(10)<<"|"<<setw(16)<<x<<setw(11)<<"|";
			cout<<"\n\t\t\t|----------------------|------------------------|--------------------------|";
		}
	}
	cout<<"\n";
}

//Removing Existing Account
void Account :: Delete_Account()
{
	//check if the Account is present or not
	int id_entered;
	
	cout<<"\n\t\t\tEnter the ID to check if it is Present or Not :- ";
	cout<<"\n\t\t\tEnter the ID to delete its Account from Bank :- ";
	cin>>id_entered;
	
	if(Check_Existing_Account(id_entered) == false)
	{
		cout<<"\n\t\t\tAccount does not Exists !!!";
	}
	else
	{
		//deleting elements of array
		for(int i=id_entered-1;i<=count;i++)
		{
			arrayID[i] = arrayID[i+1];
			arrayAccNo[i] = arrayAccNo[i+1];
			arrayName[i] = arrayName[i+1];
			arrayCity[i] = arrayCity[i+1];
			arrayAdharNo[i] = arrayAdharNo[i+1];
			arrayAccountType[i] = arrayAccountType[i+1];
			arrayBalance[i] = arrayBalance[i+1];
			arrayPassword[i] = arrayPassword[i+1];
		}
		arrayID[count] = 0;
		arrayAccNo[count] = 0;
		arrayName[count] = "";
		arrayCity[count] = "";
		arrayAdharNo[count] = 0;
		arrayAccountType[count] = 0;
		arrayBalance[count] = 0;
		arrayPassword[count] = 0;
	}
}

//Main Function
int main()
{
	int choice;
	char answer;
	
	//Creating Object for the class "Account"
	Account obj;
	
	cout<<"\t\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM"<<endl;
	
	//Main Menu
	do
	{	
		cout<<"\n";
		cout<<"\t\t\t\t ----------------- WELCOME T0 MAIN MENU ----------------- "<<endl;
		cout<<"\n";
		cout<<"\t\t\t1. Create a New Account"<<endl;
		cout<<"\t\t\t2. Show Account Details"<<endl;
		cout<<"\t\t\t3. Upadte Information of Existing Account"<<endl;
		cout<<"\t\t\t4. For Transactions on Your Account"<<endl;
		cout<<"\t\t\t5. Transfering Money From your Account to Another Account"<<endl;
		cout<<"\t\t\t6. Check for the Existing Account"<<endl;
		cout<<"\t\t\t7. Removing Existing Account"<<endl;
		cout<<"\t\t\t8. View customers List"<<endl;
		cout<<"\t\t\t9. Exit"<<endl;
		
		cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
		
		cout<<"\n\t\t\tEnter your Choice :- ";
		cin>>choice;
		
		cout<<"\n";		
		cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
		
		switch(choice)
		{
			case 1:
				obj.Get_Details();
				break;
				
			case 2:
				obj.Display_Details();
				break;
				
			case 3:
				obj.Update_Info();
				break;
				
			case 4:
				obj.Transaction();
				break;
				
			case 5:
				obj.Transaction_For_Other_Account();
				break;
				
			case 6:
				int id_entered;
				cout<<"\n\t\t\tEnter the ID to check if is is already taken or not :- ";
				cout<<"\n\t\t\tEnter the ID to display all the information :- ";
				cin>>id_entered;
				obj.Check_Existing_Account(id_entered);
				break;
				
			case 7:
				obj.Delete_Account();
				break;
				
			case 8:
				obj.CustomersList();
				break;
				
			case 9:
				exit(1);
				
			default:
				cout<<"\n\t\t\tEnter the Valid Choice !!! "<<endl;
				break;
		}
		
		cout<<"\n";		
		cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
		
		cout<<"\n\t\t\tDo you want to add another choice ? [Y/N] -> ";
		cin>>answer;
		
		cout<<"\n";		
		cout<<"\t\t\t\t --------------------------------------------------------- "<<endl;
		
	}while(answer=='y' || answer=='Y');
	
	
	return 0;
}

/*
D E V E L O P E D   B Y   S A N K E T   S O N J E.
*/
