#include<iostream>//cin cout
#include"list.h"//class
#include<string>
#include<sstream>//from string to int or int to string
#include<fstream>// file
using namespace std;

int main()
{
	int ID,Position,choice=0,i=0;
	string line,arr[4];

	//Object from Class List for Each Menu
	List Sandwitches;
	List SoftDrinks;
	List Appetizers;

	//ifstream to Read from File
	ifstream SandwitchesOutFile("Sandwitches.txt");
	ifstream SoftDrinksOutFile("Soft Drinks.txt");
	ifstream AppetizersOutFile("Appetizers.txt");

	//ofstream to write to File
	ofstream SandwitchesInFile;
	ofstream SoftDrinksInFile;
	ofstream AppetizersInFile;

	//*******************************************Read from Sandwich File and insert into Sandwich List************************
			if (SandwitchesOutFile.is_open())
			{
				Position=1;
				while (! SandwitchesOutFile.eof() )
				{
					getline (SandwitchesOutFile,line);
					istringstream iss(line);
					string word;
					while(getline(iss,word,'|'))
					{
						arr[i]=word;
						i++;
					}
					ID=atoi(line.c_str()); //Converts from string to int
					if(ID!=0)
					{
						Sandwitches.Insert(Position,ID,arr[1],arr[2]);
						Position++;
						i=0;
					}
				}
			}
			//***************************************************************************************************

			//******************************************Read from Soft Drinks File and Write to SoftDrinks List**********************
			if (SoftDrinksOutFile.is_open())
			{
				Position=1;
				while (! SoftDrinksOutFile.eof() )
				{
					getline (SoftDrinksOutFile,line);
					istringstream iss(line);
					string word;
					while(getline(iss,word,'|'))
					{
						arr[i]=word;
						i++;
					}
					int ID;
					ID=atoi(line.c_str()); //Converts from string to int
					if(ID!=0)
					{
						SoftDrinks.Insert(Position,ID,arr[1],arr[2]);
						Position++;
						i=0;
					}
				}
			}
			//***************************************************************************************************

			//*************************************Read from Appetizer File and insert into Appetizer List*************************
			if (AppetizersOutFile.is_open())
			{
				Position=1;
				while (! AppetizersOutFile.eof() )
				{
					getline (AppetizersOutFile,line);
					istringstream iss(line);
					string word;
					while(getline(iss,word,'|'))
					{
						arr[i]=word;
						i++;
					}
					int ID;
					ID=atoi(line.c_str()); //Converts from string to int
					if(ID!=0)
					{
						Appetizers.Insert(Position,ID,arr[1],arr[2]);
						Position++;
						i=0;
					}
				}
			}
			//***************************************************************************************************

//**************************************Start of main Program***********************************************
	while(true)
	{
	cout<<"________________________________________"<<endl;
	cout<<"Cashier Menu Project:"<<endl;
	cout<<"________________________________________"<<endl;
	cout<<"1. Update Menu. \n2. Make Order. \n3. Display Menu. \n4. Exit."<<endl;
	cout<<"________________________________________"<<endl;
	cout<<"Your Choice: ";
	cin>>choice;

	if(choice==1)// Update Menu.
	{
		cout<<"________________________________________"<<endl;
		cout<<"Choose one of these set Menu:"<<endl;
		cout<<"________________________________________"<<endl;
		cout<<"1.Sandwiches. \n2.Soft Drinks. \n3.Appetizers"<<endl;
		cout<<"________________________________________"<<endl;
		cout<<"Your Choice: ";
		cin>>choice;

		if(choice==1)// Sandwiches
		{
				cout<<"________________________________________"<<endl;
				cout<<"Sandwiches Menu"<<endl;
				cout<<"________________________________________"<<endl;
				Sandwitches.Output();

				cout<<"________________________________________"<<endl;
				cout<<"Select one of the following updates"<<endl;
				cout<<"________________________________________"<<endl;				
				cout<<"1. Add Sandwich. \n2. Update Sandwich Info. \n3. Delete Sandwich."<<endl;
				cout<<"________________________________________"<<endl;
				cout<<"Your Choice: ";
				cin>>choice;

				if(choice==1)// Add Sandwiches
				{
					string Sandwitch_Name,Sandwitch_Price;
					int ID;

					while(true)
					{
						cout<<"ID: ";
						cin>>ID;
						if(ID!=0)
						{
							cin.ignore();
							//***************** Enter Record Info.*****************************
							cout<<"Sandwich Name: ";
							std::getline(std::cin,Sandwitch_Name);

							cout<<"Sandwich Price: ";
							std::getline(std::cin,Sandwitch_Price);
							//*****************************************************************
	
							//********************* Insert Values in Linked List***************
							Sandwitches.Insert(Position,ID,Sandwitch_Name,Sandwitch_Price);
							Position++;
							//*****************************************************************
						}
						else
						{
							break;
						}

					}

					//***************************Dispay Linked List Content********************
					cout<<"________________________________________"<<endl;
					cout<<"Sandwiches Menu"<<endl;
					cout<<"________________________________________"<<endl;
					Sandwitches.Output();
					cout<<"________________________________________"<<endl;
					//*************************************************************************
					choice=0;
				}
				if(choice==2)// Update Sandwiches
				{
					int ID,NewID;
					string Sandwitch_Name,Sandwitch_Price,IDNum;
					string NewSandwitch_Name,NewSandwitch_Price;

					string word;
					cout<<"Please enter the ID Number you want to Update: ";
					cin>>ID;
		
					//***********************Update the old value with the new value**********************
					for(int i=1;i<=Sandwitches.Length();i++)
					{
						if(ID==Sandwitches.get(i))
						{
							cout<<"ID: ";
							cin>>NewID;
							cin.ignore();
							cout<<"Sandwich Name: ";
							std::getline(std::cin,NewSandwitch_Name);
							cout<<"Sandwich Price: ";
							std::getline(std::cin,NewSandwitch_Price);
							Sandwitches.Update(i,NewID,NewSandwitch_Name,NewSandwitch_Price);
						}
					}
					//******************************************************************************
		
					Sandwitches.Output();
					cout<<"---------------------------------"<<endl;
					choice=0;
				}
				if(choice==3)// Delete Sandwitches
				{
					int ID;
					string Sandwitch_Name,Sandwitch_Price,IDNum;
		
					cout<<"Please enter the ID Number you want to Delete: ";
					cin>>ID;

					//******************************Delete the record from the linked list************************************
					for(int i=1;i<=Sandwitches.Length();i++)
					{
						if(ID==Sandwitches.get(i))
						{
							int Item=Sandwitches.get(i);
							Sandwitches.Delete(i,Item);
						}
					}
					Sandwitches.Output();
					cout<<"---------------------------------"<<endl;
					//********************************************************************************************************
					choice=0;
				}
		}



		if(choice==2)// Soft Drinks
		{
				cout<<"________________________________________"<<endl;
				cout<<"Soft Drinks Menu"<<endl;
				cout<<"________________________________________"<<endl;
				SoftDrinks.Output();

				cout<<"________________________________________"<<endl;
				cout<<"Select one of the following updates"<<endl;
				cout<<"________________________________________"<<endl;				
				cout<<"1. Add Drink. \n2. Update Drink Info. \n3. Delete Drink."<<endl;
				cout<<"________________________________________"<<endl;
				cout<<"Your Choice: ";
				cin>>choice;

				if(choice==1)// Add Drink
				{
					string Drink_Name,Drink_Price;
					int ID;

					while(true)
					{
						cout<<"ID: ";
						cin>>ID;
						if(ID!=0)
						{
							
							cin.ignore();
							//***************** Enter Record Info. ****************************
							cout<<"Drink Name: ";
							std::getline(std::cin,Drink_Name);
							cout<<"Sandwich Price: ";
							std::getline(std::cin,Drink_Price);
	
							//********************* Insert Values in Linked List***************
							SoftDrinks.Insert(Position,ID,Drink_Name,Drink_Price);
							Position++;
							//*****************************************************************
						}
						else
						{
							break;
						}

					}

					//***************************Dispay Linked List Content********************
					cout<<"________________________________________"<<endl;
					cout<<"Soft Drinks Menu"<<endl;
					cout<<"________________________________________"<<endl;
					SoftDrinks.Output();
					cout<<"________________________________________"<<endl;
					//*************************************************************************
					choice=0;
				}
				if(choice==2)// Update Drink
				{
					int ID,NewID;
					string Drink_Name,Drink_Price,IDNum;
					string NewDrink_Name,NewDrink_Price;

					string word;
					cout<<"Please enter the ID Number you want to Update: ";
					cin>>ID;
		
					//***********************Update the old value with the new value**********************
					for(int i=1;i<=SoftDrinks.Length();i++)
					{
						if(ID==SoftDrinks.get(i))
						{
							cout<<"ID: ";
							cin>>NewID;
							cin.ignore();
							cout<<"Drink Name: ";
							std::getline(std::cin,NewDrink_Name);
							cout<<"Drink Price: ";
							std::getline(std::cin,NewDrink_Price);
							SoftDrinks.Update(i,NewID,NewDrink_Name,NewDrink_Price);
						}
					}
					//******************************************************************************

					SoftDrinks.Output();
					cout<<"---------------------------------"<<endl;
					choice=0;
				}
				if(choice==3)// Delete Drink
				{
					int ID;
					string Drink_Name,Drink_Price,IDNum;
		
					cout<<"Please enter the ID Number you want to Delete: ";
					cin>>ID;

					//******************************Delete the record from the linked list************************************
					for(int i=1;i<=SoftDrinks.Length();i++)
					{
						if(ID==SoftDrinks.get(i))
						{
							int Item=SoftDrinks.get(i);
							SoftDrinks.Delete(i,Item);
						}
					}
					SoftDrinks.Output();
					cout<<"---------------------------------"<<endl;
					//********************************************************************************************************
					choice=0;
				}
		}


		if(choice==3)// Appetizer
		{
				cout<<"________________________________________"<<endl;
				cout<<"Appetizers Menu"<<endl;
				cout<<"________________________________________"<<endl;
				Appetizers.Output();

				cout<<"________________________________________"<<endl;
				cout<<"Select one of the following updates"<<endl;
				cout<<"________________________________________"<<endl;				
				cout<<"1. Add Appetizer. \n2. Update Appetizer Info. \n3. Delete Appetizer."<<endl;
				cout<<"________________________________________"<<endl;
				cout<<"Your Choice: ";
				cin>>choice;

				if(choice==1)//Add Appetizer
				{
					string Appetizer_Name,Appetizer_Price;
					int ID;

					while(true)
					{
						cout<<"ID: ";
						cin>>ID;
						if(ID!=0)
						{
							cin.ignore();
							//***************** Enter Record Info. ****************************
							cout<<"Appetizer Name: ";
							std::getline(std::cin,Appetizer_Name);
							cout<<"Appetizer Price: ";
							std::getline(std::cin,Appetizer_Price);
	
							//********************* Insert Values in Linked List***************
							Appetizers.Insert(Position,ID,Appetizer_Name,Appetizer_Price);
							Position++;
							//*****************************************************************
						}
						else
						{
							break;
						}

					}

					//***************************Dispay Linked List Content********************
					cout<<"________________________________________"<<endl;
					cout<<"Appetizer Menu"<<endl;
					cout<<"________________________________________"<<endl;
					Appetizers.Output();
					cout<<"________________________________________"<<endl;
					//*************************************************************************
					choice=0;
				}
				if(choice==2)// Update Appetizer
				{
					int ID,NewID;
					string Appetizer_Name,Appetizer_Price,IDNum;
					string NewAppetizer_Name,NewAppetizer_Price;

					string word;
					cout<<"Please enter the ID Number you want to Update: ";
					cin>>ID;
		
					//***********************Update the old value with the new value**********************
					for(int i=1;i<=Appetizers.Length();i++)
					{
						if(ID==Appetizers.get(i))
						{
							cout<<"ID: ";
							cin>>NewID;
							cin.ignore();
							cout<<"Appetizer Name: ";
							std::getline(std::cin,NewAppetizer_Name);
							cout<<"Appetizer Price: ";
							std::getline(std::cin,NewAppetizer_Price);
							Appetizers.Update(i,NewID,NewAppetizer_Name,NewAppetizer_Price);
						}
					}
					//******************************************************************************
		
					Appetizers.Output();
					cout<<"---------------------------------"<<endl;
					choice=0;
				}
				if(choice==3)// Delete Appetizer
				{
					int ID;
					string Appetizer_Name,Appetizer_Price,IDNum;
		
					cout<<"Please enter the ID Number you want to Delete: ";
					cin>>ID;

					//******************************Delete the record from the linked list************************************
					for(int i=1;i<=Appetizers.Length();i++)
					{
						if(ID==Appetizers.get(i))
						{
							int Item=Appetizers.get(i);
							Appetizers.Delete(i,Item);
						}
					}
					Appetizers.Output();
					cout<<"---------------------------------"<<endl;
					//********************************************************************************************************
					choice=0;
				}
			}
		}

		if(choice==2)// Make Order
		{
			int S,Price,Order_Sum=0;
			Position=1;
			while(true)
			{
			cout<<"________________________________________"<<endl;
			cout<<"Choose one of these set Menu:"<<endl;
			cout<<"________________________________________"<<endl;
			cout<<"1. Sandwiches. \n2. Soft Drinks. \n3. Appetizers. \n4. Cancel Order.\n0. Finish Order."<<endl;
			cout<<"________________________________________"<<endl;
			cout<<"Your Choice: ";
			cin>>choice;

			if(choice==1)// Sandwitches Menu
			{	
				Sandwitches.Output();
				cout<<"Select Sandwich from the above menu: ";
				cin>>S;
				if(S!=0)
				{
				for(int i=1;i<=Sandwitches.Length();i++)
				{
					if(S==Sandwitches.get(i))
					{
						Position++;
						string p=Sandwitches.getPrice(i);
						Price=atoi(p.c_str());
						Order_Sum+=Price;
					}
				}
				cout<<"------------------------------------------------"<<endl;
				cout<<"the total is "<<Order_Sum<<endl;
				cout<<"------------------------------------------------"<<endl;
				}
				else
					break;
			}

			if(choice==2)// Soft Drinks Menu
			{	
				SoftDrinks.Output();
				cout<<"Select Sandwich from the above menu: ";
				
				cin>>S;
				if(S!=0)
				{
				for(int i=1;i<=SoftDrinks.Length();i++)
				{
					if(S==SoftDrinks.get(i))
					{
						Position++;
						string p=SoftDrinks.getPrice(i);
						Price=atoi(p.c_str());
						Order_Sum+=Price;
					}
				}
				cout<<"------------------------------------------------"<<endl;
				cout<<"the total is "<<Order_Sum<<endl;
				cout<<"------------------------------------------------"<<endl;
				}
				else
					break;
			}

			if(choice==3)// Appetizer
			{
				Appetizers.Output();
				cout<<"Select Sandwich from the above menu: ";
				cin>>S;
				if(S!=0)
				{
				for(int i=1;i<=Appetizers.Length();i++)
				{
					if(S==Appetizers.get(i))
					{
						Position++;
						string p=Appetizers.getPrice(i);
						Price=atoi(p.c_str());
						Order_Sum+=Price;
					}
				}
				cout<<"------------------------------------------------"<<endl;
				cout<<"the total is "<<Order_Sum<<endl;
				cout<<"------------------------------------------------"<<endl;
				}
				else
					break;
			}
			if(choice==4)// Cancel the Order
			{
				Order_Sum=0;
				continue;
			}
			if(choice==0)// End of Order
			{
				cout<<"------------------------------------------------"<<endl;
				cout<<"the total is "<<Order_Sum<<endl;
				cout<<"------------------------------------------------"<<endl;
				break;
			}
		}
	}
	if(choice==3)//Display Menu
	{
		Sandwitches.Output();
		SoftDrinks.Output();
		Appetizers.Output();
	}
	if(choice==4)//Exit
	{
		Sandwitches.apply_changes("Sandwitches");
		SoftDrinks.apply_changes("Soft Drinks");
		Appetizers.apply_changes("Appetizers");
		exit(0);
	}
	char answer;
	cout<<"Do you want to return to the Main Menu? Y or N: ";
	cin>>answer;
	if(answer=='y')
	{
		system("cls");
		continue;
	}
	else
	{
		Sandwitches.apply_changes("Sandwitches");
		SoftDrinks.apply_changes("Soft Drinks");
		Appetizers.apply_changes("Appetizers");
		break;
	}
	
	return 0;
}
}