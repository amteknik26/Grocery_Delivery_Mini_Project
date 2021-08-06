#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<ctime>
#include<windows.h>

using namespace std;
string do_id[100];
int do_count;
COORD coord = {0, 0};

void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void main_interface_animation()
{
    system("cls");
	system("color FC");
	int j,i,x,y;
	for(i=0;i<45;i++)
	{
		gotoxy(i,13);
		cout<<" ";
		cout<<"Hi !";
		Sleep(50);
	}
	for(j=67;j>30;j--)
	{
		gotoxy(j,14);
		cout<<" Thank You For Choosing Helpy Hands";cout<<"            ";
		Sleep(50);
	}
	gotoxy(45,13);cout<<"Hi !";
	gotoxy(31,14);cout<<" Thank You For Choosing Helpy Hands";
	Sleep(100);
	gotoxy(32,15);cout<<" Your All In One Delivery Partner";
	Sleep(500);
	for(int j=78;j>=0;j--)
	{
		gotoxy(j,20);cout<<"\\";
		gotoxy(j,4);cout<<"/";
		Sleep(30);
	}
	Sleep(500);
	gotoxy(56,23);cout<<"Akhilesh     4SF18IS008";
	gotoxy(56,24);cout<<"Amaan        4SF18IS010";
	Sleep(4000);
	system("cls");
}
class customer
{
public:
    string customer_username,customer_address,customer_mobile,customer_email;
    string buffer;
    void read_customer_data();
    void customer_pack();
    void write_to_customer_file();
    void customer_unpack();
    int check_customer(string,string);
    void display_customer();
    void search_customer(string);
};

void customer :: read_customer_data()
{
    cout<<"\nEnter your details:\n";
    cout<<"Username: ";
    cin>>customer_username;
    cout<<"Address: ";
    cin>>customer_address;
    cout<<"Mobile Number: ";
    cin>>customer_mobile;
    cout<<"Email: ";
    cin>>customer_email;
}

void customer :: customer_pack()
{
    buffer.erase();
    buffer+=customer_mobile+"|"+customer_username+"|"+customer_address+"|"+customer_email+"$"+"\n";
}

void customer :: write_to_customer_file()
{
    fstream file;
    file.open("customer_file.txt",ios::out|ios::app);
    file<<buffer;
    file.close();
}

void customer :: customer_unpack()
{
    int i=0;
    customer_mobile.erase();
    while(buffer[i]!='|')
        customer_mobile+=buffer[i++];
    customer_username.erase();
    i++;
    while(buffer[i]!='|')
        customer_username+=buffer[i++];
    customer_address.erase();
    i++;
    while(buffer[i]!='|')
        customer_address+=buffer[i++];
    customer_email.erase();
    i++;
    while(buffer[i]!='$')
        customer_email+=buffer[i++];
}

int customer :: check_customer(string name,string phone)
{
    int flag=0;
    ifstream file;
    file.open("customer_file.txt",ios::in);
    while(!file.eof())
    {
        buffer.erase();
        getline(file,buffer);
        customer_unpack();
        if(name==customer_username && phone==customer_mobile)
        {
            flag=1;
            return flag;
        }
    }
    file.close();
    return flag;
}

void customer :: display_customer()
{
    string temp="0";
    ifstream file;
    ifstream myFile("customer_file.txt");
    if(myFile.fail())
    {
        cout<<"No Records in Customer File\n";
    }
    else
    {
        file.open("customer_file.txt",ios::in);
        cout<<"Customer Mobile No.\tCustomer Name\tCustomer Address\t\tCustomer Email\n";
        while(!file.eof())
        {
            getline(file,buffer);
            customer_unpack();
            if(customer_email==temp)
                break;
            cout<<customer_mobile<<"\t\t"<<customer_username<<"\t\t"<<customer_address<<"\t\t"<<customer_email<<endl;
            temp=customer_email;
        }
        file.close();
    }
}

void customer :: search_customer(string c_num)
{
    string temp="0";
    ifstream file;
    ifstream myFile("customer_file.txt");
    if(myFile.fail())
    {
        cout<<"No Records in Customer File\n";
    }
    else
    {
        file.open("customer_file.txt",ios::in);
        cout<<"Customer Mobile No.\tCustomer Name\tCustomer Address\n";
        while(!file.eof())
        {
            getline(file,buffer);
            customer_unpack();
            if(customer_email==temp)
                break;
            if(customer_mobile==c_num)
            {
                cout<<customer_mobile<<"\t\t"<<customer_username<<"\t\t"<<customer_address<<endl;
                temp=customer_email;
            }
        }
        file.close();
    }
}

class employee
{
public:
    string employee_username,employee_mobile,employee_address,employee_email;
    string buffer;
    void read_employee_data();
    void employee_pack();
    void write_to_employee_file();
    void employee_unpack();
    int check_employee(string,string,string);
    void display_employee();
};

void employee :: read_employee_data()
{
    cout<<"\nEnter your details:\n";
    cout<<"Username: ";
    cin>>employee_username;
    cout<<"Address: ";
    cin>>employee_address;
    cout<<"Mobile Number: ";
    cin>>employee_mobile;
    cout<<"Email: ";
    cin>>employee_email;
}

void employee :: employee_pack()
{
    buffer.erase();
    buffer+=employee_mobile+"|"+employee_username+"|"+employee_address+"|"+employee_email+"$"+"\n";
}

void employee :: write_to_employee_file()
{
    fstream file;
    file.open("employee_file.txt",ios::out|ios::app);
    file<<buffer;
    file.close();
}

void employee :: employee_unpack()
{
    int i=0;
    employee_mobile.erase();
    while(buffer[i]!='|')
        employee_mobile+=buffer[i++];
    employee_username.erase();
    i++;
    while(buffer[i]!='|')
        employee_username+=buffer[i++];
    employee_address.erase();
    i++;
    while(buffer[i]!='|')
        employee_address+=buffer[i++];
    employee_email.erase();
    i++;
    while(buffer[i]!='$')
        employee_email+=buffer[i++];
}

int employee :: check_employee(string name,string phone,string password)
{
    int flag=0;
    ifstream file;
    file.open("employee_file.txt",ios::in);
    while(!file.eof())
    {
        buffer.erase();
        getline(file,buffer);
        employee_unpack();
        if(name==employee_username && phone==employee_mobile && password=="12345")
        {
            flag=1;
            return flag;
        }
    }
    file.close();
    return flag;
}

void employee :: display_employee()
{
    string temp="0";
    ifstream file;
    ifstream myFile("employee_file.txt");
    if(myFile.fail())
    {
        cout<<"No Records in Employee File\n";
    }
    else
    {
        file.open("employee_file.txt",ios::in);
        cout<<"Customer Mobile No.\tCustomer Name\tCustomer Address\t\t\n";
        while(!file.eof())
        {
            getline(file,buffer);
            employee_unpack();
            if(employee_email==temp)
                break;
            cout<<employee_mobile<<"\t\t"<<employee_username<<"\t\t"<<employee_address<<"\t\t"<<employee_email<<endl;
            temp=employee_email;
        }
        file.close();
    }
}

class store
{
public:
    string store_id,store_name,store_address,store_phone;
    string buffer;
    int store_count;
    string store_id_list[100];
    int store_index_list[100];
    void read_store();
    void store_pack();
    void create_store_index();
    string extract_store_id();
    void write_to_store_file();
    void sort_store_index();
    void display_store();
    void store_unpack();
    int search_store(string);
    int search_store_index(string);
    void delete_store(string);
    void search(string);
    void update_store(string);
};

void store :: read_store()
{
    cout<<"Enter Store Details: \n";
    cout<<"Store ID: ";
    cin>>store_id;
    cout<<"Store Name: ";
    cin>>store_name;
    cout<<"Store Address: ";
    cin>>store_address;
    cout<<"Store Phone Number: ";
    cin>>store_phone;
}

void store :: store_pack()
{
    buffer.erase();
    buffer+=store_id+"|"+store_name+"|"+store_address+"|"+store_phone+"$"+"\n";
}

void store :: write_to_store_file()
{
    int pos;
    fstream file;
    file.open("store_file.txt",ios::out|ios::ate|ios::app);
    pos=file.tellp();
    file<<buffer;
    file.close();
    store_id_list[++store_count]=store_id;
    store_index_list[store_count]=pos;
    sort_store_index();
}

string store::extract_store_id()
{
    string store_id;
    int i=0;
    store_id.erase();
    while(buffer[i]!='|')
        store_id+=buffer[i++];
    return store_id;
}

void store :: create_store_index()
{
    fstream file;
    int pos;
    string store_id;
    store_count=-1;
    file.open("store_file.txt",ios::in);
    while(!file.eof())
    {
        pos=file.tellg();
        buffer.erase();
        getline(file,buffer);
        if(buffer[0]!='*')
        {
            if(buffer.empty())
                break;
            store_id=extract_store_id();
            store_id_list[++store_count]=store_id;
            store_index_list[store_count]=pos;
        }
    }
    file.close();
    sort_store_index();
    buffer.erase();
}

void store::sort_store_index()
{
    int temp_Address;
    string temp_store_id;
    for(int i=0;i<=store_count;i++)
    {
        for(int j=i+1;j<=store_count;j++)
        {
            if(store_id_list[i]>store_id_list[j])
            {
                temp_store_id=store_id_list[i];
                store_id_list[i]=store_id_list[j];
                store_id_list[j]=temp_store_id;
                temp_Address=store_index_list[i];
                store_index_list[i]=store_index_list[j];
                store_index_list[j]=temp_Address;
            }
        }
    }
//    To check index(Primary Indexing)
//    for(int i=0;i<=store_count;i++)
//    {
//        cout<<store_id_list[i]<<"\t"<<store_index_list[i]<<"\n";
//    }
}

void store :: store_unpack()
{
    int i=0;
    store_id.erase();
    while(buffer[i]!='|')
        store_id+=buffer[i++];
    store_name.erase();
    i++;
    while(buffer[i]!='|')
        store_name+=buffer[i++];
    store_address.erase();
    i++;
    while(buffer[i]!='|')
        store_address+=buffer[i++];
    store_phone.erase();
    i++;
    while(buffer[i]!='$')
        store_phone+=buffer[i++];
}

void store :: display_store()
{
    string temp="0";
    ifstream file;
    ifstream myFile("store_file.txt");
    if(myFile.fail())
    {
        cout<<"No Records in Store File\n";
    }
    else
    {
        file.open("store_file.txt",ios::in);
        cout<<"Store ID\tStore Name\tStore Address\tStore Phone Number\n";
        while(!file.eof())
        {
            getline(file,buffer);
            store_unpack();
            if(store_phone==temp)
                break;
            cout<<store_id<<"\t\t"<<store_name<<"\t\t"<<store_address<<"\t\t"<<store_phone<<endl;
            temp=store_phone;
        }
        file.close();
    }
}

int store :: search_store_index(string key)
{
    int low=0,high=store_count,mid=0,flag=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(store_id_list[mid]==key)
        {
            flag=1;
            break;
        }
        if(store_id_list[mid]>key)
            high=mid-1;
        if(store_id_list[mid]<key)
            low=mid+1;
    }
    if(flag)
        return mid;
    else
        return -1 ;
}

int store :: search_store(string key)
{
    int pos=0;
    fstream file;
    buffer.erase();
    pos=search_store_index(key);
    if(pos==-1)
        return 0;
    else if(pos>=0)
    {
        return 1;
    }
    return 0;
}

void store :: delete_store(string key)
{
    string buff="",prev="";
    int pos=0,i;
    fstream file;
    fstream temp_file;
    pos=search_store_index(key);
    if(pos>=0)
    {
        file.open("store_file.txt",ios::in|ios::out);
        temp_file.open("temp_store.txt",ios::out|ios::trunc);
        temp_file.close();
        temp_file.open("temp_store.txt",ios::in|ios::out|ios::app);
        while(!file.eof())
        {
            getline(file,buffer);
            store_unpack();
            if(store_phone==prev)
                break;
            prev=store_phone;
            if(store_id!=key)
            {
                buff+=store_id+"|"+store_name+"|"+store_address+"|"+store_phone+"$"+"\n";
            }
        }
        temp_file << buff;
        file.close();
        cout<<buff;
        file.open("store_file.txt",ios::out|ios::trunc);
        file.close();
        file.open("store_file.txt",ios::out|ios::app);
        file << buff;
        file.close();
        temp_file.close();
        cout<<"\nRecord Deleted \n";
        for(i=pos;i<store_count;i++)
        {
            store_id_list[i]=store_id_list[i+1];
            store_index_list[i]=store_index_list[i+1];
        }
        store_count--;
    }
    else
        cout<<"record not found\n";
}

void store :: update_store(string key)
{
    string buff="",prev="",name,address,phone;
    int pos=0,ch;
    fstream file;
    fstream temp_file;
    pos=search_store_index(key);
    cout<<"Update options:\n";
    cout<<"1: Store Name\t2: Store Address\t3: Store Phone Number\n";
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter new Name: ";
                cin>>name;
                break;
        case 2: cout<<"Enter new Address: ";
                cin>>address;
                break;
        case 3: cout<<"Enter new Phone Number: ";
                cin>>phone;
                break;
        default:cout<<"Invalid choice\n";
    }
    if(pos>=0)
    {
        file.open("store_file.txt",ios::in|ios::out);
        temp_file.open("temp_update_store.txt",ios::out|ios::trunc);
        temp_file.close();
        temp_file.open("temp_update_store.txt",ios::in|ios::out|ios::app);
        while(!file.eof())
        {
            getline(file,buffer);
            store_unpack();
            if(store_phone==prev)
                break;
            prev=store_phone;
            if(store_id!=key)
            {
                buff+=store_id+"|"+store_name+"|"+store_address+"|"+store_phone+"$"+"\n";
            }
            else if(store_id==key && ch==1)
            {
                buff+=store_id+"|"+name+"|"+store_address+"|"+store_phone+"$"+"\n";
            }
            else if(store_id==key && ch==2)
            {
                buff+=store_id+"|"+store_name+"|"+address+"|"+store_phone+"$"+"\n";
            }
            else if(store_id==key && ch==3)
            {
                buff+=store_id+"|"+store_name+"|"+store_address+"|"+phone+"$"+"\n";
            }
        }
        temp_file << buff;
        file.close();
        file.open("store_file.txt",ios::out|ios::trunc);
        file.close();
        file.open("store_file.txt",ios::out|ios::app);
        file << buff;
        file.close();
        temp_file.close();
        cout<<"\nRecord Updated \n";
    }
    else
        cout<<"record not found\n";
}

class item
{
public:
    string st_id,item_id,item_name,item_quantity,item_price;
    string buffer;
    int item_count;
    string item_name_list[100];
    int item_index_list[100];
    void read_item(string);
    void item_pack();
    void create_item_index();
    string extract_item_name();
    void write_to_item_file();
    void sort_item_index();
    void display_item(string);
    void item_unpack();
    string get_item_price(string);
    int search_item_index(string);
    void delete_item(string,string);
    void update_item(string,string);
};

void item :: read_item(string str_id)
{
    st_id=str_id;
    cout<<"Item ID: ";
    cin>>item_id;
    cout<<"Item Name: ";
    cin>>item_name;
    cout<<"Item quantity: ";
    cin>>item_quantity;
    cout<<"Item price: ";
    cin>>item_price;
}

void item :: item_pack()
{
    buffer.erase();
    buffer+=st_id+"|"+item_id+"|"+item_name+"|"+item_quantity+"|"+item_price+"$"+"\n";
}

void item :: write_to_item_file()
{
    int pos;
    fstream file;
    file.open("item_file.txt",ios::out|ios::ate|ios::app);
    pos=file.tellp();
    file<<buffer;
    file.close();
    item_name_list[++item_count]=item_name;
    item_index_list[item_count]=pos;
    sort_item_index();
}

string item :: extract_item_name()
{
    string item_name;
    int i=0;
    item_name.erase();
    for(int j=0;j<2;j++)
    {
        while(buffer[i]!='$')
        {
            if(buffer[i++]=='|')
                break;
        }
    }
    while(buffer[i]!='|')
        item_name+=buffer[i++];
    return item_name;
}

void item :: create_item_index()
{
    fstream file;
    int pos;
    string item_name;
    item_count=-1;
    file.open("item_file.txt",ios::in);
    while(!file.eof())
    {
        pos=file.tellg();
        buffer.erase();
        getline(file,buffer);
        if(buffer[0]!='*')
        {
            if(buffer.empty())
                break;
            item_name=extract_item_name();
            item_name_list[++item_count]=item_name;
            item_index_list[item_count]=pos;
        }
    }
    file.close();
    sort_item_index();
    buffer.erase();
}

void item :: sort_item_index()
{
    int temp_Address;
    string temp_item_name;
    for(int i=0;i<=item_count;i++)
    {
        for(int j=i+1;j<=item_count;j++)
        {
            if(item_name_list[i]>item_name_list[j])
            {
                temp_item_name=item_name_list[i];
                item_name_list[i]=item_name_list[j];
                item_name_list[j]=temp_item_name;
                temp_Address=item_index_list[i];
                item_index_list[i]=item_index_list[j];
                item_index_list[j]=temp_Address;
            }
        }
    }
    //To check index(secondary indexing)
    //for(int i=0;i<=item_count;i++)
    //{
    //    cout<<item_name_list[i]<<"\t"<<item_index_list[i]<<"\n";
    //}
}

void item :: item_unpack()
{
    int i=0;
    st_id.erase();
    while(buffer[i]!='|')
        st_id+=buffer[i++];
    item_id.erase();
    i++;
    while(buffer[i]!='|')
        item_id+=buffer[i++];
    item_name.erase();
    i++;
    while(buffer[i]!='|')
        item_name+=buffer[i++];
    item_quantity.erase();
    i++;
    while(buffer[i]!='|')
        item_quantity+=buffer[i++];
    item_price.erase();
    i++;
    while(buffer[i]!='$')
        item_price+=buffer[i++];
}

void item :: display_item(string str_id)
{
    string temp="0";
    ifstream file;
    ifstream myFile("item_file.txt");
    if(myFile.fail())
    {
        cout<<"\nNo Records in Item File\n";
    }
    else
    {
        file.open("item_file.txt",ios::in);
        cout<<"\nStore ID\tItem ID\t\tItem Name\tItem Quantity\tItem Price(in Rupees)\n";
        while(!file.eof())
        {
            getline(file,buffer);
            item_unpack();
            if(st_id==str_id)
            {
                if(item_id==temp)
                break;
                cout<<st_id<<"\t\t"<<item_id<<"\t\t"<<item_name<<"\t\t"<<item_quantity<<"\t\t"<<item_price<<endl;
                temp=item_id;
            }

        }
        file.close();
    }
}

string item::get_item_price(string it_name)
{
    string it_pr;
    ifstream file;
    file.open("item_file.txt",ios::in);
    while(!file.eof())
    {
        getline(file,buffer);
        item_unpack();
        if(item_name==it_name)
            it_pr=item_price;
    }
    return it_pr;
}

int item :: search_item_index(string key)
{
    int low=0,high=item_count,mid=0,flag=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(item_name_list[mid]==key)
        {
            flag=1;
            break;
        }
        if(item_name_list[mid]>key)
            high=mid-1;
        if(item_name_list[mid]<key)
            low=mid+1;
    }
    if(flag)
        return mid;
    else
        return -1 ;
}

void item :: delete_item(string key,string str_id)
{
    string buff="",prev="";
    int pos=0,i;
    fstream file;
    fstream temp_file;
    pos=search_item_index(key);
    if(pos>=0)
    {
        file.open("item_file.txt",ios::in|ios::out);
        temp_file.open("temp_item.txt",ios::out|ios::trunc);
        temp_file.close();
        temp_file.open("temp_item.txt",ios::in|ios::out|ios::app);
        while(!file.eof())
        {
            getline(file,buffer);
            item_unpack();
            if(item_id==prev)
                break;
            prev=item_id;
            if(item_name!=key || st_id!=str_id)
            {
                buff+=st_id+"|"+item_id+"|"+item_name+"|"+item_quantity+"|"+item_price+"$"+"\n";
            }
        }
        temp_file << buff;
        file.close();
        file.open("item_file.txt",ios::out|ios::trunc);
        file.close();
        file.open("item_file.txt",ios::out|ios::app);
        file << buff;
        file.close();
        temp_file.close();
        cout<<"\nRecord Deleted \n";
        for(i=pos;i<item_count;i++)
        {
            item_name_list[i]=item_name_list[i+1];
            item_index_list[i]=item_index_list[i+1];
        }
        item_count--;
    }
    else
        cout<<"record not found\n";
}

void item :: update_item(string key,string str_id)
{
    string buff="",prev="",quantity,price;
    int pos=0,ch;
    fstream file;
    fstream temp_file;
    pos=search_item_index(key);
    cout<<"Update options:\n";
    cout<<"1: Item Quantity\t2: Item Price\n";
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter new value for Item Quantity: ";
                cin>>quantity;
                break;
        case 2: cout<<"Enter new value for Item Price: ";
                cin>>price;
                break;
        default:cout<<"Invalid choice\n";
    }
    if(pos>=0)
    {
        file.open("item_file.txt",ios::in|ios::out);
        temp_file.open("temp_update_item.txt",ios::out|ios::trunc);
        temp_file.close();
        temp_file.open("temp_update_item.txt",ios::in|ios::out|ios::app);
        while(!file.eof())
        {
            getline(file,buffer);
            item_unpack();
            if(item_id==prev)
                break;
            prev=item_id;
            if(item_name!=key || st_id!=str_id)
            {
                buff+=st_id+"|"+item_id+"|"+item_name+"|"+item_quantity+"|"+item_price+"$"+"\n";
            }
            else if((item_name==key || st_id!=str_id) && ch==1)
            {
                buff+=st_id+"|"+item_id+"|"+item_name+"|"+quantity+"|"+item_price+"$"+"\n";
            }
            else if((item_name==key || st_id!=str_id) && ch==2)
            {
                buff+=st_id+"|"+item_id+"|"+item_name+"|"+item_quantity+"|"+price+"$"+"\n";
            }
        }
        temp_file << buff;
        file.close();
        cout<<buff;
        file.open("item_file.txt",ios::out|ios::trunc);
        file.close();
        file.open("item_file.txt",ios::out|ios::app);
        file << buff;
        file.close();
        temp_file.close();
        cout<<"\nRecord Updated \n";
    }
    else
        cout<<"record not found\n";
}

class delivery
{
public:
    string delivery_id,delivery_order_id,delivery_customer_name,delivery_employee_name,delivery_time,deliver_order_price,delivery_order_details,delivery_store_name,delivery_status;
    string buffer;
    void read_delivery(string,string,string,string,string,string,string,string);
    void delivery_pack();
    void write_to_delivery_file();
    void delivery_unpack();
    void display_delivery(string);
    void get_delivery_id();
};

void delivery :: read_delivery(string del_id,string ord_id,string c_name,string e_name,string o_price,string o_details,string dtime,string str_name)
{
    cout<<"Enter 1 if delivery successful or 0 if delivery canceled: ";
    cin>>delivery_status;
    if(delivery_status=="1")
        delivery_status="Successful";
    else
        delivery_status="Cancelled";
    delivery_id=del_id;
    delivery_order_id=ord_id;
    delivery_customer_name=c_name;
    delivery_employee_name=e_name;
    deliver_order_price=o_price;
    delivery_order_details=o_details;
    delivery_time=dtime;
    delivery_store_name=str_name;
}

void delivery :: delivery_pack()
{
    buffer.erase();
    buffer+=delivery_id+"|"+delivery_order_id+"|"+delivery_customer_name+"|"+delivery_store_name+"|"+delivery_order_details+"|"+deliver_order_price+"|"+delivery_employee_name+"|"+delivery_time+"|"+delivery_status+"$"+"\n";
}

void delivery :: write_to_delivery_file()
{
    fstream file;
    file.open("delivery_file.txt",ios::out|ios::app);
    file<<buffer;
    file.close();
}

void delivery :: delivery_unpack()
{
    int i=0;
    delivery_id.erase();
    while(buffer[i]!='|')
        delivery_id+=buffer[i++];
    delivery_order_id.erase();
    i++;
    while(buffer[i]!='|')
        delivery_order_id+=buffer[i++];
    delivery_customer_name.erase();
    i++;
    while(buffer[i]!='|')
        delivery_customer_name+=buffer[i++];
    delivery_store_name.erase();
    i++;
    while(buffer[i]!='|')
        delivery_store_name+=buffer[i++];
    delivery_order_details.erase();
    i++;
    while(buffer[i]!='|')
        delivery_order_details+=buffer[i++];
    deliver_order_price.erase();
    i++;
    while(buffer[i]!='|')
        deliver_order_price+=buffer[i++];
    delivery_employee_name.erase();
    i++;
    while(buffer[i]!='|')
        delivery_employee_name+=buffer[i++];
    delivery_time.erase();
    i++;
    while(buffer[i]!='|')
        delivery_time+=buffer[i++];
    delivery_status.erase();
    i++;
    while(buffer[i]!='$')
        delivery_status+=buffer[i++];
}

void delivery :: display_delivery(string check)
{
    string temp="0";
    ifstream file;
    ifstream myFile("delivery_file.txt");
    if(myFile.fail())
    {
        cout<<"\nNo Records in Item File\n";
    }
    else
    {
        file.open("delivery_file.txt",ios::in);
        cout<<"\nDelivery ID\tOrder ID  Customer Name\tStore Name\tOrder details\t\tOrder Price\tEmployee Name\tDelivery time\t\tDelivery status\n";
        while(!file.eof())
        {
            getline(file,buffer);
            delivery_unpack();
            if(check=="ADMIN" || check==delivery_customer_name || check==delivery_employee_name)
            {
                if(delivery_order_id==temp)
                break;
                cout<<delivery_id<<"\t\t"<<delivery_order_id<<"\t    "<<delivery_customer_name<<"\t"<<delivery_store_name<<"\t\t"<<delivery_order_details<<"\t"<<deliver_order_price<<"\t\t"<<delivery_employee_name<<"\t\t"<<delivery_time<<"\t"<<delivery_status<<endl;
                temp=delivery_order_id;
            }
        }
        file.close();
    }
}

void delivery :: get_delivery_id()
{
    fstream file;
    string temp="0";
    file.open("delivery_file.txt",ios::in);
    while(!file.eof())
    {
        getline(file,buffer);
        delivery_unpack();
        if(delivery_order_id==temp)
            break;
        do_id[do_count]=delivery_order_id;
        do_count++;
        temp=delivery_order_id;
    }
    file.close();
}

class order
{
public:
    delivery d;
    string order_id,customer_order_name,employee_order_name,customer_order_number,employee_order_number,order_details,order_price,store_order_name;
    string buffer;
    void read_order(string,string,string,string,string,string);
    void order_pack();
    void write_to_order_file();
    void order_unpack();
    void display_order(string);
    void update_orders(string,string,string);
    void pending_orders(string);
    void extract_order_details(string);
    void pending_orders_for_delivery(string);
};

void order :: read_order(string c_name,string c_no,string ord_id,string str_name,string ord_details,string ord_price)
{
    customer_order_name=c_name;
    customer_order_number=c_no;
    order_id=ord_id;
    store_order_name=str_name;
    order_details=ord_details;
    order_price=ord_price;
    employee_order_name="Assigning soon";
    employee_order_number="Assigning soon";
}

void order :: order_pack()
{
    buffer.erase();
    buffer+=order_id+"|"+customer_order_name+"|"+customer_order_number+"|"+store_order_name+"|"+order_details+"|"+order_price+"|"+employee_order_name+"|"+employee_order_number+"$"+"\n";
}

void order :: write_to_order_file()
{
    fstream file;
    file.open("order_file.txt",ios::out|ios::app);
    file<<buffer;
    file.close();
}

void order :: order_unpack()
{
    int i=0;
    order_id.erase();
    while(buffer[i]!='|')
        order_id+=buffer[i++];
    customer_order_name.erase();
    i++;
    while(buffer[i]!='|')
        customer_order_name+=buffer[i++];
    customer_order_number.erase();
    i++;
    while(buffer[i]!='|')
        customer_order_number+=buffer[i++];
    store_order_name.erase();
    i++;
    while(buffer[i]!='|')
        store_order_name+=buffer[i++];
    order_details.erase();
    i++;
    while(buffer[i]!='|')
        order_details+=buffer[i++];
    order_price.erase();
    i++;
    while(buffer[i]!='|')
        order_price+=buffer[i++];
    employee_order_name.erase();
    i++;
    while(buffer[i]!='|')
        employee_order_name+=buffer[i++];
    employee_order_number.erase();
    i++;
    while(buffer[i]!='$')
        employee_order_number+=buffer[i++];
}

void order :: display_order(string check)
{
    string temp="0";
    ifstream file;
    ifstream myFile("updated_order_file.txt");
    if(myFile.fail())
    {
        cout<<"No Records \n";
    }
    else
    {
        file.open("updated_order_file.txt",ios::in);
        cout<<"Order ID\tCustomer Name\tCustomer Mobile No.\tStore Name\tOrder Details\t\tOrder Price\tEmployee Name\tEmployee number\n";
        while(!file.eof())
        {
            int flag=0;
            getline(file,buffer);
            order_unpack();
            if(order_price==temp)
                break;
            if(customer_order_number==check || check=="ADMIN" || check==employee_order_number)
            {
                if(check==employee_order_number)
                {
                    for(int i=0;i<do_count;i++)
                    {
                        if(order_id==do_id[i])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                temp=order_price;
                if(flag==1)
                    continue;
                cout<<order_id<<"\t\t"<<customer_order_name<<"\t\t"<<customer_order_number<<"\t\t"<<store_order_name<<"\t\t"<<order_details<<"\t\t"<<order_price<<"\t"<<employee_order_name<<"\t"<<employee_order_number<<"\n";

            }
        }
        file.close();
    }
}

void order :: extract_order_details(string ord_id)
{
    ifstream file;
    ifstream myFile("updated_order_file.txt");
    if(myFile.fail())
    {
        cout<<"No Records \n";
    }
    else
    {
        file.open("updated_order_file.txt",ios::in);
        while(!file.eof())
        {
            getline(file,buffer);
            order_unpack();
            if(order_id==ord_id)
            {
                break;
            }
        }
        file.close();
    }
}

void order :: pending_orders(string check)
{
    string temp_id,temp_c_name,temp_c_ph,temp_st_name,temp_price,temp_details;
    fstream file1,file2;
    file1.open("order_file.txt",ios::in);
    cout<<"Pending orders: \n";
    cout<<"Order ID\tCustomer Name\tCustomer Mobile No.\tStore Name\tOrder Details\t\tOrder Price\tEmployee Name\tEmployee number\n";
    while(!file1.eof())
    {
        int flag=0;
        getline(file1,buffer);
        order_unpack();
        temp_id=order_id;
        temp_c_name=customer_order_name;
        temp_c_ph=customer_order_number;
        temp_st_name=store_order_name;
        temp_details=order_details;
        temp_price=order_price;
        file2.open("updated_order_file.txt",ios::in);
        while(!file2.eof())
        {
            getline(file2,buffer);
            order_unpack();
            if(temp_id==order_id)
            {
                flag=1;
                break;
            }
        }
        file2.close();
        if(flag==0)
        {
            if(temp_c_ph==check || check=="ADMIN")
                cout<<temp_id<<"\t\t"<<temp_c_name<<"\t\t"<<temp_c_ph<<"\t\t"<<temp_st_name<<"\t\t"<<temp_details<<"\t\t"<<temp_price<<"\t"<<"Assigning soon"<<"\t"<<"Assigning soon"<<"\n";
        }
    }

    file1.close();
}

void order :: update_orders(string ord_id,string emp_name,string emp_ph)
{
    fstream file,file1;
    file.open("updated_order_file.txt",ios::out|ios::app);
    file1.open("order_file.txt",ios::in);
    file.seekp(0);
    while(!file1.eof())
    {
        getline(file1,buffer);
        order_unpack();
        if(order_id==ord_id)
        {
            order_id=ord_id;
            employee_order_name=emp_name;
            employee_order_number=emp_ph;
            order_pack();
            file<<buffer;
            file1.close();
            file.close();
        }
    }
}

int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    int choice,ch,flag,sch,ord_price=0,hold=0;
    fstream file;
    string name,phone,password;
    string pr;
    string temp;
    stringstream ss;
    customer c;
    employee e;
    store s;
    item i;
    order o;
    delivery d;
    s.create_store_index();
    i.create_item_index();
    main_interface_animation();
    for(;;)
    {
        cout<<"*********************************************************************************\n";
        cout<<"*                                                                               *\n";
        cout<<"*\t\t\t\tHelpy Hands\t\t\t\t\t*\n";
        cout<<"*\t\t\t    Login/Registration\t\t\t\t*\n";
        cout<<"*                                                                               *\n";
        cout<<"*********************************************************************************\n";
        cout<<"*                                                                               *\n";
        cout<<"* 1: Customer Login\t\t2: Employee Login\t\t3: Admin Login\t*\n";
        cout<<"* 4: Customer Registration\t5: Employee Registration\t6: Exit\t\t*\n";
        cout<<"*                                                                               *\n";
        cout<<"*********************************************************************************\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\nEnter your Username: ";
                    cin>>name;
                    cout<<"Enter your Mobile Numeber: ";
                    cin>>phone;
                    flag=c.check_customer(name,phone);
                    if(flag==0)
                    {
                        cout<<"\nInvalid credentials\nTry Again!\n";
                        break;
                    }
                    for(;;)
                    {
                        system("cls");
                        cout<<"\n\t     Welcome "<<name<<"\n\tWe are here to serve YOU\n";
                        cout<<"\n1: Place Order\t\t2: View Pending Orders\n3: View Past Orders\t4: Delivery Details\n\t\t5: Logout?\n";
                        cout<<"Enter your choice: ";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1: for(;;)
                                    {
                                        s.display_store();
                                        cout<<"Enter store id and store name to select items from that store: \n";
                                        cout<<"store id: ";
                                        cin>>temp;
                                        cout<<"store name: ";
                                        string str_name;
                                        cin>>str_name;
                                        if(s.search_store(temp)==1)
                                        {
                                            i.display_item(temp);
                                            string ord="",chr,it_name,it_qt,it_pr;
                                            for(;;)
                                            {
                                                cout<<"Enter item name: ";
                                                cin>>it_name;
                                                cout<<"Enter quantity: ";
                                                cin>>it_qt;
                                                int x;
                                                istringstream(it_qt) >> x;
                                                it_pr=i.get_item_price(it_name);
                                                int y;
                                                istringstream(it_pr) >> y;
                                                hold=x*y;
                                                ord_price=ord_price+hold;
                                                ord=ord+it_name+"*"+it_qt;
                                                file.open("order_id_count.txt",ios::in);
                                                string buff;
                                                int val;
                                                getline(file,buff);
                                                istringstream(buff) >> val;
                                                file.clear();
                                                file.close();
                                                cout<<"\nOrder ID\tOrder details\t\tTotal Price(Including delivery charges)\n";
                                                cout<<val<<"\t\t"<<ord<<"\t\t"<<ord_price+20<<"\n";
                                                cout<<"\n1: Add more items\t2: Re Enter Items\n3: Confirm Order\t4: Cancel Order\n";
                                                cout<<"Enter your choice: ";
                                                cin>>sch;
                                                switch(sch)
                                                {
                                                    case 1: ord=ord+" + ";
                                                            continue;

                                                    case 2: ord="";
                                                            ord_price=0;
                                                            break;

                                                    case 3: ord_price=ord_price+20;
                                                            ss<<ord_price;
                                                            ss>>pr;
                                                            file.open("order_id_count.txt");
                                                            val++;
                                                            file << val;
                                                            file.close();
                                                            o.read_order(name,phone,buff,str_name,ord,pr);
                                                            o.order_pack();
                                                            o.write_to_order_file();
                                                            break;

                                                    case 4: ord_price=0;
                                                            break;

                                                    default:cout<<"Invalid choice\n";
                                                }
                                                if(sch==4 || sch==3)
                                                    break;
                                            }
                                            if(sch==4 || sch==3)
                                                break;
                                        }
                                        else
                                        {
                                            cout<<"Store does not exist in the list\n";
                                        }
                                    }
                                    break;

                            case 2: for(;;)
                                    {
                                        o.pending_orders(phone);
                                        cout<<"Enter 0 to Exit: ";
                                        cin>>sch;
                                        if(sch==0)
                                            break;
                                        else
                                            cout<<"Invalid choice\n";
                                    }
                                    break;

                            case 3: for(;;)
                                    {
                                        o.display_order(phone);
                                        cout<<"Enter 0 to Exit: ";
                                        cin>>sch;
                                        if(sch==0)
                                            break;
                                        else
                                            cout<<"Invalid choice\n";
                                    }
                                    break;

                            case 4: for(;;)
                                    {
                                        d.display_delivery(name);
                                        cout<<"Enter 0 to exit: ";
                                        cin>>ch;
                                        if(ch==0)
                                            break;
                                        else
                                            cout<<"Invalid choice\n";
                                    }

                            case 5: break;

                            default:cout<<"\nInvalid choice\n";
                        }
                        if(ch==5)
                            break;
                    }

                    break;

            case 2: cout<<"\nEnter your Username: ";
                    cin>>name;
                    cout<<"Enter your Mobile Numeber: ";
                    cin>>phone;
                    cout<<"Enter Password: ";
                    cin>>password;
                    flag=e.check_employee(name,phone,password);
                    if(flag==0)
                    {
                        cout<<"\nInvalid credentials\nTry Again!\n";
                        break;
                    }
                    for(;;)
                    {
                        cout<<"\t\t\tWelcome "<<name;
                        cout<<"\n1: Check pending deliveries\t2: Finalize Delivery\n3: View successful deliveries\t4: Logout\n";
                        cout<<"Enter your choice: ";
                        cin>>ch;
                        if(ch==1)
                        {
                            for(;;)
                            {
                                string c_num;
                                d.get_delivery_id();
                                o.display_order(phone);
                                cout<<"Enter Customer Mobile Number to fetch Customer details: ";
                                cin>>c_num;
                                cout<<endl;
                                c.search_customer(c_num);
                                cout<<"\nEnter 0 to exit: ";
                                cin>>sch;
                                if(sch==0)
                                    break;
                                else
                                    cout<<"Invalid choice\n";
                            }
                        }
                        else if(ch==2)
                        {
                            for(;;)
                            {
                                string ord_id;
                                cout<<"Enter Order ID: ";
                                cin>>ord_id;
                                o.extract_order_details(ord_id);
                                file.open("delivery_id_count.txt",ios::in);
                                string buff;
                                int val;
                                getline(file,buff);
                                istringstream(buff) >> val;
                                file.close();
                                time (&rawtime);
                                timeinfo = localtime(&rawtime);
                                strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
                                string dtime(buffer);
                                d.read_delivery(buff,o.order_id,o.customer_order_name,o.employee_order_name,o.order_price,o.order_details,dtime,o.store_order_name);
                                d.delivery_pack();
                                d.write_to_delivery_file();
                                file.open("delivery_id_count.txt");
                                val++;
                                file << val;
                                file.close();
                                break;
                            }
                        }
                        else if(ch==3)
                        {
                            for(;;)
                            {
                                d.display_delivery(name);
                                cout<<"Enter 0 to exit: ";
                                cin>>ch;
                                if(ch==0)
                                    break;
                                else
                                    cout<<"Invalid choice\n";
                            }
                        }
                        else if(ch==4)
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Invalid Choice\n";
                        }
                    }
                    break;

            case 3: cout<<"Enter Username: ";
                    cin>>name;
                    cout<<"Enter Password: ";
                    cin>>password;
                    if(name!="ADMIN" || password!="54321")
                    {
                        cout<<"Invalid Credentials\nTry Again!\n";
                        break;
                    }
                    for(;;)
                    {
                        cout<<"\n*************************************************************************";
                        cout<<"\n|\t\t\t\tADMIN\t\t\t\t\t|";
                        cout<<"\n*************************************************************************";
                        cout<<"\n|1: Customer Details\t2: Employee Details\t3: Order Details\t|\n|4: Store Details\t5: Delivery Details\t6: Logout\t\t|\n";
                        cout<<"*************************************************************************\n";
                        cout<<"Enter your choice: ";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1: for(;;)
                                    {
                                        c.display_customer();
                                        cout<<"Enter 0 to exit: ";
                                        cin>>sch;
                                        if(sch==0)
                                            break;
                                        else
                                            cout<<"Invalid choice\n";
                                    }
                                    break;

                            case 2: for(;;)
                                    {
                                        e.display_employee();
                                        cout<<"Enter 0 to exit: ";
                                        cin>>sch;
                                        if(sch==0)
                                            break;
                                        else
                                            cout<<"Invalid choice\n";
                                    }
                                    break;

                            case 3: for(;;)
                                    {
                                        string ord_id,emp_ph,emp_name;
                                        o.pending_orders(name);
                                        cout<<"Enter 1 to assign employee to deliver orders else 0 to Exit: ";
                                        cin>>sch;
                                        if(sch==1)
                                        {
                                            cout<<"\nEnter Order ID: ";
                                            cin>>ord_id;
                                            cout<<"Enter Employee Name: ";
                                            cin>>emp_name;
                                            cout<<"Enter Employee Mobile Number: ";
                                            cin>>emp_ph;
                                            o.update_orders(ord_id,emp_name,emp_ph);
                                        }
                                        else if(sch==0)
                                            break;
                                        else
                                            cout<<"Invalid Choice\n";
                                    }
                                    break;

                            case 4: for(;;)
                                    {
                                        s.display_store();
                                        cout<<"\n1: Add new store\t\t2: Add items to store\n3: Update Stores\t\t4: Update Items\n5: Remove Stores\t\t6: Remove Items\n7: Display Items\t\t8: Exit\n";
                                        cout<<"Enter your choice: ";
                                        cin>>sch;
                                        switch(sch)
                                        {
                                            case 1: s.read_store();
                                                    s.store_pack();
                                                    s.write_to_store_file();
                                                    break;

                                            case 2: cout<<"Enter Store ID to add items: ";
                                                    cin>>temp;
                                                    if(s.search_store(temp)==1)
                                                    {
                                                        i.read_item(temp);
                                                        i.item_pack();
                                                        i.write_to_item_file();
                                                    }
                                                    else
                                                    {
                                                        cout<<"Store does not exist in the list\n";
                                                    }
                                                    break;

                                            case 3: cout<<"Enter Store ID: ";
                                                    cin>>temp;
                                                    s.update_store(temp);
                                                    break;

                                            case 4: cout<<"Enter store id to display available items: ";
                                                    cin>>temp;
                                                    if(s.search_store(temp)==1)
                                                    {
                                                        string key;
                                                        i.display_item(temp);
                                                        cout<<"Enter item name to update: ";
                                                        cin>>key;
                                                        i.update_item(key,temp);
                                                    }
                                                    else
                                                    {
                                                        cout<<"Store does not exist in the list\n";
                                                    }
                                                    break;

                                            case 5: cout<<"Enter Store ID: ";
                                                    cin>>temp;
                                                    s.delete_store(temp);
                                                    break;

                                            case 6: cout<<"Enter store id to display available items: ";
                                                    cin>>temp;
                                                    if(s.search_store(temp)==1)
                                                    {
                                                        string key;
                                                        i.display_item(temp);
                                                        cout<<"Enter item name to delete: ";
                                                        cin>>key;
                                                        i.delete_item(key,temp);
                                                    }
                                                    else
                                                    {
                                                        cout<<"Store does not exist in the list\n";
                                                    }
                                                    break;

                                            case 7: cout<<"Enter store id to display available items: ";
                                                    cin>>temp;
                                                    if(s.search_store(temp)==1)
                                                    {
                                                        i.display_item(temp);
                                                        for(;;)
                                                        {
                                                            cout<<"Enter 0 to Exit: ";
                                                            cin>>ch;
                                                            if(ch==0)
                                                                break;
                                                            else
                                                                cout<<"Invalid choice\n";
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cout<<"Store does not exist in the list\n";
                                                    }
                                                    break;

                                            case 8: break;

                                            default: cout<<"Invalid Choice\n";
                                        }
                                        if(sch==8)
                                            break;
                                    }
                                    break;

                            case 6: for(;;)
                                    {
                                        d.display_delivery(name);
                                        cout<<"Enter 0 to exit: ";
                                        cin>>ch;
                                        if(ch==1)
                                            break;
                                        else
                                            cout<<"Invalid choice\n";
                                    }

                            case 7: break;

                            default:cout<<"Invalid choice\n";
                        }
                        if(ch==7)
                            break;
                    }
                    break;


            case 4: c.read_customer_data();
                    c.customer_pack();
                    c.write_to_customer_file();
                    break;

            case 5: e.read_employee_data();
                    e.employee_pack();
                    e.write_to_employee_file();
                    break;

            case 6: return 0;

            default:cout<<"Invalid choice\n";
        }
    }
    return 0;
}
