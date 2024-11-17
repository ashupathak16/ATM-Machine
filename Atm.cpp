#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class BankAccount {
public:
    string name;
    string userName;
    string password;
    string accountNo;
    float balance = 0;
    int transactions = 0;
    vector<string> transactionHistory;

    void registerAccount() {
        cout << "\nEnter Your Name - ";
        getline(cin >> ws, name);
        cout << "\nEnter Your Username - ";
        getline(cin, userName);
        cout << "\nEnter Your Password - ";
        getline(cin, password);
        cout << "\nEnter Your Account Number - ";
        getline(cin, accountNo);
        cout << "\nRegistration completed..kindly login" << endl;
    }

    bool login() {
        bool isLogin = false;
        string Username, Password;

        while (!isLogin) {
            cout << "\nEnter Your Username - ";
            getline(cin >> ws, Username);

            if (Username == userName) {
                while (!isLogin) {
                    cout << "\nEnter Your Password - ";
                    getline(cin, Password);
                    if (Password == password) {
                        cout << "\nLogin successful!!" << endl;
                        isLogin = true;
                    } else {
                        cout << "\nIncorrect Password" << endl;
                    }
                }
            } else {
                cout << "\nUsername not found" << endl;
            }
        }
        return isLogin;
    }

    void withdraw() {
        float withdrawAmount;
        cout << "Enter the withdrawal amount: ";
        cin >> withdrawAmount;
        if (balance >= withdrawAmount) {
            balance -= withdrawAmount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
            transactionHistory.push_back("Withdrawal of " + to_string(withdrawAmount));
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void deposit() {
        float depositAmount;
        cout << "Enter the deposit amount: ";
        cin >> depositAmount;
        balance += depositAmount;
        cout << "Deposit successful. New balance: " << balance << endl;
        transactionHistory.push_back("Deposit of " + to_string(depositAmount));
    }

    void transfer() {
        float transferAmount;
        cout << "Enter the transfer amount: ";
        cin >> transferAmount;
        if (balance >= transferAmount) {
            balance -= transferAmount;
            cout << "Transfer successful. Remaining balance: " << balance << endl;
            transactionHistory.push_back("Transfer of " + to_string(transferAmount));
        } else {
            cout << "Insufficient funds for transfer." << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    void transHistory() {
        cout << "Transaction History:" << endl;
        for (const auto& transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }
};

int main() {
    int choice;
    cout << "\n**** WELCOME TO IDBI ATM ****\n";
    cout << "1.Register \n2.Exit\n";
    cout << "Enter Your Choice - ";
    cin >> choice;

    if (choice == 1) {
        BankAccount b;
        b.registerAccount();

        while (true) {
            int ch;
            cout << "\n1.Login \n2.Exit\n";
            cout << "Enter Your Choice - ";
            cin >> ch;

            if (ch == 1) {
                if (b.login()) {
                    cout << "\n\n**********WELCOME BACK " << b.name << " **********\n";
                    bool isFinished = false;

                    while (!isFinished) {
                        int c;
                        cout << "\n1.Withdraw \n2.Deposit \n3.Transfer \n4.Check Balance \n5.Transaction History \n6.Exit\n";
                        cout << "Enter Your Choice - ";
                        cin >> c;

                        switch (c) {
                            case 1:
                                b.withdraw();
                                break;
                            case 2:
                                b.deposit();
                                break;
                            case 3:
                                b.transfer();
                                break;
                            case 4:
                                b.checkBalance();
                                break;
                            case 5:
                                b.transHistory();
                                break;
                            case 6:
                                isFinished = true;
                                break;
                            default:
                                cout << "Invalid option selected!" << endl;
                        }
                    }
                }
            } else {
                exit(0);
            }
        }
    } else {
        exit(0);
    }

    return 0;
}
