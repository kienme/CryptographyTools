#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

using namespace std;

char filename[50], reader[1001], alpha[26], rope[26][1001];
int choice, nul[26], key, pos, ret=0, no=0;
void introtwo(void);

////////////////////////////////////////////////////////////////////////////////

void read(void)
{
	cout<<"\nEnter name of file(with extension): ";
	gets(filename);
	gets(filename);

   	ifstream myfile;
	myfile.open(filename);

	while(myfile.good())
	myfile.getline(reader,1001);

	myfile.close();
}

////////////////////////////////////////////////////////////////////////////////

void save_atbash(void)
{
	cout<<"\n\nEnter file name(with extension): ";
	gets(filename);
	
	ofstream myfile;
	myfile.open(filename);
	for(int i=0;reader[i]!='\0';++i)
	myfile<<reader[i];

	myfile.close();
	
	cout<<"\nDone.Congrats";
}

////////////////////////////////////////////////////////////////////////////////

void save_atbash_dec()
{
	cout<<"\n\nEnter file name(with extension): ";
	gets(filename);
	gets(filename);

	ofstream myfile;
	myfile.open(filename);

	for(int i=0;reader[i]!='\0';++i)
	myfile<<reader[i];

	myfile.close();

	cout<<"\nDone.Congrats";
	getch();
	
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			++ret;
			break;
	}
	
}

////////////////////////////////////////////////////////////////////////////////

void atbash_ec(void)
{
	system("cls");
	cout<<"\t\t\t\tAtbash Encoding\n\n\n";
	cout<<"Enter text to be encrypted\n\n";
	gets(reader);
	gets(reader);

	int i, k, m;

	for(m=0;reader[m]!='\0';++m)
	{
		if(isupper(reader[m]))
			for(i=65,k=90;i<=90;++i,--k)
			{
				if(int(reader[m])==i)
				{
					reader[m]=char(k);
					break;
				}
			}

		else
			for(i=97,k=122;i<=122;++i,--k)
			{
				if(int(reader[m])==i)
				{
					reader[m]=char(k);
					break;
				}
			}
	}

	save_atbash();

	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void atbash_dec(void)
{
	system("cls");
	cout<<"\t\t\t\tAtbash Decoding\n\n\n";
	read();

	int i, k, m;

	for(m=0;reader[m]!='\0';++m)
	{
		if(isupper(reader[m]))
			for(i=65,k=90;i<=90;++i,--k)
			{
				if(int(reader[m])==i)
				{
					reader[m]=char(k);
					break;
				}
			}

		else
			for(i=97,k=122;i<=122;++i,--k)
			{
				if(int(reader[m])==i)
				{
					reader[m]=char(k);
					break;
				}
			}
	}
	
	cout<<"\nDecoded script\n\n";
	puts(reader);
	
	getch();
	cout<<"\nSave to a file?\n";
	choice=getchar();
	
	switch(choice)
	{
        case 'y':
		case 'Y':
			save_atbash_dec();
			break;
			
		case 'n':
		case 'N':
			cout<<"Done.Congrats!";
			break;
	}
	
	if(ret==0)
	{

		getch();
		cout<<"\n\nGo back to main menu?\n";
		choice=getchar();
		choice=getchar();

		switch(choice)
		{
        	case 'y':
			case 'Y':
				system("cls");
				introtwo();
				break;

			case 'n':
			case 'N':
				break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void auto_save(void)
{
	cout<<"Enter name of file(with extension): ";
	gets(filename);
	gets(filename);
	
	ofstream myfile;
	myfile.open(filename);
	for(int l=0;rope[pos][l]!='\0';++l)
	myfile<<rope[pos][l];
	myfile.close();
	
	cout<<"\n\nDone.Congrats!";
	
	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

int check_dict(char newwx[])
{
    char word[50];
    
	ifstream myfile;
	myfile.open("Dictionary.txt");

	while(myfile>>word)
		if(strcmp(word,newwx)==0)
			return 1;

	myfile.close();

	return 0;
}

////////////////////////////////////////////////////////////////////////////////

void auto_compare(void)
{
    int checker, j, m, tree;
    char neww[50];

	for(m=0;m<=25;++m)
	{
		tree=0;

    	for(int i=0;rope[m][i]!='\0';++i)
			if(rope[m][i]==' ')
					if(tree==0)
					{
						for(int k=0,j=i+1;rope[m][j]!=' ';++k,++j)
   						neww[k]=rope[m][j];

						++tree;
						break;
					}

		checker=check_dict(neww);

		if(checker==1)
        {
		    pos=m;
		    break;
        }
	}

	if(pos!=26)
	{
		cout<<"\nLegitimate script found!\n\n";
		getch();
		for(int l=0;rope[pos][l]!='\0';++l)
		cout<<rope[pos][l];
		
		getch();
		cout<<"\n\nSave script to a file?\n";
		choice=getchar();

		switch(choice)
		{
			case 'y':
			case 'Y':
				auto_save();
				break;
				
			case 'n':
			case 'N':
				cout<<"Done.Congrats!";
				break;
		}
	}

	else
	cout<<"\nNot found";

	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void auto_decode(void)
{
	system("cls");
	cout<<"\t\t\t       Automatic Caesar Decipher\n\n\n";

	read();

    for(int i=0;i<=25;++i)
	{

		for(int k=0;reader[k]!='\0';++k)
		{
			int bad=i-26;

			if (isdigit(reader[k]))
            {
				rope[i][k]=reader[k];
				continue;
            }

			switch(reader[k])
			{
				case '-':
					rope[i][k]='-';
					continue;

				case ' ':
					rope[i][k]=' ';
					continue;

				case ',':
					rope[i][k]=',';
					continue;

				case '.':
					rope[i][k]='.';
					continue;

				case '!':
					rope[i][k]='!';
					continue;

			}

			if(isupper(reader[k]))
			{
				if(int(reader[k]+i)>90)
				rope[i][k]=char(int(reader[k])+bad);

				else
				rope[i][k]=char(reader[k]+i);
			}

			else
			{
                if(int(reader[k]+i)>122)
				rope[i][k]=char(int(reader[k])+bad);

				else
				rope[i][k]=char(reader[k]+i);
			}
		}
	}
	auto_compare();
}

///////////////////////////////////

void destroy_xor(void)
{
    ofstream myfile;
	myfile.open(filename);
	myfile<<"--CONTENTS DESTROYED--";
	myfile.close();
}

////////////////////////////////////////////////////////////////////////////////

void xor_dec(void)
{
	system("cls");
	
	cout<<"\t\t\t\tXOR Decryption\n\n\n\n";
	read();
	
	cout<<"\nEnter key: ";
	cin>>key;

	system("cls");

	for(int i=0;reader[i]!='\0';++i)
	reader[i]=char(int(reader[i])^key);

	cout<<"Decrypted code:\n\n";
	puts(reader);
	
	getch();
	cout<<"\nDestroy contents of original file?\n";
	choice=getchar();
	choice=getchar();
	
	switch(choice)
	{
		case 'y':
		case 'Y':
			destroy_xor();
			break;
	}
	
	cout<<"\nDone.Congrats!";
	
	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void save_xor(void)
{
	cout<<"\nEnter file name(with extension): ";
	gets(filename);
	gets(filename);
	
	ofstream myfile;
	myfile.open(filename);
	
	for(int i=0;reader[i]!='\0';++i)
	myfile<<reader[i];
	
	myfile.close();

	cout<<"\nDone.Congrats";
	
	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();
	
	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void xor_ec(void)
{
    system("cls");

	cout<<"\t\t\t\tXOR Encryption\n\n\n\n";
	cout<<"Enter text to be encrypted.\n\n";
	gets(reader);
	gets(reader);
	
	cout<<"\nEnter key(digits): ";
	cin>>key;

	for(int i=0;reader[i]!='\0';++i)
	reader[i]=reader[i]^key;

	save_xor();
}

////////////////////////////////////////////////////////////////////////////////

void save_caesar(void)
{
	int index;
	
	cout<<"\n\nEnter index number of decoded script\n";
	cin>>index;
	--index;
	
	cout<<"\nEnter file name(with extension): ";
	gets(filename);
	gets(filename);
	
	ofstream myfile;
	myfile.open(filename);
	
	for(int k=0;reader[k]!='\0';++k)
	{
        int bad=index-26;
        
        switch(reader[k])
		{
			case ' ':
				myfile<<" ";
				continue;

			case ',':
				myfile<<",";
				continue;

			case '.':
				myfile<<".";
				continue;

			case '!':
				myfile<<"!";
				continue;
		}

        
        if(isupper(reader[k]))
		{
			if(int(reader[k]+index)>90)
			myfile<<char(int(reader[k])+bad);

			else
			myfile<<char(reader[k]+index);
		}

		else
		{
            if(int(reader[k]+index)>122)
			myfile<<char(int(reader[k])+bad);

			else
			myfile<<char(reader[k]+index);
		}
	}
	
	myfile.close();
	cout<<"\nDone.Congrats!";
	
	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void caesar(void)
{
	system("cls");
	cout<<"\t\t\t\tCaesar Decipher Permutations\n\n\n";

	read();

	float sleeper;
	cout<<"\nEnter time interval(seconds): ";
	cin>>sleeper;
	
	system("cls");
	for(int i=0;i<=25;++i)
	{
		if(i<9)
		cout<<i+1<<".  ";
		else
		cout<<i+1<<". ";

		for(int k=0;reader[k]!='\0';++k)
		{
   			int bad=i-26;

			switch(reader[k])
			{
				case ' ':
					cout<<" ";
					continue;

				case ',':
					cout<<",";
					continue;

				case '.':
					cout<<".";
					continue;

				case '!':
					cout<<"!";
					continue;
			}

			if(isupper(reader[k]))
			{
				if(int(reader[k]+i)>90)
				cout<<char(int(reader[k])+bad);

				else
				cout<<char(reader[k]+i);
			}

			else
			{
                if(int(reader[k]+i)>122)
				cout<<char(int(reader[k])+bad);

				else
				cout<<char(reader[k]+i);
			}

		}
		cout<<endl<<endl;
		Sleep(sleeper*1000);
	}

	getch();
	cout<<"Save decoded script to file?\n";
	choice=getchar();
	choice=getchar();
	
	switch(choice)
	{
		case 'y':
		case 'Y':
			save_caesar();
			break;
			
		case 'n':
		case 'N':
			cout<<"\nDone.Congrats!";
	}
	
	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();
	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void savereport(void)
{
	cout<<"\nEnter filename(with extension): ";
	gets(filename);
	gets(filename);

	ofstream myfile;
	myfile.open(filename);

	myfile<<"FREQUENCY REPORT"<<endl<<endl;
	myfile<<"Subject: "<<reader<<endl<<endl;

	for(int m=0;m<=25;++m)
	{
		if(m<9)
		myfile<<m+1<<".  ";

		else
		myfile<<m+1<<". ";

		myfile<<alpha[m]<<":"<<nul[m]<<endl;
	}

	myfile.close();
	cout<<"\nDone.Congrats!";

	getch();
	cout<<"\n\nGo back to main menu?\n";
	choice=getchar();
//	choice=getchar();

	switch(choice)
	{
        case 'y':
		case 'Y':
			system("cls");
			introtwo();
			break;

		case 'n':
		case 'N':
			++no;
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////

void frequency(void)
{
	system("cls");
	cout<<"\t\t\t\tFrequency Analysis\n\n\n";
	cout<<"1. Read from file\n";
	cout<<"2. Enter string\n\n";
	cout<<"Enter choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: read();
			break;
			
		case 2:
			cout<<"\n\nEnter string\n";
			gets(reader);
			gets(reader);
			break;
	}
	
	int i,l,k;

	for(l=0;l<=26;++l)
	nul[l]=0;

	for(i=0,k=97;k<=122;++i,++k)
	alpha[i]=char(k);
	
	for(int j=0;j<=25;++j)
	for(int i=0;reader[i]!='\0';++i)
	if(alpha[j]==reader[i])
	++nul[j];
	
	system("cls");
	cout<<"\t\t\t\tFrequency report\n\n\n";

	for(int m=0;m<=25;++m)
	{
		if(m<9)
		cout<<m+1<<".  ";

		else
		cout<<m+1<<". ";

		cout<<alpha[m]<<":"<<nul[m]<<endl;
	}
	
	getch();
	cout<<"\n\nSave report to a file?\n";
	choice=getchar();
	
	switch(choice)
	{
		case 'y':
		case 'Y': 

			savereport();
			break;
	}
	
	if(!no)
	{
		getch();
		cout<<"\n\nGo back to main menu?\n";
		choice=getchar();
	choice=getchar();                //this was in comment

		switch(choice)
		{
     		case 'y':
			case 'Y':
				system("cls");
				introtwo();
				break;

			case 'n':
			case 'N':
				break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void caes_ec(void)
{
	system("cls");
	cout<<"\t\t\t\tCaesar encipher\n\n\n";
	cout<<"1. Read from file\n2. Enter string\n\n";
	cout<<"Enter choice: ";
	cin>>choice;
	
	if(choice==1)
	read();
	
	if(choice==2)
	{
		cout<<"\n\nEnter string: ";
		gets(reader);
		gets(reader);
	}
	
	int i,num;
	
	cout<<"\nEnter shift number(1-25): ";
	cin>>num;

	for(int k=1;num>26;++k)
	num-=26;

	for(i=0;reader[i]!='\0';++i)
	{
        int bad=num-26;

		if(isalpha(reader[i]))
		{
			if(isupper(reader[i]))
			{
				if((reader[i]+num)>90)
				reader[i]=reader[i]+bad;

				else
				reader[i]+=num;
			}

			else
			{
				if((reader[i]+num)>122)
				reader[i]=reader[i]+bad;

				else
				reader[i]+=num;
			}
		}
	}

	puts(reader);
}

////////////////////////////////////////////////////////////////////////////////

void introtwo(void)
{
    cout<<"\t\t\t\tCryptography tools\n\n\n\n\n\n";
	cout<<"\t\t1. XOR encryption\n";
	cout<<"\t\t2. XOR decryption\n";
	cout<<"\t\t3. Atbash encoding\n";
	cout<<"\t\t4. Atbash decoding\n";
	cout<<"\t\t5. Frequency analysis\n";
	cout<<"\t\t6. Caesar encipher\n";
	cout<<"\t\t7. Caesar decipher(automatic)\n";
	cout<<"\t\t8. Caesar decipher(permutations)\n";
	cout<<"\n\n\n\t\tEnter choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: xor_ec();
			break;
			
		case 2: xor_dec();
		    break;
		    
		case 3: atbash_ec();
		    break;
		    
		case 4: atbash_dec();
		    break;
		    
		case 5: frequency();
		    break;
		    
		case 6: caes_ec();
		    break;
		    
		case 7: auto_decode();
			break;

		case 8: caesar();
		    break;
			
	}
}

////////////////////////////////////////////////////////////////////////////////

void intro(void)
{
	for(int i=0;i<=100;i=i+5)
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\t\t\t\tLoading "<<i<<"%...";
		Sleep(i);
	}

	Sleep(700);
	system("cls");
	
	introtwo();
}

////////////////////////////////////////////////////////////////////////////////

int main()
{
	intro();
	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
