/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int hexToDecimal(string str) {
	int sum = 0;
	char c;
	for (int i = str.length() - 1; i >= 0; --i) {
		c = str.at(i);

		if (c >= '0' && c <= '9')
			sum += (c - '0') * pow(16, str.length() - i - 1);
		else
			sum += (c - 'A' + 10) * pow(16, str.length() - i - 1);
	}
	return sum;
}

int findPassword() {
	priority_queue<string> desc_queue;
	vector<string> vec;
	int n, k, key_length;
	string str;
	string str1, str2;
	cin >> n >> k;
	cin >> str;

	// string will be: A B C D 1 2 3 4 -> A B C D 1 2 3 4 A B C D 1 2 3 4 (length = 8 -> 16)
	str += str;
	key_length = n / 4;

	for (int i = 0; i < str.length() / 2; ++i) {
		desc_queue.push(str.substr(i, key_length));
	}

	for (int i = 1; i < str.length() / 2; ++i) {
		str1 = desc_queue.top();
		desc_queue.pop();
		str2 = desc_queue.top();

		if (str1 != str2)
			vec.push_back(str1);
	}
	if (vec.at(vec.size() - 1) != desc_queue.top())
		vec.push_back(desc_queue.top());

	return hexToDecimal(vec.at(k-1));
}

int main(int argc, char** argv)
{
	int test_case;
		int T;
		/*
		   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
		   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
		   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
		   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
		   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
		   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
		   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
		*/
		//freopen("input.txt", "r", stdin);
		cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		cout << "#" << test_case << " " << findPassword() << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}