#include "helpers.h"

#include <fstream>
#include <sstream>
#include <iterator>

namespace fashion {

bool read_features(std::istream& stream, Classifier::features_t& features) 
{
    std::string line;
    std::getline(stream, line);

    features.clear();
    std::istringstream linestream{line};
    double value;
    while (linestream >> value) {
        features.push_back(value);
    }
    return stream.good();
}

bool read_features_csv(std::istream& stream, Classifier::features_t& features, separator_t sep)
{
    std::string line;
    std::getline(stream, line);
    std::stringstream linestream{line};
    std::string cell;
    features.clear();
    while (std::getline(linestream, cell, sep)) {
        if (!cell.empty()) {
            features.push_back(std::stof(cell));
        }
    }
    return stream.good();
}

std::vector<float> read_vector(std::istream& stream) 
{
    std::vector<float> result;

    std::copy(std::istream_iterator<float>(stream),
              std::istream_iterator<float>(),
              std::back_inserter(result));
    return result;
}

}