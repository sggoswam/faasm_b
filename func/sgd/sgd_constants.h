#ifndef FAASM_SGD_CONSTANTS_H
#define FAASM_SGD_CONSTANTS_H

#include <stdint.h>

const char *EPOCH_COUNT_KEY = "epochCount";
const char *WEIGHTS_KEY = "weights";
const char *INPUTS_KEY = "inputs";
const char *OUTPUTS_KEY = "outputs";

const int N_BATCHES = 10; // Number of batches in each epoch

const int N_WEIGHTS = 10; // Number of weights
const int N_TRAIN = 1000; // Number of training examples

const double LEARNING_RATE = 0.1;
const uint8_t MAX_EPOCHS = 10;

#endif