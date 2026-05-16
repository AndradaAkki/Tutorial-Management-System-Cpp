#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tutorial.h"
#include "FileWriter.h"



class HTMLFileWriter : public FileWriter {
private:
    std::string filename;
public:
    HTMLFileWriter(const std::string& file) : filename(file) {}
    void write(const std::vector<Tutorial>& tutorials) const {
        std::ofstream out(filename);
        out << "<!DOCTYPE html>\n";
        out << "<html>\n";
        out << "<head>\n";
        out << "<title>Playlist</title>\n";  // You can modify this if you want a different title
        out << "</head>\n";
        out << "<body>\n";
        out << "<table border=\"1\">\n";

        // Table header (column names)
        out << "<tr>\n";
        out << "<td>Presenter</td>\n";
        out << "<td>Title</td>\n";
        out << "<td>Duration</td>\n";
        out << "<td>Link</td>\n";
        out << "</tr>\n";

        // Loop through each tutorial and display it in the table
        for (const auto& t : tutorials) {
            out << "<tr>\n";
            out << "<td>" << t.get_presenter_c() << "</td>\n";
            out << "<td>" << t.get_title_c() << "</td>\n";
            out << "<td>" << t.get_duration_c() << "</td>\n";  // Assuming duration is a custom class with to_string() method
            out << "<td><a href=\"" << t.get_link_c() << "\">Link</a></td>\n";
            out << "</tr>\n";
        }

        out << "</table>\n";
        out << "</body>\n";
        out << "</html>\n";
    }
	void open() const override{
        
        //wstring wideLink(filename.begin(), filename.end());
        //ShellExecute(0, L"open", wideLink.c_str(), 0, 0, SW_SHOWNORMAL);
	}
};
