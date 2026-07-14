#include <iostream>
#include <string>
#include <unistd.h>
#define MAX 1000
using namespace std;

struct person
{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct books
{
    person per[MAX];
    int size;
};

void add(books *temp)
{ // 添加联系人

    if (temp->size == MAX)
    {
        cout << "联系人已满" << endl;
        return;
    }
    else
    {
        cout << "姓名:" << endl;
        cin >> temp->per[temp->size].name;
        cout << "姓别(男 - 1 女 - 2):" << endl;
        int sex;
        cin >> sex;
        while (true)
        {
            if (sex == 1 || sex == 2)
            {
                temp->per[temp->size].sex = sex;
                break;
            }
            else
            {
                cout << "请输入正确的内容" << endl;
                cin >> sex;
            }
        }
        cout << "年龄:" << endl;
        cin >> temp->per[temp->size].age;
        cout << "手机号码:" << endl;
        cin >> temp->per[temp->size].phone;
        cout << "地址:" << endl;
        cin >> temp->per[temp->size].address;
        temp->size++;
        cout << "添加成功" << endl;
        cout << "按任意键继续..." << endl;
        cin.ignore(); // 忽略缓冲区中的换行符
        cin.get();
        system("clear");
    }
}

void show(books *temp)
{ // 显示所有联系人
    if (temp->size == 0)
    {
        cout << "联系人为空" << endl;
    }
    else
    {
        string sex;
        for (int i = 0; i < temp->size; i++)
        {
            cout << "序号 " << i + 1 << "\t";
            cout << "姓名：" << temp->per[i].name << "\t";

            if (temp->per[i].sex == 1)
                sex = "男";
            else
                sex = "女";
            cout << "性别：" << sex << "\t";
            cout << "年龄：" << temp->per[i].age << "\t";
            cout << "手机号码：" << temp->per[i].phone << "\t";
            cout << "地址：" << temp->per[i].address << endl;
        }
    }
    cout << "按任意键继续..." << endl;
    cin.ignore(); // 忽略缓冲区中的换行符
    cin.get();
    system("clear");
}

void ShowMenu()
{ // 菜单
    cout << "--------------" << endl;
    cout << "|1.添加联系人|" << endl;
    cout << "|2.显示联系人|" << endl;
    cout << "|3.删除联系人|" << endl;
    cout << "|4.查找联系人|" << endl;
    cout << "|5.修改联系人|" << endl;
    cout << "|6.清空联系人|" << endl;
    cout << "|0.退出通讯录|" << endl;
    cout << "--------------" << endl;
}

int search(books *temp, string tname)
{
    int num = 0;
    int in[MAX];
    int a;
    for (int i = 0; i < temp->size; i++)
    {
        if (temp->per[i].name == tname)
        {
            in[num] = i;
            num++;
        }
    }
    if (num == 1)
    {
        return in[0];
    }
    else if (num > 1)
    {
        cout << "以下有多个联系人请选择：" << endl;
        string sex;
        for (int i = 0; i < num; i++)
        {
            cout << "序号 " << i + 1 << "\t";
            cout << "姓名：" << temp->per[in[i]].name << "\t";
            if (temp->per[in[i]].sex == 1)
                sex = "男";
            else
                sex = "女";
            cout << "性别：" << sex << "\t";
            cout << "年龄：" << temp->per[in[i]].age << "\t";
            cout << "手机号码：" << temp->per[in[i]].phone << "\t";
            cout << "地址：" << temp->per[in[i]].address << endl;
        }
        cin >> a;
        return in[a - 1];
    }
    else
        return -1;
}

void del(books *temp)
{
    string tname;
    cout << "输入需要删除联系人的姓名：";
    cin >> tname;
    int temp1 = search(temp, tname);
    if (temp1 == -1)
        cout << "没有此联系人" << endl;
    else
    {
        for (int i = temp1; i < temp->size - 1; i++)
        {
            temp->per[i].name = temp->per[i + 1].name;
            temp->per[i].sex = temp->per[i + 1].sex;
            temp->per[i].age = temp->per[i + 1].age;
            temp->per[i].phone = temp->per[i + 1].phone;
            temp->per[i].address = temp->per[i + 1].address;
        }
        cout << "删除成功" << endl;
        temp->size--;
    }
    cout << "按任意键继续..." << endl;
    cin.ignore(); // 忽略缓冲区中的换行符
    cin.get();
    system("clear");
}

void find(books *temp)
{
    string tname;
    string sex;
    cout << "输入需要查找联系人的姓名：" << endl;
    cin >> tname;
    int num = 0;
    int in[MAX];
    for (int i = 0; i < temp->size; i++)
    {
        if (temp->per[i].name == tname)
        {
            in[num] = i;
            num++;
        }
    }
    if (num == 0)
    {
        cout << "没有此联系人" << endl;
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            cout << "序号 " << i + 1 << "\t";
            cout << "姓名：" << temp->per[in[i]].name << "\t";
            if (temp->per[in[i]].sex == 1)
            {
                sex = "男";
            }
            else
            {
                sex = "女";
            }
            cout << "性别：" << sex << "\t";
            cout << "年龄：" << temp->per[in[i]].age << "\t";
            cout << "手机号码：" << temp->per[in[i]].phone << "\t";
            cout << "地址：" << temp->per[in[i]].address << endl;
        }
    }
    cout << "按任意键继续..." << endl;
    cin.ignore(); // 忽略缓冲区中的换行符
    cin.get();
    system("clear");
}

void revise(books *temp)
{
    string tname;
    int temp1, rev;
    string sex;
    cout << "输入需要修改联系人的姓名：" << endl;
    cin >> tname;
    temp1 = search(temp, tname);
    if (temp1 == -1)
        cout << "没有此联系人" << endl;
    else
    {
        cout << "姓名：" << temp->per[temp1].name << "\t";
        if (temp->per[temp1].sex == 1)
            sex = "男";
        else
            sex = "女";
        cout << "性别：" << sex << "\t";
        cout << "年龄：" << temp->per[temp1].age << "\t";
        cout << "手机号码：" << temp->per[temp1].phone << "\t";
        cout << "地址：" << temp->per[temp1].address << endl;
        cout << "1.姓名\n2.性别\n3.年龄\n4.手机号码\n5.地址" << endl;
        cout << "请输入需要修改的内容" << endl;
        cin >> rev;
        switch (rev)
        {
        case 1:
            cout << "请输入修改后的姓名" << endl;
            cin >> temp->per[temp1].name;
            cout << "修改成功" << endl;
            break;
        case 2:
            int sex;
            cout << "请输入修改后的性别(男 - 1 女 - 2)" << endl;
            cin >> sex;
            while (true)
            {
                if (sex == 1 || sex == 2)
                {
                    // temp->per[temp->size].sex = sex;
                    temp->per[temp1].sex = sex;
                    break;
                }
                else
                {
                    cout << "请输入正确的内容" << endl;
                    cin >> sex;
                }
            }
            // sex = temp->per[temp1].sex;
            cout << "修改成功" << endl;
            break;
        case 3:
            cout << "请输入修改后的年龄" << endl;
            cin >> temp->per[temp1].age;
            cout << "修改成功" << endl;
            break;
        case 4:
            cout << "请输入修改后的手机号码" << endl;
            cin >> temp->per[temp1].phone;
            cout << "修改成功" << endl;
            break;
        case 5:
            cout << "请输入修改后的地址" << endl;
            cin >> temp->per[temp1].address;
            cout << "修改成功" << endl;
            break;
        }
    }
    cout << "按任意键继续..." << endl;
    cin.ignore(); // 忽略缓冲区中的换行符
    cin.get();
    system("clear");
}

void alldel(books *temp)
{
    string judge;
    cout << "是否要删除全部通讯录？(y/n)" << endl;
    cin >> judge;
    while (true)
    {
        if (judge == "y")
        {
            temp->size = 0;
            cout << "已清空!" << endl;
            break;
        }
        else if (judge == "n")
        {
            cout << "已取消操作" << endl;
            break;
        }
        else
            cout << "请输入正确的指令" << endl;
    }
    cout << "按任意键继续..." << endl;
    cin.ignore(); // 忽略缓冲区中的换行符
    cin.get();
    system("clear");
}

int main()
{
    books abs;
    abs.size = 0;
    string name;
    int temp;
    while (true)
    {
        ShowMenu();
        cin >> temp;
        switch (temp)
        {
        case 1:
            add(&abs);
            break;
        case 2:
            show(&abs);
            break;
        case 3:
            del(&abs);
            break;
        case 4:
            find(&abs);
            break;
        case 5:
            revise(&abs);
            break;
        case 6:
            alldel(&abs);
            break;
        case 0:
            cout << "欢迎再次使用" << endl;
            cout << "按任意键继续..." << endl;
            cin.ignore(); // 忽略缓冲区中的换行符
            cin.get();
            return 0;
        default:
            cout << "请输入正确的指令" << endl;
            cout << "按任意键继续..." << endl;
            cin.ignore(); // 忽略缓冲区中的换行符
            cin.get();
            system("clear");
        }
    }
}
