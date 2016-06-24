#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "common.h"
#include "VisualCryptographyMC.h"

static const level WhiteShare1[2][2] = {0,0,1,1};
static const level WhiteShare2[2][2] = {0,0,1,1};
static const level BlackShare1[2][2] = {0,0,1,1};
static const level BlackShare2[2][2] = {1,1,0,0};
 
void GenerateShareMC(level cColor, level share1[][2], level share2[][2], unsigned int r)
{	

}

void *PartialCodec(void *pcMCDataArg)
{

	MCData *pcMCData = (MCData *)pcMCDataArg;

// ********************************************************************************

// 1) If pcMCData->iCodecPath=ENCODE, the code performs encoding. In that case    *
//    input image of size (iHeight x iWidth) pixels of (type level) is stored at  *
//    address pcMCData->pImgData. The share images of size (2*iHeight x 2*iWidth) *
//    are stored at addresses pcMCData->pShare1 and pcMCData->pShare2.            *
//            																	  *
// 2) If pcMCData->iCodecPath==DECODE, the code performs decoding. In that case   *
//    output image of size (iHeight x iWidth) pixels of (type level) is stored    *
//    at address pcMCData->pImgData. The share images of size (iHeight x iWidth)  *
//	  are stored at addresses pcMCData->pShare1 and pcMCData->pShare2.            *
// ********************************************************************************


int rnum;


if(pcMCData->iCodecPath==0)
{

for (int y=pcMCData->iTd*(pcMCData->iHeight/pcMCData->iNumOfThreads);y<(pcMCData->iHeight/pcMCData->iNumOfThreads)+pcMCData->iTd*(pcMCData->iHeight/pcMCData->iNumOfThreads);y++)
   {
  
  for(int x=pcMCData->iWidth%pcMCData->iNumOfThreads;x<pcMCData->iNumOfThreads*pcMCData->iWidth/pcMCData->iNumOfThreads;x++)
  
       {
       
        if  (*(pcMCData->pImgData+x+y*pcMCData->iWidth)==BLACK)
             {
                
              rnum = rand_r(pcMCData->pSeeds)%2;
                          
       
		 if(rnum==0)   
          {		    
          	*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x)=0;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+1)=0;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth)=1;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1)=1;
            } 
			else
			{			 
   		      *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x)=1;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+1)=1;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth)=0;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1)=0;
			}	            
            		
		       	*(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x)=1-*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x);
            *(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x+1)=1-*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+1);
            *(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth)=1- *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth);
            *(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1)=1-*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1);
			}
			else 
			{
	 rnum = rand_r(pcMCData->pSeeds)%2;
           
			 
			if(rnum==0)    
              {
		        *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x)=0;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+1)=0;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth)=1;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1)=1;
            } 
			else
			{		 	 
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x)=1;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+1)=1;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth)=0;
            *(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1)=0;
			} 
			
           	*(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x)=*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x);
            *(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x+1)=*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+1);
            *(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth)=*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth);
            *(pcMCData->pShare2+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1)=*(pcMCData->pShare1+2*y*pcMCData->iWidth*2 +2*x+2*pcMCData->iWidth+1);
            
			}
		  }}
			}
      
 if(pcMCData->iCodecPath==1)
 {
for (int y=pcMCData->iTd*(pcMCData->iHeight/pcMCData->iNumOfThreads);y<(pcMCData->iHeight/pcMCData->iNumOfThreads)+pcMCData->iTd*(pcMCData->iHeight/pcMCData->iNumOfThreads);y++)
   {
  
  for(int x=pcMCData->iWidth%pcMCData->iNumOfThreads;x<pcMCData->iNumOfThreads*pcMCData->iWidth/pcMCData->iNumOfThreads;x++)
   
    {
         
  *(pcMCData->pImgData+x+pcMCData->iWidth*y)=!(*(pcMCData->pShare1+x+pcMCData->iWidth*y) || *(pcMCData->pShare2+x+pcMCData->iWidth*y));    
  }
  }
 }
			  

}

void VCEncoderMC(ImageData *pcShare1, ImageData *pcShare2, ImageData *pcImageData, TimeRecord *pTR)
{
	int iNumOfThreads, iTd;
	pthread_t *pcPthread;
	MCData    *pcMCData;
	struct timeval start,stop;
	unsigned int *pSeeds;

	printf("MC Encoding... \n");

		//------Generate shares pixels---------//
	pcShare1->imgData = (level *)malloc(4 * pcImageData->iHeight * pcImageData->iWidth * sizeof(level));
	pcShare2->imgData = (level *)malloc(4 * pcImageData->iHeight * pcImageData->iWidth * sizeof(level));


	iNumOfThreads = 16;


	
	if((pcImageData->iHeight % iNumOfThreads)!=0)
	{
		printf("Warning: the height of the original image is not divisible by number of threads\n");
	}
	
	if((pcImageData->iWidth % iNumOfThreads)!=0)
	{
		printf("Warning: the width of the original image is not divisible by number of threads\n");
	}
	
	pcPthread = (pthread_t *)malloc(sizeof(pthread_t)*iNumOfThreads);
	pcMCData  = (MCData *)malloc(sizeof(MCData)*iNumOfThreads);
	pSeeds     = (unsigned int *)malloc(sizeof(unsigned int)*iNumOfThreads*CLINE);
	
	//Collect data
	for(iTd=0;iTd < iNumOfThreads;iTd++)
	{
		pcMCData[iTd].iWidth  = pcImageData->iWidth;
		pcMCData[iTd].iHeight = pcImageData->iHeight;		
		pcMCData[iTd].iTd = iTd;
		pcMCData[iTd].iNumOfThreads = iNumOfThreads;
		pcMCData[iTd].pShare1 = pcShare1->imgData;
		pcMCData[iTd].pShare2 = pcShare2->imgData;
		pcMCData[iTd].pImgData = pcImageData->imgData;
		pSeeds[iTd] = time(NULL);
		pcMCData[iTd].pSeeds = &pSeeds[iTd*CLINE];
		pcMCData[iTd].iCodecPath = 0;
	}
		gettimeofday(&start,0);

	//Launch threads
	for(iTd=0;iTd < iNumOfThreads;iTd++)
	{	
		pthread_create(&(pcPthread[iTd]), NULL, PartialCodec, (void *)&pcMCData[iTd]);
	}


	//Wait all threads to finish
	for(iTd=0;iTd < iNumOfThreads;iTd++)
	{
			pthread_join(pcPthread[iTd],NULL);
	}
	
	free(pcMCData);
	free(pcPthread);
	free(pSeeds);
	
	gettimeofday(&stop,0);
	pTR->EncryptionTime = ((stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_usec)) / 1000;
	
	//----------Fill in shares----------//
	pcShare1->iWidth  = 2 * pcImageData->iWidth;
	pcShare1->iHeight = 2 * pcImageData->iHeight;
	pcShare2->iWidth  = 2 * pcImageData->iWidth;
	pcShare2->iHeight = 2 * pcImageData->iHeight;

	//Fill in file header
	memcpy(&(pcShare1->cBmpFH), &(pcImageData->cBmpFH), sizeof(BitMapFileHeader));
	memcpy(&(pcShare2->cBmpFH), &(pcImageData->cBmpFH), sizeof(BitMapFileHeader));

	//Fill in info header
	memcpy(&(pcShare1->cBmpIH), &(pcImageData->cBmpIH), sizeof(BitMapInfoHeader));
	memcpy(&(pcShare2->cBmpIH), &(pcImageData->cBmpIH), sizeof(BitMapInfoHeader));

	//Fill in color table
	memcpy(pcShare1->cBmpImage, pcImageData->cBmpImage, 2*sizeof(BitMapImage));
	memcpy(pcShare2->cBmpImage, pcImageData->cBmpImage, 2*sizeof(BitMapImage));

	//----------Adjust shares----------//
	sprintf(pcShare1->imageName, "Share1M_%s",pcImageData->imageName); //adjust name
	sprintf(pcShare2->imageName, "Share2M_%s",pcImageData->imageName);
	pcShare1->cBmpIH.width  = pcShare1->iWidth; //adjust width
	pcShare2->cBmpIH.width  = pcShare2->iWidth;
	pcShare1->cBmpIH.height = pcShare1->iHeight;  //adjust height
	pcShare2->cBmpIH.height = pcShare2->iHeight;  
	pcShare1->cBmpIH.biSizeImage = pcShare1->cBmpIH.height * (((pcShare1->cBmpIH.bitPix * pcShare1->cBmpIH.width + 31) / 32) * 4); //adjust image size
	pcShare2->cBmpIH.biSizeImage = pcShare2->cBmpIH.height * (((pcShare2->cBmpIH.bitPix * pcShare2->cBmpIH.width + 31) / 32) * 4); //adjust image size	
	pcShare1->cBmpFH.bfSize = pcShare1->cBmpIH.biSizeImage + pcShare1->cBmpFH.bfOffBits;
	pcShare2->cBmpFH.bfSize = pcShare2->cBmpIH.biSizeImage + pcShare2->cBmpFH.bfOffBits;
}

void VCDecoderMC(ImageData *pcShare1, ImageData *pcShare2, char *pInputImageName, ImageData *pcImageData, TimeRecord *pTR)
{

	int iNumOfThreads, iTd;
	pthread_t *pcPthread;
	MCData    *pcMCData;
	struct timeval start,stop;

	gettimeofday(&start,0);
	printf("MC Decoding ...\n");

	memcpy(pcImageData, pcShare1, sizeof(ImageData));
	pcImageData->imgData = (level *)malloc(pcImageData->iHeight * pcImageData->iWidth * sizeof(level));
	sprintf(pcImageData->imageName, "ReconM_%s",pInputImageName);



	iNumOfThreads = 16;


	pcPthread = (pthread_t *)malloc(sizeof(pthread_t)*iNumOfThreads);
	pcMCData  = (MCData *)malloc(sizeof(MCData)*iNumOfThreads);
		
	if((pcImageData->iHeight % iNumOfThreads)!=0)
	{
		printf("Warning: the height of the original image is not divisible by number of threads\n");
	}
	
	if((pcImageData->iWidth % iNumOfThreads)!=0)
	{
		printf("Warning: the width of the original image is not divisible by number of threads\n");
	}
	
	//Collect data
	for(iTd=0;iTd < iNumOfThreads;iTd++)
	{
		pcMCData[iTd].iWidth  = pcImageData->iWidth;
		pcMCData[iTd].iHeight = pcImageData->iHeight;		
		pcMCData[iTd].iTd = iTd;
		pcMCData[iTd].iNumOfThreads = iNumOfThreads;
		pcMCData[iTd].pShare1 = pcShare1->imgData;
		pcMCData[iTd].pShare2 = pcShare2->imgData;
		pcMCData[iTd].pImgData = pcImageData->imgData;
		pcMCData[iTd].iCodecPath = 1;
	}

	//Launch threads
	for(iTd=0;iTd < iNumOfThreads;iTd++)
	{	
		pthread_create(&(pcPthread[iTd]), NULL, PartialCodec, (void *)&pcMCData[iTd]);
	}


	//Wait for all threads to finish
	for(iTd=0;iTd < iNumOfThreads;iTd++)
	{
		pthread_join(pcPthread[iTd],NULL);
	}
	
	free(pcMCData);
	free(pcPthread);
 	
	gettimeofday(&stop,0);
	pTR->DecodeTime = ((stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_usec)) / 1000;
 
}
 



