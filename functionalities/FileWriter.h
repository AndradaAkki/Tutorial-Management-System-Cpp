#pragma once
#include <vector>
#include "Tutorial.h"

class FileWriter {
public:
    virtual ~FileWriter() = default;
    virtual void write(const std::vector<Tutorial>& tutorials) const = 0;
    virtual void open() const {
		return;
    }
    
};
