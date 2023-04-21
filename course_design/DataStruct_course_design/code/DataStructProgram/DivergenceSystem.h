#pragma once
/*********************************************************
 * ��Ȩ��������ѧ
 * ��д�ߣ�����Խ������׿��Ф��ܰ�����裬����
 *
 * ��дʱ�䣺2022/12/04
 * ����������DivergenceSystemͷ�ļ���
 *			 ���������Զ����������
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <QDebug>
#include <map>

class D_S_PretreatSystem;
class D_S_TreatedSystem;
void string_split(const std::string& str, const std::string& split, std::vector<int>& rs);
void string_split(const std::string& str, const std::string& split, std::vector<std::string>& rs);

struct D_S_Student {
	/*
	ԭʼѧ�����ݵĴ洢�ڵ�
	*/
	int ID = 0;  // ѧ��ѧ��
	int choice = 0;  //ѧ��־Ը��ֵΪ1�����һ־Ը
	double GPA = -1;  //���㣬����ά����4λ��Ч����
	int rank = 0;  //ѧ��������Ϣ��ֵΪ1����������һ
	friend std::istream& operator>>(std::istream& in, D_S_Student& DSS);
	friend std::ostream& operator<<(std::ostream& out, const D_S_Student& DSS);
};

struct D_S_DeLinkedListNode {
	D_S_Student data;
	D_S_DeLinkedListNode* pre = nullptr;
	D_S_DeLinkedListNode* nex = nullptr;
};

class D_S_MajorList {
	/*
	���ڽ���ԭʼ���ݵ�������
	��Ӧ��һ��רҵ�ķ���ǰ��ʼ�ļ�
	*/
public:
	D_S_MajorList();
	~D_S_MajorList();
	void deleteMajorList(); //�ͷ������ڴ�ռ�
	void printList(); //�����ԡ�������̨���������
	void initList(std::string filePath); //���ļ�����ԭʼ���ݣ����洢������
	void addNode(D_S_Student DSS); //���ӽڵ�
	void setListName(std::string name); //���ø�רҵ������
	int getNodeNum(); //��ȡ��רҵ����

	friend D_S_PretreatSystem;
	friend D_S_TreatedSystem;

private:
	D_S_DeLinkedListNode* head = nullptr;
	D_S_DeLinkedListNode* tail = nullptr;
	std::string majorName = "NULL";
	int nodeNum = 0;
	std::pair<int, int> maxNum = { -1, -1 }; //first->רҵ�༶����second->�༶����
};


class D_S_PretreatSystem {
	/*
	���ڽ�����δ����רҵ��������������һ�𲢽��з�������
	*/
public:
	void initSystem(); //���ڳ�ʼ��Ԥ����ϵͳ
	int addMajorList(std::string filePath, std::string majorName, std::pair<int, int> pairNum); //��Ԥ����ϵͳ�������µ�רҵ������
	D_S_Student getNodeByPos(int pos1, int pos2); //ͨ���±��ȡ����ѧ����Ϣ
	int getListNum(); //�õ�רҵ����
	int getListNodeNum(int pos); //ͨ���±��ȡ��Ӧרҵ��ѧ������
	int getSumNum(); //�õ�ѧ������

	friend D_S_TreatedSystem;

private:
	std::vector<D_S_MajorList> MajorList;
	std::map<int, bool> mp; //���ڱ��ѧ��ѧ��
	int listNum = 0;
};

struct D_S_StudentPro {
	/*
	�������ѧ�����ݽڵ�
	*/
	int ID = -1; //ѧ��ѧ��
	double GPA = 0; //ѧ������
	int rank = 0; //ѧ������
	std::vector<std::pair<int, int>> choice; //����ǰ�����ѧ���ı�����������������һ��Ԫ�أ�first->רҵ��second->�༶
	friend std::istream& operator>>(std::istream& in, D_S_StudentPro& DSSP);
	friend std::ostream& operator<<(std::ostream& out, const D_S_StudentPro& DSSP);
};

class D_S_TreatedSystem {
	/*
	�������ѧ������ϵͳ��
	*/
public:
	std::vector<double> initSystem(D_S_PretreatSystem& DSP); //����������Ԥ����ϵͳ�����ڳ�ʼ���������ѧ������ϵͳ��
	void initSystem(QString filePath); //���ڴ��ļ�����������ѧ������ϵͳ��
	void saveSystem(QString filePath); //��Ӳ���е����������ѧ������ϵͳ��
	void deleteSystem(); //�ͷ��ڴ�ռ�
	std::vector<D_S_StudentPro> getArray(); //���ѧ����Ϣ
	D_S_StudentPro getArrayNode(int Pos); //ͨ���±��õ���ѧ����Ϣ
	D_S_StudentPro getArrayNodeByID(int tmpID); //ͨ��ѧ����ѧ�Ż�õ�����ѧ����Ϣ
	std::string getMajorName(int Pos); //ͨ���±��ȡרҵ����
	int getMajorPos(std::string str); //ͨ��רҵ���ƻ�ȡ��Ӧ�±�
	std::vector<int> getClassNum(); //��õ�ǰ�༶����
	std::pair<int, int> getMajorClassPos(int majorPos); //��õ�ǰרҵ��Ӧ�༶���±�
	int getStuNum(); //��õ�ǰȫ��ѧ������'
	bool modifyArrayNodeByID(int tmpID, int majorPos, int classPos); //�޸�ѧ����Ϣ
	void sortSystem(); //ϵͳ����

	int getClassLeftRange(int x); //�߶����еĻ��ַ�Χ����
	int getMajorLeftRange(int x); //�߶����еĻ��ַ�Χ����
	bool isInit = false; //���ڱ�ǵ�ǰ��������޷������ѧ������ϵͳ��

private:
	std::vector<D_S_StudentPro> DSSParray;
	std::vector<std::string> majorName; //רҵ����
	std::vector<std::pair<int, int>> maxNum; // first->�༶������second->�༶���������
	std::vector<int> nowMajorNum; //��ǰרҵ����
	std::vector<int> nowClassNum; //��ǰ�༶����
};

struct D_S_S_TreeNode {
	/*
	����ά���߶��������ݽڵ�
	*/
	double GPASum = 0, GPAMax = -1, GPAMin = 10;
	int l = 0, r = 0;
	D_S_S_TreeNode* left = nullptr, * right = nullptr;

	friend std::ostream& operator<<(std::ostream& out, const D_S_S_TreeNode& DSSTN);
};

class D_S_SegmentTree {
	/*
	�߶�����װ��
	����ά��ѧ�����ݵ���������ֵ
	*/
public:
	void build(D_S_TreatedSystem& DSTS, D_S_S_TreeNode*& x, int l, int r); //������������ʼ���߶���
	void build(D_S_TreatedSystem& DSTS, int l, int r); //������������ʼ���߶���
	D_S_S_TreeNode query(D_S_S_TreeNode* x, int l, int r); //��ѯ����
	D_S_S_TreeNode query(int l, int r); //��ѯ����

	double getS(int l, int r, double x); //ά������
	void deleteTree(); //�ͷ��ڴ�ռ�
private:
	D_S_S_TreeNode* root = nullptr;
};