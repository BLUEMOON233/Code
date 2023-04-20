#pragma once
#include<iostream>
//#include<QDebug>
using namespace std;

class StudentManager;
class Node;
class SSNode;
class SSNodeData;
class StudentList;
class StudentSegment;

//�÷ֵ�3 �Զ�����ķ�װ
//�÷ֵ�7 ���ļ��ṹ
//�÷ֵ�21 ͼ�λ�����

class CStudent {
public:
	CStudent() {}
	CStudent(int tNum, string tName = "NULL", bool tGender = false, double tMathGrade = 0.0, double tComGrade = 0.0, double tEngGrade = 0.0, double tPhyGrade = 0.0) //�÷ֵ�2 ��ȱʡ�βκ���1
		:Num(tNum), Name(tName), Gender(tGender), MathGrade(tMathGrade), ComGrade(tComGrade), EngGrade(tEngGrade), PhyGrade(tPhyGrade) {} //�÷ֵ�4 ���캯��1
	CStudent(CStudent& CS) :Num(CS.Num), Name(CS.Name), Gender(CS.Gender), MathGrade(CS.MathGrade), ComGrade(CS.ComGrade), EngGrade(CS.EngGrade), PhyGrade(CS.PhyGrade) {}
	//�÷ֵ�5 ���ƹ��캯��
	~CStudent() {
		//qDebug() << "CStudent destrcuting";
	} //�÷ֵ�4 ��������
	void getInfo(string& name, bool& gender, double& mathgrade, double& comgrade, double& enggrade, double& phygrade);
	void editInfo(string name, bool gender, double mathgrade, double comgrade, double enggrade, double phygrade);
	CStudent& operator++(); //�÷ֵ�13 ���������1
	static long long SumOfStudent; //�÷ֵ�8 ��ľ�̬��Ա
	static long long getSumOfStudent() { return SumOfStudent; }

	friend StudentManager; //�÷ֵ�9 ��Ԫ��
	friend Node;
	friend StudentList;
	friend SSNode;
	friend StudentSegment;
	friend ofstream& operator<<(ofstream& out, CStudent& CS); //�÷ֵ�13 ���������2


private:
	int Num = -1;
	string Name = "NULL";
	bool Gender = false;	//male = true, female = false;
	double MathGrade = 0.0;
	double ComGrade = 0.0;
	double EngGrade = 0.0;
	double PhyGrade = 0.0;
};

struct CStudentArray {
	int* posSt = nullptr;
	CStudent** st = nullptr;
	int cnt = 0;
};

class Node {
public:
	Node() :data(nullptr), next(nullptr) {}

	friend StudentList;
	friend StudentManager;
private:
	CStudent* data;
	Node* next;
};

class StudentList {
public:
	StudentList();
	void initStudentList(StudentManager sm);
	void addList(CStudent tdata);
	bool insertList(long long pos, CStudent tdata);
	bool deleteList(long long pos);
	void freeList();
	long long getListCount();

	friend StudentManager;
private:
	Node* head = nullptr;
	long long cnt = 0;
};

class StudentManager {
public:
	StudentManager() :st(nullptr), cnt(0) {} //�÷ֵ�4 ���캯��2
	void StudentList2Manager(StudentList sl);
	CStudent* queryStudent(long long num = 1); //�÷ֵ�2 ��ȱʡ�βκ���2
	CStudentArray queryStudentByName(string tName = "NULL");
	long long getCount();
	string getFilePath() const { return FilePath; } //�÷ֵ�10 �������ݱ���

	void Write(); //�÷ֵ�17 д�ļ�
	void Read(); //�÷ֵ�18 ���ļ�

	friend StudentList;
	friend StudentSegment;

private:
	CStudent* st = nullptr;
	long long cnt = 0;
	const string FilePath = "D:/res.txt";
};

class SSNodeDataBase { //�÷ֵ�15 ������
public:
	virtual string queryType() = 0;
};

class SSNodeData :public SSNodeDataBase {
public:
	double MathGradeSum = 0, ComGradeSum = 0, EngGradeSum = 0, PhyGradeSum = 0;
	double MathGradeMax = -1, ComGradeMax = -1, EngGradeMax = -1, PhyGradeMax = -1;
	double MathGradeMin = 200, ComGradeMin = 200, EngGradeMin = 200, PhyGradeMin = 200;
	SSNodeData() :SSNodeDataBase() {}
	string queryType();
	virtual void update(SSNodeData t); //�÷ֵ�14 �麯��
};

class Range {
public:
	Range(long long ll, long long rr) :l(ll), r(rr) {}
	bool check(long long SumCnt);

	friend SSNode;
	friend StudentSegment;
private:
	long long l;
	long long r;
};

class SSNode :public SSNodeData { //�÷ֵ�11 �̳�������
public:
	SSNode(long long tl, long long tr) :range(tl, tr), left(nullptr), right(nullptr), SSNodeData() {} //�÷ֵ�12 �����๹�캯������ɶԻ��๹�캯���ĵ���
	long long mid() { return (range.l + range.r) >> 1; }
	long long len() { return range.r - range.l + 1; }
	SSNodeData SSNode2SSNodeData();
	string queryType();
	virtual void update(SSNodeData t); //�÷ֵ�14 �麯��

	friend StudentSegment;
private:
	Range range; //�÷ֵ�6 ������
	SSNode* left, * right;
	//SSNodeData data;
};

class StudentSegment {
public:
	void build(StudentManager& sm, SSNode*& x, long long l, long long r);
	void build(StudentManager& sm, long long l, long long r);
	//�÷ֵ�1 ���Ա�������ء�
	//void modify(StudentManager& sm, SSNode*& x, long long l, long long r);
	SSNodeData query(SSNode* x, long long l, long long r);
	SSNode*& getRoot();

private:
	SSNode* root;
};
