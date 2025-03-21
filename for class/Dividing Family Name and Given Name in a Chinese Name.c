#include <stdio.h>
#include <string.h>

char *twoCharFMname[] = {"�a��", "�ڶ�", "�q��", "�q�{", "�q��", "�q�F", "�W�x", "�L��", "�Ϧ�", "�Ĥ�", "��C", "����", "�F��", "���]", "�s�]", "��]", "���]", "�u�]", "���]", "�}�e", "�t��", "�[�C", "�Ѹ�", "�F��", "�F��", "���", "����", "�L�J", "�E�S", "�ʨ�", "�ݤ�", "���M", "�Өj", "�I��", "�B�O", "�O��", "�E�_", "�Y��", "��_", "�n�c", "�ХC", "���"};

char *oneCharFMname[] = { "��", "��", "�i", "�B", "��", "��", "��", "�d", "��", "�P", "�}", "�]", "��", "��", "�J", "�L", "��", "��", "��", "ù", "�G", "��", "��", "��", "��", "�\\", "�H", "��", "��", "��", "��", "�^", "��", "��", "��", "��", "��", "�K", "�_", "�E", "��", "��", "��", "Ĭ", "�Q", "�{", "�f", "�B", "�H", "��", "��", "�c", "��", "��", "��", "�Z", "��", "��", "�S", "�L", "��", "��", "��", "��", "��", "��", "�L", "��", "��", "�J", "�Q", "��", "�s", "��", "��", "��", "�F", "��", "��", "�q", "�p", "��", "�v", "�s", "��", "�P", "�U", "��", "�q", "��", "��", "�U", "��", "�Y", "��", "��", "�x", "�Z", "��", "��", };

int isTwoCharSurname(const char *str) {
    for (int i=0; i<sizeof(twoCharFMname)/sizeof(twoCharFMname[0]);i++){
        if (strncmp(str, twoCharFMname[i], 6) == 0) {
            return 1;
        }
    }
    return 0;
}

void nameChecking(){
    char name[500];
    while(1){
        printf("�аݴL�m�j�W (��J quit ������}���t��)�G");
        fgets(name,sizeof(name),stdin); strtok(name,"\r\n");

        if (strcmp(name, "quit") == 0) {
            break;
        }

        int length = strlen(name);

        if(length==8){ //�|�Ӧr
            printf("�w�� %.*s �P�� %s ���Y�{�I\n",4, name, name + 4);
        }

        if(length==4){ //��Ӧr

            printf("�w�� %.*s �P�� %s ���Y�{�I\n",2, name, name+2);
        }

        if(length==9){ //�T�Ӧr
            if (isTwoCharSurname(name)) {
                printf("�аݱz�m (1) %.*s �٬O (2) %.*s�H", 3, name, 6, name);
                int ans;
                if (scanf("%d",&ans) == 1) {
                    getchar();
                    if (ans == 1) {
                        printf("�w�� %.*s �P�� %s ���Y�{�I\n",3,name,name+3);
                    } else if (ans == 2) {
                        printf("�w�� %.*s �P�� %s ���Y�{�I\n",6,name,name+6);
                    }
                }
            }
            else {
                printf("�w�� %.*s �P�� %s ���Y�{�I\n",3,name,name+3);
            }
        }
    }
    printf("\n�P�¨ϥΥ��t�ΡI");
}

int main()
{
    nameChecking();
    return 0;
}
