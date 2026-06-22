#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

void sumeru();
void nodkrai();
void country();
void otherCountry();
void weapon();
char checkInput(std::string);

int main(){
    bool loop=1;
    char play=0;
    do{
        std::cout<<"===Welcome to Genshin Character Guesser! (Dendro version only)==="<<'\n';
        std::cout<<"Here are the list of dendro characters. Pick one and don't say it out!"<<'\n';
        std::cout<<"For every question asked, type Y for Yes or N for No."<<'\n'<<'\n';
        
        std::string character[12][4]={{"Alhaitham","M", "Sumeru", "Sword"},
                                    {"Baizhu", "M", "Liyue", "Catalyst"},
                                    {"Collei", "F", "Sumeru", "Bow"},
                                    {"Emilie", "F", "Fontaine", "Polearm"},
                                    {"Kaveh", "M", "Sumeru", "Claymore"},
                                    {"Kinich", "M", "Natlan", "Claymore"},
                                    {"Kirara", "F", "Inazuma", "Sword"},
                                    {"Lauma", "F", "Nod-Krai", "Catalyst"},
                                    {"Nahida", "F", "Sumeru", "Catalyst"},
                                    {"Nefer", "F", "Nod-Krai", "Catalyst"},
                                    {"Tighnari", "M", "Sumeru", "Bow"},
                                    {"Yaoyao", "F", "Liyue", "Polearm"}};

        int rows=sizeof(character)/sizeof(character[0]);
        int columns=sizeof(character[0])/sizeof(character[0][0]);

        std::cout<<std::left<<std::setw(15)<<"Characters";
        std::cout<<std::setw(12)<<"Gender";
        std::cout<<std::setw(13)<<"Country";
        std::cout<<std::setw(13)<<"Weapon"<<'\n';
        std::cout<<"------------------------------------------------------"<<'\n';

        for (int i=0; i<rows; i++){
            for (int j=0; j<columns; j++){
                int width=(j==1)? 10:15;
            std::cout<<std::left<<std::setw(15)<<character[i][j]; 
        }  std::cout<<'\n';
        }
    
        std::cout<<"Let's begin by asking some questions:"<<'\n'<<'\n';
        country();

        play=' ';
        while (play!='Y'&&play!='N'){
        std::cout<<"Continue playing?"<<'\n';
        std::cin>>play;
        play=std::toupper(play);
        if (play=='Y'){
            loop=1;
        }
        else if (play=='N'){
            loop=0;
        }
        else 
        std::cout<<"Invalid input. Type Y/N only."<<'\n';
    }
    } while (loop==1);
    std::cout<<"Thank you for playing!"<<'\n';
    
  return 0;  
}

void country(){
    std::string input_string;
    char answer;
    char gender;
    std::cout<<"Is the character from Liyue ?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
        if (answer=='Y'){
            std::cout<<"Is the character a male?";
            std::cin>>gender;
            answer=std::toupper(gender);
            answer=='Y'? std::cout<<"Aha! The character you picked is Baizhu."<<'\n': std::cout<<"Aha! The character you picked is Yaoyao."<<'\n';
        }
        else if (answer=='N'){
            otherCountry();}
}

char checkInput(std::string answer){
    while ((answer.length()!=1)||((answer[0]!='Y'&&answer[0]!='N'&&answer[0]!='y'&&answer[0]!='n'))){
        std::cout<<"Invalid input. Type Y/N only.";
        std::cin>>answer;
    }
        return std::toupper(answer[0]);
}

void otherCountry(){
    std::string input_string;
    char answer;
    bool found=0;
    
    if (!found){
    std::cout<<"Is the character from Sumeru?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
    if (answer=='Y'){
        sumeru();
        found=1;
    }
}
    if (!found){
    std::cout<<"Is the character from Inazuma?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
    if(answer=='Y'){
        std::cout<<"Aha! The character you picked is Kirara"<<std::endl;
        found=1;
    }
}
    if (!found){
    std::cout<<"Is the character from Fontaine?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
    if (answer=='Y'){
        std::cout<<"Aha! The character you picked is Emilie."<<'\n';
        found=1;
    }
}
    if (!found){
    std::cout<<"Is the character from Natlan?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
        if (answer=='Y'){
            std::cout<<"Aha! The character you picked is Kinich."<<'\n';
            found=1;
        }
    }

    if (!found){
    std::cout<<"Is the character from Nod-Krai?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
        if (answer=='Y'){
            nodkrai();
            found=1;
        }
        else if (answer=='N'){
        std::cout<<"Wait, you said no for everything...The character you picked is the dendro traveler!"<<std::endl;
    }
    } }
       
void sumeru(){
    std::string input_string;
    char answer;
    bool found=0;

    if (!found){
    std::cout<<"Is the character a female?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
     if (answer=='Y'){
        char answer1;
        std::cout<<"Does the character use bow?"<<'\n';
        std::cin>>input_string;
        answer=checkInput(input_string);
        if (answer=='Y'){
            std::cout<<"Aha! The character you picked is Collei."<<'\n';
            found=1;
        }
        else if (answer=='N'){
            std::cout<<"Aha! The character you picked is Nahida."<<'\n';
            found=1;
    }
}
    else if (answer=='N'){
        weapon();
    }
}
}

void weapon(){
    std::string input_string;
    char answer;
    bool found=0;

    if (!found){
    std::cout<<"Does the character use sword?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
     if (answer=='Y'){
                std::cout<<"Aha! The character you picked is Alhaitham."<<'\n';
                found=1;
            }
    else if (answer=='N'){
    std::cout<<"Does the character use bow?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);
     if (answer=='Y'){
                std::cout<<"Aha! The character you picked is Tighnari."<<'\n';
                found=1;
            }
    }
}
    if (!found){
    std::cout<<"Does the character use claymore?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);  
     if (answer=='Y'){
                std::cout<<"Aha! The character you picked is Kaveh."<<'\n';
                found=1;
            }
    std::cout<<"Wait, you said no to everything...Try again."<<'\n';
}
}

void nodkrai (){
    std::string input_string;
    char answer;
    bool found=0;

    if(!found){
    std::cout<<"Is the character the head of the Curatorium of Secrets?"<<'\n';
    std::cin>>input_string;
    answer=checkInput(input_string);  
            if (answer=='Y'){
                std::cout<<"Aha! The character you picked is Nefer."<<'\n';
                found=1;
            }
            else if (answer=='N'){
                std::cout<<"Aha! The character you picked is Lauma."<<'\n';
                found=1;
            }
            else 
            std::cout<<"Wait, you said no to everything...Try again."<<'\n';
}
}
