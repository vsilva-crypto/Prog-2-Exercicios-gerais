/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest)
{
    int i = 0; 

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (str[i] >= 'a' || str[i] <= 'z')
            str[i] -= 32;
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        if (str[i] >= 'A' || str[i] <= 'Z')
            str[i] += 32;
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str)
{
    int tam = string_length(str);
    int i = tam, j = 0;
    char tempString[tam + 1];

    string_copy(str, tempString);

    while (j != '\0')
    {
        str[j] = tempString[i];
        i--;
        j++;
    }
}
