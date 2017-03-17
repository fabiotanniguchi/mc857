#include "FL.h"

int main(int argc, char **argv) {
    //color image
    ColorImage *colorImage = ReadColorImage("../data/squares.ppm");
    int depth = colorImage->Imax + 1;
    int block = 4;
    int blocks = block * block * block;
    int l1;
    int l2;
    int l3;
    //int *h = (int *) calloc(blocks, sizeof(int));
    //printf("TESTE3\n");
    float h[blocks];
    //printf("TESTE4\n");
    int block_size = depth / block;

    for(int k = 0; k < blocks; k++){
        h[k] = 0;
    }

    for (int i = 0; i < colorImage->ny; i++) {
        for (int j = 0; j < colorImage->nx; j++) {
            // red
            l1 = colorImage->cor[i][j].val[0];
            // green
            l2 = colorImage->cor[i][j].val[1];
            // blue
            l3 = colorImage->cor[i][j].val[2];
            //printf("l1 = %d block_size = %d depth = %d block = %d, blocks = %d\n", l1, block_size, depth, block, blocks);
            int red = l1 / block_size;
            int green = l2 / block_size;
            int blue = l3 / block_size;
            //printf("red = %d green = %d blue = %d\n", l1, l2, l3);
            //printf("TESTE5\n");
            int index = red + (green * block) + (blue * block * block);
            //printf("TESTE6 index = %d\n", index);
            h[index] += 1;
            //printf("TESTE7\n");
        }
    }

    for(int k = 0; k < blocks; k++){
       h[k] = h[k]/(colorImage->ny * colorImage->nx);
    }

    FILE *fp;
    fp = fopen("h.txt", "w");
    for(int k = 0; k < blocks; k++){
	    fprintf(fp, "%d %f\n", k, h[k]);
    }
    fclose(fp);

    return 0;
}
