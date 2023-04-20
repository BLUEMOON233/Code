#include <bits/stdc++.h>

//[class]:Student
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
    out << stu.getName() << ' ' << '\t' << stu.getID() << ' ' << '\t' << stu.getGender() << ' ';
    return out;
}

std::istream& operator>>(std::istream& out, Student& stu) {
    std::string name, gender;
    int id;
    std::cout << "������ѧ��������ID���Ա�\n";
    std::cin >> name >> id >> gender;
    stu.setName(name), stu.setGender(gender), stu.setID(id);
    return out;
}

//[struct]:Node
template <class Element>
struct Node {
    Element data;
    Node<Element>* p;
};

//[class]:LinkList
template <class Element>
class LinkList {
   public:
    LinkList();
    LinkList(Element initElement[], int n);
    ~LinkList();
    bool Empty();
    void printList();
    void Insert(int i, Element x);
    Element Delete(int i);
    int getLength();
    Element findbyIndex(int i);
    LinkList<Element> findbyName(std::string tName);
    LinkList<Element> findbyID(int tID);
    LinkList<Element> findbyGender(std::string tGender);

   private:
    Node<Element>* head = nullptr;
    int size = -1;
};

template <class Element>
LinkList<Element>::LinkList() {
    this->head = new Node<Element>;
    this->head->p = nullptr;
    this->size = 0;
}

template <class Element>
LinkList<Element>::LinkList(Element initElement[], int n) {
    this->size = n;
    this->head = new Node<Element>;
    if (n == 0)
        this->head->p = nullptr;
    else {
        Node<Element>* now = this->head;
        for (int i = 1; i <= n; i++) {
            Node<Element>* tmp = new Node<Element>;
            tmp->data = initElement[i - 1];
            now->p = tmp;
            now = tmp;
        }
        now->p = nullptr;
    }
}

template <class Element>
LinkList<Element>::~LinkList() {
    Node<Element>* now = this->head;
    while (now != nullptr) {
        Node<Element>* p = now;
        now = now->p;
        delete p;
    }
}

template <class Element>
bool LinkList<Element>::Empty() {
    if (this->head->p == nullptr)
        return true;
    else
        return false;
}

template <class Element>
void LinkList<Element>::printList() {
    Node<Element>* now = this->head->p;
    if (this->getLength() == 0)
        std::cout << "����ѧ�����ݣ�";
    else {
        std::cout << "����" << ' ' << '\t' << "ID" << ' ' << '\t' << "�Ա�" << '\n';
        while (now != nullptr) {
            std::cout << now->data << '\n';
            now = now->p;
        }
    }
}

template <class Element>
void LinkList<Element>::Insert(int i, Element x) {
    Node<Element>*now = this->head, *tmp = nullptr;
    int cnt = 0;
    while (now != nullptr && cnt < i - 1) {
        now = now->p;
        cnt++;
    }
    if (now == nullptr)
        throw "Wrong Position of Insert";
    else {
        tmp = new Node<Element>;
        tmp->data = x, tmp->p = now->p, now->p = tmp;
        this->size++;
    }
}

template <class Element>
Element LinkList<Element>::Delete(int i) {
    Node<Element>*now = this->head, *p = nullptr;
    int cnt = 0;
    while (now != nullptr && cnt < i - 1) {
        now = now->p;
        cnt++;
    }
    if (now == nullptr)
        throw "Wrong Position of Delete";
    else {
        p = now->p;
        Element tmp = p->data;
        now->p = p->p;
        delete p;
        this->size--;
        return tmp;
    }
}

template <class Element>
int LinkList<Element>::getLength() {
    return this->size;
}

template <class Element>
Element LinkList<Element>::findbyIndex(int i) {
    Node<Element>* now = this->head;
    int cnt = 0;
    while (now != nullptr && cnt < i) {
        now = now->p;
        cnt++;
    }
    if (now == nullptr)
        throw "Wrong Position of FindbyIndex";
    else {
        return now->data;
    }
}

template <class Element>
LinkList<Element> LinkList<Element>::findbyName(std::string tName) {
    LinkList<Element> tmpll;
    Node<Element>* now = this->head;
    while (now != nullptr) {
        if (now->data.getName() == tName)
            tmpll.Insert(tmpll.getLength(), now->data);
        now = now->p;
    }
    return tmpll;
}

template <class Element>
LinkList<Element> LinkList<Element>::findbyID(int tID) {
    LinkList<Element> tmpll;
    Node<Element>* now = this->head;
    while (now != nullptr) {
        if (now->data.getID() == tID)
            tmpll.Insert(tmpll.getLength(), now->data);
        now = now->p;
    }
    return tmpll;
}

template <class Element>
LinkList<Element> LinkList<Element>::findbyGender(std::string tGender) {
    LinkList<Element> tmpll;
    Node<Element>* now = this->head;
    while (now != nullptr) {
        if (now->data.getGender() == tGender)
            tmpll.Insert(tmpll.getLength(), now->data);
        now = now->p;
    }
    return tmpll;
}

int main() {
    Student initStuList[] = {{"����Խ", 1, "��װֱ����"}, {"������", 2, "Ů"}, {"��Ө�", 3, "Ů"}, {"�����", 4, "��"}};
    LinkList<Student> ll(initStuList, 4);
    int op;
    bool isEnd = true;
    while (isEnd) {
        std::cout << "*****************************************\n"
                  << "����0 �˳�������\n����1 ��ѯ�������Ƿ�Ϊ��\n����2 �����ݲ��뵥����\n����3 �ӵ�������ɾ������\n����4 ��ѯ��������\n����5 ͨ��������������\n����6 ͨ��������������\n����7 ͨ��ѧ��ID��ѯ����\n����8 ͨ��ѧ���Ա��ѯ����\n";
        std::cout << "��ǰ������������Ϊ��\n";
        ll.printList();
        std::cin >> op;
        std::cout << "*****************************************\n";
        Student nowX;
        int idx;
        std::string str;
        switch (op) {
            case 0:
                std::cout << "�˳�������\n";
                isEnd = false;
                break;
            case 1:
                if (ll.Empty())
                    std::cout << "������Ϊ�գ�\n";
                else
                    std::cout << "������Ϊ�գ�\n";
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
                std::cout << "��������Ϊ" << ll.getLength() << '\n';
                break;
            case 5:
                std::cout << "������������\n";
                std::cin >> str;
                ll.findbyName(str).printList();
                break;
            case 6:
                std::cout << "����������λ�ã�\n";
                std::cin >> idx;
                std::cout << "����Ϊ��" << ll.findbyIndex(idx) << '\n';
                break;
            case 7:
                std::cout << "������ID��\n";
                std::cin >> idx;
                ll.findbyID(idx).printList();
                break;
            case 8:
                std::cout << "�������Ա�\n";
                std::cin >> str;
                ll.findbyGender(str).printList();
                break;
            default:
                std::cout << "�����������������룡\n";
                break;
        }
    }
}