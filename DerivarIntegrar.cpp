#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*Funciones*/
void derivacionNumerica();
void integracionNumerica();
double funcion(double x, vector<double> coeficientes, int grado);
double integralPolinomica(int grado, double a, double b);
double derivadaNumerica(double (*f)(double), double x, double h);
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);

int main()
{

    int opcion;

    do
    {
        cout << "\n     ======================================================================\n";
        cout << "\t\t\tMenu principal" << endl;
        cout << "\tCalculadora de metodos de calculo numerico." << endl;
        cout << "\n     ======================================================================\n";
        cout << "\t1. Derivacion Numerica" << endl;
        cout << "\t2. Integracion Numerica" << endl;
        cout << "\t3. SALIR" << endl;
        cout << "\n\t Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            derivacionNumerica();
            break;

        case 2:
            integracionNumerica();
            break;
        }
    } while (opcion != 3);
    return 0;
}

/* ==============Funciones==============*/

void derivacionNumerica()
{

    int selection;
    double x, h, resultado;
try_again:
    cout << "\n     ======================================================================\n"
         << endl;
    cout << "\t1. (x)^a               2. a^x\n";
    cout << "\t3. ln(x)               4. asin(x)\n";
    cout << "\t5. acos(x)             6. atan(x)\n";
    cout << "\t7. EXIT\n\n";
    cout << "\tIngrese su opcion: ";
    cin >> selection;

    if (selection >= 1 && selection <= 6)
    {
        cout << "\tIngrese el valor de x: ";
        cin >> x;
        cout << "\tIngrese el valor de h: ";
        cin >> h;
        switch (selection)
        {

        case 1:
            resultado = derivadaNumerica(f1, x, h);
            break;
        case 2:
            resultado = derivadaNumerica(f2, x, h);
            break;
        case 3:
            resultado = derivadaNumerica(f3, x, h);
            break;
        case 4:
            resultado = derivadaNumerica(f4, x, h);
            break;
        case 5:
            resultado = derivadaNumerica(f5, x, h);
            break;
        case 6:
            resultado = derivadaNumerica(f6, x, h);
            break;
        }
        cout << "\tEl resultado es: " << resultado << endl;
    }
}
/*==============Metodo de derivacion por definicion==============*/

double derivadaNumerica(double (*f)(double), double x, double h)
{
    return (f(x + h) - f(x)) / h;
}

double f1(double x)
{
    double a;
    cout << "\tIngrese a: ";
    cin >> a;

    return pow(x, a);
}

double f2(double x)
{
    double a;
    cout << "\tIngrese a: ";
    cin >> a;
    return pow(a, x);
}

double f3(double x)
{
    return log(x);
}

double f4(double x)
{
    double a;
    cout << "\tIngrese a: ";
    cin >> a;
    return a * sin(x);
}

double f5(double x)
{
    double a;
    cout << "\tIngrese a: ";
    cin >> a;
    return a * cos(x);
}

double f6(double x)
{
    double a;
    cout << "Ingrese a: ";
    cin >> a;
    return a * tan(x);
}

void integracionNumerica()
{

    int opcion, grado;
try_again:
    cout << "\n     ======================================================================\n"
         << endl;
    cout << "\t1.Funcion polinomica P(x) = an*x^n + a(n-1)*x^(n-1) + ... + a1*x + a0." << endl;
    cout << "\t2. a.e^x" << endl;
    cout << "\t3. a^(x)" << endl;
    cout << "\t4. asin(x)" << endl;
    cout << "\t5. acos(x)" << endl;
    cout << "\t6. SALIR\n\n";
    cout << "\tIngrese su opcion: ";
    cin >> opcion;
    if (opcion >= 1 && opcion <= 5)
    {
        switch (opcion)
        {
        case 1:
        {
            int grado;
            double a, b;

            cout << "\tIngrese el grado de la funcion polinomica: ";
            cin >> grado;
            cout << "\tIngrese los limites de integracion (a y b): ";
            cin >> a >> b;

            double resultado = integralPolinomica(grado, a, b);

            cout << "\n\tEl valor de la integral es: " << resultado << endl;
            break;
        }
        case 2:
        {
            float a;
            cout << "\n\tIntegral del tipo a.e^x" << endl;
            cout << "\n\tIngrese a: " << endl;
            cin >> a;

            double limite_inf, limite_sup;
            cout << "\n\tIngrese los limites de integracion (limite inferior y limite superior): ";
            cin >> limite_inf >> limite_sup;

            // Regla del trapecio
            int intervalos = 100; // n�mero de intervalos
            double h = (limite_sup - limite_inf) / intervalos;
            double suma = 0.0;

            for (int i = 0; i <= intervalos; i++)
            {
                if (i == 0 || i == intervalos)
                    suma += exp(limite_inf);
                else
                    suma += 2 * exp(limite_inf);
                limite_inf += h;
            }

            double resultado = a * suma * (h / 2);
            cout << "\n\tLa integral es: " << resultado << endl;
            break;
        }
        case 3:
        {
            float a;
            cout << "\n\tIntegral del tipo a^x" << endl;
            cout << "\n\tIngrese a: " << endl;
            cin >> a;

            double limite_inf, limite_sup;
            cout << "\n\tIngrese los limites de integracion (limite inferior y limite superior): ";
            cin >> limite_inf >> limite_sup;

            // Regla del trapecio
            int n = 100; // n�mero de intervalos
            double h = (limite_sup - limite_inf) / n;
            double suma = 0.0;
            for (int i = 0; i <= n; i++)
            {
                if (i == 0 || i == n)
                    suma += pow(a, limite_inf);
                else
                    suma += 2 * pow(a, limite_inf);
                limite_inf += h;
            }
            suma *= h / 2;

            cout << "\n\tLa integral es: " << suma << endl;
            break;
        }
        case 4:
        {
            float a;
            cout << "\n\tIntegral del tipo a*sin(x)" << endl;
            cout << "\n\tIngrese a: " << endl;
            cin >> a;

            double limite_inf, limite_sup;
            cout << "\n\tIngrese los limites de integracion (limite inferior y limite superior): ";
            cin >> limite_inf >> limite_sup;

            // Regla del trapecio
            int n = 100; // n�mero de intervalos
            double h = (limite_sup - limite_inf) / n;
            double suma = 0.0;
            for (int i = 0; i <= n; i++)
            {
                if (i == 0 || i == n)
                    suma += a * sin(limite_inf);
                else
                    suma += 2 * a * sin(limite_inf);
                limite_inf += h;
            }
            suma *= h / 2;

            cout << "\n\tLa integral es: " << suma << endl;
            break;
        }
        case 5:
        {
            float a;
            cout << "\n\tIntegral del tipo a*cos(x)" << endl;
            cout << "\n\tIngrese a: " << endl;
            cin >> a;

            double limite_inf, limite_sup;
            cout << "\n\tIngrese los limites de integracion (limite inferior y limite superior): ";
            cin >> limite_inf >> limite_sup;

            // Regla del trapecio
            int n = 100; // n�mero de intervalos
            double h = (limite_sup - limite_inf) / n;
            double suma = 0.0;
            for (int i = 0; i <= n; i++)
            {
                if (i == 0 || i == n)
                    suma += (a * cos(limite_inf)) / 2.0;
                else
                    suma += a * cos(limite_inf);
                limite_inf += h;
            }
            double integral = h * suma;

            cout << "\n\tLa integral es: " << integral << endl;
            break;
        }
        }
    }
}

// Case 1
double integralPolinomica(int grado, double a, double b)
{
    vector<double> coeficientes(grado + 1);

    for (int i = 0; i <= grado; i++)
    {
        cout << "\tIngrese el coeficiente de x^" << i << ": ";
        cin >> coeficientes[i];
    }

    double integral = 0;
    int n = 100; // n�mero de intervalos

    double h = (b - a) / n;

    for (int i = 0; i < n; i++)
    {
        double xi = a + i * h;
        double xi1 = a + (i + 1) * h;
        // Regla del trapecio
        integral += (funcion(xi, coeficientes, grado) + funcion(xi1, coeficientes, grado)) * h / 2;
    }
    return integral;
}

double funcion(double x, vector<double> coeficientes, int grado)
{
    double resultado = 0;
    for (int i = 0; i <= grado; i++)
    {
        resultado += coeficientes[i] * pow(x, i);
    }
    return resultado;
}
