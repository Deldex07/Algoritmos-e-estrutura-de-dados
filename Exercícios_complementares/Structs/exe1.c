#include <stdio.h>

typedef struct Horario{
    int hora,minuto,segundo;
}Horario;

typedef struct Data{
    int dia,mes,ano;
}Data;

typedef struct Compromisso{
    Data data;
    Horario horario;
    char t[100];
}Compromisso;

int main(){
    Compromisso cps;

    printf("Horário(00:00:00): ");
    scanf("%d:%d:%d", &cps.horario.hora, &cps.horario.minuto, &cps.horario.segundo);

    printf("Data(00/00/00): ");
    scanf("%d/%d/%d", &cps.data.dia, &cps.data.mes, &cps.data.ano);

    printf("Compromisso: ");
    scanf(" %[^\n]s", cps.t);

    printf("\n--- Detalhes do Compromisso ---\n");
    printf("Horário: %02d:%02d:%02d\n", cps.horario.hora, cps.horario.minuto, cps.horario.segundo);
    printf("Data: %02d/%02d/%04d\n", cps.data.dia, cps.data.mes, cps.data.ano);
    printf("Compromisso: %s\n", cps.t);

    return 0;
}