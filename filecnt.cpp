#include<iostream>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
using namespace std;

//declaration of the directory information
//made some change in comment

struct directoryData                                                
{

     // initializing the variable of directory count, filecount and file size
        int directoryCount;
        int fileCount;
        int fileSize;
};

//prototype for function filecnt(char *)

struct directoryData filecnt(char* );                               
int main(int argc,char* argv[])
{
    char path[512];                                    
    struct directoryData temp;
   
    // asking user and displaying to enter the path
    cout << "Enter path of the directory : ";

    // reading the data
    cin >> path;
                                                    
    // calling function filecnt

    temp = filecnt(path);                                         

   //Displaying the output after reading the data
            
    cout << "The total number of directories in directory " << path << " is: " << temp.directoryCount << endl; 
    cout << "The total number of files in directory " << path << " is: "<< temp.fileCount << endl; 
    cout << "The total number of bytes occupied by all file in directory " << path <<" is: " << temp.fileSize << endl; 
    return 0;
                        
}

struct directoryData filecnt(char *Path)
{
   
    struct directoryData temp1;

    // creating the subdiectory path using array
   
    char newpath[512];                                         

    static int flag = 0,directoryCount = 0,fileCount = 0,fileSize = 0;
    DIR *parentDir;

    struct dirent *dirent; 
    
    //opening the path for directory             
    parentDir= opendir(Path); 

   // checking condition for the error message id directory cannot open.                                  
    if (parentDir == NULL && flag==0)                           
    {
         cout<< "Error: cannot open the directory " << Path << endl;
         exit (-1);

    }
    
    //reading all the file and subdirectory from the parent directory.
    while ((dirent= readdir(parentDir)) != NULL)                
    {
        flag = 2;                 // setting flag to 2

         // checking for file and directories in parent or current directory     
        if (strcmp((*dirent).d_name, ".") != 0 && strcmp((*dirent).d_name, "..") != 0) 
        { 
           
           //checking if the content inside is directory or not
           if((*dirent).d_type == DT_DIR)                         
           {

                // incrementing in the directory
                directoryCount++;  
                
                // creating new path                                                                    
                strcpy(newpath, Path);                          

                strcat(newpath, "/");
                strcat(newpath, (*dirent).d_name);
                filecnt(newpath);                             
           }
            
            //checking for the regular file 
             
           if((*dirent).d_type == DT_REG)                         
           {
               // incrementing file size count 
                fileCount++;                                  
                fileSize = fileSize + (*dirent).d_reclen;
           }

 
        }
     }

     //closing the directory
     closedir(parentDir); 
                               
     temp1.directoryCount = directoryCount;
     temp1.fileCount = fileCount;
     temp1.fileSize = fileSize;
  
     // returninf the directory set in tmp   
     return temp1;                                              
}

