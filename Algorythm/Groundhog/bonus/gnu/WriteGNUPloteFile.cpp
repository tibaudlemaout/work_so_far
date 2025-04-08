/*
** EPITECH PROJECT, 2024
** B-CNA-410-NAN-4-1-groundhog-thomas.cluseau
** File description:
** WriteGNUPloteFile
*/
#include "../include/Groundhog.hpp"

void MakePlot(const std::string& filename)
{
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "plot '%s' with lines\n", filename.c_str());
        fflush(gnuplotPipe);
        std::cout << "Plot generated using Gnuplot" << std::endl;
        getchar(); // Wait for user to press Enter before closing Gnuplot
        pclose(gnuplotPipe);
    } else {
        std::cerr << "Unable to open Gnuplot pipe" << std::endl;
    }
}

void writeDataToFile(const std::vector<double>& data, const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < data.size(); ++i) {
            file << i << " " << data[i] << std::endl;
        }
        file.close();
        std::cout << "Data written to file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
    MakePlot(filename);
}
