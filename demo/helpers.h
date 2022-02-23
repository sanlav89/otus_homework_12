#include <istream>
#include <string>

#include <classifier.h>

namespace fashion {

using separator_t = char;

bool read_features(std::istream& stream, Classifier::features_t& features);

bool read_features_csv(std::istream& stream, Classifier::features_t& features, separator_t sep = ',');

std::vector<float> read_vector(std::istream&);

}