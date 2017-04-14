//
// Created by deangeli on 4/7/17.
//

#include "bagOfVisualWords.h"

FeatureMatrix* computeFeatureVectors(DirectoryManager* directoryManager, int patchSize){

	
	return NULL;
}

FeatureMatrix* computeFeatureVectors(Image* imagePack, int patchSize){
	Image* currentSlice;
	Image* patch;
	Histogram* histogram;
	FeatureVector* patchVector;
	int patchX_axis = imagePack->nx/patchSize;
	int patchY_axis = imagePack->ny/patchSize;
	int nPatchesImage = patchX_axis * patchY_axis;
	int nPatches = nPatchesImage * imagePack->nz;
	int nBinsChannel = 256/64;
	int nBins = nBinsChannel * nBinsChannel * nBinsChannel;
	FeatureMatrix* featureMatrix = createFeatureMatrix(nPatches, nBins);
	int k = 0;
	for(int z = 0; z < imagePack->nz; ++z){
		currentSlice = getSlice(imagePack, z);
		for(int y = 0; y < imagePack->ny-patchSize; y += patchSize){
			for(int x = 0; x < imagePack->nx-patchSize; x += patchSize){
				patch = extractSubImage(currentSlice, x, y, patchSize, patchSize);
				histogram = computeHistogram(patch, 64, true);
				patchVector = createFeatureVector(histogram);
				featureMatrix->featureVector[k] = patchVector;
				k++;
				destroyHistogram(&histogram);
				destroyImage(&patch);
				destroyFeatureVector(&patchVector);
			}
		}
		destroyImage(&currentSlice);
	}
	return featureMatrix;
}

FeatureMatrix* kMeansClustering(FeatureMatrix* featureMatrix, int numberOfCluster){
	FeatureMatrix* dict = createFeatureMatrix(numberOfCluster);
	int k = 0;
	bool *isUsed = (bool*)calloc(featureMatrix->nFeaturesVectors, sizeof(bool));
	int* labels = (int*)calloc(featureMatrix->nFeaturesVectors, sizeof(int));
	while(k < numberOfCluster){
		int randomIndex = RandomInteger(0, featureMatrix->nFeaturesVectors);
		if(isUsed[randomIndex] == false){

			dict->featureVector[k] = copyFeatureVector(featureMatrix->featureVector[randomIndex]);
			labels[k] = k;
			isUsed[randomIndex] = true;
			k++;
		}
	}
	free(isUsed);

	for(int i = 0; i < featureMatrix->nFeaturesVectors; ++i){
		// acha o cluster mais proximo

		// depois de achar
		// labels[i] = indiceCluster;
	}
	return NULL;
}
