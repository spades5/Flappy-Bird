#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char name[100];
    int level; //Starting from 1
    int experience; //0
    int health; //350~600
    int mana; //100~120
    int speed; //35~50
    int attack; //40~60
}PlayerData;

typedef struct{
    char name[100];//ora
    int health; //150~170
    int speed; //35~50
    int attack; //20~30
    int provideExp; //15
}MonsterData;

void initialPlayer(PlayerData *player){
    srand((unsigned) time(NULL));
    printf("�п�J���a���W�r�G");
    scanf("%s",PlayerData.name);
    PlayerData->level = 1;
    PlayerData->experience = 0;
    PlayerData->health = rand()%251+350;
    PlayerData->mana = rand()%21+100;
    PlayerData->speed = rand()%16+35;
    PlayerData->attack = rand()%21+40;
}

void initialMonster(MonsterData *monster){
    srand((unsigned) time(NULL));
    MonsterData->name='�b�~�H';
    MonsterData->health = rand()%21+170;
    MonsterData->speed = rand()%16+35;
    MonsterData->attack = rand()%11+20;
    MonsterData->provideExp = 15;
}

void printPlayerData(PlayerData player){
    printf("%s\n",PlayerData.name);
    printf("���� %d, ��O %d, �t�� %d, �����O %d, �g��� %d",PlayerData.level,PlayerData.health,PlayerData.speed,PlayerData.attack,PlayerData.experience);
}

void attack_P2M(PlayerData *player,MonsterData *monster){ //player attack monster
    char action[10];
    int wave=0;
    while(wave<1){
        printf("choose the action!!!(A : Attack,H : Heal,F : Flee)");
        scanf("%s",action);

        if (strcmp(action,"A") == 0 || strcmp(action,"a") == 0){ //����
            printf("%s�����A�y��%s���� %d �I�C",PlayerData->name,MonsterData->name,PlayerData->attack);
            MonsterData.health -= PlayerData.attack;
            wave++;
        }
        if(strcmp(action,"H") == 0 || strcmp(action,"h"){ //��_
           if(PlayerData->mana>=20){
                PlayerData.mana -=20;
                PlayerData.health +=100;
                printf("%s��_100��O (�k�O-20)",PlayerData->name);
                wave++;
           }
           else
           {
                printf("�k�O����(�k�O %d)",PlayerData->mana);
           }
        }
        if(strcmp(action,"F") == 0 || strcmp(action,"f") == 0){ //�k�]
            int speedDifference = PlayerData->speed - MonsterData->speed;
            int fleeChance = 0;
            if(speedDifference>=50){
                fleeChance = 100;
            }
            else if(speedDifference<=-50){
                fleeChance = 0;
            }
            else{
                fleeChance = 50+speedDifference;
            }

            srand((unsigned) time(NULL));
            int randomValue = rand()%100;

            if(fleeChance>randomValue){
                printf("�k�]���\");
                wave ++;
            }
            else{
                printf("�k�]����");
                wave ++;
            }
        }
    }
}

void attack_M2P(PlayerData *player,MonsterData *monster){ //monster attack player
    printf("%s�����A�y��%s���� %d �I�C",MonsterData->name,PlayerData->name,MonsterData->attack);
    PlayerData->health -= MonsterData->attack;
}

#define monsterTotal 3;

int main(){
    PlayerData player;
    MonsterData monster[monsterTotal];
    int i;

    initialPlayer(&player);
    for(i=0;i<mosterTotal;i++){
        initialMonster(&monster[i]);
    }
    for(i=0;i<mosterTotal;i++){
        printPlayerData(player);
        //player and monster still alive
        while(PlayerData.health > 0 && MonsterData.health > 0){
            if(MonsterData.speed>PlayerData.speed){
                attack_M2P(player,monster);
            }
            if(MonsterData.speed<=PlayerData.speed){
                    attack_P2M(player,monster);
            }
        }
    }

}
