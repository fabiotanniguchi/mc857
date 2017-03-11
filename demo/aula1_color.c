#include "FL.h"

int main(int argc, char **argv) {

    float h[256][3];
    int k;
    for(k = 0; k < 256; k++){
        h[k][0] = 0;
        h[k][1] = 0;
        h[k][2] = 0;
    }

    //color image
    ColorImage *colorImage = ReadColorImage("../data/lenaColor.ppm");

    double ka = (2^(colorImage->ny * colorImage->nx))/4;

    for (int i = 0; i < colorImage->ny; ++i) {
        for (int j = 0; j < colorImage->nx; ++j) {
/*
            colorImage->cor[i][j].val[0] = 255 - colorImage->cor[i][j].val[0];
            colorImage->cor[i][j].val[1] = 255 - colorImage->cor[i][j].val[1];
            colorImage->cor[i][j].val[2] = 255 - colorImage->cor[i][j].val[2];
*/
            index = (i*colorImage->ny) + j;

	    int l1 = (colorImage->cor[i][j].val[0])/ka;
	    int l2 = (colorImage->cor[i][j].val[1])/ka;
	    int l3 = (colorImage->cor[i][j].val[2])/ka;

	    h[colorImage->cor[i][j].val[0]][0] = h[colorImage->cor[i][j].val[0]][0] + 1;
	    h[colorImage->cor[i][j].val[1]][1] = h[colorImage->cor[i][j].val[1]][1] + 1;
	    h[colorImage->cor[i][j].val[2]][2] = h[colorImage->cor[i][j].val[2]][2] + 1;
        }
    }

    for(k = 0; k < 256; k++){
       h[k][0] = h[k]/(colorImage->nrows * colorImage->ncols);
       h[k][1] = h[k]/(colorImage->nrows * colorImage->ncols);
       h[k][2] = h[k]/(colorImage->nrows * colorImage->ncols);
    }

    FILE *fp;
    fp = fopen("h.txt", "w");
    for(k = 0; k < 255; k++){
	    fprintf(fp, "%d %d %d %d %f\n", k, h[k]);
    }
    fclose(fp);

    return 0;
}

