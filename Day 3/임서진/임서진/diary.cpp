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
    // ������
    Diary(const string& password) { this->password = password; }

    // �ϱ� �ۼ�
    void Write(const string& content) { contents.push_back(content); }

    // �ϱ� ����
    void Remove(int index) { contents.erase(contents.begin() + index); }

    // �ϱ� �˻�
    vector<string> Search(const string& word) {
        vector<string> results;
        for (const string& content : contents) {
            if (content.find(word) != string::npos) {
                results.push_back(content);
            }
        }
        return results;
    }

    // ��й�ȣ Ȯ��
    bool CheckPassword(const string& input) { return password == input; }

    // ��й�ȣ ����
    void ChangePassword(const string& new_password) { password = new_password; }
};

int main() {
    // ��й�ȣ ����
    string password = "my_password";
    Diary diary(password);

    // �α���
    while (true) {
        string input;
        cout << "��й�ȣ�� �Է��ϼ���: ";
        cin >> input;
        cin.ignore(); // ���� ���ڸ� �����ݴϴ�.

        if (diary.CheckPassword(input)) {
            cout << "�α��� ����!" << endl;
            break;
        }
        else {
            cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    // �޴� ���
    while (true) {
        int choice;
        cout << "1. �ϱ� �ۼ�" << endl;
        cout << "2. �ϱ� �˻�" << endl;
        cout << "3. ��й�ȣ ����" << endl;
        cout << "4. ����" << endl;
        cout << "����: ";
        cin >> choice;
        cin.ignore(); // ���� ���ڸ� �����ݴϴ�.

        switch (choice) {
        case 1:
            // �ϱ� �ۼ�
        {string content;
        cout << "�ϱ� ������ �Է��ϼ���: ";
        getline(cin, content);
        diary.Write(content);
        break; }
        case 2:
            // �ϱ� �˻�
        {string word;
        cout << "�˻��� �ܾ �Է��ϼ���: ";
        cin >> word;
        vector<string> results = diary.Search(word);
        for (const string& result : results) {
            cout << result << endl;
        }
        break; }
        case 3:
        {// ��й�ȣ ����
        string new_password;
        cout << "���ο� ��й�ȣ�� �Է��ϼ���: ";
        cin >> new_password;
        diary.ChangePassword(new_password);
        break;
        }
        case 4:
            // ����
            cout << "�����մϴ�." << endl;
            return 0;
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���." << endl;
        }
    }

    return 0;
}
