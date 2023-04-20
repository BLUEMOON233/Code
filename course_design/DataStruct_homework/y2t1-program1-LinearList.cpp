#include <iostream>
const int MaxSize = 1e3 + 7;

struct indexArray {
    int length = 0;
    int data[MaxSize];
};

std::ostream& operator<<(std::ostream& out, const indexArray IA) {
    for (int i = 0; i < IA.length; i++)
        out << IA.data[i] << " \n"[i == IA.length - 1];
    return out;
}

class Student {
   public:
    Student(){};
    Student(std::string Tname, int Tid, std::string Tgender)
        : name(Tname), id(Tid), gender(Tgender) {}
    void setName(std::string tName) {
        this->name = tName;
    }
    void setID(int tID) {
        this->id = tID;
    }
    void setGender(std::string tGender) {
        this->gender = tGender;
    }
    std::string getName() {
        return this->name;
    }
    int getID() {
        return this->id;
    }
    std::string getGender() {
        return this->gender;
    }
    friend std::ostream& operator<<(std::ostream& out, Student stu);
    friend std::istream& operator>>(std::istream& out, Student& stu);
    bool operator==(Student& stu) {
        if (this->gender != stu.getGender() || this->name != stu.getName() || this->id != stu.getID())
            return false;
        else
            return true;
    }

   private:
    std::string name = "null";
    int id = -1;
    std::string gender = "null";
};

std::ostream& operator<<(std::ostream& out, Student stu) {
    out << stu.getName() << ' ' << stu.getID() << ' ' << stu.getGender() << ' ';
    return out;
}

std::istream& operator>>(std::istream& out, Student& stu) {
    std::string name, gender;
    int id;
    std::cout << "������������ID���Ա�\n";
    std::cin >> name >> id >> gender;
    stu.setName(name), stu.setGender(gender), stu.setID(id);
    return out;
}

template <typename Element>
class LinearList {
   public:
    LinearList();
    LinearList(Element t[], int len);
    ~LinearList();
    bool InitList();
    bool DestoryList();
    int Length();
    Element Get(int i);
    indexArray Locate(Element x);
    void Insert(int i, Element x);
    Element Delete(int i);
    bool Empty();
    void Add(Element x);

   private:
    Element data[MaxSize];
    int length = -1;  // -1 ��ʾ˳������� 0 ��ʾ˳���Ϊ�� ��������ʾ˳���Ԫ�ظ���
};

template <typename Element>
LinearList<Element>::LinearList() {
    this->InitList();
}

template <typename Element>
LinearList<Element>::LinearList(Element t[], int len) {
    this->InitList();
    length = len;
    for (int i = 0; i < len; i++)
        data[i] = t[i];
}

template <typename Element>
LinearList<Element>::~LinearList() {
    this->DestoryList();
}

template <typename Element>
bool LinearList<Element>::InitList() {
    this->length = 0;
    return true;
}

template <typename Element>
bool LinearList<Element>::DestoryList() {
    this->length = -1;
    return true;
}

template <typename Element>
int LinearList<Element>::Length() {
    if (length == -1)
        throw "Null";
    return this->length;
}

template <typename Element>
Element LinearList<Element>::Get(int i) {
    if (length == -1)
        throw "Null";
    return data[i];
}

template <typename Element>
indexArray LinearList<Element>::Locate(Element x) {
    indexArray IA;
    if (length == -1)
        throw "Null";
    for (int i = 0; i < this->length; i++)
        if (x == this->data[i])
            IA.data[IA.length++] = i + 1;
    return IA;
}

template <typename Element>
void LinearList<Element>::Insert(int i, Element x) {
    if (length == -1)
        throw "Null";
    if (this->length == MaxSize)
        throw "full";
    else if (i < 1 || i > this->length)
        throw "WrongPosition";
    for (int j = this->length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    this->length++;
}

template <typename Element>
Element LinearList<Element>::Delete(int i) {
    if (length == -1)
        throw "Null";
    if (this->length == MaxSize)
        throw "full";
    else if (i < 1 || i > this->length)
        throw "WrongPosition";
    length--;
    Element tmp = data[i - 1];
    for (int j = i - 1; j < this->length; j++)
        data[j] = data[j + 1];
    return tmp;
}

template <typename Element>
bool LinearList<Element>::Empty() {
    if (length == -1)
        throw "Null";
    if (length == 0)
        return true;
    else
        return false;
}

template <typename Element>
void LinearList<Element>::Add(Element x) {
    if (length == -1)
        throw "Null";
    if (this->length == MaxSize)
        throw "full";
    data[length++] = x;
}

int main() {
    Student initStuList[] = {{"����Խ", 1, "��װֱ����"}, {"����׿", 2, "Ů"}, {"���ݺ�", 3, "��"}, {"֧¶��", 4, "Ů"}};
    LinearList<Student> ll(initStuList, 4);
    std::cout << initStuList[1];
    int op;
    bool isEnd = true;
    while (isEnd) {
        std::cout << "*****************************************\n"
                  << "����0 �˳����Ա�\n����1 ��ѯ���Ա��Ƿ�Ϊ��\n����2 �����ݲ������Ա�\n����3 �����Ա���ɾ������\n����4 �����Ա�β��������\n����5 ��ѯ���Ա���\n����6 ��ȡ������Ӧ����\n����7 ��λ��������\n";
        std::cout << "��ǰ���Ա�������Ϊ��\n";
        for (int i = 0; i < ll.Length(); i++) {
            std::cout << i << ":   " << ll.Get(i) << "\n";
        }
        std::cin >> op;
        std::cout << "*****************************************\n";
        Student nowX;
        int idx;
        indexArray IA;
        switch (op) {
            case 0:
                std::cout << "�˳����Ա�\n";
                isEnd = false;
                break;
            case 1:
                if (ll.Empty())
                    std::cout << "���Ա�Ϊ�գ�\n";
                else
                    std::cout << "���Ա�Ϊ�գ�\n";
                break;
            case 2:
                std::cout << "���������ݼ�����Ҫ���������λ�ã�\n";
                std::cin >> nowX >> idx;
                ll.Insert(idx, nowX);
                break;
            case 3:
                std::cout << "��������Ҫɾ�����ݵ�����λ�ã�\n";
                std::cin >> idx;
                ll.Delete(idx);
                break;
            case 4:
                std::cout << "���������ݣ�\n";
                std::cin >> nowX;
                ll.Add(nowX);
                break;
            case 5:
                std::cout << "���Ա���Ϊ" << ll.Length() << '\n';
                break;
            case 6:
                std::cout << "����������λ�ã�\n";
                std::cin >> idx;
                std::cout << "����Ϊ��" << ll.Get(idx) << '\n';
                break;
            case 7:
                std::cout << "���������ݣ�\n";
                std::cin >> nowX;
                IA = ll.Locate(nowX);
                if (IA.length) {
                    std::cout << "����λ������Ϊ��\n";
                    std::cout << IA;
                } else {
                    std::cout << "δ�ҵ�������\n";
                }
                break;
            default:
                std::cout << "�����������������룡\n";
                break;
        }
    }
}