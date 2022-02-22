#pragma once

#include <string>

#include "classifier.h"

#include <catboost/c_api.h>

namespace kdd99 {

class CatboostClassifier: public BinaryClassifier {
public:
    CatboostClassifier(const std::string& modepath);

    ~CatboostClassifier() override;
    
    float predict_proba(const features_t&) const override;

private:
    ModelCalcerHandle* model_; 
};

}