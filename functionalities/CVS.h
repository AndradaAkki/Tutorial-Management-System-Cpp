#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tutorial.h"
#include "FileWriter.h"
#include <Windows.h>
#include <shellapi.h>


class CSVFileWriter : public FileWriter {
private:
    std::string filename;
public:
    CSVFileWriter(const std::string& file) : filename(file) {}
    void write(const std::vector<Tutorial>& tutorials) const override {
        std::ofstream out(filename);
        out << "Title,Presenter,Duration,Likes,Link\n";

        for (const auto& t : tutorials) {
            out << t.get_title_c() << ","
                << t.get_presenter_c() << ","
                << t.get_duration_c() << ","  // assuming to_string() returns MM:SS
                << t.get_likes_c() << ","
                << t.get_link_const() << "\n";
        }
    }
	void open() const override{
		wstring wideLink(filename.begin(), filename.end());
        ShellExecute(
        NULL,        // No parent window
            L"open",      // Operation to perform
            L"notepad.exe", // Program to open with
            wideLink.c_str(),    // File to open
            NULL,        // Default directory
            SW_SHOW      // Show window normally
        );
       
	}
};