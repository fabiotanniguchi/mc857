//
// Created by deangeli on 3/22/17.
//
#include "filtering.h"


FeatureVector* correlation1D(FeatureVector*X1,FeatureVector*X2,bool normalization){
    return NULL;
}
FeatureVector* correlation1D(FeatureVector*X1,Kernel kernel){
    return NULL;
}
float* correlation1D(FeatureVector*X1,Kernel *kernel, int n){
    return NULL;
}

FeatureVector* circularCrossCorrelation1D(FeatureVector*X1,FeatureVector*X2,bool normalization){
    FeatureVector* signal;
    FeatureVector* filter;
    FeatureVector* output;

    if (X1->size > X2->size) {
        signal = X1;
        filter = X2;
    } else {
        signal = X2;
        filter = X1;
    }

    output = createFeatureVector(signal->size);

    int filterCenter = filter->size/2;
    for (int i = 0; i < signal->size; i++) {
        float sum = 0;
        for (int j = 0; j < filter->size; j++) {
            int index = i - filterCenter + j;
            if (index < 0) {
                index = signal->size + index;
            }
            if (index > signal->size) {
                index %= signal->size;
            }
            sum += signal->features[index] * filter->features[j];
        }

        output->features[i] = sum;
    }

    return output;
}

FeatureVector* circularCrossCorrelation1D(FeatureVector*X1,Kernel *kernel){
    return NULL;
}

float* circularCrossCorrelation1D(FeatureVector*X1,Kernel *kernel, int *n){
    return NULL;
}


FeatureVector* covolution1D(FeatureVector*X1,FeatureVector*X2){
    return NULL;
}
FeatureVector* covolution1D(FeatureVector*X1,Kernel *kernel){
    return NULL;
}
float* covolutionn1D(FeatureVector*X1,Kernel *kernel, int n){
    return NULL;
}

FeatureVector* circularCovolution1D(FeatureVector*X1,FeatureVector*X2){
    return NULL;
}
FeatureVector* circularCovolution1D(FeatureVector*X1,Kernel *kernel){
    return NULL;
}

float* circularCovolution1D(FeatureVector*X1,Kernel *kernel, int n){
    return NULL;
}
