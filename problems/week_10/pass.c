#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LEN 128
#define MASTER_PASSWORD "EXAMPLE"

typedef struct {
    char site[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
} Credential;

Credential credentials[MAX_ACCOUNTS];
int total = 0;
const char *FILENAME = "vault.dat";

void xor_encrypt_decrypt(char *data, const char *key) {
    size_t len = strlen(data);
    size_t klen = strlen(key);
    for (size_t i = 0; i < len; i++) {
        data[i] ^= key[i % klen];
    }
}

void save_credentials() {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        perror("Error saving file");
        return;
    }

    for (int i = 0; i < total; i++) {
        xor_encrypt_decrypt(credentials[i].password, MASTER_PASSWORD);
        fwrite(&credentials[i], sizeof(Credential), 1, file);
        xor_encrypt_decrypt(credentials[i].password, MASTER_PASSWORD);
    }

    fclose(file);
    printf("Credentials saved successfully.\n");
}

void load_credentials() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) return;

    while (fread(&credentials[total], sizeof(Credential), 1, file)) {
        xor_encrypt_decrypt(credentials[total].password, MASTER_PASSWORD);
        total++;
    }

    fclose(file);
}

void add_credential() {
    if (total >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }

    printf("Site: ");
    scanf("%s", credentials[total].site);
    printf("Usuário: ");
    scanf("%s", credentials[total].username);
    printf("Senha: ");
    scanf("%s", credentials[total].password);

    total++;
    save_credentials();
}

void list_credentials() {
    for (int i = 0; i < total; i++) {
        printf("\n[%d] %s | %s | %s\n", i + 1,
               credentials[i].site,
               credentials[i].username,
               credentials[i].password);
    }
}

void delete_credential() {
    int id;
    printf("ID of the credential to remove: ");
    scanf("%d", &id);
    if (id < 1 || id > total) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = id - 1; i < total - 1; i++) {
        credentials[i] = credentials[i + 1];
    }
    total--;
    save_credentials();
}

int main() {
    char master[MAX_LEN];
    printf("Enter the master password: ");
    scanf("%s", master);

    if (strcmp(master, MASTER_PASSWORD) != 0) {
        printf("Incorrect password!\n");
        return 1;
    }

    load_credentials();

    int option;
    do {
        printf("\n=== Password Manager ===\n");
        printf("1. Add\n2. List\n3. Remove\n0. Exit\n");
        printf("Choose: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1: add_credential(); break;
            case 2: list_credentials(); break;
            case 3: delete_credential(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (option != 0);

    return 0;
}
