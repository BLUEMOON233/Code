#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//���ú���
void PrintHelp();
int InsertRecord();
int QueryAllRecord();
int QueryRecord();
int DelRecord();
int ModifyRecord();
int QueryFailedRecord();
int BubbleSort();
int DeleteAll();

// ѧ����Ϣ�ṹ��
typedef struct _STRU_STU_SCORE_ {
    unsigned int nStuId;
    string cpName;
    string sex;
    double nScoreComputing;
    double nScoreMath;
    double nScoreEnglish;
    double nScoreAver;
} STRU_STU_SCORE;

//���������л����ڵ㡣
struct NODE {
    _STRU_STU_SCORE_ data;
    NODE* next;
};

//������
class List {
    NODE* head;

   public:
    List() { head = NULL; }
    void InsertList(_STRU_STU_SCORE_ bData);
    void DeleteList_Id(unsigned int aID);
    void OutputList();
    void FindList_Id(unsigned int aID);
    void FindList_Name(string name);
    void FindList_Sum();
    void ModifyRecord(_STRU_STU_SCORE_ e);
    void BubbleSort(int op);
    void Fileout();
    void DeleteAll();
    NODE* GetHead() { return head; }
};
List test;  //��������ʱ���в������������

//�����е�������������ȫ��ѧ������
void List::OutputList() {
    NODE* current = head;
    cout << endl;
    if (head == NULL) {
        cout << "��ѧ������ϵͳ������ѧ����¼\n";
        return;
    }
    cout << endl;
    cout << setw(10) << "ѧ��" << setw(15) << "����" << setw(8) << "�Ա�"
         << setw(10) << setprecision(1) << "����" << setw(10) << setprecision(1)
         << "�����" << setw(10) << setprecision(1) << "Ӣ��" << setw(10)
         << setprecision(1) << "ƽ����" << endl;
    cout << fixed;
    while (current != NULL) {
        cout << setw(10) << current->data.nStuId << setw(15)
             << current->data.cpName << setw(8) << current->data.sex << setw(10)
             << setprecision(1) << current->data.nScoreComputing << setw(10)
             << setprecision(1) << current->data.nScoreMath << setw(10)
             << setprecision(1) << current->data.nScoreEnglish << setw(10)
             << setprecision(1) << current->data.nScoreAver;
        current = current->next;
        cout << endl;
    }
    cout << endl;
}

//�����е������������������������ݡ�
void List::InsertList(_STRU_STU_SCORE_ bData) {
    NODE *p, *s;
    p = head;
    s = (NODE*)new (NODE);
    s->data = bData;
    if (p == NULL) {
        head = s;
        s->next = NULL;
    } else {
        while (p->next != NULL)
            p = p->next;
        p->next = s;
        s->next = NULL;
    }
}

//�����е�����������������ΪID��������
void List::FindList_Id(unsigned int aID) {
    NODE* current = head;
    bool flag = true;
    cout << endl;
    cout << setw(10) << "ѧ��" << setw(15) << "����" << setw(8) << "�Ա�"
         << setw(10) << setprecision(1) << "����" << setw(10) << setprecision(1)
         << "�����" << setw(10) << setprecision(1) << "Ӣ��" << setw(10)
         << setprecision(1) << "ƽ����" << endl;
    while (current != NULL) {
        if (current->data.nStuId == aID) {
            cout << fixed;
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag)
        cout << "δ��ѯ����ѧ��" << endl;
}

//�����е������������ú���Ϊ����������������
void List::FindList_Name(string name) {
    NODE* current = head;
    bool flag = true;
    cout << endl;
    cout << setw(10) << "ѧ��" << setw(15) << "����" << setw(8) << "�Ա�"
         << setw(10) << setprecision(1) << "����" << setw(10) << setprecision(1)
         << "�����" << setw(10) << setprecision(1) << "Ӣ��" << setw(10)
         << setprecision(1) << "ƽ����" << endl;
    while (current != NULL) {
        if (current->data.cpName == name) {
            cout << fixed;
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag)
        cout << "δ��ѯ����ѧ��" << endl;
}

//�����е�ɾ��������ʹ��ID��������ѧ����¼����ɾ����
void List::DeleteList_Id(unsigned aID) {
    NODE *p, *q;
    p = head;
    bool flag = false;
    if (p == NULL) {
        cout << endl << "ѧ���б�������ѧ����¼\n" << endl;
        return;
    }
    if (p->data.nStuId == aID) {
        head = p->next;
        flag = true;
        delete p;
    } else {
        while (p->data.nStuId != aID && p->next != NULL) {
            q = p;
            p = p->next;
        }
        if (p->data.nStuId == aID) {
            q->next = p->next;
            flag = true;
            delete p;
        }
    }
    if (flag)
        cout << endl << "ɾ����ϡ�" << endl << endl;
    else
        cout << endl << "δ�ҵ���ѧ����¼��" << endl << endl;
}

//�����е��޸ĺ�����ΪID������ѯ
void List::ModifyRecord(_STRU_STU_SCORE_ e) {
    NODE* current = head;
    bool flag = true;
    while (current != NULL) {
        if (current->data.nStuId == e.nStuId) {
            current->data = e;
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag)
        cout << "δ��ѯ����ѧ��" << endl;
}

//�����е�ͳ�ƺ���������ͳ�Ƹ���������ѧ������
void List::FindList_Sum() {
    int sum0 = 0, sum60 = 0, sum75, sum85 = 0;
    cout << endl;
    cout << endl;
    cout << setw(10) << "ѧ��" << setw(15) << "����" << setw(8) << "�Ա�"
         << setw(10) << setprecision(1) << "����" << setw(10) << setprecision(1)
         << "�����" << setw(10) << setprecision(1) << "Ӣ��" << setw(10)
         << setprecision(1) << "ƽ����" << endl;
    cout << fixed;
    cout << "\n������ֶε�ѧ��Ϊ��\n";
    NODE* current = head;
    bool flag = true;
    while (current != NULL) {
        if (current->data.nScoreAver >= 0 && current->data.nScoreAver < 60) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
        }
        current = current->next;
    }
    if (flag)
        cout << "��\n";
    cout << "����Ϊ:" << sum0 << endl << endl;
    flag = true;
    cout << "����ֶε�ѧ��Ϊ\n";
    current = head;
    while (current != NULL) {
        if (current->data.nScoreAver >= 60 && current->data.nScoreAver < 75) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
            sum60++;
        }
        current = current->next;
    }
    if (flag)
        cout << "��\n";
    cout << "����Ϊ:" << sum60 << endl << endl;
    flag = true;
    cout << "���÷ֶε�ѧ��Ϊ��\n";
    current = head;
    while (current != NULL) {
        if (current->data.nScoreAver >= 75 && current->data.nScoreAver < 85) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
            sum75++;
        }
        current = current->next;
    }
    if (flag)
        cout << "��\n";
    flag = true;
    cout << "����Ϊ:" << sum75 << endl << endl;
    cout << "����ֶε�ѧ��Ϊ��\n";
    current = head;
    while (current != NULL) {
        if (current->data.nScoreAver >= 85 && current->data.nScoreAver <= 100) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
            sum85++;
        }
        current = current->next;
    }
    if (flag)
        cout << "��\n";
    cout << "����Ϊ:" << sum85 << endl << endl;
}

//�����е����������ɶ��������������������
void List::BubbleSort(int op) {
    if (head == NULL)
        return;
    else {
        NODE* goal = head;
        while (goal->next != NULL)
            goal = goal->next;
        if (op == '1') {
            for (NODE* i = head; i != goal; i = i->next)
                for (NODE* j = i; j != NULL; j = j->next)
                    if (i->data.nScoreAver < j->data.nScoreAver)
                        swap(i->data, j->data);
        } else
            for (NODE* i = head; i != goal; i = i->next)
                for (NODE* j = i; j != NULL; j = j->next)
                    if (i->data.nScoreAver > j->data.nScoreAver)
                        swap(i->data, j->data);
    }
}

//�����еĴ洢�������������ļ��д洢���ݣ�������txt����ʽ�洢
void List::Fileout() {
    ofstream fout("source.txt", ios::binary);
    NODE* current = head;
    while (current != NULL) {
        fout << current->data.cpName << ' ';
        fout << current->data.nStuId << ' ';
        fout << current->data.sex << ' ';
        fout << current->data.nScoreComputing << ' ';
        fout << current->data.nScoreEnglish << ' ';
        fout << current->data.nScoreMath << ' ';
        fout << current->data.nScoreAver << ' ';
        current = current->next;
    }
    fout << "end";
    fout.close();
}

//�����е���պ����������������ѧ������
void List::DeleteAll() {
    while (head != NULL) {
        NODE* p;
        p = head;
        head = p->next;
        delete p;
    }
}

int main() {                                   // main������
    ifstream fcin("source.txt", ios::binary);  //��ʼ��ʼ��test�������
    while (1) {                                //��ʼ��test�������
        string op;
        fcin >> op;
        if (op == "end") {
            fcin.close();
            break;
        } else {
            _STRU_STU_SCORE_ tmp;
            tmp.cpName = op;
            fcin >> tmp.nStuId;
            fcin >> tmp.sex;
            fcin >> tmp.nScoreComputing;
            fcin >> tmp.nScoreEnglish;
            fcin >> tmp.nScoreMath;
            fcin >> tmp.nScoreAver;
            test.InsertList(tmp);
        }
    }

    system("color 30");  //ʵ����ɫЧ��
    char cSelection;
    PrintHelp();  //����˵����
    while (1) {
        printf("\n����������ѡ��i,d,m,g,a,f,h,c��q����");
        cSelection = getche();
        switch (cSelection) {  // switch���ʵ�ֹ���ѡ��
            case 'i':
            case 'I': {
                InsertRecord();
                break;
            }
            case 'd':
            case 'D': {
                DelRecord();
                break;
            }
            case 'm':
            case 'M': {
                ModifyRecord();
                break;
            }
            case 'g':
            case 'G': {
                QueryRecord();
                break;
            }
            case 'a':
            case 'A': {
                QueryAllRecord();
                break;
            }
            case 'f':
            case 'F': {
                QueryFailedRecord();
                break;
            }
            case 'c':
            case 'C': {
                DeleteAll();
                break;
            }
            case 'q':
            case 'Q': {
                //				DestroyList();;
                break;
            }
            case 'h':
            case 'H': {
                PrintHelp();
                break;
            }
            case 's':
            case 'S': {
                BubbleSort();
                break;
            }
            default: {
                break;
            }
        }
        if (cSelection == 'q' || cSelection == 'Q') {
            cout << "\n\n�Ƿ񱣴浽�ļ�����Y/N��" << endl;
            int op;
            while (1) {
                op = getche();
                if (op == 'y' || op == 'Y') {
                    test.Fileout();
                    break;
                } else if (op == 'n' || op == 'N')
                    break;
                else
                    cout << "�����������������롣" << endl;
            }
            break;
        }
    }
    return 0;
}

void PrintHelp() {
    cout << "\n//"
            "**************************************************************"
            "****"
            "********//\n";
    cout << "//*************  ѧ    ��   ��   ��   ��   ��   ϵ   ͳ    "
            "*****************//\n";
    cout << "//"
            "**************************************************************"
            "****"
            "********//\n";

    cout << "��1������һ����¼��������i��I��\n��2��ɾ��һ����¼��������d��D"
            "��\n";
    cout << "��3���޸ļ�¼��������m��M��\n��4����ѯ��¼��������g��G��\n";
    cout
        << "��5����ʾ���м�¼��������a��A��\n��6����ʾ��������ͳ�����ݣ�������f"
           "��F��"
           "\n";
    cout << "��7����ʾ�����ļ���������h��H��\n��8��ɾ�����м�¼��������c��C"
            "��\n";
    cout << "��9����������,������s��S��\n"
         << "��10���˳���������q��Q��\n";

    cout << flush;

    return;
}

int InsertRecord() {
    STRU_STU_SCORE e;
    int rslt;

    cout << "\n�������¼�ĸ�����Ϣ��\n";

    cout << "\nѧ�ţ�";
    cin >> e.nStuId;

    cout << "\n������";
    cin >> e.cpName;

    cout << "\n�Ա�";
    cin >> e.sex;

    while (1) {
        cout << "\n������ɼ���";
        cin >> e.nScoreComputing;
        if (e.nScoreComputing >= 0 && e.nScoreComputing <= 100)
            break;
        cout << "����ĳɼ�Ӧ����0-100��֮�䣬�����¼�������\n\n";
    }
    while (1) {
        cout << "\n�����ɼ���";
        cin >> e.nScoreMath;
        if (e.nScoreMath >= 0 && e.nScoreMath <= 100)
            break;
        cout << "����ĳɼ�Ӧ����0-100��֮�䣬�����¼�������\n\n";
    }
    while (1) {
        cout << "\nӢ��ɼ���";
        cin >> e.nScoreEnglish;
        if (e.nScoreEnglish >= 0 && e.nScoreEnglish <= 100)
            break;
        cout << "����ĳɼ�Ӧ����0-100��֮�䣬�����¼�������\n\n";
    }

    e.nScoreAver = (e.nScoreComputing + e.nScoreEnglish + e.nScoreMath) / 3;

    // ��������
    // ���������Insert��������

    test.InsertList(e);

    rslt = 0; /* ������ */
    if (rslt == 0) {
        cout << endl << "�����¼�ɹ���";
    } else {
        cout << endl << "\n�����¼ʧ�ܣ�";
    }
    cout << flush;
    return 0;
}

int QueryAllRecord() {
    //��ӡ����ѧ���ĳɼ���Ϣ��
    cout << "\n��ӡ����ѧ���ĳɼ���Ϣ��\n";
    // ��ʾ����ѧ����Ϣ
    test.OutputList();
    cout << endl;
    cout << flush;
    return 0;
}

int QueryRecord() {
    while (true) {
        char jdg;
        cout << "\n��������Ҫ��ѯѧ�Ż�������";
        cout << "\nѧ��������1������������2:";
        jdg = getche();
        if (jdg == '1') {
            unsigned int e;

            cout << "\n������Ҫ��ѯ��¼��ѧ�ţ�";
            cin >> e;
            cout << endl;
            cout << endl;
            test.FindList_Id(e);
            cout << endl;
            cout << endl;
            cout << flush;
            return 0;
        } else if (jdg == '2') {
            string e;
            cout << "\n������Ҫ��ѯ��¼��������";
            cin >> e;
            cout << endl;
            cout << endl;
            test.FindList_Name(e);
            cout << endl;
            cout << endl;
            cout << flush;
            return 0;
        } else {
            cout << "\n������������������";
            continue;
        }
    }
}

int DelRecord() {
    unsigned int stuid;
    cout << "\n������Ҫɾ����¼��ѧ�ţ�";
    cin >> stuid;
    test.DeleteList_Id(stuid);
    // ɾ����¼����
    return 0;
}

int ModifyRecord() {
    STRU_STU_SCORE e;

    cout << "\n�������޸ļ�¼��ѧ�ţ�";
    cin >> e.nStuId;

    cout << "\n��������º�ļ�¼���ݣ�\n";
    cout << "\n������";
    cin >> e.cpName;

    cout << "\n�Ա�";
    cin >> e.sex;

    while (1) {
        cout << "\n������ɼ���";
        cin >> e.nScoreComputing;
        if (e.nScoreComputing >= 0 && e.nScoreComputing <= 100)
            break;
        cout << "����ĳɼ�Ӧ����0-100��֮�䣬�����¼�������\n\n";
    }
    while (1) {
        cout << "\n�����ɼ���";
        cin >> e.nScoreMath;
        if (e.nScoreMath >= 0 && e.nScoreMath <= 100)
            break;
        cout << "����ĳɼ�Ӧ����0-100��֮�䣬�����¼�������\n\n";
    }
    while (1) {
        cout << "\nӢ��ɼ���";
        cin >> e.nScoreEnglish;
        if (e.nScoreEnglish >= 0 && e.nScoreEnglish <= 100)
            break;
        cout << "����ĳɼ�Ӧ����0-100��֮�䣬�����¼�������\n\n";
    }

    e.nScoreAver = (e.nScoreComputing + e.nScoreEnglish + e.nScoreMath) / 3;

    // �޸ļ�¼����

    test.ModifyRecord(e);
    cout << endl << "�޸���ϡ�" << endl << endl;
    return 0;
}

int QueryFailedRecord() {
    test.FindList_Sum();
    return 0;
}

int BubbleSort() {
    cout << "\n��������˳����������������";
    cout << "\n˳������������1����������������2:";
    int op;
    op = getche();
    test.BubbleSort(op);
    test.OutputList();
    cout << endl << "������ϡ�" << endl << endl;
    return 0;
}

int DeleteAll() {
    cout << endl << "��ȷ���Ƿ��������ѧ����¼ (Y/N)" << endl;
    int op;
    while (1) {
        op = getche();
        if (op == 'y' || op == 'Y') {
            test.DeleteAll();
            cout << endl << "ɾ����ϡ�" << endl << endl;
            break;
        } else if (op == 'n' || op == 'N') {
            cout << endl << "�ѳ���ɾ������" << endl;
            break;
        } else
            cout << endl << "�����������������롣" << endl;
    }
    return 0;
}