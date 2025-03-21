#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffling(int card[], int N)
{
    srand( (unsigned)time(NULL) );
    for(int i=N-1;i>0;i--) //�ϦV���j�A�C���j��N��ڭ̷|��ܷ�e�d�򤺪��@�i�d���A�ñN��P�Y���H����ܪ��d���洫
    {
        int k = rand() % (i + 1);//�q�L�� rand() �����G���l�ơA�N�H���ƭ���b 0 �� i �����A�o�˨C���H����ܪ����޽d��|�H�۰j�骺�i��v���Y�p�C (i+1)��+1�O�T�Ocard[0]�Bcard[1]���洫��
        int temp = card[k];//card[k] �H���D�X�Ӫ��d
        card[k] = card[i];//card[i] ��e���d
        card[i] = temp;
    }
}

int main()
{
    char *tarot[22] = {"The Fool", "The Magician", "The High Priestess", "The Empress", "The Emperor", "The Hierophant", "The Lovers", "The Chariot", "Justice", "The Hermit", "Wheel of Fortune", "Strength", "The Hanged Man", "Death", "Temperance", "The Devil", "The Tower", "The Star", "The Moon", "The Sun", "Judgement", "The World"};
    int card[22];
    int i;

    for (int i = 0; i < 22; i++)
    {
        card[i] = i;
    }

    shuffling(card, 22);

    for (int i=0;i<22;i++)
    {
        printf("[%02d]%s\n", card[i], tarot[card[i]]);
    }
    return 0;
}
