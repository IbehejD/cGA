/**
 * Copyright (c) 2025 David Ibehej
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const size_t BITS_PER_CHAR = 8;
typedef unsigned char Gene;
typedef double (*Callback)(Gene *, size_t);

typedef struct Solution
{
    Gene *value;
    double fitness;
} Solution;

unsigned char get_bit_from_gene(int position, Gene *gene)
{
    int BITS_PER_CHAR_idx = position / BITS_PER_CHAR;
    int bit_idx = position % BITS_PER_CHAR;
    return (gene[BITS_PER_CHAR_idx] >> bit_idx) & 1;
}
void calculate_fitness(Solution *solution, size_t solution_size, Callback callback)
{
    solution->fitness = callback(solution->value, solution_size);
}

void generate_candidate(Solution *solution, float *probability_arr, size_t probability_arr_sizes)
{
    for (size_t i = 0; i < probability_arr_sizes; i++)
    {
        double r = (double)random() / (double)0x7fffffff;
        if (r < probability_arr[i])
        {
            solution->value[i / BITS_PER_CHAR] |= (1 << (i % BITS_PER_CHAR)); // Nastaví i-tý bit v příslušném bajtu na 1
        }
        else
        {
            solution->value[i / BITS_PER_CHAR] &= ~(1 << (i % BITS_PER_CHAR)); // Nastaví i-tý bit v příslušném bajtu na 0
        }
    }
}

void fill_probability_array(float *probability_arr, size_t probability_arr_size)
{
    for (size_t i = 0; i < probability_arr_size; i++)
    {
        probability_arr[i] = 0.5;
    }
}

int compete(Solution *a, Solution *b)
{
    return b->fitness > a->fitness;
}

void update_probability_array(float *probability_arr, size_t probability_arr_size, Gene *winner, Gene *loser, size_t population_size)
{
    for (size_t i = 0; i < probability_arr_size; i++)
    {
        unsigned char winner_bit = get_bit_from_gene(i, winner);
        unsigned char loser_bit = get_bit_from_gene(i, loser);

        if (winner_bit != loser_bit)
        {
            if (winner_bit)
                probability_arr[i] += 1.0 / (float)population_size;
            else
                probability_arr[i] -= 1.0 / (float)population_size;
        }
    }
}

void run(int generations, size_t gene_size, size_t population_size, Callback fitness_function)
{
    srandom(time(NULL));

    float *probability_arr = calloc(gene_size, sizeof(float));
    size_t gene_bytes = (gene_size + 7) / 8;

    Solution best_solution = {(Gene *)calloc(gene_bytes, BITS_PER_CHAR), 0};

    Solution candidates[] = {
        {(Gene *)calloc(gene_bytes, BITS_PER_CHAR), 0},
        {(Gene *)calloc(gene_bytes, BITS_PER_CHAR), 0}};

    fill_probability_array(probability_arr, gene_size);

    for (int i = 0; i < generations; i++)
    {
        generate_candidate(&candidates[0], probability_arr, gene_size);
        generate_candidate(&candidates[1], probability_arr, gene_size);

        calculate_fitness(&candidates[0], gene_size, fitness_function);
        calculate_fitness(&candidates[1], gene_size, fitness_function);

        int winner_index = compete(&candidates[0], &candidates[1]);

        update_probability_array(probability_arr, gene_size, candidates[winner_index].value, candidates[!winner_index].value, population_size);

        if (candidates[winner_index].fitness > best_solution.fitness)
        {
            Gene *temp = best_solution.value;
            best_solution = candidates[winner_index];
            candidates[winner_index].value = temp;
        }

        printf("generation: %d best fitness: %f\n", i + 1, best_solution.fitness);
    }

    free(candidates[0].value);
    free(candidates[1].value);
    free(best_solution.value);
    free(probability_arr);
}
double fitness(Gene *gene, size_t gene_size)
{
    // Converts the gene (bitstring) to its decimal value
    unsigned long long num = 0;
    size_t gene_bytes = (gene_size + 7) / 8;

    for (size_t i = 0; i < gene_bytes; i++)
    {
        num |= ((unsigned long long)gene[i]) << (8 * i);
    }

    return (double)num;
}

int main()
{
    Callback fitness_function = fitness;
    run(100, 32, 10, fitness_function);
    return 0;
}