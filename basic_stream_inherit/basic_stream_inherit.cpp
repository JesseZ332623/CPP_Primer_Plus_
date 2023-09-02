#include <iostream>
#include <fstream>
#include <cstdlib>

const int LIMIT = 5;
void file_it(std::ostream & out_stream, double focal, const double *eye_pices, int n);

void file_it(std::ostream & out_stream, double focal, const double *eye_pices, int n)
{
    std::ios_base::fmtflags initial = out_stream.setf(std::ios_base::fixed);
    out_stream.precision(0);

    out_stream << "Focal length of objective: " << focal << "mm" << std::endl;

    out_stream.setf(std::ios::showpoint);
    out_stream.precision(1);
    out_stream.width(12);

    out_stream << "f.l. eyepieces";
    out_stream.width(15);
    out_stream << "magnification" << std::endl;

    for (int index = 0; index < n; ++index)
    {
        out_stream.width(12);
        out_stream << eye_pices[index];
        out_stream.width(15);
        out_stream << int(focal / eye_pices[index] * 0.5) << std::endl;
    }
    out_stream.setf(initial);
}

int main(int argc, char const *argv[])
{
    std::ofstream file_out;
    const char *file_name = "Ep_data.txt";
    double objective = 0.0000;
    double eye_pisces[LIMIT];

    file_out.open(file_name);

    if (!file_out.is_open())
    {
        std::cout << "Can't open" << file_name << '.' << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter the focal lengths of your" "telescope objective in mm: ";
    std::cin >> objective;

    std::cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepiece:" << std::endl;

    for (int index = 0; index < LIMIT; ++index)
    {
        std::cout << "Eyepiece #" << index + 1 << ": ";
        std::cin >> eye_pisces[index];
    }

    file_it(file_out, objective, eye_pisces, LIMIT);
    file_it(std::cout, objective, eye_pisces, LIMIT);

    std::cout << "Done.\n";

    return EXIT_SUCCESS;
}
