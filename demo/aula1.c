#include "FL.h"

int main(int argc, char **argv) {

    float h[256];

    int k;
    for(k = 0; k < 256; k++){
        h[k] = 0;
    }

    //gray image
    GrayImage *grayImage = ReadGrayImage("../data/lena.pgm");
    int index=0;
    for (int i = 0; i < grayImage->nrows; ++i) {
        for (int j = 0; j < grayImage->ncols; ++j) {
            index = (i*grayImage->ncols) + j;
//            grayImage->val[index] = 255 - grayImage->val[index];

            h[grayImage->val[index]] = h[grayImage->val[index]] + 1;
        }
    }

    for(k = 0; k < 256; k++){
       h[k] = h[k]/(grayImage->nrows * grayImage->ncols);
    }

    FILE *fp;
    fp = fopen("h.txt", "w");
    for(k = 0; k < 255; k++){
	    fprintf(fp, "%d %f\n", k, h[k]);
    }
    fclose(fp);

    return 0;
}

