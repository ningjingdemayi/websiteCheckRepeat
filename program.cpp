//**************************************************************************** 
//*  ��    �ƣ� checkRepeat.
//*  ��    ���� ����ĳ��ַ�Ƿ���ڵĿ���̨����
//*  ������ƣ� ��    ��
//*  ��    �ڣ� 2013/7/16 14:48:39
//******************************************************************************* 


#include <iostream>
#include <bitset>
#include "md5.h"

using namespace std;

//��ʼ��λͼ����12λ����ʾ������������20λ����ʾλͼ�ڲ�λ����
bitset< 1 << 20 >  * map = new bitset< 1 << 20 >[ 1 << 12 ]();

int charToInt(char input)
{
	if(input >= 97)
		return input - 87;
	if(input >= 64)
		return input - 55;

	return input - 48;
}

int main()
{
	string inputStr ;
	string md5_32;

	while(1)
	{
		MD5 md5;
		cout << endl << "��������ַ��";
		cin >> inputStr;
		md5.update(inputStr);
		md5_32 = md5.toString();
		unsigned int indexInt[8] = {};
		cout << "���ܺ���ַ���Ϊ��" << endl;
		
		//���ַ�ת��Ϊʮ���ƣ�����indeInt����
		for(int i = 0 ; i < 8 ; i++)
		{
			cout << md5_32[i] << "(";
			indexInt[i] = charToInt(md5_32[i]);
			cout << indexInt[i] << ")  ";
		}

		//��indexInt�� 0 ��1 ��2 ����map����������
		indexInt[0] <<= 8;
		indexInt[1] <<= 4;
		unsigned int arrayIndex = indexInt[0] + indexInt[1] + indexInt[2];

		//��indexInt�� 3 �� 4 �� 5 �� 6 ��7 ����map��λͼ�ڲ�����
		indexInt[3] <<= 16;
		indexInt[4] <<= 12;
		indexInt[5] <<= 8;
		indexInt[6] <<= 4;
		unsigned int bitIndex = indexInt[3] + indexInt[4] + indexInt[5] + indexInt[6] + indexInt[7];
		
		if(map[arrayIndex].at(bitIndex))
			cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!�Ѿ����ڣ�����Ϊ��map[" << arrayIndex << "]" << ".at(" << bitIndex << ")" << endl; 
		else
			map[arrayIndex].set(bitIndex);

		cout << endl << endl;
	}

}
