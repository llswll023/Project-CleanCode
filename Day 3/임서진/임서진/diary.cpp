//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class diary {
//	char content[100][100] = {0,};
//
//	int write(string words) {
//		
//		for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				if (content[i][j] == 0) {
//					content[i][j] = words;
//					return i;
//					break;
//				}
//			}
//		}
//
//
//	}
//	
//	void remove(int index) {
//		content[index][0] = {0,};
//	}
//
//	string search(string word) {
//
//		for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				if (content[i][j] == word) {
//					
//					return content[i][j];
//					break;
//				}
//			}
//		}
//
//};
//
//	int main(void) {
//	}

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

class Diary {
private:
    vector<string> contents;
    string password;

public:
    // 생성자
    Diary(const string& password) { this->password = password; }

    // 일기 작성
    void Write(const string& content) { contents.push_back(content); }

    // 일기 삭제
    void Remove(int index) { contents.erase(contents.begin() + index); }

    // 일기 검색
    vector<string> Search(const string& word) {
        vector<string> results;
        for (const string& content : contents) {
            if (content.find(word) != string::npos) {
                results.push_back(content);
            }
        }
        return results;
    }

    // 비밀번호 확인
    bool CheckPassword(const string& input) { return password == input; }

    // 비밀번호 변경
    void ChangePassword(const string& new_password) { password = new_password; }
};

int main() {
    // 비밀번호 설정
    string password = "my_password";
    Diary diary(password);

    // 로그인
    while (true) {
        string input;
        cout << "비밀번호를 입력하세요: ";
        cin >> input;
        cin.ignore(); // 개행 문자를 지워줍니다.

        if (diary.CheckPassword(input)) {
            cout << "로그인 성공!" << endl;
            break;
        }
        else {
            cout << "비밀번호가 일치하지 않습니다. 다시 시도하세요." << endl;
        }
    }

    // 메뉴 출력
    while (true) {
        int choice;
        cout << "1. 일기 작성" << endl;
        cout << "2. 일기 검색" << endl;
        cout << "3. 비밀번호 변경" << endl;
        cout << "4. 종료" << endl;
        cout << "선택: ";
        cin >> choice;
        cin.ignore(); // 개행 문자를 지워줍니다.

        switch (choice) {
        case 1:
            // 일기 작성
        {string content;
        cout << "일기 내용을 입력하세요: ";
        getline(cin, content);
        diary.Write(content);
        break; }
        case 2:
            // 일기 검색
        {string word;
        cout << "검색할 단어를 입력하세요: ";
        cin >> word;
        vector<string> results = diary.Search(word);
        for (const string& result : results) {
            cout << result << endl;
        }
        break; }
        case 3:
        {// 비밀번호 변경
        string new_password;
        cout << "새로운 비밀번호를 입력하세요: ";
        cin >> new_password;
        diary.ChangePassword(new_password);
        break;
        }
        case 4:
            // 종료
            cout << "종료합니다." << endl;
            return 0;
        default:
            cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
        }
    }

    return 0;
}
