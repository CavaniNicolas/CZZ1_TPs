#ifndef histoH
#define histoH

void computeHisto(histogram_t, list_t);
void displayHisto(histogram_t);
int maxHisto(histogram_t);
float meanHisto(histogram_t);
int countHisto(histogram_t);
void displayString(gdata_t, char *, int, int);
void displayGraphicalHisto(gdata_t, histogram_t);
void displayGraph(histogram_t);
void displayText(histogram_t);

#endif