//**************************************************************************** 
//*  名    称： checkRepeat.
//*  描    述： 测试某网址是否存在的控制台程序
//*  程序设计： 刘    杰
//*  日    期： 2013/7/16 14:48:39
//******************************************************************************* 


#include <iostream>
#include <bitset>
#include "md5.h"

using namespace std;

//初始化位图，用12位来表示数组索引，用20位来表示位图内部位索引
bitset<1024 * 1024>  * map = new bitset<1024 * 1024>[512 * 8]();

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
		cout << endl << "请输入网址：";
		cin >> inputStr;
		md5.update(inputStr);
		md5_32 = md5.toString();
		unsigned int indexInt[8] = {};
		cout << "加密后的字符串为：" << endl;
		
		//将字符转换为十进制，存入indeInt数组
		for(int i = 0 ; i < 8 ; i++)
		{
			cout << md5_32[i] << "(";
			indexInt[i] = charToInt(md5_32[i]);
			cout << indexInt[i] << ")  ";
		}

		//用indexInt的 0 ，1 ，2 构建map的数组索引
		indexInt[0] <<= 8;
		indexInt[1] <<= 4;
		unsigned int arrayIndex = indexInt[0] + indexInt[1] + indexInt[2];

		//用indexInt的 3 ， 4 ， 5 ， 6 ，7 构建map的位图内部索引
		indexInt[3] <<= 16;
		indexInt[4] <<= 12;
		indexInt[5] <<= 8;
		indexInt[6] <<= 4;
		unsigned int bitIndex = indexInt[3] + indexInt[4] + indexInt[5] + indexInt[6] + indexInt[7];
		
		if(map[arrayIndex].at(bitIndex))
			cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!已经存在，索引为：map[" << arrayIndex << "]" << ".at(" << bitIndex << ")" << endl; 
		else
			map[arrayIndex].set(bitIndex);

		cout << endl << endl;
	}

}