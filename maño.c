#include <stdio.h>
#include <string.h>
#include <windows.h>

#define nn 164 // ASCII code for 'ñ'
#define NN 165 // ASCII code for 'Ñ'
// TO CREATE FILE NAME WITH 'Ñ', THE NUMBER IS '209', NOT 165 LIKE ABOVE. IDK WHY

void create10Files(); // prototyping the functions below main in orde to call it propertly
void create100Files();
void printResponse();

int main()
{
    char response[16];
    char queEsManio[16] = "que es mano?\n";
    queEsManio[9] = nn;

    while (strcmp(response, queEsManio) != 0)
    {
        printf("Disculpe, tiene ma%co?\n", nn);
        fgets(response, 20, stdin);
    }
    if (strcmp(response, queEsManio) == 0) // comparing input user to string "que es maño?"
    {
        const wchar_t *file = L"D:\\Repositorios\\C Projects\\Maño\\dross.jpg";

        int ret = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)file, SPIF_UPDATEINIFILE);

        create100Files();
        printResponse();

        return 0;
    }
}

void create10Files()
{
    char fileName[64] = "testing/MANO00.txt"; // averiguar como hacer para reemplazar el leojv por cualquiera sea el nombre de usuario
    fileName[10] = 209;

    int unitsDigitLimit = 10;
    int unitsDigitPosition = 13;
    for (int i = 0; i < unitsDigitLimit; i++)
    {
        fileName[unitsDigitPosition] = 48 + i; // incrementing the 'unit's digit' of the file name
        FILE *fpointer = fopen(fileName, "a");

        for (int i = 0; i < 1024; i++) // si quiero que pesesn 1GB c/u, acá poner 1.073.741.824
        {
            fprintf(fpointer, "XD"); // con un solo caracter. si son 2 caracteres, reducir el iterador a la mitad
        }
        fclose(fpointer);
    }
}

void create100Files()
{
    char fileName[64] = "MANO00.txt"; // averiguar como hacer para reemplazar el leojv por cualquiera sea el nombre de usuario
    fileName[2] = 209;                // changing the 'N' for 'Ñ'

    int unitsDigitLimit = 10;
    int unitsDigitPosition = 5; // cambiar segun cambie la ruta del archivo
    int tensDigitLimit = 10;    // para elegir hasta cuantos archivos crear (en 10, va a crear de 90 a 99, (si unitsDigitLimit tambien esta en 10) )
    int tensDigitPosition = 4;  // cambiar segun cambie la ruta del archivo
    for (int j = 0; j < tensDigitLimit; j++)
    {
        fileName[tensDigitPosition] = 48 + j; // incrementing the 'tens digit' of the file name

        for (int i = 0; i < unitsDigitLimit; i++)
        {
            fileName[unitsDigitPosition] = 48 + i; // incrementing the 'units digit' of the file name
            FILE *fpointer = fopen(fileName, "a"); // creating .txt file
            for (int i = 0; i < 4096; i++)         // si quiero que pesesn 1GB c/u, acá poner 1.073.741.824 (imprimiendo un solo caracter. si son 2 caracteres, reducir el iterador a la mitad
            {
                fprintf(fpointer, "XD");
            }
            fclose(fpointer);
        }
    }
}

void printResponse()
{
    for (int i = 0; i < 10000; i++)
    {
        printf("UN HUEVO DE ESTE TAMA%cO ", NN);
    }
    for (int i = 0; i < 10000; i++)
    {
        printf("XDXDXDXDXDXDXDXDXDXD");
    }
    printf("\n");
    system("pause");
}