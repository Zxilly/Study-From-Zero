#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char name[20];
    int prio;
    int needtime;
    char state;
    struct node *next;
} PCB;

PCB *ready = NULL, *run = NULL, *finish = NULL;
int num;

void GetFirst();

void Output();

void InsertPrio(PCB *in);

__attribute__((unused)) void InsertTime(PCB *in);

void InsertFinish(PCB *in);

void PrioCreate();

void Priority();

int main() {
    printf("the number of processes:");
    scanf("%d", &num);
    PrioCreate();
    Priority();
    Output();
    return 0;
}

void GetFirst() {
    run = ready;
    if (ready != NULL) {
        run->state = 'R';
        ready = ready->next;
        run->next = NULL;
    }
}

void Output() {
    PCB *p;
    p = ready;
    printf("pcb_name\tpriority\tneed_time\tpro_state\n");
    while (p != NULL) {
        printf("%s\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->needtime, p->state);
        p = p->next;
    }
    p = finish;
    while (p != NULL) {
        printf("%s\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->needtime, p->state);
        p = p->next;
    }
    p = run;
    while (p != NULL) {
        printf("%s\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->needtime, p->state);
        p = p->next;
    }
}

void InsertPrio(PCB *in) {
    PCB *fst;
    fst = ready;

    if (ready == NULL) {
        in->next = ready;
        ready = in;
    } else {
        if (in->prio >= fst->prio) {
            in->next = ready;
            ready = in;
        } else {
            while (fst->next != NULL) {
                fst = fst->next;
            }
            if (fst->next == NULL) {
                in->next = fst->next;
                fst->next = in;
            } else {
                in->next = fst;
            }
        }
    }
}

void InsertFinish(PCB *in) {
    PCB *fst;
    fst = finish;
    if (finish == NULL) {
        in->next = finish;
        finish = in;
    } else {
        while (fst->next != NULL) {
            fst = fst->next;
        }
        in->next = fst->next;
        fst->next = in;
    }
}

void PrioCreate() {
    PCB *tmp;
    int i;
    printf("process_name,need_time,priority:\n");
    for (i = 0; i < num; i++) {
        if ((tmp = (PCB *) malloc(sizeof(PCB))) == NULL) {
            perror("malloc");
            exit(1);
        }
        scanf("%s", tmp->name);
        getchar();
        scanf("%d", &(tmp->needtime));
        getchar();
        scanf("%d", &(tmp->prio));
        tmp->state = 'W';
        InsertPrio(tmp);
    }
}

void Priority() {
    int flag = 1;
    GetFirst();
    while (run != NULL) {
        Output();
        while (flag) {
            run->prio -= 3;
            run->needtime--;
            if (run->needtime == 0) {
                run->state = 'F';
                InsertFinish(run);
                flag = 0;
            } else {
                run->state = 'W';
                InsertPrio(run);
                flag = 0;
            }
        }
        flag = 1;
        GetFirst();
    }
}