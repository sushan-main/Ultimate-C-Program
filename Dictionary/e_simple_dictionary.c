#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 150

typedef struct
{
    char word[MAX_LENGTH];
    char synonyms[MAX_LENGTH];
    char antonyms[MAX_LENGTH];
} Dictionary;

Dictionary dict[MAX_WORDS];
int wordCount = 0;

void addWord()
{
    if (wordCount >= MAX_WORDS)
    {
        printf("Dictionary is full!\n");
        return;
    }

    printf("Enter word: ");
    scanf(" %[^\n]s", dict[wordCount].word);
    printf("Enter synonyms (comma separated, or '!none'): ");
    scanf(" %[^\n]s", dict[wordCount].synonyms);
    printf("Enter antonyms (comma separated, or '!none'): ");
    scanf(" %[^\n]s", dict[wordCount].antonyms);

    wordCount++;
    printf("Word added successfully!\n");
}

void displayWords()
{
    if (wordCount == 0)
    {
        printf("No words in the dictionary.\n");
        return;
    }

    for (int i = 0; i < wordCount; i++)
    {
        printf("%d. %s\n", i + 1, dict[i].word);
        printf("\tSynonyms: %s\n", strcmp(dict[i].synonyms, "!none") == 0 ? "No Data" : dict[i].synonyms);
        printf("\tAntonyms: %s\n", strcmp(dict[i].antonyms, "!none") == 0 ? "No Data" : dict[i].antonyms);
    }
}

int strcmp_IgnoreCase(const char *text, const char *word)
{
    // Create copies of the strings to avoid modifying the originals
    char str1[strlen(text) + 1];
    char str2[strlen(word) + 1];

    strcpy(str1, text);
    strcpy(str2, word);

    // Convert both strings to lowercase
    for (int i = 0; str1[i] != '\0'; i++)
    {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        str2[i] = tolower(str2[i]);
    }

    // Use strstr to search for the lowercase word in the lowercase text
    if (strcmp(str1, str2) == 0)
    {
        return 0;
    }
}

void searchWord()
{
    int choice;
    printf("Search by:\n");
    printf("1. Index\n");
    printf("2. Word\n");
    printf("3. Antonym/Synonym\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int index;
        printf("Enter index: ");
        scanf("%d", &index);
        if (index > 0 && index <= wordCount)
        {
            printf("Found in Location %d\n", index);
            printf("Word: %s\n", dict[index - 1].word);
            printf("Synonyms: %s\n", strcmp(dict[index - 1].synonyms, "!none") == 0 ? "No Data" : dict[index - 1].synonyms);
            printf("Antonyms: %s\n", strcmp(dict[index - 1].antonyms, "!none") == 0 ? "No Data" : dict[index - 1].antonyms);
        }
        else
        {
            printf("Invalid index!\n");
        }
    }
    else if (choice == 2)
    {
        char query[MAX_LENGTH];
        printf("Enter word to search: ");
        scanf(" %[^\n]s", query);
        for (int i = 0; i < wordCount; i++)
        {
            if (strcmp_IgnoreCase(dict[i].word, query) == 0)
            {
                printf("Found in Location %d\n", i + 1);
                printf("Word: %s\n", dict[i].word);
                printf("Synonyms: %s\n", strcmp(dict[i].synonyms, "!none") == 0 ? "No Data" : dict[i].synonyms);
                printf("Antonyms: %s\n", strcmp(dict[i].antonyms, "!none") == 0 ? "No Data" : dict[i].antonyms);
                return;
            }
        }
        printf("Word not found!\n");
    }
    else if (choice == 3)
    {
        char query[MAX_LENGTH];
        printf("Enter antonym or synonym to search: ");
        scanf(" %[^\n]s", query);
        for (int i = 0; i < wordCount; i++)
        {
            if (strstr(dict[i].synonyms, query) || strstr(dict[i].antonyms, query))
            {
                printf("Found in Location %d\n", i + 1);
                printf("Word: %s\n", dict[i].word);
                printf("Synonyms: %s\n", strcmp(dict[i].synonyms, "!none") == 0 ? "No Data" : dict[i].synonyms);
                printf("Antonyms: %s\n", strcmp(dict[i].antonyms, "!none") == 0 ? "No Data" : dict[i].antonyms);
                return;
            }
        }
        printf("Word not found!\n");
    }
    else
    {
        printf("Invalid choice!\n");
    }
}

void updateWord()
{
    char query[MAX_LENGTH];
    printf("Enter word to update: ");
    scanf(" %[^\n]s", query);

    for (int i = 0; i < wordCount; i++)
    {
        if (strcmp_IgnoreCase(dict[i].word, query) == 0)
        {
            printf("Enter new word (or '!same' to keep the same): ");
            char newWord[MAX_LENGTH];
            scanf(" %[^\n]s", newWord);
            if (strcmp(newWord, "!same") != 0)
            {
                strcpy(dict[i].word, newWord);
            }

            printf("Enter new synonyms (or '!same' for no change, '!none' for no data): ");
            char newSynonyms[MAX_LENGTH];
            scanf(" %[^\n]s", newSynonyms);
            if (strcmp(newSynonyms, "!same") != 0)
            {
                strcpy(dict[i].synonyms, newSynonyms);
            }

            printf("Enter new antonyms (or '!same' for no change, '!none' for no data): ");
            char newAntonyms[MAX_LENGTH];
            scanf(" %[^\n]s", newAntonyms);
            if (strcmp(newAntonyms, "!same") != 0)
            {
                strcpy(dict[i].antonyms, newAntonyms);
            }

            printf("Word updated successfully!\n");
            return;
        }
    }
    printf("Word not found!\n");
}

void saveToFile()
{
    FILE *file = fopen("Dictionary/dictionary-data.txt", "w");
    if (!file)
    {
        printf("Error saving file!\n");
        return;
    }

    for (int i = 0; i < wordCount; i++)
    {
        fprintf(file, "%d:%s:%s:%s\n", i + 1, dict[i].word, dict[i].antonyms, dict[i].synonyms);
    }

    fclose(file);
    printf("Dictionary saved successfully!\n");
}
void deleteWord()
{
    char query[MAX_LENGTH];
    printf("Enter word to delete: ");
    scanf(" %[^\n]s", query);

    for (int i = 0; i < wordCount; i++)
    {
        if (strcmp_IgnoreCase(dict[i].word, query) == 0)
        {
            for (int j = i; j < wordCount - 1; j++)
            {
                dict[j] = dict[j + 1];
            }
            wordCount--;
            printf("Word deleted successfully!\n");
            return;
        }
    }
    printf("Word not found!\n");
}

void loadFromFile()
{
    FILE *file = fopen("Dictionary/dictionary-data.txt", "r");
    if (!file)
    {
        printf("No existing dictionary file found.\n");
        return;
    }
    int temp;
    wordCount = 0;
    while (fscanf(file, "%d:%[^:]:%[^:]:%[^\n]\n", &temp, dict[wordCount].word, dict[wordCount].antonyms, dict[wordCount].synonyms) != EOF)
    {
        wordCount++;
    }
    fclose(file);
    printf("Dictionary loaded successfully!\n");
}

void dictionary()
{
    int choice;
    loadFromFile();
    do
    {
        system("cls");
        printf("\nDictionary Menu:\n");
        printf("1. Add Word\n");
        printf("2. Display Words\n");
        printf("3. Search Word\n");
        printf("4. Delete Word\n");
        printf("5. Update Word\n");
        printf("6. Save and Return Back to Main Menu\n");
        printf("7. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addWord();
            break;
        case 2:
            displayWords();
            break;
        case 3:
            searchWord();
            break;
        case 4:
            deleteWord();
            break;
        case 5:
            updateWord();
            break;
        case 6:
            saveToFile();
            continue;
            break;
        case 7:
            saveToFile();
            printf("\nShutting down...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (choice != 6);
}