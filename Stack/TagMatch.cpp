#include <iostream>
#include <stack>
#include <string>

using namespace std;

int readTag(FILE* fp, string& tag)
{
	tag = "";
	int ret = 0;
	char ch;
	int idx = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '>') break;
		if (ch == '/' && ret == 0)
		{
			ret = 1;
			continue;
		}

		tag += ch;
	}
	return ret;
}

int main(int argc, char* argv[])
{
	// 파일 argument가 없으면 사용법을 보여주고 종료
	if (argc != 2)
	{
		cout << "usage : stack.exe filename" << endl;
		return 1;
	}

	// 스택 변수 선언
	stack<string> S;

	// 파일을 연다. 파일명은 argv[1]에 지정되어 있다.
	FILE* fp = fopen(argv[1], "rt");
	if (!fp)
	{
		// 파일 열기에 실패하면
		cout << "failt to open File:" << argv[1] << endl;
		return 1;
	}

	int closed;
	char ch;
	string tag;
	try
	{
		// 파일에서 글자 하나를 읽어 들인다. 파일 마지막(EOF)이면 루프를 종료
		while ((ch = fgetc(fp)) != EOF)
		{
			// Tag Signal이면
			if (ch == '<')
			{
				closed = readTag(fp, tag);

				if (closed)
				{
					string ts = S.top();
					if (ts != tag)
					{
						char msg[64];
						sprintf(msg, "Not Match Tag - [%s-%s]", ts.c_str(), tag.c_str());
						throw(exception(msg));
					}
					S.pop();
				}
				else
					S.push(tag);
			}
		}

		// 최종적으로 스택이 비어 있으면
		if (S.empty())
			cout << "Match!!!" << endl;
		// 최종적으로 스택에 데이터가 있으면
		else
			cout << "Mismatch!!!" << endl;
	}
	catch (const exception& e)
	{
		// 예외가 발생되었을 때
		cout << e.what() << endl;
	}

	// 파일 닫기
	fclose(fp);

	return 1;
}