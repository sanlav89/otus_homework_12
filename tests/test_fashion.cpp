#include <fstream>

#include <gtest/gtest.h>

#include <fashionclassifier.h>

#include <helpers.h>

using namespace fashion;

const size_t width = 28;
const size_t height = 28;

TEST(FashionClassifier, accuracy) 
{
    // Load Tensrflow model
    auto clf = FashionClassifier{"train/saved_model", width, height};
    
    // Load test data
    auto features = FashionClassifier::features_t{};
    std::ifstream test_data{"train/test.csv"};
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
    
    ASSERT_NEAR(accuracy, 0.909, 1e-5);
}

TEST(FashionClassifier, predict) 
{
    auto clf = FashionClassifier{"train/saved_model", width, height};
    
    auto features = FashionClassifier::features_t{};
    std::ifstream test_data{"train/test_data_cnn.txt"};
    ASSERT_TRUE(test_data.is_open());
    
    for (;;) {
        size_t y_true;
        test_data >> y_true;
        if (!read_features(test_data, features)) {
            break;
        }
        auto y_pred = clf.predict(features);
        ASSERT_EQ(y_true, y_pred);
    }
}
