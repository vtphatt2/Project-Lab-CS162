#include "viewProfile.h"
UserProfile* readUserProfile(const string& filePath) {
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cout << "Error opening the file!" << endl;
        return nullptr;
    }

    UserProfile* userProfile = new UserProfile;

    getline(inFile, userProfile->ID);
    getline(inFile, userProfile->fullName);
    getline(inFile, userProfile->sex);
    getline(inFile, userProfile->dayOfBirth);
    getline(inFile, userProfile->socialID);

    inFile.close();
    return userProfile;
}

// Function to display user profile
void displayUserProfile(UserProfile* userProfile) {
    if (userProfile == nullptr) {
        cout << "Error: User profile not found!" << endl;
        return;
    }

    cout << "ID: " << userProfile->ID << endl;
    cout << "Full Name: " << userProfile->fullName << endl;
    cout << "Sex: " << userProfile->sex << endl;
    cout << "Day of Birth: " << userProfile->dayOfBirth << endl;
    cout << "Phone Number: " << userProfile->socialID << endl;
}

// Function to get the user profile based on the ID
void viewProfile(const string& IDuser) {
    string basePath = "DataSet/";

    string infoStudentPath = basePath + "infoStudent/" + IDuser + "/profile";
    UserProfile* studentProfile = readUserProfile(infoStudentPath);
    if (studentProfile != nullptr) {
        displayUserProfile(studentProfile);
        delete studentProfile;
        return;
    }

    string infoStaffPath = basePath + "infoStaff/" + IDuser + "/profile";
    UserProfile* staffProfile = readUserProfile(infoStaffPath);
    if (staffProfile != nullptr) {
        displayUserProfile(staffProfile);
        delete staffProfile;
        return;
    }

    cout << "Error: User profile not found!" << endl;
}
