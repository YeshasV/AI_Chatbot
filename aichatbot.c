#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Memory {
    char name[30];
    char lastTopic[30];
};

void printing(int a,char sym,int b,float sol){
    printf("%d ",a);
    Sleep(50);
    printf("%c ",sym);
    Sleep(50);
    printf("%d ",b);
    Sleep(50);
    printf("= ");
    Sleep(50);
    printf("%.2f",sol);
    printf("\n");
}

void printing1(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        printf("%c",str[i]);
        Sleep(30);
    }
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

void greet() {
    const char *greetings[] = {
        "Hello!",
        "Hi there!",
        "Hey! Nice to see you.",
        "Hello human!"
    };
    printf("Bot: ");
    printing1(greetings[rand() % 4]);
    printf("\n");
}

void tellTime() {
    time_t t;
    time(&t);
    printf("Bot: ");
    printing1("Current time is ");
    printf("%s", ctime(&t));
    printf("\n");
}

void counterfun(int a,int b){
    for(int i=a;i<=b;i++){
        printf("     %d\n",i);
        Sleep(1000);
    }
}

void mathResponse(char input[]) {
    int a, b;
    if (sscanf(input, "add %d %d", &a, &b) == 2) {
        printf("Bot: ");
        printing(a,'+',b, a+b);
    }
    else if (sscanf(input, "subtract %d %d", &a, &b) == 2) {
        printf("Bot: ");
        printing(a,'-',b, a-b);
    }
    else if(sscanf(input,"multiply %d %d",&a,&b)==2){
        printf("Bot: ");
        printing(a,'x',b, a*b);
    }
    else if(sscanf(input,"divide %d %d",&a,&b)==2){
        printf("Bot: ");
        float a1=a;
        float b1=b;
        float quoti=a1/b1;
        printing(a1,'/',b1,quoti);
    }
    else {
        printf("Bot: ");
        printing1("I can do math like: add 5 10");
        printf("\n");
    }
}

void narratestory(){
    printf("Bot:");
    printing1("\n\n\033[1m\033[1mThe Last Light\033[0m");
    printf("\n\n\n");
    printing1("Every night at exactly 9:07 PM, the streetlight outside Aarav's window flickered once and stayed on. No earlier. No later");
    printf("\n\n");
    printing1("When the power cuts started, the entire neighborhood drowned in darkness-except that one lamp.");
    printf("\n\n");
    printing1("Curious, Aarav stepped outside one evening. The air was silent, heavy. As he stood beneath the glow, the light warmed instead of blinding him. A voice whispered, 'You came.'");
    printf("\n\n");
    printing1("The lamp dimmed, revealing memories instead of shadows-his childhood laughter, his mother's smile, the days he thought were lost. Aarav realized then: the light wasn't powered by electricity, but by remembrance.");
    printf("\n\n");
    printing1("When dawn arrived, the streetlight went dark forever.");
    printf("\n\n");
    printing1("But Aarav no longer feared the night.");
    printf("\n\n");
    printing1("Because some lights, once found, never truly go out.");
    printf("\n");
}

int main() {
    struct Memory botMemory = {"", ""};
    char input[200];

    srand(time(0));

    printf("AI Chatbot (C Language)\n");
    greet();

    while (1) {
        printf("\nYou: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input , "\n")] = 0;
        toLowerCase(input);

        if (strstr(input, "exit") || strstr(input, "bye")) {
            printf("Bot: ");
            printing1("Goodbye! Have a great day.");
            break;
        }

        else if (strstr(input, "my name is")) {
            sscanf(input, "my name is %[^\n]", botMemory.name);
            printf("Bot:");
            printing1(" Nice to meet you, ");
            printf("%s\n", botMemory.name);
            strcpy(botMemory.lastTopic, "name");
        }

        else if (strstr(input, "hello") || strstr(input, "hi")) {
            greet();
            strcpy(botMemory.lastTopic, "greeting");
        }

        else if (strstr(input, "nice") && strstr(input, "to")){
            printf("Bot: ");
            printing1("Nice to meet you too");
            printf("\n");
        }

        else if (strstr(input, "what is my name")) {
            if (strlen(botMemory.name) > 0){
                printf("Bot:");
                printing1(" Your name is ");
                printf("%s\n", botMemory.name);
            }
            else{
                printf("Bot:");
                printing1(" You haven't told me your name yet.");
                printf("\n");
            }

        }

        else if (strstr(input, "what") && (strstr(input, "ur") || strstr(input, "your")) && strstr(input, "name")){
                printf("Bot: ");
                printing1("My name is Tomo AI. Please don't tell anyone!");
                printf("\n");
        }

        else if (strstr(input, "time")) {
            tellTime();
            strcpy(botMemory.lastTopic, "time");
        }

        else if (strstr(input, "add") || strstr(input, "subtract") || strstr(input,"multiply") || strstr(input,"divide")) {
            mathResponse(input);
            strcpy(botMemory.lastTopic, "math");
        }

        else if (strstr(input, "help") || (strstr(input, "can") && (strstr(input, "u") || strstr(input, "you")) && strstr(input, "do")  ) ) {
            printf("Bot:");
            printing1(" I can chat,\n     remember your name,\n     tell time, narrate story,\n     can count,\n     and do simple math.");
            printf("\n");
        }

        else if (strlen(input) == 0) {
            printf("Bot:");
            printing1(" Say something");
            printf("\n");
        }

        else if (strstr(input, "clear")){
            system("cls");
            printf("AI Chatbot (C Language)\n");
        }

        else if (strstr(input, "story")){
            narratestory();
            printf("\n");
        }

        else if (strstr(input, "nice") || strstr(input, "good") || strstr(input,"welldone") || strstr(input,"best")){
            printf("Bot: ");
            printing1("Thank you, remember I am always by your side");
            printf("\n");
        }
        else if (strstr(input, "sing") || strstr(input, "dance")){
            printf("Bot: ");
            printing1("Ha ha ha! I am sorry i can't sing or dance.");
            printf("\n");
        }
        else if ((strstr(input, "are") || strstr(input, "r")) && strstr(input, "ai") && (strstr(input, "u") || strstr(input, "you"))){
            printf("Bot: ");
            printing1("I am a rule-based AI chatbot but not an actual AI");
            printf("\n");
        }
        else if ((strstr(input, "are") || strstr(input, "r")) && strstr(input, "how") && (strstr(input, "u") || strstr(input, "you"))){
            printf("Bot: ");
            printing1("I am fine. Thank you.");
            printf("\n");
        }
        else if (strstr(input, "count") && strstr(input, "can")){
            printf("Bot: ");
            printing1("Yes. Enter 2 numbers in the format:count [beginning] [ending]");
            printf("\n");
        }
        else if (strstr(input, "count")){
            int a,b;
            if(sscanf(input,"count %d %d",&a,&b)==2){
                counterfun(a,b);
            }
            else{
                printf("Bot: ");
                printing1("Enter 2 numbers in the format:count [beginning] [ending]");
                printf("\n");
            }
        }
        else if (strstr(input,"+") || strstr(input,"-") || strstr(input,"*") || strstr(input,"/")){
            printf("Bot: ");
            float a,b;
            if(sscanf(input,"%f*%f",&a,&b)==2){
                printing(a,'x',b,a*b);
            }
            else if(sscanf(input,"%f+%f",&a,&b)==2){
                printing(a,'+',b,a+b);
            }
            else if(sscanf(input,"%f-%f",&a,&b)==2){
                printing(a,'-',b,a-b);
            }
            else if(sscanf(input,"%f/%f",&a,&b)==2){
                printing(a,'/',b,a/b);
            }
            else{
                printing1("I didn't get that!");
                printf("\n");
            }
        }

        else {
            printf("Bot:");
            printing1(" I didn't understand that. And i have limited features due to C programming language, type 'help' to see what i can do.");
            if (strlen(botMemory.lastTopic) > 0){
                printing1(" Last topic was ");
                printf("%s.\n", botMemory.lastTopic);
            }
            else
                printf("\n");
        }
    }

    return 0;
}
