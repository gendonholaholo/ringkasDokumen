#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <cstdio>

using namespace std;
namespace fs = std::filesystem;

bool isCommandAvailable(const string &command) {
    string fullCommand = "powershell -Command \"Get-Command " + command + " -ErrorAction SilentlyContinue\"";
    return system(fullCommand.c_str()) == 0;
}

void installSoftware() {
    if (!isCommandAvailable("pdftotext")) {
        cout << "Poppler not found. Installing via Scoop..." << endl;
        system("powershell -Command \"scoop install poppler\"");
    } else {
        cout << "Poppler is already installed." << endl;
    }

    if (!isCommandAvailable("ollama")) {
        cout << "Ollama not found. Installing..." << endl;
        system("powershell -Command \"Invoke-WebRequest -Uri https://ollama.com/install.sh -OutFile install.sh; ./install.sh\"");
    } else {
        cout << "Ollama is already installed." << endl;
    }

    cout << "Pulling the llama3.2 model..." << endl;
    system("powershell -Command \"ollama pull llama3.2\"");
}

void extractTextFromPDF(const string &pdfPath, const string &outputDir) {
    string baseName = fs::path(pdfPath).stem().string();
    string txtPath = outputDir + "/" + baseName + ".txt";

    string command = "pdftotext -layout " + pdfPath + " " + txtPath;
    system(command.c_str());

    cout << "Extracted text saved to: " << txtPath << endl;
}

void analyzeTextWithOllama(const string &txtPath) {
    string command = "powershell -Command \"Get-Content -Path '" + txtPath + "' | ollama run llama3.2 --verbose 'tolong diringkas dengan detail'\"";
    system(command.c_str());
    cout << "Analyzed text from: " << txtPath << endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <path_to_pdf>" << endl;
        return 1;
    }

    installSoftware();

    string pdfPath = argv[1];
    string outputDir = "Txt";

    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }

    extractTextFromPDF(pdfPath, outputDir);
    string txtPath = outputDir + "/" + fs::path(pdfPath).stem().string() + ".txt";
    analyzeTextWithOllama(txtPath);

    return 0;
}

