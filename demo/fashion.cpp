#include <iostream>
#include <fstream>
#include <cassert>

#include <fashionclassifier.h>
#include <helpers.h>

using namespace fashion;

int main(int argc, char *argv[])
{
    assert(argc == 3);
    
    // Disable Tensorflow logging
    char var[] = "TF_CPP_MIN_LOG_LEVEL=3";
    putenv(var);
    
    // Load Tensrflow model
    auto clf = FashionClassifier{argv[2], 28, 28};
    
    // Load test data
    auto features = FashionClassifier::features_t{};
    std::ifstream test_data{argv[1]};
    assert(test_data.is_open());
    
    // Calculate Accuracy
    auto steps_all = 0;
    float accuracy = 0;
    
    for (;;) {
        size_t y_true;
        test_data >> y_true;
        if (!read_features_csv(test_data, features)) {
            break;
        }

        auto y_pred = clf.predict(features);
        if (y_true == y_pred) {
            accuracy += 1;
        }
        steps_all++;
    }
    accuracy /= steps_all;
    
    std::cout << accuracy << std::endl;
    
    return 0;
}
