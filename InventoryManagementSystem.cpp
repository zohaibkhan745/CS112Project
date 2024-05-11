#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
    int proCode;
    float price,discount;
    string proName;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void del();
    void list();
    void receipt();
};

void shopping::menu()
{
    m:
    int choice;
    string email, password;
    cout<<"\t\t\t_______________________________________________"<<endl;
    cout<<endl;
    cout<<"\t\t\t_____________Supermarket Main Menu_____________"<<endl;
    cout<<endl;
    cout<<"\t\t\t_______________________________________________"<<endl;
    cout<<"\t\t\t|  1) Administrator                |"<<endl;
    cout<<"\t\t\t|  2) Buyer                        |"<<endl;
    cout<<"\t\t\t|  3) Exit                         |"<<endl;
    cout<<"\t\t\t|  Please select!                  |"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<">>>>>>>>>>>> Please login <<<<<<<<<<<<<"<<endl;
        cout<<">>Enter email: "<<endl;
        cin>>email;
        cout<<">>Enter password: "<<endl;
        cin>>password;

        if (email == "neha@email.com" && password == "neha123")
        {
            administrator();
        }
        else{
            cout<<"Invalid email/password !"<<endl;
        }
        break;
    case 2:{
        buyer();
    }
    break;
    case 3:{
        exit(0);
    }
    default:
    {cout<<"Enter a valid choice !"<<endl;}
    }
goto m;
}

void shopping::administrator(){
    m:
    int choice;
    cout<<endl;
    cout<<"\t\t\t\t______________Administrator menu______________"<<endl;
    cout<<">> 1) Add a product. "<<endl;
    cout<<">> 2) Modify a product. "<<endl;
    cout<<">> 3) Remove a product. "<<endl;
    cout<<">> 4) List of the products. "<<endl;
    cout<<">> 5) Back to main menu. "<<endl;
    cout<<"Please enter your choice !"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        del();
        break;
    case 4:
        list();
        break;
    case 5:
        menu();
        break;
    default:
        {cout<<"Enter a valid choice !"<<endl;}
    }
goto m;
}

void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t\t________________Buyer menu____________"<<endl;
    cout<<">> 1) Buy a product. "<<endl;
    cout<<">> 2) Back to main menu. "<<endl;
    cout<<"Please enter your choice !"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        {cout<<"Enter a valid choice !"<<endl;}
    }
    goto m;
}

void shopping::add(){
    m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    cout<<"\t\t\t\t________Add a new product________"<<endl;
    cout<<"Product code: "<<endl;
    cin>>proCode;
    cout<<"Name of the product: "<<endl;
    cin>>proName;
    cout<<"Price of the product: "<<endl;
    cin>>price;
    cout<<"Discount on the product: "<<endl;
    cin>>discount;

    data.open("database.txt", ios::in);
    if (!data) //product does not exist int the file
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<proCode<<" "<<proName<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d; //initialising the index of product
        while (!data.eof()) //end of file - eof
        {
            if (c==proCode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if (token==1)
    {
        goto m;
    }
    else{
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<proCode<<" "<<proName<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    cout<<"Record inserted !"<<endl;
}

void shopping::edit(){
    fstream data, data1;
    int proKey, token=0, c;
    float p,d;
    string n;
    
    cout<<"\t\t\t\t________Modify a product________"<<endl;
    cout<<">>Product code: "<<endl;
    cin>>proKey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout<<"Product doesn't exist !"<<endl;
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>proCode>>proName>>price>>discount;
        while (!data.eof())
        {
            if (proKey==proCode)
            {
                cout<<">>New product code: "<<endl;
                cin>>c;
                cout<<">>New product name: "<<endl;
                cin>>n;
                cout<<">>New product price: "<<endl;
                cin>>p;
                cout<<">>New product discount: "<<endl;
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"Record Edited !"<<endl;
                token++;
            }
            else{
                data1<<" "<<proCode<<" "<<proName<<" "<<price<<" "<<discount<<"\n";      
                }
            data>>proCode>>proName>>price>>discount; 
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token==0)
        {
            cout<<"Record not found!"<<endl;
        }
        
    }

}
void shopping :: del(){
    fstream data,data1;
    int proKey,token=0;
    cout<<"\t\t\t\t________Delete a product________"<<endl;
    cout<<">>Product code: "<<endl;
    cin>>proKey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout<<"Product doesn't exist !"<<endl;
    }
else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>proCode>>proName>>price>>discount;
    while (!data.eof())
        {
            if (proKey==proCode)
            {
                cout<<"Product deleted successfully!"<<endl;
                token++;
            }else{
                data1<<" "<<proCode<<" "<<proName<<" "<<price<<" "<<discount<<"\n";
            }
            data>>proCode>>proName>>price>>discount; 
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if (token==0)
        {
            cout<<"Record can't be found. "<<endl;
        }
        
    }
}    

void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\t\t\t\t________List of the products________"<<endl;
    cout<<endl;
    // cout<<"\t\t\t\t____________________________________"<<endl;
    cout<<"\t\t\tProduct code\t\t\tName\t\t\tPrice"<<endl;
    cout<<"\t\t\t_____________________________________________________________"<<endl;
    data>>proCode>>proName>>price>>discount;
    while (!data.eof())
    {
        cout<<"\t\t\t"<<proCode<<"\t\t\t\t"<<proName<<"\t\t\t"<<price<<"\n";
        data>>proCode>>proName>>price>>discount;
    }data.close();
}
void shopping :: receipt(){
    fstream data;
    int arrc[100], arrq[100], c=0;
    char choice;
    float amount=0,discount = 0,total=0;

    cout<<">>>>>>>>>>>>>RECEIPT<<<<<<<<<<<<<<"<<endl;
    data.open("database.txt",ios::in);
    if (!data)
    {
        cout<<"Empty database."<<endl;
    }
    else
    {
        data.close();
        list();
        cout<<"\t\t\t_____________________________________________________________"<<endl;
        cout<<endl;
        cout<<"\t\t\t\t____Please place your order____"<<endl;
        cout<<endl;
        do
        {
            m:
            cout<<">>Enter product code: "<<endl;
            cin>>arrc[c];
            cout<<">>Enter the product quantity: "<<endl;
            cin>>arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c]==arrc[i])
                {
                    cout<<"Duplicate product code. Please try again."<<endl;
                    goto m;
                }
            }
            c++;
            cout<<"Do you want to buy another product? Press y for yes / n for no"<<endl;
            cin>>choice;
        } while(choice =='y');
        cout<<"\t\t\t\t________RECEIPT________"<<endl;
        cout<<"\t Product code\t\tName\t\tQuantity\t\tPrice\t\t\tAmount\t\t\tAmount with discount"<<endl;
        cout<<"\t________________________________________________________________________________________________________________________________"<<endl;
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt",ios::in);
            data>>proCode>>proName>>price>>discount;
            while (!data.eof())
            {
                if (proCode==arrc[i])
                {
                    amount = price*arrq[i];
                    discount = amount - (amount*discount/100);
                    total+=discount;
                    cout<<"\n\t\t"<<proCode<<"\t\t"<<proName<<"\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t\t\t"<<amount<<"\t\t\t"<<discount<<"\n";
                }data>>proCode>>proName>>price>>discount;
            }
        }
        data.close();
    }
    cout<<"\t________________________________________________________________________________________________________________________________"<<endl;
    cout<<endl;
    cout<<"\nTotal Amount: "<<total<<endl;
}
int main(){
    system("cls");
    shopping shop;
    shop.menu();
}