#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Message {
    string content;
    int processingTime;
};

struct CompareMessages {
    bool operator()(const Message& msg1, const Message& msg2) {
        return msg1.processingTime > msg2.processingTime;
    }
};

int main() {
    priority_queue<Message, vector<Message>, CompareMessages> messageQueue;

    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Send a message\n";
        cout << "2. Process the next message\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            Message message;
            cout << "Enter the message content: ";
            cin.ignore();
            getline(cin, message.content);
            cout << "Enter the processing time (priority): ";
            cin >> message.processingTime;
            messageQueue.push(message);
        } else if (choice == 2) {
            if (!messageQueue.empty()) {
                Message nextMessage = messageQueue.top();
                messageQueue.pop();
                cout << "Processing message with content: " << nextMessage.content << endl;
            } else {
                cout << "No messages to process." << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    return 0;
}

