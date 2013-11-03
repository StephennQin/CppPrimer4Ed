#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";
	string sentence = line1+' '+line2+' '+line3;
	string separators(" \t:,\v\r\n\f");//�����ָ������ַ�
	string word;
	vector<string> longestWords, shortestWords;//��������̵��ʵ�vector����
	string::size_type maxLen, minLen, wordLen, count=0;//sentence�������̵����Լ���һ���ʵĳ��ȣ�������Ŀ
	string::size_type startPos = 0, endPos = 0;//���ʵ���ʼ������λ��

	endPos = sentence.find_first_of(separators,endPos);//���Ȼ�ȡ��һ������
	if(endPos == string::npos)//�Ҳ�����һ���ָ���λ�ã����ַ���ֻ��һ������
        wordLen = sentence.size() - startPos;
    else
        wordLen = endPos-startPos;

    word.assign( sentence.begin() + startPos, sentence.begin() + startPos + wordLen );//��ȡ����
    startPos = sentence.find_first_not_of(separators,endPos);//�����´β��ҵ���ʼλ��
    maxLen = minLen = wordLen;//��ȡ���ǵ�һ�����ʣ����̶�����
    longestWords.push_back( word );
    shortestWords.push_back( word );
    ++count;

	//ÿ��ѭ������sentence�е�һ������
	while( (startPos=sentence.find_first_of( separators,endPos )) != string::npos )//�ҵ���һ������ʼλ��
	{
		++startPos;
		endPos = sentence.find_first_of( separators,startPos );//�ҵ���һ���ʵĽ���λ��

		if( (endPos-startPos) == 0 )//�ж��Ƿ�������ȡ�������ָ����ַ�

			;
		else
		{

			++count;

			if( endPos == string::npos )//�Ҳ�����һ���ָ���λ�ã����õ��������һ������
				wordLen = sentence.size() - startPos;
			else
				wordLen = endPos-startPos;

			word.assign( sentence.begin()+startPos,sentence.begin()+startPos+wordLen );//��ȡ����

			startPos = sentence.find_first_not_of( separators,endPos );//�����´β��ҵ���ʼλ��

			if( wordLen > maxLen ){//��ǰ���ʱ�Ŀǰ������ʸ���
				maxLen = wordLen;
				longestWords.clear();//��մ������ʵ�����
				longestWords.push_back( word );
			}
			else if( wordLen == maxLen )//��ǰ������Ŀǰ������ʵȳ�
				longestWords.push_back( word );

			if( wordLen<minLen ){//��ǰ���ʱ�Ŀǰ������ʸ���
				minLen = wordLen;
				shortestWords.clear();//��մ����̵��ʵ�����
				shortestWords.push_back( word );
			}
			else if( wordLen == minLen )//��ǰ������Ŀǰ����̵��ʵȳ�
				shortestWords.push_back( word );
		}
	}

	//���������Ŀ
	cout << "word amount:" << count << endl;
	vector<string>::iterator iter;

	//��������
	cout << "longest word(s):" << endl;
	iter = longestWords.begin();
	while( iter != longestWords.end() )
		cout << *iter++ << endl;

	//�����̵���
	cout << "shortest word(s):" << endl;
	iter = shortestWords.begin();
	while( iter != shortestWords.end() )
		cout << *iter++ << endl;

	return 0;
}
