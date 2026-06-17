#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        printf("ERROR: Invalid arguments\n");
        printf("only this formate Input/outpus allowed\n");
        printf("./a.out -e <input.bmp> <secret.txt> [output.bmp]\n");
        printf("./a.out -d <stego.bmp> [output_file]\n");
        return 1;
    }



    //structure variable define
    EncodeInfo encInfo;
    DecodeInfo decInfo;
   
    // collect the result from check operation 
    int res = check_operation_type(argv);
    
        //res if 0 or e_encode
        if(res == e_encode)
        {
            //check argc value may vary from 4 to 5
            if(argc>=4 && argc<=5)
            {
                //check read and validate encode validation
                if(read_and_validate_encode_args(argv,&encInfo) == e_failure)
                {

                    printf("ERROR: Invalid arguments\n");
                    return 0;
                    
                }
                //do encoding  if not equal to failure

                printf("=================================\n");
                printf("\tENCODING PROCESS\n");
                printf("=================================\n");
                if(do_encoding(&encInfo) == e_failure)
                {
                    printf("Error in Encoding\n");
                    return 0;
                }

            }else{
                printf("ERROR: Invalid arguments\n");
                printf("only this formate Input/outpus allowed\n");
                printf("./a.out -e <input.bmp> <secret.txt> [output.bmp]\n");
                printf("./a.out -d <stego.bmp> [output_file]\n");
                return 1;
            }
            //if all condition faulse then encoding done
            printf("=================================\n");
            printf("\tENCODING COMPLETED\n");
            printf("=================================\n");

        }else
        {
            // res equal to 1 or e{-decode
         if(res == e_decode)
            {
                 if(read_and_validate_decode_args(argv,&decInfo) == e_failure)
                {

                    printf("ERROR: Invalid arguments\n");
                    return 0;
                    
                }
                //do encoding  if not equal to failure
                printf("=================================\n");
                printf("\t DECODING PROCESS\n");
                printf("=================================\n");
                if(do_decoding(&decInfo) == e_failure)
                {
                    printf("Error in Encoding\n");
                    return 0;
                }
                

            
            }else
            {
                // if not print error msg
            printf("Error in Decoing\n");
                    return 0;
            }
     
                //if all condtion faulse decoding done
                printf("=================================\n");
                printf("\t DECODING COMPLETED\n");
                printf("=================================\n");

        }

}


OperationType check_operation_type(char *argv[])
{

    //check argv[1] -e or not
    if(strcmp(argv[1],"-e")==0)
    {
        return e_encode;


            //check argv[1] -d or not
    }else if(strcmp(argv[1],"-d")==0)
    {
            return e_decode;
    }
    else
    {       // if not both it will take it has e_unsupported
            return e_unsupported;
    }



}


