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
	//sentence�������̵����Լ���һ���ʵĳ��ȣ�������Ŀ
	string::size_type maxLen, minLen, wordLen, count=0;
	//��������̵��ʵ�vector����
	vector<string> longestWords, shortestWords;
	//���ʵ���ʼ������λ��
	string::size_type startPos=0, endPos=0;

	//ÿ��ѭ������sentence�е�һ������
	while( (startPos = sentence.find_first_of( separators, endPos ))!= string::npos )
	{   //�ҵ���һ�����ʵ���ʼλ��
		++count;
		//�ҵ���һ���ʵĽ���λ��
		endPos = sentence.find_first_of(separators,startPos);

		if( endPos == string::npos )//�Ҳ�����һ���ָ���λ�ã����õ��������һ������
            wordLen = sentence.size() - startPos;
        else                        //�ҵ���һ�����ַָ�����λ��
            wordLen = endPos - startPos;

        word.assign( sentence.begin()+startPos,
                    sentence.begin()+startPos+wordLen );//��ȡ����

        //�����´β��ҵ���ʼλ��
        startPos = sentence.find_first_not_of( separators, endPos );

        if ( count == 1 ) { //�ҵ��ĵ�һ������
            maxLen = minLen = wordLen;
            longestWords.push_back( word );
            shortestWords.push_back( word );
        }
        else {
            if( wordLen>maxLen ){ //��ǰ���ʱ�Ŀǰ������ʸ���
				maxLen = wordLen;
				longestWords.clear(); //��մ������ʵ�����
				longestWords.push_back( word );
			}
			else if( wordLen == maxLen ) //��ǰ������Ŀǰ������ʵȳ�
				longestWords.push_back( word );

			if( wordLen<minLen ){ //��ǰ���ʱ�Ŀǰ������ʸ���
				minLen=wordLen;
				shortestWords.clear(); //��մ����̵��ʵ�����
				shortestWords.push_back( word );
			}
			else if( wordLen == minLen ) //��ǰ������Ŀǰ����̵��ʵȳ�
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
