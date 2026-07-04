#include <stdio.h>

int main () {
    int h,m,s;
    printf("Digite o tempo em horas, minutos e segundos: ");
    scanf("%d %d %d", &h, &m, &s);
    while(h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
        printf("Tempo inválido. Digite novamente: ");
        scanf("%d %d %d", &h, &m, &s);
    }
    int duracao;
    printf("Digite a duração em segundos: ");
    scanf("%d", &duracao);
    while(duracao < 0) {
        printf("Duração inválida. Digite novamente: ");
        scanf("%d", &duracao);
    }

    int novo_horario = h*3600 + m*60 + s + duracao;
    novo_horario = novo_horario % 86400; // 24 horas
    int novo_h = novo_horario / 3600;
    int novo_m = (novo_horario % 3600) / 60;
    int novo_s = novo_horario % 60;
    printf("Novo horário: %02d:%02d:%02d\n", novo_h, novo_m, novo_s);
}