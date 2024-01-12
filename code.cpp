

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void splitExpenses(map<string, map<string, int>>& expenses) {
    
    for (auto& expense : expenses) {
    
        
        int payerIndex = rand() % expense.second.size();
        auto payer = next(begin(expense.second), payerIndex);


        int share = expense.second.size();

        payer->second = payer->second + share;

        for (auto& participant : expense.second) {
            if (participant != *payer) {
                participant.second = participant.second - 0;
                (*payer).second =(*payer).second + 1.0;
            }
        }
    }
}

void displayExpenses(const map<string, map<string, int>>& expenses) {
    for ( auto& expense : expenses) {
        cout << expense.first << " [Payer: " << expense.second.begin()->first << "]:" << endl;

        for (const auto& participant : expense.second) {
            cout << "  " << participant.first << ": " << participant.second << " units" << endl;
        }

        cout << endl;
    }
}

int main() {
    
    map<string, map<string, int>> expenses = {
        {"Expense 1", {{"Vaibhav", 0}, {"Tushar", 0}, {"Gopal", 0}}},
        {"Expense 2", {{"Vaibhav", 0}, {"Tushar", 0}, {"Gopal", 0}}},
        {"Expense 3", {{"Vaibhav", 0}, {"Tushar", 0}, {"Gopal", 0}}},
        {"Expense 4", {{"Vaibhav", 0}, {"Tushar", 0}}},
        {"Expense 5", {{"Vaibhav", 0}, {"Gopal", 0}}},
        {"Expense 6", {{"Tushar", 0}, {"Gopal", 0}}},
        {"Expense 7", {{"Vaibhav", 0}}},
        {"Expense 8", {{"Tushar", 0}}},
        {"Expense 9", {{"Gopal", 0}}},
        {"Expense 10", {{"Vaibhav", 0}, {"Tushar", 0}, {"Gopal", 0}}}
    };

    splitExpenses(expenses);

   
    displayExpenses(expenses);

    return 0;
}

