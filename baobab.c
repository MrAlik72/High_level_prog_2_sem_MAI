//фигня с форматом для вывода на экран (нужно пофиксить!!!)||дичь с вершиной 
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct derevo {
        float key;
        int h;
        struct derevo* left;
        struct derevo* right;
        struct derevo* roditel;
} yzel;

yzel* create(yzel* koreshock, float key) {
        yzel* tmp = malloc(sizeof(yzel));
        tmp->key = key;
        tmp->h = 1;
        tmp->roditel = NULL;
        tmp->left = NULL;
        tmp->right = NULL;
        koreshock = tmp;
        return koreshock;
}

yzel* add(yzel* koreshock, float key) {
        yzel* koreshock2 = koreshock, *koreshock3 = NULL;
        yzel* tmp = malloc(sizeof(yzel));
        tmp->key = key;
        while (koreshock2 != NULL) {
                koreshock3 = koreshock2;
                if (key < koreshock2->key) {
                        koreshock2 = koreshock2->left;
                }
                else {
                        koreshock2 = koreshock2->right;
                }
        }
        tmp->roditel = koreshock3;
        tmp->left = NULL;
        tmp->right = NULL;
        if (key < koreshock3->key) {
                koreshock3->left = tmp;
        }
        else {
                koreshock3->right = tmp;
        }
        return koreshock;
}

yzel* search(yzel* koreshock, float key) {
        if (koreshock == NULL) {
                return NULL;
        }
        if (koreshock->key == key) {
                return koreshock;
        }
        if (key < koreshock->key) {
                return search(koreshock->left, key);
        }
        else {
                return search(koreshock->right, key);
        }
}

yzel* min(yzel* koreshock) {
        yzel* l = koreshock;
        while (l->left != NULL) {
                l = l->left;
        }
        return l;
}

yzel* max(yzel* koreshock) {
        yzel* r = koreshock;
        while (r->right != NULL) {
                r = r->right;
        }
        return r;
}

yzel* next(yzel* koreshock) {
        yzel* p = koreshock, * l = NULL;
        if (p->right != NULL) {
                return min(p->right);
        }
        l = p->roditel;
        while (l != NULL && p == l->right) {
                p = l;
                l = l->roditel;
        }
        return l;
}

void deleteyzel(yzel* koreshock) {
        if (koreshock->left && koreshock->right) {
                yzel* localMax = max(koreshock->left);
                koreshock->key = localMax->key;
                deleteyzel(localMax);
                return;
        }
        else if (koreshock->left) {
                if (koreshock == koreshock->roditel->left) {
                        koreshock->roditel->left = koreshock->left;
                }
                else {
                        koreshock->roditel->right = koreshock->left;
                }
        }
        else if (koreshock->right) {
                if (koreshock == koreshock->roditel->right) {
                        koreshock->roditel->right = koreshock->right;
                }
                else {
                        koreshock->roditel->left = koreshock->right;
                }
        }
        else {
                if (koreshock == koreshock->roditel->left) {
                        koreshock->roditel->left = NULL;
                }
                else {
                        koreshock->roditel->right = NULL;
                }
        }
        free(koreshock);
}


void delete(yzel* koreshock, float value) {
        koreshock = search(koreshock, value);
        deleteyzel(koreshock);
}


void print_menu(int n) {
        printf("\nКоличество вершин в дереве: %d\n", n);
        printf("Что будем делать с ним?\n");
        printf("0. Закончить работу с программой\n");
        printf("1. Добавить новый узел\n2. Визуализировать дерево\n3. Удалить узел\n");
        printf("4. Проверить, находятся ли все листья на одном уровне\n");
        printf("\nВведите номер команды: ");
}

void print_derevo(yzel* t, int h) {
        if (t != NULL) {
                print_derevo(t->right, h + 1);
                for (int i = 0; i < 5 * h; i++) {
                        printf(" ");
                }
                printf("%.1f\n", t->key);
                print_derevo(t->left, h + 1);
        }
}

void update(yzel* koreshock) {
        if (koreshock == NULL) {
                return;
        }
        if (koreshock->roditel == NULL) {
                koreshock->h = 1;
        }
        else {
                koreshock->h = koreshock->roditel->h + 1;
        }
        update(koreshock->left);
        update(koreshock->right);
}

int maximum(int a, int b) {
        if (a > b) {
                return a;
        }
        return b;
}

int max_deapth(yzel* koreshock) {
        if (koreshock == NULL) {
                return 0;
        }
        return 1 + maximum(max_deapth(koreshock->left), max_deapth(koreshock->right));
}


bool leaflvls(yzel* koreshock, int maxd) {
        bool ans = true;
        if (koreshock == NULL) {
                return ans;
        }
        if (koreshock->left == NULL && koreshock->right == NULL) {
                ans &= (maxd == koreshock->h);
        }
        ans &= leaflvls(koreshock->left, maxd);
        ans &= leaflvls(koreshock->right, maxd);
        return ans;
}

int main() {
        yzel* derevo = NULL;
        printf("Давайте создадим дерево, введите ключ вершины: ");
        float key;
        scanf("%f", &key);
        printf("\n");
        derevo = create(derevo, key);
        int n = 1, task;
        do {
                print_menu(n);
                scanf("%d", &task);
                float key1;
                switch (task) {
                case 1:
                        printf("\nВведите ключ узла, который нужно добавить: ");
                        scanf("%f", &key1);
                        if (search(derevo, key1) != NULL) {
                                printf("\nТакая вершина уже есть в дереве\n");
                        }
                        else {
                                derevo = add(derevo, key1);
                                printf("\nВершина успешно добавлена\n");
                                n++;
                        }
                        break;
                case 2:
                        printf("\n");
                        print_derevo(derevo, 0);
                        break;
                case 3:
                        printf("\nВведите ключ узла, который хотите удалить: ");
                        scanf("%f", &key1);
                        if (search(derevo, key1) == NULL) {
                                printf("\nТакой вершины нет в дереве\n");
                        }
                        else if (n == 1) {
                                printf("\nВ дереве остался один узел, вы не можете его удалить\n");
                        }
                        else {
                                delete(derevo, key1);
                                n--;
                                printf("\nВершина успешно удалена\n");
                        }
                        break;
                case 4:
                        printf("\n");
                        update(derevo);
                        int maxd = max_deapth(derevo);
                        if (leaflvls(derevo, maxd)) {
                                printf("\nВсе листья дерева расположены на одном уровне\n");
                        }
                        else {
                                printf("\nНе все листья дерева расположены на одном уровне\n");
                        }
                        break;
                case 0:
                        break;
                default:
                        printf("\nВы ввели неверную команду\n");
                }
        } while (task != 0);
}