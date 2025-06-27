bool load(const char *dictionary)
{
    root = create_node();
    if (root == NULL) return false;

    FILE *file = fopen(dictionary, "r");
    if (file == NULL) return false;

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *current = root;
        for (int i = 0; word[i]; i++)
        {
            int index = char_to_index(word[i]);
            if (current->children[index] == NULL)
            {
                current->children[index] = create_node();
                if (current->children[index] == NULL) return false;
            }
            current = current->children[index];
        }
        current->is_word = true;
        word_count++;
    }

    fclose(file);
    return true;
}
