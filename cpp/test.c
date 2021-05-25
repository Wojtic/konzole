#include <stdio.h>
#include <stdint.h>

const uint8_t snake_data[][5] = {{25, 3, 1, 0, 255}, {25, 5, 1, 255, 0}, {26, 5, 1, 0, 255}, {25, 6, 1, 1, 255}, {26, 6, 1, 1, 0}, {27, 6, 2, 1, 255}, {24, 7, 1, 1, 255}, {29, 7, 1, 2, 255}, {9, 8, 11, 3, 255}, {20, 8, 1, 4, 255}, {24, 11, 1, 255, 1}, {27, 11, 2, 2, 1}, {29, 11, 1, 255, 2}, {12, 12, 1, 4, 3}, {13, 12, 4, 255, 3}, {25, 12, 2, 255, 1}, {27, 12, 2, 255, 2}, {25, 17, 6, 3, 255}, {28, 18, 1, 5, 3}, {29, 18, 1, 6, 3}, {29, 19, 1, 5, 6}, {1, 20, 8, 3, 255}, {21, 20, 4, 4, 255}, {28, 20, 2, 3, 5}, {20, 21, 5, 3, 4}, {1, 23, 11, 4, 3}, {1, 24, 12, 255, 4}, {17, 24, 14, 255, 3}};
const uint8_t snake_data_v2[] = {31, 19, 34, 64, 7, 19, 34, 64, 7, 19, 34, 64, 7, 19, 34, 64, 7, 19, 34, 64, 7, 19, 34, 64, 7, 19, 34, 64, 7, 19, 34, 64, 7, 7, 46, 64, 7, 7, 46, 64, 7, 7, 46, 64, 7, 7, 35, 75, 7, 7, 35, 19, 7, 35, 19, 7, 35, 19, 7, 35, 19, 7, 47, 7, 7, 47, 7, 7, 47, 7, 7, 76, 34, 7, 19, 64, 34, 7, 19, 64, 34, 7, 19, 64, 34, 7, 6, 99, 8, 64, 34, 7, 2, 129, 0, 101, 4, 38, 7, 4, 128, 101, 4, 38, 7, 5, 100, 160, 4, 38, 7, 5, 100, 160, 4, 32, 193, 35, 7, 6, 163, 5, 32, 224, 192, 35, 7, 16, 38, 7, 31};

const uint8_t pacman_data[][5] = {{9, 2, 3, 0, 255}, {12, 2, 2, 1, 255}, {7, 3, 2, 0, 255}, {12, 3, 2, 0, 1}, {14, 3, 2, 1, 255}, {6, 4, 1, 0, 255}, {14, 4, 2, 0, 1}, {16, 4, 1, 1, 255}, {5, 5, 1, 0, 255}, {16, 5, 1, 0, 1}, {17, 5, 1, 1, 255}, {7, 6, 2, 2, 0}, {14, 6, 2, 2, 0}, {4, 7, 1, 0, 255}, {6, 7, 1, 2, 0}, {9, 7, 1, 2, 0}, {13, 7, 1, 2, 0}, {16, 7, 1, 2, 0}, {17, 7, 1, 0, 1}, {18, 7, 1, 1, 255}, {8, 8, 2, 3, 2}, {15, 8, 2, 3, 2}, {6, 10, 1, 0, 2}, {8, 10, 1, 2, 3}, {9, 10, 1, 0, 3}, {13, 10, 1, 0, 2}, {15, 10, 1, 2, 3}, {16, 10, 1, 0, 3}, {7, 11, 2, 0, 2}, {14, 11, 2, 0, 2}, {17, 12, 1, 4, 0}, {18, 12, 1, 4, 1}, {19, 12, 4, 5, 255}, {15, 13, 2, 4, 0}, {19, 13, 4, 4, 5}, {23, 13, 2, 5, 255}, {14, 14, 1, 4, 0}, {23, 14, 2, 4, 5}, {25, 14, 1, 5, 255}, {13, 15, 1, 4, 0}, {25, 15, 1, 4, 5}, {26, 15, 1, 5, 255}, {12, 16, 1, 4, 0}, {26, 16, 1, 4, 5}, {27, 16, 1, 5, 255}, {6, 17, 1, 1, 0}, {7, 17, 1, 255, 0}, {25, 17, 2, 255, 4}, {27, 17, 1, 255, 5}, {5, 18, 1, 1, 0}, {6, 18, 1, 255, 1}, {8, 18, 1, 255, 0}, {11, 18, 1, 4, 0}, {23, 18, 2, 255, 4}, {4, 19, 1, 1, 0}, {5, 19, 1, 255, 1}, {9, 19, 1, 255, 0}, {21, 19, 2, 255, 4}, {4, 20, 1, 255, 1}, {10, 20, 1, 255, 0}, {20, 20, 1, 255, 4}, {20, 22, 1, 5, 255}, {20, 23, 1, 4, 5}, {21, 23, 2, 5, 255}, {11, 24, 1, 255, 4}, {21, 24, 2, 4, 5}, {23, 24, 2, 5, 255}, {23, 25, 2, 4, 5}, {25, 25, 3, 5, 255}, {12, 26, 1, 255, 4}, {25, 26, 1, 4, 5}, {27, 26, 1, 255, 5}, {13, 27, 1, 255, 4}, {25, 27, 1, 5, 4}, {26, 27, 1, 255, 5}, {14, 28, 1, 255, 4}, {23, 28, 2, 5, 4}, {25, 28, 1, 255, 5}, {15, 29, 2, 255, 4}, {19, 29, 4, 5, 4}, {23, 29, 2, 255, 5}, {17, 30, 2, 255, 4}, {19, 30, 4, 255, 5}};
const uint8_t pacman_data_v2[] = {31, 31, 31, 31, 6, 43, 64, 11, 4, 44, 64, 12, 3, 34, 98, 38, 64, 13, 2, 34, 100, 37, 14, 2, 34, 97, 129, 96, 38, 13, 1, 36, 96, 129, 40, 12, 1, 49, 11, 1, 47, 165, 7, 1, 64, 44, 169, 5, 1, 64, 35, 98, 36, 171, 4, 2, 64, 33, 100, 34, 173, 3, 2, 64, 33, 97, 129, 96, 33, 175, 2, 3, 64, 33, 96, 129, 34, 175, 2, 4, 65, 36, 177, 1, 6, 68, 177, 1, 11, 192, 175, 192, 1, 11, 192, 166, 1, 192, 165, 192, 1, 11, 192, 165, 3, 192, 164, 192, 1, 11, 192, 165, 3, 192, 164, 192, 1, 12, 192, 163, 5, 192, 162, 192, 2, 12, 192, 163, 5, 192, 162, 192, 2, 13, 192, 161, 7, 192, 160, 192, 3, 14, 192, 160, 7, 193, 4, 15, 192, 7, 192, 5, 31, 31, 31, 31};

const uint8_t nastaveni_data[][5] = {{13, 2, 6, 0, 255}, {14, 3, 3, 1, 0}, {17, 3, 1, 2, 0}, {7, 4, 2, 0, 255}, {15, 4, 2, 2, 1}, {23, 4, 2, 0, 255}, {6, 5, 1, 0, 255}, {7, 5, 2, 1, 0}, {9, 5, 1, 0, 255}, {12, 5, 1, 0, 255}, {13, 5, 1, 1, 0}, {14, 5, 1, 2, 1}, {18, 5, 1, 2, 0}, {19, 5, 1, 0, 255}, {22, 5, 1, 0, 255}, {23, 5, 2, 2, 0}, {25, 5, 1, 0, 255}, {5, 6, 1, 0, 255}, {6, 6, 1, 1, 0}, {9, 6, 1, 1, 0}, {10, 6, 2, 0, 255}, {12, 6, 1, 1, 0}, {13, 6, 1, 2, 1}, {19, 6, 1, 2, 0}, {20, 6, 2, 0, 255}, {22, 6, 1, 2, 0}, {25, 6, 1, 2, 0}, {26, 6, 1, 0, 255}, {4, 7, 1, 0, 255}, {5, 7, 1, 1, 0}, {10, 7, 2, 1, 0}, {12, 7, 1, 2, 1}, {20, 7, 2, 2, 0}, {26, 7, 1, 2, 0}, {27, 7, 1, 0, 255}, {8, 8, 4, 2, 1}, {4, 9, 1, 255, 0}, {5, 9, 1, 0, 1}, {7, 9, 1, 2, 1}, {26, 9, 1, 0, 2}, {27, 9, 1, 255, 0}, {5, 10, 1, 255, 0}, {6, 10, 1, 0, 1}, {7, 10, 1, 1, 2}, {25, 10, 1, 0, 2}, {26, 10, 1, 255, 0}, {14, 11, 4, 0, 2}, {5, 12, 1, 0, 255}, {6, 12, 1, 1, 0}, {13, 12, 1, 0, 2}, {14, 12, 4, 255, 0}, {18, 12, 1, 0, 2}, {25, 12, 1, 2, 0}, {26, 12, 1, 0, 255}, {2, 13, 3, 0, 255}, {5, 13, 1, 1, 0}, {6, 13, 2, 2, 1}, {12, 13, 1, 0, 2}, {13, 13, 1, 255, 0}, {18, 13, 1, 255, 0}, {19, 13, 1, 0, 2}, {26, 13, 1, 2, 0}, {27, 13, 3, 0, 255}, {3, 14, 2, 1, 0}, {5, 14, 1, 2, 1}, {11, 14, 1, 0, 2}, {12, 14, 1, 255, 0}, {19, 14, 1, 255, 0}, {20, 14, 1, 0, 2}, {27, 14, 1, 2, 0}, {28, 14, 1, 3, 0}, {4, 15, 1, 2, 1}, {4, 16, 1, 1, 2}, {27, 17, 1, 3, 2}, {3, 18, 2, 0, 1}, {5, 18, 1, 1, 2}, {11, 18, 1, 2, 0}, {12, 18, 1, 0, 255}, {19, 18, 1, 0, 255}, {20, 18, 1, 2, 0}, {26, 18, 1, 3, 2}, {27, 18, 2, 0, 3}, {2, 19, 3, 255, 0}, {5, 19, 1, 0, 1}, {6, 19, 1, 1, 2}, {12, 19, 1, 2, 0}, {13, 19, 1, 0, 255}, {18, 19, 1, 0, 255}, {19, 19, 1, 2, 0}, {25, 19, 1, 3, 2}, {26, 19, 1, 0, 3}, {27, 19, 3, 255, 0}, {5, 20, 1, 255, 0}, {6, 20, 1, 0, 1}, {7, 20, 1, 1, 2}, {13, 20, 1, 2, 0}, {14, 20, 4, 0, 255}, {18, 20, 1, 2, 0}, {24, 20, 1, 3, 2}, {25, 20, 1, 0, 3}, {26, 20, 1, 255, 0}, {14, 21, 4, 2, 0}, {5, 22, 1, 0, 255}, {6, 22, 1, 1, 0}, {25, 22, 1, 3, 0}, {26, 22, 1, 0, 255}, {4, 23, 1, 0, 255}, {5, 23, 1, 1, 0}, {24, 23, 2, 2, 3}, {26, 23, 1, 3, 0}, {27, 23, 1, 0, 255}, {7, 24, 1, 2, 1}, {9, 24, 3, 1, 2}, {20, 24, 2, 3, 2}, {4, 25, 1, 255, 0}, {5, 25, 1, 0, 1}, {7, 25, 2, 1, 2}, {10, 25, 2, 0, 1}, {12, 25, 1, 1, 2}, {20, 25, 2, 0, 3}, {22, 25, 1, 3, 2}, {25, 25, 1, 3, 2}, {26, 25, 1, 0, 3}, {27, 25, 1, 255, 0}, {5, 26, 1, 255, 0}, {6, 26, 1, 0, 1}, {9, 26, 1, 0, 1}, {10, 26, 2, 255, 0}, {12, 26, 1, 0, 1}, {13, 26, 1, 1, 2}, {19, 26, 1, 0, 2}, {20, 26, 2, 255, 0}, {22, 26, 1, 0, 3}, {23, 26, 2, 3, 2}, {25, 26, 1, 0, 3}, {26, 26, 1, 255, 0}, {6, 27, 1, 255, 0}, {7, 27, 2, 0, 1}, {9, 27, 1, 255, 0}, {12, 27, 1, 255, 0}, {13, 27, 1, 0, 1}, {14, 27, 1, 1, 2}, {18, 27, 1, 0, 2}, {19, 27, 1, 255, 0}, {22, 27, 1, 255, 0}, {23, 27, 2, 0, 3}, {25, 27, 1, 255, 0}, {7, 28, 2, 255, 0}, {15, 28, 1, 1, 2}, {23, 28, 2, 255, 0}, {14, 29, 2, 0, 1}, {16, 29, 2, 0, 2}, {13, 30, 6, 255, 0}};
const uint8_t nastaveni_data_v2[] = {31, 31, 12, 37, 12, 12, 32, 67, 32, 12, 6, 33, 3, 32, 64, 96, 65, 32, 3, 33, 6, 5, 32, 65, 32, 1, 32, 64, 99, 64, 32, 1, 32, 65, 32, 5, 4, 32, 67, 33, 64, 101, 64, 33, 67, 32, 4, 3, 32, 67, 96, 66, 102, 67, 96, 65, 32, 3, 3, 32, 66, 112, 65, 32, 3, 4, 32, 65, 111, 65, 32, 4, 5, 32, 64, 111, 64, 32, 5, 5, 32, 64, 101, 35, 101, 64, 32, 5, 4, 32, 64, 101, 32, 3, 32, 101, 64, 32, 4, 1, 34, 64, 101, 32, 5, 32, 101, 64, 34, 1, 1, 32, 65, 101, 32, 7, 32, 101, 65, 32, 1, 1, 32, 64, 102, 32, 7, 32, 102, 64, 32, 1, 1, 32, 64, 102, 32, 7, 32, 103, 32, 1, 1, 32, 103, 32, 7, 32, 103, 32, 1, 1, 34, 102, 32, 5, 32, 102, 34, 1, 4, 32, 102, 32, 3, 32, 102, 32, 4, 5, 32, 102, 35, 101, 128, 32, 5, 5, 32, 112, 128, 32, 5, 4, 32, 114, 128, 32, 4, 3, 32, 116, 128, 32, 3, 3, 32, 110, 130, 98, 128, 32, 3, 4, 32, 99, 33, 102, 128, 33, 128, 97, 128, 32, 4, 5, 32, 97, 32, 1, 32, 100, 128, 32, 1, 32, 129, 32, 5, 6, 33, 3, 32, 98, 128, 32, 3, 33, 6, 12, 32, 131, 32, 12, 12, 37, 12, 31, 31};

const uint8_t mario_data[][5] = {{10, 0, 10, 0, 255}, {8, 2, 2, 0, 255}, {20, 2, 6, 0, 255}, {8, 4, 6, 1, 0}, {14, 4, 4, 2, 0}, {18, 4, 2, 3, 0}, {20, 4, 2, 2, 0}, {22, 4, 4, 255, 0}, {6, 6, 2, 1, 255}, {8, 6, 2, 2, 1}, {12, 6, 2, 2, 1}, {22, 6, 4, 2, 255}, {12, 8, 2, 1, 2}, {18, 8, 2, 2, 3}, {20, 8, 2, 3, 2}, {26, 8, 2, 2, 255}, {6, 10, 2, 255, 1}, {8, 10, 2, 1, 2}, {10, 10, 4, 2, 1}, {18, 10, 2, 3, 2}, {22, 10, 4, 3, 2}, {26, 10, 2, 255, 2}, {8, 12, 2, 255, 1}, {18, 12, 4, 2, 3}, {22, 12, 4, 255, 3}, {8, 14, 2, 0, 255}, {10, 14, 2, 0, 2}, {12, 14, 2, 4, 2}, {14, 14, 4, 0, 2}, {18, 14, 2, 4, 2}, {20, 14, 2, 0, 2}, {22, 14, 2, 0, 255}, {6, 16, 2, 0, 255}, {24, 16, 2, 0, 255}, {4, 18, 2, 0, 255}, {14, 18, 4, 4, 0}, {26, 18, 2, 0, 255}, {4, 20, 4, 2, 0}, {10, 20, 2, 4, 0}, {12, 20, 2, 5, 4}, {18, 20, 2, 5, 4}, {20, 20, 2, 4, 0}, {24, 20, 4, 2, 0}, {8, 22, 2, 2, 0}, {12, 22, 2, 4, 5}, {18, 22, 2, 4, 5}, {22, 22, 2, 2, 0}, {8, 24, 2, 4, 2}, {22, 24, 2, 4, 2}, {4, 26, 4, 255, 2}, {14, 26, 4, 255, 4}, {24, 26, 4, 255, 2}, {6, 28, 2, 1, 255}, {8, 28, 4, 1, 4}, {12, 28, 2, 255, 4}, {18, 28, 2, 255, 4}, {20, 28, 4, 1, 4}, {24, 28, 2, 1, 255}, {4, 30, 2, 1, 255}, {26, 30, 2, 1, 255}, {4, 32, 8, 255, 1}, {20, 32, 8, 255, 1}};
const uint8_t mario_data_v2[] = {31, 31, 31, 31, 17, 33, 69, 3, 97, 17, 33, 69, 3, 97, 5, 99, 5, 35, 69, 1, 99, 5, 99, 5, 35, 69, 1, 99, 1, 33, 97, 67, 97, 1, 39, 65, 131, 99, 1, 33, 97, 67, 97, 1, 39, 65, 131, 99, 35, 101, 67, 37, 135, 99, 35, 101, 67, 37, 135, 99, 35, 97, 65, 97, 67, 133, 161, 133, 3, 35, 97, 65, 97, 67, 133, 161, 133, 3, 35, 73, 35, 135, 5, 35, 73, 35, 135, 5, 35, 73, 35, 135, 5, 35, 73, 35, 135, 5, 35, 195, 65, 193, 65, 133, 161, 133, 3, 35, 195, 65, 193, 65, 133, 161, 133, 3, 1, 33, 67, 195, 65, 37, 135, 99, 1, 33, 67, 195, 65, 37, 135, 99, 1, 33, 1, 67, 193, 1, 39, 65, 131, 99, 1, 33, 1, 67, 193, 1, 39, 65, 131, 99, 1, 33, 1, 67, 193, 3, 35, 69, 1, 99, 1, 33, 1, 67, 193, 3, 35, 69, 1, 99, 7, 65, 7, 33, 69, 3, 97, 7, 65, 7, 33, 69, 3, 97, 31, 31, 31, 31};

const uint8_t piskvorky_data[][5] = {{1, 1, 2, 0, 255}, {6, 1, 1, 0, 255}, {9, 1, 1, 0, 255}, {13, 1, 3, 0, 255}, {20, 1, 1, 0, 255}, {1, 2, 1, 255, 0}, {3, 2, 1, 0, 255}, {5, 2, 1, 0, 255}, {14, 2, 1, 255, 0}, {2, 3, 1, 255, 0}, {4, 3, 1, 0, 255}, {6, 3, 1, 255, 0}, {8, 3, 1, 0, 255}, {10, 3, 1, 0, 255}, {12, 3, 1, 0, 255}, {13, 3, 1, 255, 0}, {15, 3, 1, 255, 0}, {16, 3, 1, 0, 255}, {19, 3, 1, 0, 255}, {20, 3, 1, 255, 0}, {5, 4, 1, 255, 0}, {10, 4, 1, 255, 0}, {20, 4, 1, 0, 255}, {2, 5, 1, 0, 255}, {5, 5, 1, 0, 255}, {1, 6, 1, 0, 255}, {3, 6, 2, 255, 0}, {6, 6, 1, 0, 255}, {12, 6, 1, 255, 0}, {13, 6, 1, 0, 255}, {15, 6, 1, 0, 255}, {16, 6, 1, 255, 0}, {2, 7, 1, 255, 0}, {5, 7, 1, 255, 0}, {10, 7, 1, 0, 255}, {14, 7, 1, 0, 255}, {1, 8, 1, 255, 0}, {6, 8, 1, 255, 0}, {13, 8, 3, 255, 0}, {21, 8, 1, 0, 255}, {3, 9, 5, 0, 255}, {11, 9, 2, 0, 255}, {22, 9, 7, 0, 255}, {1, 10, 2, 0, 255}, {13, 10, 6, 0, 255}, {29, 10, 2, 0, 255}, {1, 11, 4, 255, 0}, {25, 11, 6, 255, 0}, {5, 12, 3, 255, 0}, {11, 12, 8, 255, 0}, {22, 12, 3, 255, 0}, {8, 13, 1, 255, 0}, {14, 13, 3, 0, 255}, {15, 14, 1, 255, 0}, {19, 14, 1, 255, 0}, {13, 15, 1, 0, 255}, {14, 15, 1, 255, 0}, {16, 15, 1, 255, 0}, {17, 15, 1, 0, 255}, {8, 18, 1, 0, 255}, {13, 18, 1, 255, 0}, {14, 18, 1, 0, 255}, {16, 18, 1, 0, 255}, {17, 18, 1, 255, 0}, {19, 18, 1, 0, 255}, {15, 19, 1, 0, 255}, {14, 20, 3, 255, 0}, {3, 21, 5, 0, 255}, {11, 21, 8, 0, 255}, {22, 21, 2, 0, 255}, {1, 22, 2, 0, 255}, {24, 22, 7, 0, 255}, {1, 23, 5, 255, 0}, {12, 23, 5, 255, 0}, {29, 23, 2, 255, 0}, {6, 24, 2, 255, 0}, {11, 24, 1, 255, 0}, {17, 24, 2, 255, 0}, {22, 24, 7, 255, 0}, {24, 25, 2, 0, 255}, {29, 25, 1, 0, 255}, {10, 26, 1, 255, 0}, {19, 26, 1, 255, 0}, {24, 26, 1, 255, 0}, {26, 26, 1, 0, 255}, {28, 26, 1, 0, 255}, {25, 27, 1, 255, 0}, {27, 27, 1, 0, 255}, {29, 27, 1, 255, 0}, {28, 28, 1, 255, 0}, {8, 29, 1, 255, 0}, {21, 29, 1, 255, 0}, {25, 29, 1, 0, 255}, {27, 29, 1, 255, 0}, {28, 29, 1, 0, 255}, {26, 30, 1, 255, 0}, {29, 30, 1, 0, 255}, {9, 31, 1, 255, 0}, {20, 31, 1, 255, 0}, {25, 31, 1, 255, 0}, {28, 31, 2, 255, 0}};
const uint8_t piskvorky_data_v2[] = {31, 0, 32, 3, 33, 1, 32, 10, 32, 8, 0, 33, 1, 33, 2, 32, 10, 32, 8, 1, 35, 2, 33, 9, 33, 8, 2, 34, 2, 33, 9, 33, 8, 1, 33, 0, 33, 1, 34, 8, 33, 8, 0, 33, 2, 33, 0, 34, 8, 34, 7, 8, 34, 8, 34, 7, 2, 41, 4, 42, 2, 0, 61, 32, 2, 32, 2, 50, 5, 8, 34, 8, 34, 7, 2, 34, 2, 34, 8, 33, 8, 0, 33, 2, 33, 1, 33, 2, 34, 2, 33, 8, 0, 32, 4, 32, 1, 33, 0, 33, 2, 33, 0, 33, 8, 0, 33, 2, 33, 1, 33, 0, 32, 4, 32, 0, 33, 8, 2, 34, 3, 33, 0, 33, 2, 33, 0, 33, 8, 9, 33, 2, 34, 2, 34, 7, 9, 33, 8, 34, 7, 2, 42, 3, 39, 5, 0, 33, 0, 58, 32, 7, 52, 2, 8, 34, 8, 34, 7, 8, 34, 8, 34, 7, 8, 34, 9, 33, 0, 32, 5, 8, 33, 10, 33, 0, 33, 1, 33, 32, 8, 33, 10, 33, 1, 35, 1, 8, 33, 10, 33, 2, 33, 2, 8, 33, 10, 33, 1, 33, 0, 33, 32, 9, 32, 10, 32, 1, 33, 2, 32, 32, 9, 32, 10, 32, 8, 31};

const uint8_t tetris_data[][5] = {{11, 5, 10, 0, 255}, {12, 6, 7, 1, 0}, {19, 6, 1, 2, 0}, {13, 7, 6, 3, 1}, {12, 13, 1, 2, 1}, {13, 13, 6, 2, 3}, {12, 14, 8, 0, 2}, {1, 15, 10, 0, 255}, {21, 15, 10, 0, 255}, {2, 16, 7, 1, 0}, {9, 16, 1, 2, 0}, {12, 16, 7, 1, 0}, {19, 16, 1, 2, 0}, {22, 16, 7, 1, 0}, {29, 16, 1, 2, 0}, {3, 17, 6, 3, 1}, {13, 17, 6, 3, 1}, {23, 17, 6, 3, 1}, {2, 23, 1, 2, 1}, {3, 23, 6, 2, 3}, {12, 23, 1, 2, 1}, {13, 23, 6, 2, 3}, {22, 23, 1, 2, 1}, {23, 23, 6, 2, 3}, {2, 24, 8, 0, 2}, {12, 24, 8, 0, 2}, {22, 24, 8, 0, 2}, {1, 25, 30, 255, 0}};
const uint8_t tetris_data_v2[] = {31, 14, 41, 6, 14, 32, 70, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 103, 32, 6, 14, 41, 6, 4, 51, 6, 4, 32, 70, 96, 33, 70, 96, 32, 6, 4, 32, 64, 133, 96, 33, 64, 133, 96, 32, 6, 4, 32, 64, 133, 96, 33, 64, 133, 96, 32, 6, 4, 32, 64, 133, 96, 33, 64, 133, 96, 32, 6, 4, 32, 64, 133, 96, 33, 64, 133, 96, 32, 6, 4, 32, 64, 133, 96, 33, 64, 133, 96, 32, 6, 4, 32, 64, 133, 96, 33, 64, 133, 96, 32, 6, 4, 32, 103, 33, 103, 32, 6, 4, 51, 6, 14, 41, 6, 14, 32, 70, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 64, 133, 96, 32, 6, 14, 32, 103, 32, 6, 14, 41, 6, 31};

int main()
{
    printf("Moje ukládání : To druhé ukládání :D\n");
    printf("   Snake: %d : %d\n", sizeof(snake_data_v2), sizeof(snake_data));
    printf(" Pac-man: %d : %d\n", sizeof(pacman_data_v2), sizeof(pacman_data));
    printf("Nastavení: %d : %d\n", sizeof(nastaveni_data_v2), sizeof(nastaveni_data));
    printf("   Mario: %d : %d\n", sizeof(mario_data_v2), sizeof(mario_data));
    printf("Piškvorky: %d : %d\n", sizeof(piskvorky_data_v2), sizeof(piskvorky_data));
    printf("  Tetris: %d : %d\n", sizeof(tetris_data_v2), sizeof(tetris_data));
    return 0;
}