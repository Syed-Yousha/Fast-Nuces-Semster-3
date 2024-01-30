#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct WebPage {
    string url;
    WebPage* next;
};

void addWebPage(WebPage*& head, string url) {
    WebPage* newPage = new WebPage;
    newPage->url = url;
    newPage->next = head;
    head = newPage;
}

bool navigateBack(WebPage*& head, stack<string>& pageStack) {
    if (pageStack.empty()) {
        cout << "No previous page to navigate to." << endl;
        return false;
    }

    string currentUrl = head->url;
    string previousUrl = pageStack.top();

    pageStack.push(currentUrl);

    WebPage* temp = head;
    head = head->next;
    delete temp;

    cout << "Navigating back to: " << previousUrl << endl;
    return true;
}

int main() {
    WebPage* browsingHistory = NULL;
    stack<string> pageStack;

    addWebPage(browsingHistory, "Instagram");
    addWebPage(browsingHistory, "LinkedIn");
    addWebPage(browsingHistory, "Twitter");
    addWebPage(browsingHistory, "Facebook");
    addWebPage(browsingHistory, "Google");

    while (true) {
        cout << "Current Page: " << browsingHistory->url << endl;
        cout << "Choose an option:\n";
        cout << "1. Go back to the previous page\n";
        cout << "2. Add a new page\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            navigateBack(browsingHistory, pageStack);
        } else if (choice == 2) {
            string newUrl;
            cout << "Enter the URL of the new page: ";
            cin >> newUrl;
            addWebPage(browsingHistory, newUrl);
            pageStack.push(browsingHistory->url);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    while (browsingHistory != NULL) {
        WebPage* temp = browsingHistory;
        browsingHistory = browsingHistory->next;
        delete temp;
    }

    return 0;
}

